CFG_LUN0_FILE="/dev/loop0"
CFG_LUN0_REMOVABLE=1
CFG_LUN0_RO=0
CFG_LUN0_FILE_MOUNT_DIR="/mnt/usb"

##
# begin of create usb msc gadget function
#
# params:
# @p1: msc function name
##
msc_func_create_begin() {

local MSC_FUNC=$1

	cd ${GADGET_ROOT_DIR}/functions

	mkdir ${MSC_FUNC}
	error_info "create msc func"

	cd ${MSC_FUNC}
}

##
# create msc's lun
#
# lun: Logical Unit Number
#
# params:
# @p1: lun name, e.g.: lun.0 lun.1
# @p2: lun device file
# @p3: the mount dir of lun device
# @p4: tools for format lun device, e.g:mkfs.vfat mkfs.ext4
##
msc_func_lun_create() {

local LUN=$1
local DEVICE=$2
local MOUNT_DIR=$3

	if [ ! -d ${MOUNT_DIR} ]; then
		mkdir -p ${MOUNT_DIR}
	fi

	mount ${DEVICE} ${MOUNT_DIR}
	error_info "mount ${DEVICE} to ${MOUNT_DIR}"

	if [ ! -d ${LUN} ]; then
		mkdir ${LUN}
	fi

	echo ${CFG_LUN0_RO} > ${LUN}/ro
	echo ${CFG_LUN0_REMOVABLE} > ${LUN}/removable
	echo ${DEVICE} > ${LUN}/file
}

##
# destroy msc's lun
#
# params:
# @p1: lun name
# @p2: lun dev mount dir
##
msc_func_lun_destroy() {

local LUN=$1
local LUN_DEV_MOUNT_DIR=$2

	umount ${LUN_DEV_MOUNT_DIR}
	error_info "umount ${LUN_DEV_MOUNT_DIR}"

# lun.0 is default, can't be manually rmdir
	if [ -d ${LUN} -a ${LUN} != "lun.0" ]; then
		rmdir ${LUN}
	fi
}

##
# done of create usb msc gadget function
#
# params:
# @p1: msc function name
##
msc_func_create_done() {

local MSC_FUNC=$1

	cd ${GADGET_ROOT_DIR}/functions

	ln -s ${MSC_FUNC} ../configs/c.1
}


##
# begin of destroy usb msc gadget function
#
# params:
# @p1: msc function name
##
msc_func_destroy_begin() {

local MSC_FUNC=$1

	cd ${GADGET_ROOT_DIR}/functions

	rm ../configs/c.1/${MSC_FUNC}
	error_info "begin destroy ${MSC_FUNC}"

	cd ${MSC_FUNC}
}

##
# done of destroy usb msc gadget function
#
# params:
# @p1: msc function name
##
msc_func_destroy_done() {

local MSC_FUNC=$1

	cd ${GADGET_ROOT_DIR}/functions

	rmdir ${MSC_FUNC}
	error_info "rm ${MSC_FUNC}"
}

##
# using ddr as storage medium
#
# params:
# @p1: /dev/loopx
# @size: x(MB)
##
ddr_img_file_create() {

local LOOP_DEV=$1
local SIZE=$2

	local image_file=image_$(basename ${LOOP_DEV})_${SIZE}M.img

	cd /tmp

	dd if=/dev/zero of=${image_file} bs=1MB count=${SIZE} > /dev/null 2>&1
	error_info "create ${image_file}"

	mkfs.vfat ${image_file} > /dev/null 2>&1
	error_info "mkfs.vfat ${image_file}"

	losetup ${LOOP_DEV} ${image_file} > /dev/null 2>&1
	error_info "losetup ${image_file}"

	cd - > /dev/null 2>&1
}

##
# destroy ddr storage medium
#
# params:
# @p1: /dev/loopx
##
ddr_img_files_destroy() {

local LOOP_DEV=$1

	local image_file_prefix=image_$(basename ${LOOP_DEV})_

	losetup -d ${LOOP_DEV}
	error_info "losetup -d ${LOOP_DEV}"

	if [ -f /tmp/${image_file_prefix}*.img ]; then
		rm /tmp/${image_file_prefix}*.img
	fi
}

msc_start() {
	msc_func_create_begin "mass_storage.0"

	if [ ${CFG_LUN0_FILE} == "/dev/loop0" ]; then
		ddr_img_file_create ${CFG_LUN0_FILE} 6
	fi

	msc_func_lun_create "lun.0" \
			    ${CFG_LUN0_FILE} \
			    ${CFG_LUN0_FILE_MOUNT_DIR}

	msc_func_create_done "mass_storage.0"
}

msc_stop() {
	msc_func_destroy_begin "mass_storage.0"

	msc_func_lun_destroy "lun.0" ${CFG_LUN0_FILE_MOUNT_DIR}

	if [ ${CFG_LUN0_FILE} == "/dev/loop0" ]; then
		ddr_img_files_destroy ${CFG_LUN0_FILE}
	fi

	msc_func_destroy_done "mass_storage.0"
}

case "$1" in
	--list)
		echo "		msc"
		;;

	--start)
		msc_start
		;;

	--stop)
		msc_stop
		;;

	*)
		echo "[msc] invalid option, will exit..."
		exit 1
		;;
esac
