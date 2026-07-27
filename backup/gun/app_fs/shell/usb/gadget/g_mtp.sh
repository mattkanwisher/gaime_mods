CFG_MTP_CONFIGURATION_FILE=/etc/usb/gadget/conf/umtprd.conf

mtp_func_create() {
	# step 1
	cd ${GADGET_ROOT_DIR}/functions

	# setp 2
	mkdir ffs.mtp
	error_info "create ffs.mtp func"

	# setp 3
	ln -s ffs.mtp ../configs/c.1

	# setp 4
	mkdir /dev/ffs-mtp
	mount -t functionfs mtp /dev/ffs-mtp

	# setp 5
	umtprd -conf ${CFG_MTP_CONFIGURATION_FILE} &
	sleep 1
}

mtp_func_destroy() {
	# setp 1
	rm ../configs/c.1/ffs.mtp

	# setp 2
	rmdir ffs.mtp
	error_info "rm ffs.mtp func"

	# setp 3
	pkill umtprd
	sleep 3

	# setp 4
	umount /dev/ffs-mtp
	rmdir /dev/ffs-mtp
}

mtp_start() {
	mtp_func_create
}

mtp_stop() {
	mtp_func_destroy
}

case "$1" in
	--list)
		echo "		mtp"
		;;

	--start)
		mtp_start
		;;

	--stop)
		mtp_stop
		;;

	*)
		echo "[mtp] invalid option, will exit..."
		exit 1
		;;
esac
