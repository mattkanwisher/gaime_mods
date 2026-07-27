CFG_UVC_ENABLE=1
CFG_UAC1_ENABLE=0
CFG_ADB_ENABLE=0
CFG_MSC_ENABLE=0
CFG_RNDIS_ENABLE=0
CFG_MTP_ENABLE=0
CFG_HID_ENABLE=1

USB_GADGET_DIR=/app/shell/usb/gadget

mount nodev -t debugfs /sys/kernel/debug/
USB_ROLE_NODE=/sys/kernel/debug/lb_hdc.0/role
USB_ROLE=`cat ${USB_ROLE_NODE}`
umount /sys/kernel/debug

if [ "x${USB_ROLE}" != "xgadget" ]; then
	echo "$0: usb is not device mode, will exit!"
	exit 0
fi

if [ ! -d $USB_GADGET_DIR ]; then
	echo "$0: not find \"${USB_GADGET_DIR}/\" directory, will exit!"
	exit 0
fi

GADGET_FUNCTIONS=""

if [ ${CFG_HID_ENABLE} -eq 1 ]; then
	GADGET_FUNCTIONS="hid"
fi

if [ ${CFG_UVC_ENABLE} -eq 1 ]; then
	GADGET_FUNCTIONS="${GADGET_FUNCTIONS} uvc"
fi

if [ ${CFG_UAC1_ENABLE} -eq 1 ]; then
	GADGET_FUNCTIONS="${GADGET_FUNCTIONS} uac1"
fi

if [ ${CFG_ADB_ENABLE} -eq 1 ]; then
	GADGET_FUNCTIONS="${GADGET_FUNCTIONS} adb"
fi

if [ ${CFG_MSC_ENABLE} -eq 1 ]; then
	GADGET_FUNCTIONS="${GADGET_FUNCTIONS} msc"
fi

if [ ${CFG_RNDIS_ENABLE} -eq 1 ]; then
	GADGET_FUNCTIONS="${GADGET_FUNCTIONS} rndis"
fi

if [ ${CFG_MTP_ENABLE} -eq 1 ]; then
	GADGET_FUNCTIONS="${GADGET_FUNCTIONS} mtp"
fi



cd $USB_GADGET_DIR

case "$1" in
	--start)
		./usb_gadget.sh -c "${GADGET_FUNCTIONS}"
		;;

	--stop)
		./usb_gadget.sh -s
		;;

	*)
		echo "($0): invalid option, will exit..."
		exit 1
		;;
esac

cd - 1&>/dev/null
