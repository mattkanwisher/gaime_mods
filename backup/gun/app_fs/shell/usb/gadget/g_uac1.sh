CFG_UAC1_CAPTURE_CHANNEL=1		# bitmap. 0:disable, 1:1ch, 3:2ch
CFG_UAC1_CAPTURE_VOLUME_ENABLE=1
CFG_UAC1_CAPTURE_VOLUME_MIN=-2560
CFG_UAC1_CAPTURE_VOLUME_MAX=0
CFG_UAC1_CAPTURE_VOLUME_RES=256
CFG_UAC1_CAPTURE_VOLUME_DEF=-1280
CFG_UAC1_CAPTURE_MUTE_ENABLE=1
CFG_UAC1_CAPTURE_SRATES="8000,16000,24000,32000,48000"
CFG_UAC1_CAPTURE_EP_NUM=2

CFG_UAC1_PLAYBACK_CHANNEL=0
CFG_UAC1_PLAYBACK_VOLUME_ENABLE=0
CFG_UAC1_PLAYBACK_VOLUME_MIN=-2560
CFG_UAC1_PLAYBACK_VOLUME_MAX=0
CFG_UAC1_PLAYBACK_VOLUME_RES=256
CFG_UAC1_PLAYBACK_VOLUME_DEF=-1280
CFG_UAC1_PLAYBACK_MUTE_ENABLE=0
CFG_UAC1_PLAYBACK_SRATES="8000"
CFG_UAC1_PLAYBACK_EP_NUM=0

CFG_UAC1_WAIT_APP_TO_RUN_ENABLE=1

uac1_func_create() {
	cd ${GADGET_ROOT_DIR}/functions

	mkdir lombo_uac1.0
	error_info "create uac1 func"

	cd lombo_uac1.0

	echo ${CFG_UAC1_WAIT_APP_TO_RUN_ENABLE} > wait_app_to_run

	echo ${CFG_UAC1_CAPTURE_CHANNEL} > c_chmask
	echo ${CFG_UAC1_CAPTURE_VOLUME_ENABLE} > c_volume_present
	echo ${CFG_UAC1_CAPTURE_VOLUME_MIN} > c_volume_min
	echo ${CFG_UAC1_CAPTURE_VOLUME_MAX} > c_volume_max
	echo ${CFG_UAC1_CAPTURE_VOLUME_RES} > c_volume_res
	echo ${CFG_UAC1_CAPTURE_VOLUME_DEF} > c_volume_def
	echo ${CFG_UAC1_CAPTURE_MUTE_ENABLE} > c_mute_present
	echo ${CFG_UAC1_CAPTURE_SRATES} > c_srate
	echo ${CFG_UAC1_CAPTURE_EP_NUM} > iso_ep_in_num

	echo ${CFG_UAC1_PLAYBACK_CHANNEL} > p_chmask
	echo ${CFG_UAC1_PLAYBACK_VOLUME_ENABLE} > p_volume_present
	echo ${CFG_UAC1_PLAYBACK_VOLUME_MIN} > p_volume_min
	echo ${CFG_UAC1_PLAYBACK_VOLUME_MAX} > p_volume_max
	echo ${CFG_UAC1_PLAYBACK_VOLUME_RES} > p_volume_res
	echo ${CFG_UAC1_PLAYBACK_VOLUME_DEF} > p_volume_def
	echo ${CFG_UAC1_PLAYBACK_MUTE_ENABLE} > p_mute_present
	echo ${CFG_UAC1_PLAYBACK_SRATES} > p_srate
	echo ${CFG_UAC1_PLAYBACK_EP_NUM} > iso_ep_out_num

	cd ..

	ln -s lombo_uac1.0 ../configs/c.1
}

uac1_func_destroy() {
	rm ../configs/c.1/lombo_uac1.0

	rmdir lombo_uac1.0
	error_info "rm lombo_uac1 func"
}

uac1_start() {
	uac1_func_create
}

uac1_stop() {
	uac1_func_destroy
}

case "$1" in
	--list)
		echo "		uac1"
		;;

	--start)
		uac1_start
		;;

	--stop)
		uac1_stop
		;;

	*)
		echo "[uac1] invalid option, will exit..."
		exit 1
		;;
esac
