# #!/bin/sh
APP_NAME=/app/bin/gun
UVC_APP=uvc-gadget
USB_MONITOR=/app/bin/usb_monitor

# QT env
source /etc/profile

case "$1" in
	start)
		LOG_DIR="/app"
		# 计算文件数量
		LOG_COUNT=$(ls -1 ${LOG_DIR}/*.log 2>/dev/null | wc -l)
		# 如果文件数量大于5，则删除日期最早的文件
		if [ $LOG_COUNT -gt 4 ]; then
			# 使用ls和head命令找到最早的文件并删除它
			# ls命令根据名字排序，因日志文件名以日期开头，自然排序匹配需求
			OLDEST_LOG=$(ls -tr ${LOG_DIR}/*.log | head -1)
			echo "Deleting oldest log file: $OLDEST_LOG"
			rm -f "$OLDEST_LOG"
		else
			echo "No need to delete files. There are only $LOG_COUNT log files."
		fi

		mount -o rw,remount /
		$UVC_APP &
		$USB_MONITOR &
		# $APP_NAME &

		;;
	stop)
		# pkill -9 $APP_NAME
		usleep 100000
		;;
	*)
		echo "($0): invalid option, exit..."
		exit ${LINENO}
		;;
esac
