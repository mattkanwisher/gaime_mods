# Modified g_msc.sh — expose the raw NAND read-only over USB mass storage,
# and (crucially) restore the composite IAD device descriptor.
#
# The stock usb_gadget.sh only sets bDeviceClass=0xEF/0x02/0x01 inside its UVC
# branch, so dropping UVC leaves bDeviceClass=0x00 and a modern host cannot
# resolve the multi-interface (HID x3 + MSC) device — it stalls at "addressed".
# We set the IAD descriptor here, which runs before the UDC is bound.
#
# The LUN points straight at /dev/nandblk read-only; no mount (the stock mount
# step + error_info exit-on-fail would abort the whole gadget for a raw device).

G=${GADGET_ROOT_DIR}
CFG_LUN0_FILE="/dev/nandblk"

msc_start() {
	# composite IAD descriptor (normally set by the UVC branch)
	echo 0xEF > ${G}/bDeviceClass
	echo 0x02 > ${G}/bDeviceSubClass
	echo 0x01 > ${G}/bDeviceProtocol

	mkdir ${G}/functions/mass_storage.0
	error_info "create msc func"
	echo 1                 > ${G}/functions/mass_storage.0/lun.0/ro
	echo 1                 > ${G}/functions/mass_storage.0/lun.0/removable
	echo ${CFG_LUN0_FILE}  > ${G}/functions/mass_storage.0/lun.0/file
	error_info "set msc lun.0 file"
	ln -s ${G}/functions/mass_storage.0 ${G}/configs/c.1
}

msc_stop() {
	rm ${G}/configs/c.1/mass_storage.0
	rmdir ${G}/functions/mass_storage.0
}

case "$1" in
	--list)  echo "		msc" ;;
	--start) msc_start ;;
	--stop)  msc_stop ;;
	*) echo "[msc] invalid option, will exit..."; exit 1 ;;
esac
