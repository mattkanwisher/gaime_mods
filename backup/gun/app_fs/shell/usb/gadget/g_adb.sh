adb_func_create() {
	# step 1
	cd ${GADGET_ROOT_DIR}/functions

	# setp 2
	mkdir ffs.adb
	error_info "create ffs.adb func"

	# setp 3
	ln -s ffs.adb ../configs/c.1

	# setp 4
	mkdir -p /dev/usb-ffs/adb
	mount -o uid=2000,gid=2000 -t functionfs adb /dev/usb-ffs/adb
	error_info "mount adb functionfs"

	# setp 5
	cd /
	adbd &
	error_info "run adbd"
	cd - >/dev/null 2>&1

	sleep 1
}

adb_func_destroy() {
	# setp 1
	rm ../configs/c.1/ffs.adb

	# setp 2
	rmdir ffs.adb
	error_info "rm ffs.adb func"

	# setp 3
	pkill adbd
	sleep 1

	# setp 4
	umount /dev/usb-ffs/adb
	rmdir /dev/usb-ffs/adb
	rmdir /dev/usb-ffs
}

adb_start() {
	adb_func_create
}

adb_stop() {
	adb_func_destroy
}

case "$1" in
	--list)
		echo "		adb"
		;;

	--start)
		adb_start
		;;

	--stop)
		adb_stop
		;;

	*)
		echo "[adb] invalid option, will exit..."
		exit 1
		;;
esac
