/*
 * usb_monitor — reconstructed from /app/bin/gun's sibling daemon.
 *
 * Clean-room C rebuilt from the Ghidra decompilation in
 * decompiled/usb_monitor.c (9788-byte ARM ELF, stripped of debug info but with
 * symbols and an intact string table). This compiles to a functionally
 * identical daemon; it is not a byte-for-byte reproduction of the vendor object.
 *
 * What it does: it watches the USB device-controller state and keeps the vision
 * process /app/bin/gun in step with the host connection.
 *
 *   - On the FIRST time the gadget reaches "configured", it launches gun.
 *   - When the state later leaves "configured" (host unplugged / reset), it
 *     disables the recoil-motor PWM and kills gun.
 *   - When the state returns to "configured", it reboots the whole device.
 *
 * That reboot-on-reconnect is exactly what fought our mass-storage backup: any
 * gadget reconfiguration trips this daemon (see FINDINGS section 17). Killing
 * usb_monitor first is what let the swap hold.
 *
 * Verified against the original by string table, control flow and the four
 * touched paths:
 *     /sys/class/udc/lb_hdc.0/state          read each second
 *     /sys/class/pwm/pwmchip0/pwm5/enable    written "0" to cut the motor
 *     /app/bin/gun &                         relaunch
 *     pkill -9 gun / reboot                  process + system control
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <syslog.h>
#include <sys/stat.h>
#include <fcntl.h>

#define UDC_STATE   "/sys/class/udc/lb_hdc.0/state"
#define PWM_ENABLE  "/sys/class/pwm/pwmchip0/pwm5/enable"
#define GUN_CMD     "/app/bin/gun &"

static volatile int running = 1;

static void signal_handler(int sig)
{
    if (sig == SIGINT || sig == SIGTERM) {
        syslog(LOG_INFO, "Received signal %d, shutting down.", sig);
        running = 0;
    }
}

/* Read the one-line UDC state (e.g. "configured", "not attached") into buf,
 * newline stripped. Yields "error" on any failure, matching the original. */
static char *read_usb_state(char *buf, size_t n)
{
    FILE *f = fopen(UDC_STATE, "r");
    if (!f) {
        syslog(LOG_ERR, "Failed to open USB state file: %s", UDC_STATE);
        strncpy(buf, "error", n);
        buf[n - 1] = '\0';
        return buf;
    }
    if (fgets(buf, n, f)) {
        buf[strcspn(buf, "\n")] = '\0';
    } else {
        syslog(LOG_ERR, "Failed to read USB state from file: %s", UDC_STATE);
        strncpy(buf, "error", n);
        buf[n - 1] = '\0';
    }
    fclose(f);
    return buf;
}

static void start_gun_task(void)
{
    if (system(GUN_CMD) == 0)
        syslog(LOG_INFO, "'gun' process start successfully.");
}

static void kill_gun_task(void)
{
    FILE *f;

    syslog(LOG_INFO, "Attempting to disable PWM and kill 'gun' process.");
    f = fopen(PWM_ENABLE, "w");
    if (!f) {
        syslog(LOG_ERR, "Failed to open PWM enable file: %s", PWM_ENABLE);
    } else {
        if (fprintf(f, "0") < 0)
            syslog(LOG_ERR, "Failed to write 0 to PWM enable file: %s", PWM_ENABLE);
        else
            syslog(LOG_INFO, "Successfully disabled PWM by writing 0 to %s", PWM_ENABLE);
        fclose(f);
    }

    if (system("pkill -9 gun") == 0)
        syslog(LOG_INFO, "'gun' process killed successfully.");
    else
        syslog(LOG_WARNING, "Failed to kill 'gun' process or 'gun' not found.");
}

static void reboot_system(void)
{
    syslog(LOG_INFO, "System is about to reboot now.");
    if (system("reboot") == -1)
        syslog(LOG_ERR, "Failed to execute reboot command.");
    syslog(LOG_INFO, "Reboot command executed.");
}

/* Classic double-fork daemonise: detach from the controlling terminal, become
 * a session leader, chdir /, and redirect the standard streams to /dev/null. */
static void daemonize(void)
{
    pid_t pid = fork();
    if (pid < 0) exit(1);
    if (pid > 0) exit(0);

    if (setsid() < 0) exit(1);
    signal(SIGHUP, SIG_IGN);

    pid = fork();
    if (pid < 0) exit(1);
    if (pid > 0) exit(0);

    if (chdir("/") < 0) {
        syslog(LOG_ERR, "Failed to change directory to /");
        exit(1);
    }
    umask(0);
    close(0); close(1); close(2);
    open("/dev/null", O_RDWR);
    dup(0);
    dup(0);
}

int main(void)
{
    char state[64];
    char last[64] = "";
    int configured_seen = 0;

    openlog("usb_monitor_daemon", LOG_PID | LOG_NDELAY, LOG_DAEMON);
    daemonize();
    syslog(LOG_INFO, "usb_monitor_daemon started.");

    signal(SIGTERM, signal_handler);
    signal(SIGINT, signal_handler);

    while (running) {
        read_usb_state(state, sizeof(state));

        if (strcmp(state, last) != 0) {
            syslog(LOG_INFO, "USB state changed from '%s' to '%s'", last, state);

            if (!configured_seen) {
                if (strcmp(state, "configured") == 0) {
                    configured_seen = 1;
                    syslog(LOG_INFO, "USB first configured state achieved.");
                    start_gun_task();
                }
            } else {
                int was = (strcmp(last, "configured") == 0);
                int now = (strcmp(state, "configured") == 0);
                if (was && !now) {
                    syslog(LOG_INFO,
                           "USB state changed from 'configured' to '%s'. Preparing to kill gun.",
                           state);
                    kill_gun_task();
                } else if (!was && now) {
                    syslog(LOG_INFO,
                           "USB state changed from '%s' to 'configured'. Preparing to reboot.",
                           last);
                    reboot_system();
                }
            }
            strncpy(last, state, sizeof(last));
            last[sizeof(last) - 1] = '\0';
        }
        sleep(1);
    }

    syslog(LOG_INFO, "usb_monitor_daemon stopped.");
    closelog();
    return 0;
}
