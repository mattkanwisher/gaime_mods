CFG_UVC0_BULK_MODE_ENABLE=0

BULK_MODE_MAX_PAYLOAD=$(expr 512 \* 32)

UVC_DIR=
UVC_FUNCTION=
UVC_STREAM_DIR=
UVC_FORMAT_DIR=

UVC_FRAME_1FPS_VAL=10000000

UVC_BANDWIDTH_4_096MBS=512
UVC_BANDWIDTH_8_912MBS=1024
UVC_BANDWIDTH_16_384MBS=2048
UVC_BANDWIDTH_24_576MBS=3072

#!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
#!!!!!!!!!!!!!!!!!!!!!!!!!!!!! uvc api start
#!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

################################################################################
# uvc create function api
################################################################################

uvc_create() {

UVC_FUNCTION=$1
local UVC_NAME=$2
local BULK_MODE=$3
local BULK_MODE_MAX_PAYLOAD=$4

	local wdir="iad/strings/0x0409"

	cd ${GADGET_ROOT_DIR}/functions

	mkdir ${UVC_FUNCTION}
	error_info "create ${UVC_FUNCTION}"

	cd ${UVC_FUNCTION}
	UVC_DIR=$(pwd)

	if [ ${BULK_MODE} -eq 1 ]; then
		echo 1 > bulk_mode
		echo ${BULK_MODE_MAX_PAYLOAD} > bulk_max_payload
	fi

	mkdir -p ${wdir}
	echo ${UVC_NAME} > ${wdir}/strings
	error_info "create ${UVC_NAME} strings"

	mkdir control/header/h
}

uvc_ct_create() {

local CT=$1
local CT_ID=$2
local CT_CONTROLS=$3
local CT_NAME=

	if [ $# -ge 4 ]; then
		CT_NAME=$4
	fi

	local wdir="control/ct/${CT}"

	mkdir ${wdir}
	error_info "create ct"

	echo ${CT_ID} > ${wdir}/bTerminalID
	error_info "set ct bTerminalID"

	echo ${CT_CONTROLS} > ${wdir}/bmControls
	error_info "set ct bmControls"

	if [ ! "${CT_NAME}" = "" ]; then
		mkdir ${wdir}/strings/0x0409
		echo ${CT_NAME} > ${wdir}/strings/0x0409/strings
	fi

	ln -s ${wdir} control/header/h
}

uvc_pu_create() {

local PU=$1
local PU_ID=$2
local PU_SOURCE_ID=$3
local PU_CONTROLS=$4
local PU_NAME=

	if [ $# -ge 5 ]; then
		PU_NAME=$5
	fi

	local wdir=control/pu/${PU}

	mkdir ${wdir}
	error_info "create pu"

	echo ${PU_ID} > ${wdir}/bUnitID
	error_info "set pu bUnitID"

	echo ${PU_SOURCE_ID} > ${wdir}/bSourceID
	error_info "set pu bSourceID"

	echo ${PU_CONTROLS} > ${wdir}/bmControls
	error_info "set pu bmControls"

	if [ ! "${PU_NAME}" = "" ]; then
		mkdir ${wdir}/strings/0x0409
		echo ${PU_NAME} > ${wdir}/strings/0x0409/strings
	fi

	ln -s ${wdir} control/header/h
}

uvc_ot_create() {

local OT=$1
local OT_ID=$2
local OT_SOURCE_ID=$3
local OT_NAME=

	if [ $# -ge 4 ]; then
		OT_NAME=$4
	fi

	local wdir=control/ot/${OT}

	mkdir ${wdir}
	error_info "create ot"

	echo ${OT_ID} > ${wdir}/bTerminalID
	error_info "set ot bTerminalID"

	echo ${OT_SOURCE_ID} > ${wdir}/bSourceID
	error_info "set ot bSourceID"

	if [ ! "${OT_NAME}" = "" ]; then
		mkdir ${wdir}/strings/0x0409
		echo ${OT_NAME} > ${wdir}/strings/0x0409/strings
	fi

	ln -s ${wdir} control/header/h
}

uvc_xu_create() {

local XU=$1
local XU_ID=$2
local XU_SOURCE_IDS=$3
local XU_CONTROLS=$4
local XU_GUID=$5
local XU_NAME=

	if [ $# -ge 6 ]; then
		XU_NAME=$6
	fi

	local wdir=control/xu/${XU}

	mkdir ${wdir}
	error_info "create xu"

	echo ${XU_ID} > ${wdir}/bUnitID
	error_info "set xu bUnitID"

	echo ${XU_SOURCE_IDS} > ${wdir}/baSourceID
	error_info "set xu baSourceID"

	echo ${XU_CONTROLS} > ${wdir}/bmControls
	error_info "set xu bmControls"

	echo ${XU_GUID} > ${wdir}/guidExtensionCode
	error_info "set xu guidExtensionCode"

	if [ ! "${XU_NAME}" = "" ]; then
		mkdir ${wdir}/strings/0x0409
		echo ${XU_NAME} > ${wdir}/strings/0x0409/strings
	fi

	ln -s ${wdir} control/header/h
}

uvc_control_link() {
	ln -s control/header/h control/class/fs
}

uvc_stream_create() {

local UVC_STREAM=$1
local UVC_STREAM_OT=$2

	cd ${UVC_DIR}/streaming

	mkdir ${UVC_STREAM} && cd ${UVC_STREAM} && mkdir header/h
	error_info "create ${UVC_STREAM}"

	echo ${UVC_STREAM_OT} > header/h/bTerminalLink

	UVC_STREAM_DIR=${UVC_DIR}/streaming/${UVC_STREAM}
}

frame_create() {

local WIDTH=$1
local HEIGHT=$2
local FPS_TAB=$3
local MAXPAYLOAD=$4

	local count=0
	local bpl=
	local min_fps=
	local max_fps=
	local fps_tab_val=

	for i in ${FPS_TAB}
	do
		if [ ${count} == 0 ]; then
			max_fps=${i}
		fi

		min_fps=${i}

		local tmp_fps_val=$(( ${UVC_FRAME_1FPS_VAL} / ${i} ))

		if [ "x${fps_tab_val}" == "x" ]; then
			fps_tab_val="${tmp_fps_val}"
		else
			fps_tab_val="${fps_tab_val} ${tmp_fps_val}"
		fi

		let count++
	done

	local min_fps_val=$(( ${UVC_FRAME_1FPS_VAL} / ${min_fps} ))
	local max_fps_val=$(( ${UVC_FRAME_1FPS_VAL} / ${max_fps} ))

	local MinBitRate=0
	local MaxBitRate=0
	local MaxVideoFrameBuf=0
	local DefFrameInterval=0

	local frame_dir=${WIDTH}x${HEIGHT}p
	local format_name=$(basename $(pwd))

	mkdir -p ${frame_dir}
	error_info "create ${frame_dir}"

	echo ${WIDTH} > ${frame_dir}/wWidth
	echo ${HEIGHT} > ${frame_dir}/wHeight
	echo ${MAXPAYLOAD} > ${frame_dir}/dwMaxPayloadTransferSize

	if [ ${format_name} = "YUYV" ]; then
		bpl=16
		MaxVideoFrameBuf=$(( ${WIDTH} * ${HEIGHT} * ${bpl} / 8 ))
		echo ${MaxVideoFrameBuf} > ${frame_dir}/dwMaxVideoFrameBufferSize_or_dwBytesPerLine
	elif [ ${format_name} = "NV12" -o ${format_name} = "MJPEG" ]; then
		bpl=12
		MaxVideoFrameBuf=$(( ${WIDTH} * ${HEIGHT} * ${bpl} / 8 ))
		echo ${MaxVideoFrameBuf} > ${frame_dir}/dwMaxVideoFrameBufferSize_or_dwBytesPerLine
	elif [ ${format_name} = "H264" -o ${format_name} = "H265" ]; then
		bpl=12
	fi

	MinBitRate=$(( ${WIDTH} * ${HEIGHT} * ${bpl} * ${min_fps} ))
	MaxBitRate=$(( ${WIDTH} * ${HEIGHT} * ${bpl} * ${max_fps} ))

	echo ${fps_tab_val} > ${frame_dir}/dwFrameInterval

	DefFrameInterval=${max_fps_val}
	echo ${DefFrameInterval} > ${frame_dir}/dwDefaultFrameInterval

	echo ${MinBitRate} > ${frame_dir}/dwMinBitRate
	echo ${MaxBitRate} > ${frame_dir}/dwMaxBitRate
}

format_default_frame_config() {

local DEFAULT_FRAME_INDEX=$1

	echo ${DEFAULT_FRAME_INDEX} > bDefaultFrameIndex
}

format_create() {

local FORMAT=$1

	local format_dir=
	local format_guid=
	local bit_per_pixel=

	cd ${UVC_STREAM_DIR}

	if [ ${FORMAT} = "YUYV" ]; then
		format_dir="uncompressed/${FORMAT}"
		format_guid="YUY2"
		bit_per_pixel=16
	elif [ ${FORMAT} = "NV12" ]; then
		format_dir="uncompressed/${FORMAT}"
		format_guid="NV12"
		bit_per_pixel=12
	elif [ ${FORMAT} = "MJPEG" ]; then
		format_dir="mjpeg/${FORMAT}"
	elif [ ${FORMAT} = "H264" ]; then
		format_dir="framebased/${FORMAT}"
		format_guid="H264"
	elif [ ${FORMAT} = "H265" ]; then
		format_dir="framebased/${FORMAT}"
		format_guid="H265"
	fi

	mkdir -p ${format_dir}
	error_info "create ${format_dir}"

	if [ ! "${format_guid}" = "" ]; then
		printf ${format_guid} > ${format_dir}/guidFormat
	fi

	if [ ! "${bit_per_pixel}" = "" ]; then
		echo ${bit_per_pixel} > ${format_dir}/bBitsPerPixel
	fi

	cd ${format_dir}

	FORMAT_DIR=$(pwd)
}

format_link() {
	cd ${UVC_STREAM_DIR}/header/h

	ln -s ${FORMAT_DIR} .
}

uvc_stream_link() {
	cd ${UVC_STREAM_DIR}/class

	ln -s ../header/h/ fs/ && ln -s ../header/h/ hs/
}

uvc_link() {
	cd ${GADGET_ROOT_DIR}/functions

	ln -s ${UVC_FUNCTION} ${GADGET_ROOT_DIR}/configs/c.1
}

################################################################################
# uvc destroy function api
################################################################################

uvc_unlink() {

local UVC_INSTANCE=$1

	rm ${GADGET_ROOT_DIR}/configs/c.1/${UVC_INSTANCE}
}

uvc_stream_destroy() {

local UVC_INSTANCE=$1
local UVC_STREAM=$2

	local wdir=${UVC_INSTANCE}/streaming/${UVC_STREAM}

	cd ${GADGET_ROOT_DIR}/functions

	cd ${wdir}
	error_info "cd ${wdir}"

	rm class/*/h

	if [ -d uncompressed -a -d uncompressed/YUYV ]; then
		rm header/h/YUYV
		rmdir uncompressed/YUYV/*/
		rmdir uncompressed/YUYV
		error_info "rm uncompressed/YUYV"
	fi

	if [ -d uncompressed -a -d uncompressed/NV12 ]; then
		rm header/h/NV12
		rmdir uncompressed/NV12/*/
		rmdir uncompressed/NV12
		error_info "rm uncompressed/NV12"
	fi

	if [ -d mjpeg -a -d mjpeg/MJPEG ]; then
		rm header/h/MJPEG
		rmdir mjpeg/MJPEG/*/
		rmdir mjpeg/MJPEG
		error_info "rm mjpeg/MJPEG"
	fi

	if [ -d framebased -a -d framebased/H264 ]; then
		rm header/h/H264
		rmdir framebased/H264/*/
		rmdir framebased/H264
		error_info "rm framebased/H264"
	fi

	if [ -d framebased -a -d framebased/H265 ]; then
		rm header/h/H265
		rmdir framebased/H265/*/
		rmdir framebased/H265
		error_info "rm framebased/H265"
	fi

	rmdir header/h

	cd ../
	rmdir ${UVC_STREAM}

	cd ../../
}

uvc_func_destroy() {

local UVC_INSTANCE=$1
local ENTITY=
local TEMP=

	cd ${GADGET_ROOT_DIR}/functions/${UVC_INSTANCE}

	if [ -d iad/strings/0x0409 ]; then
		rmdir iad/strings/0x0409/
		error_info "rm uvc iad strings"
	fi

	cd control

	rm class/*/h

	find header/h/ -type l | xargs rm
	rmdir header/h

	for TEMP in `ls ct`; do
		ENTITY=ct/${TEMP}
		if [ -d ${ENTITY}/strings/0x0409 ]; then
			rmdir ${ENTITY}/strings/0x0409
			rmdir ${ENTITY}
		else
			rmdir ${ENTITY}
		fi
	done
	error_info "rm ct"

	for TEMP in `ls pu`; do
		ENTITY=pu/${TEMP}
		if [ -d ${ENTITY}/strings/0x0409 ]; then
			rmdir ${ENTITY}/strings/0x0409
			rmdir ${ENTITY}
		else
			rmdir ${ENTITY}
		fi
	done
	error_info "rm pu"

	for TEMP in `ls xu`; do
		ENTITY=xu/${TEMP}
		if [ -d ${ENTITY}/strings/0x0409 ]; then
			rmdir ${ENTITY}/strings/0x0409
			rmdir ${ENTITY}
		else
			rmdir ${ENTITY}
		fi
	done
	error_info "rm xu"

	for TEMP in `ls ot`; do
		ENTITY=ot/${TEMP}
		if [ -d ${ENTITY}/strings/0x0409 ]; then
			rmdir ${ENTITY}/strings/0x0409
			rmdir ${ENTITY}
		else
			rmdir ${ENTITY}
		fi
	done
	error_info "rm ot"

	cd ../../
	rmdir ${UVC_INSTANCE}
	error_info "rm ${UVC_INSTANCE}"
}

#^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
#^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ uvc api start
#^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

uvc0_create() {

## create uvc
#		uvc_instance	uvc_name		is_bulk_mode				bulk_mode_max_payload
uvc_create	uvc.0		"Dashine UVC"	${CFG_UVC0_BULK_MODE_ENABLE}		${BULK_MODE_MAX_PAYLOAD}

## config uvc control
#		ct_instance	ct_id	bmControls		ct_name
uvc_ct_create 	ct0 		1	"0x00 0x00 0x00"

#		pu_instance	pu_id	pu_source_id	bmControls		pu_name
uvc_pu_create	pu0		2	1		"0x00 0x00 0x00"

#		xu_instance	xu_id	xu_source_ids	bmControls	guid											xu_name
uvc_xu_create	xu0		3 	2		"0x03"		"0x18 0x20 0x2E 0x30 0x11 0x63 0x2E 0x4A 0xBA 0x2C 0x68 0x90 0xEB 0x33 0x40 0x16" "lombo xu0"

uvc_xu_create	xu1		5 	2		"0x0F"		"0x3E 0x9C 0x51 0xF3 0x28 0x10 0xB1 0x4E 0xb8 0xbb 0xfc 0xa1 0xb1 0xa0 0x21 0x3b" "lombo xu1"
#		ot_instance	ot_id	ot_source_id	ot_name
uvc_ot_create 	ot0		4	3

## control link
uvc_control_link

## create uvc stream
uvc_stream_create "s0" 4

format_create YUYV
frame_create 320 240 "30 20 15" ${UVC_BANDWIDTH_8_912MBS}
frame_create 640 360 "30 20 15" ${UVC_BANDWIDTH_16_384MBS}
frame_create 1280 720 "10 5 2" ${UVC_BANDWIDTH_24_576MBS}
frame_create 1920 1080 "5 2" ${UVC_BANDWIDTH_24_576MBS}
format_default_frame_config 4
format_link

## stream link
uvc_stream_link

## uvc link
uvc_link
}

uvc0_destroy() {
uvc_unlink uvc.0
uvc_stream_destroy uvc.0 s0
uvc_func_destroy uvc.0
}

uvc_start() {
	uvc0_create
}

uvc_stop() {
	uvc0_destroy
}

case "$1" in
	--list)
		echo "		uvc"
	;;

	--start)
		uvc_start
	;;

	--stop)
		uvc_stop
	;;

	*)
		echo "[uvc] invalid option, will exit..."
		exit 1
	;;
esac
