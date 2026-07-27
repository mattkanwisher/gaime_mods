rndis_func_create() {
	# step 1
	cd ${GADGET_ROOT_DIR}/functions

	# setp 2
	mkdir rndis.0
	error_info "create rndis func"

	# setp 3
	ln -s rndis.0 ../configs/c.1
}

rndis_func_destroy() {
	# setp 1
	rm ../configs/c.1/rndis.0

	# setp 2
	rmdir rndis.0
	error_info "rm rndis func"
}

rndis_start() {
	rndis_func_create
}

rndis_stop() {
	rndis_func_destroy
}

case "$1" in
	--list)
		echo "		rndis"
		;;

	--start)
		rndis_start
		;;

	--stop)
		rndis_stop
		;;

	*)
		echo "[rndis] invalid option, will exit..."
		exit 1
		;;
esac
