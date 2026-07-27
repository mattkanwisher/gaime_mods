CFG_USB_VID=0x2E2C
CFG_USB_PID=0x0631
CFG_USB_MF="Tassei Denki Co.,Ltd"
CFG_USB_PRODUCT="GAIME v1"

# File:   usb_gadget.sh
# Author: lombo technology
# Describe:
# This is the usb gadget scriptor

# enable debug info
# set -x

set -u

# functions variables
FUNC_COUNT=0
FUNC_ADB_ENABLE=0
FUNC_MSC_ENABLE=0
FUNC_UVC_ENABLE=0
FUNC_MTP_ENABLE=0
FUNC_HID_ENABLE=0
FUNC_RNDIS_ENABLE=0
FUNC_UAC1_ENABLE=0
FUNC_UAC_SPEAKER_ENABLE=0
FUNC_UAC_MICROPHONE_ENABLE=0

# functions pid
PID_ADB=0
PID_MSC=1
PID_HID=2
PID_UVC=3
PID_MTP=4
PID_RNDIS=5
PID_UAC1=6
PID_UAC_SPEAKER=7
PID_UAC_MICROPHONE=8

# for uvc
DeviceClass="0xEF"
DeviceSubClass="0x02"
DeviceProtocol="0x01"

# usb gadget device-descriptor info
USB_VID=0x302E		# lombo
USB_PID=0x0419
Serial=`cat /proc/cpuinfo | grep Serial`
# USB_SERIAL=`eval echo ${Serial##*:}`
USB_SERIAL=$(shuf -i 1-100000 -n 1)

# global variable
CONFIGFS_DIR="/sys/kernel/config"
GADGET_CONFIGFS_DIR=${CONFIGFS_DIR}/usb_gadget
GADGET_ROOT_DIR=${GADGET_CONFIGFS_DIR}/g1
UDC=`ls /sys/class/udc`
CUR_DIR=$(pwd)

CUR_SCRIPT=

usage() {
cat <<EOF
usage: $0 [option]... [arguments]...

Mandatory arguments to long options are mandatory for short options too.

Options:
	-h
	--help
		display this help information

	-c/--create "[func1] [func2]..."
		create usb gadget functions

	-s
	--stop
		stop usb gadget

	-l
	--list
		lists the currently supported usb gadget functions

e.g.:
	$0 -c "msc"
	$0 --create "msc"
		(create and start msc gadget)

	$0 -c "msc adb"
		(create and start msc and adb mult gadget)
EOF
}

error_info() {
	if [ $? -ne 0 ]; then
		echo -e "${CUR_SCRIPT}, {$1} fail, exit!"
		exit 1
	fi
}

# list all support gadget functions
gadget_functions_list() {
	for i in ${CUR_DIR}/g_??* ;
	do
		case "$i" in
		*.sh)
			$i "--list"
			;;
		*)
			;;
		esac
	done
}

# create the usb gadget
gadget_create() {
	# setp 1, mount usb gadget configfs
	if [ ! -d ${GADGET_CONFIGFS_DIR} ]; then
		mount none ${CONFIGFS_DIR} -t configfs
	fi
	error_info "mount configfs"

	# setp 2, create one usb gadget
	cd ${GADGET_CONFIGFS_DIR}
	if [ -d g1 ]; then
		cd g1
	else
		mkdir g1 && cd g1
	fi
	error_info "mkdir g1"

	# setp 3, create usb gadget config and config string
	mkdir configs/c.1
	mkdir strings/0x409
	mkdir configs/c.1/strings/0x409

	# setp 4, fill usb gadget device descriptor information
	echo ${CFG_USB_VID} > idVendor

	if [ ${CFG_USB_PID}x == ""x ]; then
		echo ${USB_PID} > idProduct
	else
		echo ${CFG_USB_PID} > idProduct
	fi

	echo ${USB_SERIAL} > strings/0x409/serialnumber
	echo ${CFG_USB_MF} > strings/0x409/manufacturer
	echo ${CFG_USB_PRODUCT} > strings/0x409/product

	# setp 5, fill usb gadget config descriptor information
	echo "cfg 1" > configs/c.1/strings/0x409/configuration
	# use usb bus power, 5V,500mA
	echo 500 > configs/c.1/MaxPower
}

# destroy the usb gadget
gadget_destroy() {
	# setp 1
	cd ${GADGET_ROOT_DIR}
	error_info "cd ${GADGET_ROOT_DIR}"

	# setp 2, Unbinding USB Device Controller
	grep $UDC UDC > /dev/null 2>&1 && echo "" > UDC

	# set 3, remove functions
	cd functions
	var=$(ls ./)

	echo $var | grep "mass_storage" > /dev/null 2>&1
	if [ $? = 0 ]; then
		. ${CUR_DIR}/g_msc.sh --stop
	fi

	echo $var | grep "ffs.adb" > /dev/null 2>&1
	if [ $? = 0 ]; then
		. ${CUR_DIR}/g_adb.sh --stop
	fi

	echo $var | grep "uac1" > /dev/null 2>&1
	if [ $? = 0 ]; then
		. ${CUR_DIR}/g_uac1.sh --stop
	fi

	echo $var | grep "uac1_mic" > /dev/null 2>&1
	if [ $? = 0 ]; then
		. ${CUR_DIR}/g_uac_mic.sh --stop
	fi

	echo $var | grep "uac1_legacy" > /dev/null 2>&1
	if [ $? = 0 ]; then
		. ${CUR_DIR}/g_uac_speaker.sh --stop
	fi

	echo $var | grep "rndis" > /dev/null 2>&1
	if [ $? = 0 ]; then
		. ${CUR_DIR}/g_rndis.sh --stop
	fi

	echo $var | grep "uvc" > /dev/null 2>&1
	if [ $? = 0 ]; then
		. ${CUR_DIR}/g_uvc.sh --stop
	fi

	echo $var | grep "ffs.mtp" > /dev/null 2>&1
	if [ $? = 0 ]; then
		. ${CUR_DIR}/g_mtp.sh --stop
	fi

	echo $var | grep "hid" > /dev/null 2>&1
	if [ $? = 0 ]; then
		. ${CUR_DIR}/g_hid.sh --stop
	fi

	cd ..

	# setp 4, Clearing English strings
	rmdir strings/0x409

	# setp 5, Cleaning up configuration
	rmdir configs/c.1/strings/0x409
	rmdir configs/c.1

	# setp 6, Removing gadget directory
	cd $GADGET_CONFIGFS_DIR
	rmdir g1

	cd /
	echo "Stop usb gadget OK!"
}

Main() {
	if [ ${FUNC_COUNT} -gt 0 ]; then
		gadget_create
	fi

	if [ ${FUNC_HID_ENABLE} = 1 ]; then
		CUR_SCRIPT=${CUR_DIR}/g_hid.sh
		. ${CUR_DIR}/g_hid.sh --start
		CUR_SCRIPT=$0
		error_info "create hid"
	fi
	
	if [ ${FUNC_RNDIS_ENABLE} = 1 ]; then
		CUR_SCRIPT=${CUR_DIR}/g_rndis.sh
		. ${CUR_DIR}/g_rndis.sh --start
		error_info "create rndis"
	fi

	if [ ${FUNC_UVC_ENABLE} = 1 ]; then
		CUR_SCRIPT=${CUR_DIR}/g_uvc.sh
		. ${CUR_DIR}/g_uvc.sh --start
		CUR_SCRIPT=$0
		error_info "create uvc"

		cd ${GADGET_ROOT_DIR}
		echo ${DeviceClass} > bDeviceClass
		echo ${DeviceSubClass} > bDeviceSubClass
		echo ${DeviceProtocol} > bDeviceProtocol
	fi

	if [ ${FUNC_UAC_MICROPHONE_ENABLE} = 1 ]; then
		CUR_SCRIPT=${CUR_DIR}/g_uac_mic.sh
		. ${CUR_DIR}/g_uac_mic.sh --start
		CUR_SCRIPT=$0
		error_info "create uac_mic"
	fi

	if [ ${FUNC_UAC_SPEAKER_ENABLE} = 1 ]; then
		CUR_SCRIPT=${CUR_DIR}/g_uac_speaker.sh
		. ${CUR_DIR}/g_uac_speaker.sh --start
		CUR_SCRIPT=$0
		error_info "create uac_speaker"
	fi

	if [ ${FUNC_UAC1_ENABLE} = 1 ]; then
		. ${CUR_DIR}/g_uac1.sh --start
		error_info ${LINENO}
	fi

	if [ ${FUNC_MSC_ENABLE} = 1 ]; then
		CUR_SCRIPT=${CUR_DIR}/g_msc.sh
		. ${CUR_DIR}/g_msc.sh --start
		CUR_SCRIPT=$0
		error_info "create msc"
	fi

	if [ ${FUNC_MTP_ENABLE} = 1 ]; then
		CUR_SCRIPT=${CUR_DIR}/g_mtp.sh
		. ${CUR_DIR}/g_mtp.sh --start
		error_info "create mtp"
	fi

	if [ ${FUNC_ADB_ENABLE} = 1 ]; then
		CUR_SCRIPT=${CUR_DIR}/g_adb.sh
		. ${CUR_DIR}/g_adb.sh --start
		CUR_SCRIPT=$0
		error_info "create adb"
	fi

	if [ ${FUNC_COUNT} -gt 0 ]; then
		# start the usb gadget
		echo ${UDC} > ${GADGET_CONFIGFS_DIR}/g1/UDC
		error_info "udc run"
		echo "Start usb gadget OK!"
	fi
}

if [ -z "$1" ]; then
	usage
	exit 0
fi

ARGS=`getopt -o hc:sl -l help,create:,stop,list -n $0 -- "$@"`
if [ $? != 0 ]; then
	echo "Terminating..."
	exit 1
fi

eval set -- "${ARGS}"

while true
do
	case "$1" in
	-h|--help)
		usage
		exit 0
	;;

	'')
		usage
		exit 0
	;;

	-c|--create)
		for func in $2;
		do
		case $func in
			msc)
				FUNC_MSC_ENABLE=1
				FUNC_COUNT=$(($FUNC_COUNT+1))
				USB_PID=$((${USB_PID} + (1<<${PID_MSC})))
			;;

			adb)
				FUNC_ADB_ENABLE=1
				FUNC_COUNT=$(($FUNC_COUNT+1))
				USB_PID=$((${USB_PID} + (1<<${PID_ADB})))
			;;

			uac_mic)
				FUNC_UAC_MICROPHONE_ENABLE=1
				FUNC_COUNT=$(($FUNC_COUNT+1))
				USB_PID=$((${USB_PID} + (1<<${PID_UAC_MICROPHONE})))
			;;

			uac_speaker)
				FUNC_UAC_SPEAKER_ENABLE=1
				FUNC_COUNT=$(($FUNC_COUNT+1))
				USB_PID=$((${USB_PID} + (1<<${PID_UAC_SPEAKER})))
			;;

			uac1)
				FUNC_UAC1_ENABLE=1
				FUNC_COUNT=$(($FUNC_COUNT+1))
				USB_PID=$((${USB_PID} + (1<<${PID_UAC1})))
			;;

			rndis)
				FUNC_RNDIS_ENABLE=1
				FUNC_COUNT=$(($FUNC_COUNT+1))
				USB_PID=$((${USB_PID} + (1<<${PID_RNDIS})))
			;;

			uvc)
				FUNC_UVC_ENABLE=1
				FUNC_COUNT=$(($FUNC_COUNT+1))
				USB_PID=$((${USB_PID} + (1<<${PID_UVC})))
			;;

			mtp)
				FUNC_MTP_ENABLE=1
				FUNC_COUNT=$(($FUNC_COUNT+1))
				USB_PID=$((${USB_PID} + (1<<${PID_MTP})))
			;;

			hid)
				FUNC_HID_ENABLE=1
				FUNC_COUNT=$(($FUNC_COUNT+1))
				USB_PID=$((${USB_PID} + (1<<${PID_HID})))
			;;

			*)
				echo "Not support $func gadget!!!"
				exit 1
			;;
		esac
		done

		shift 2
	;;

	-s|--stop)
		gadget_destroy
		exit 0
	;;

	-l|--list)
		gadget_functions_list
		exit 0
	;;

	--)
		shift
		break
	;;

	*)
		echo "Option is error!, exit..."
		eixt 1
	esac
done

Main
