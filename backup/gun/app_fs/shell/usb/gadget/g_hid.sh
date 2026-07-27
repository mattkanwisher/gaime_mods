CFG_USB_HID_MOUSE_ENABLE=0
CFG_USB_HID_KEYBOARD_ENABLE=1
CFG_USB_HID_MULTMEDIA_ENABLE=0
CFG_USB_HID_TOUCH_SCREEN_ENABLE=1
CFG_USB_HID_UPDATE_ENABLE=1

if [ ${CFG_USB_HID_MOUSE_ENABLE} = 1 ]; then
:<<eof
0x05, 0x01,        /* Usage Page (Generic Desktop)                                    */
0x09, 0x02,        /* Usage (Mouse)                                                   */
0xa1, 0x01,        /* Collection (Application)                                        */
0x09, 0x01,        /*   Usage (Pointer)                                               */
0xa1, 0x00,        /*   Collection (Physical)                                         */
0x05, 0x09,        /*     Usage Page (Buttons)                                        */
0x19, 0x01,        /*     Usage Minimum (01)                                          */
0x29, 0x08,        /*     Usage Maximun (08)                                          */
0x15, 0x00,        /*     Logical Minimum (0)                                         */
0x25, 0x01,        /*     Logical Maximum (1)                                         */
0x75, 0x01,        /*     Report Size (1)                                             */
0x95, 0x08,        /*     Report Count (8)                                            */
0x81, 0x02,        /*     Input (Data, Variable, Absolute)                            */
0x05, 0x01,        /*     Usage Page (Generic Desktop)                                */
0x09, 0x30,        /*     Usage (X)                                                   */
0x09, 0x31,        /*     Usage (Y)                                                   */
0x16, 0x01, 0x00,  /*     Logical Minimum (-32767)                                         */
0x26, 0xFF, 0x7F,  /*     Logical Maximum (32767)                                     */
0x75, 0x10,        /*     Report Size (16)                                             */
0x95, 0x02,        /*     Report Count (2)                                            */
0x81, 0x06,        /*     Input (Data, Variable, Relative)                            */
0xc0,              /*   End Collection                                                */
0xc0,              /* End Collection                                                  */
eof

REPORT_DESC_TEMP_MOUSE="
	\\x05\\x01
	\\x09\\x02
	\\xa1\\x01
	\\x09\\x01
	\\xa1\\x00
	\\x05\\x09
	\\x19\\x01
	\\x29\\x08
	\\x15\\x00
	\\x25\\x01
	\\x75\\x01
	\\x95\\x08
	\\x81\\x02
	\\x05\\x01
	\\x09\\x30
	\\x09\\x31
	\\x16\\x01\\x00
	\\x26\\xff\\x7f
	\\x75\\x10
	\\x95\\x02
	\\x81\\x06
	\\xc0
	\\xc0
"

REPORT_LENGTH_MOUSE=5
fi

if [ ${CFG_USB_HID_TOUCH_SCREEN_ENABLE} = 1 ]; then
:<<eof
0x05, 0x0d,                    /* Usage Page (Digitizer)                                   */
0x09, 0x04,                    /* Usage (Touch Screen)                                     */
0xa1, 0x01,                    /* Collection (Application)                                */
0x85, 0x01,                    /*   Report ID                                             */
0x09, 0x20,                    /*   Usage (Stylus)                                       */
0xA1, 0x00,                    /*   Collection (Physical)                                 */
0x09, 0x42,                    /*     Usage (Tip Switch)                                  */
0x09, 0x32,                    /*     Usage (In Range)                                   */
0x15, 0x00,                    /*     Logical Minimum (0)                                 */
0x25, 0x01,                    /*     Logical Maximum (1)                                 */
0x75, 0x01,                    /*     Report Size (1)                                    */
0x95, 0x02,                    /*     Report Count (2)                                   */
0x81, 0x02,                    /*     Input (Data, Variable, Absolute)                   */
0x75, 0x01,                    /*     Report Size (1)                                    */
0x95, 0x06,                    /*     Report Count (6)                                   */
0x81, 0x01,                    /*     Input (Constant, Array, Absolute)                  */
0x05, 0x01,                    /*     Usage Page (Generic Desktop)                        */
0x09, 0x01,                    /*     Usage (Pointer)                                     */
0xA1, 0x00,                    /*     Collection (Physical)                               */
0x09, 0x30,                    /*        Usage (X)                                       */
0x09, 0x31,                    /*        Usage (Y)                                       */
0x16, 0x00, 0x00,              /*        Logical Minimum (0)                              */
0x26, 0x10, 0x27,              /*        Logical Maximum (10000)                          */
0x36, 0x00, 0x00,              /*        Physical Minimum (0)                             */
0x46, 0x10, 0x27,              /*        Physical Maximum (10000)                         */
0x66, 0x00, 0x00,              /*        Unit (None)                                     */
0x75, 0x10,                    /*        Report Size (16)                                 */
0x95, 0x02,                    /*        Report Count (2)                                 */
0x81, 0x02,                    /*        Input (Data, Variable, Absolute)                */
0xc0,                          /*     End Collection                                      */
0xc0,                          /*   End Collection                                        */
0xc0                           /* End Collection                                          */
eof

REPORT_DESC_TEMP_TOUCH_SCREEN="
	\\x05\\x0d
	\\x09\\x04
	\\xa1\\x01
	\\x85\\x01
	\\x09\\x20
	\\xa1\\x00
	\\x09\\x42
	\\x09\\x32
	\\x15\\x00
	\\x25\\x01
	\\x75\\x01
	\\x95\\x02
	\\x81\\x02
	\\x75\\x01
	\\x95\\x06
	\\x81\\x01
	\\x05\\x01
	\\x09\\x01
	\\xa1\\x00
	\\x09\\x30
	\\x09\\x31
	\\x16\\x00\\x00
	\\x26\\x10\\x27
	\\x36\\x00\\x00
	\\x46\\x10\\x27
	\\x66\\x00\\x00
	\\x75\\x10
	\\x95\\x02
	\\x81\\x02
	\\xc0
	\\xc0
	\\xc0
"

REPORT_LENGTH_TOUCH_SCREEN=6
fi



if [ ${CFG_USB_HID_KEYBOARD_ENABLE} = 1 ]; then
:<<eof
0x05, 0x01,	/* USAGE_PAGE (Generic Desktop)	          */
0x09, 0x06,	/* USAGE (Keyboard)                       */
0xa1, 0x01,	/* COLLECTION (Application)               */
0x05, 0x07,	/*   USAGE_PAGE (Keyboard)                */
0x19, 0xe0,	/*   USAGE_MINIMUM (Keyboard LeftControl) */
0x29, 0xe7,	/*   USAGE_MAXIMUM (Keyboard Right GUI)   */
0x15, 0x00,	/*   LOGICAL_MINIMUM (0)                  */
0x25, 0x01,	/*   LOGICAL_MAXIMUM (1)                  */
0x75, 0x01,	/*   REPORT_SIZE (1)                      */
0x95, 0x08,	/*   REPORT_COUNT (8)                     */
0x81, 0x02,	/*   INPUT (Data,Var,Abs)                 */
0x95, 0x01,	/*   REPORT_COUNT (1)                     */
0x75, 0x08,	/*   REPORT_SIZE (8)                      */
0x81, 0x03,	/*   INPUT (Cnst,Var,Abs)                 */
0x95, 0x05,	/*   REPORT_COUNT (5)                     */
0x75, 0x01,	/*   REPORT_SIZE (1)                      */
0x05, 0x08,	/*   USAGE_PAGE (LEDs)                    */
0x19, 0x01,	/*   USAGE_MINIMUM (Num Lock)             */
0x29, 0x05,	/*   USAGE_MAXIMUM (Kana)                 */
0x91, 0x02,	/*   OUTPUT (Data,Var,Abs)                */
0x95, 0x01,	/*   REPORT_COUNT (1)                     */
0x75, 0x03,	/*   REPORT_SIZE (3)                      */
0x91, 0x03,	/*   OUTPUT (Cnst,Var,Abs)                */
0x95, 0x06,	/*   REPORT_COUNT (6)                     */
0x75, 0x08,	/*   REPORT_SIZE (8)                      */
0x15, 0x00,	/*   LOGICAL_MINIMUM (0)                  */
0x25, 0x65,	/*   LOGICAL_MAXIMUM (101)                */
0x05, 0x07,	/*   USAGE_PAGE (Keyboard)                */
0x19, 0x00,	/*   USAGE_MINIMUM (Reserved)             */
0x29, 0x65,	/*   USAGE_MAXIMUM (Keyboard Application) */
0x81, 0x00,	/*   INPUT (Data,Ary,Abs)                 */
0xc0		/* END_COLLECTION                         */
eof

REPORT_DESC_TEMP_KEYBOARD="
	\\x05\\x01
	\\x09\\x06
	\\xa1\\x01
	\\x05\\x07
	\\x19\\xe0
	\\x29\\xe7
	\\x15\\x00
	\\x25\\x01
	\\x75\\x01
	\\x95\\x08
	\\x81\\x02
	\\x95\\x01
	\\x75\\x08
	\\x81\\x03
	\\x95\\x05
	\\x75\\x01
	\\x05\\x08
	\\x19\\x01
	\\x29\\x05
	\\x91\\x02
	\\x95\\x01
	\\x75\\x03
	\\x91\\x03
	\\x95\\x06
	\\x75\\x08
	\\x15\\x00
	\\x25\\x65
	\\x05\\x07
	\\x19\\x00
	\\x29\\x65
	\\x81\\x00
	\\xc0
"
REPORT_LENGTH_KEYBOARD=8
fi

if [ ${CFG_USB_HID_MULTMEDIA_ENABLE} = 1 ]; then
:<<eof
0x05, 0x0c,	/* GLOBAL_USAGE_PAGE(Consumer)   */
0x09, 0x01,	/* LOCAL_USAGE(Consumer Control) */
0xa1, 0x01,	/* MAIN_COLLECTION(Applicatior)  */
0x09, 0xe9,	/* LOCAL_USAGE(Volume Increment) */
0x09, 0xea,	/* LOCAL_USAGE(Volume Decrement) */
0x09, 0xe2, 	/* LOCAL_USAGE(Mute)             */
0x15, 0x00,	/* GLOBAL_LOGICAL_MINIMUM(0)     */
0x25, 0x01,	/* GLOBAL_LOCAL_MAXIMUM(1)       */
0x95, 0x03,	/* GLOBAL_REPORT_COUNT(3)        */
0x75, 0x01,	/* GLOBAL_REPORT_SIZE(1)         */
0x81, 0x02,	/* MAIN_INPUT                    */
0x95, 0x05,	/* GLOBAL_REPORT_COUNT(5)        */
0x75, 0x01,	/* GLOBAL_REPORT_SIZE(1)         */
0x81, 0x03,	/* MAIN_INPUT                    */
0xc0		/* MAIN_COLLECTION_END           */
eof

REPORT_DESC_TEMP="
	\\x05\\x0c
	\\x09\\x01
	\\xa1\\x01
	\\x09\\xe9
	\\x09\\xea
	\\x09\\xe2
	\\x15\\x00
	\\x25\\x01
	\\x95\\x03
	\\x75\\x01
	\\x81\\x02
	\\x95\\x05
	\\x75\\x01
	\\x81\\x03
	\\xc0
 "
REPORT_LENGTH=1

fi

if [ ${CFG_USB_HID_UPDATE_ENABLE} = 1 ]; then
:<<eof
0x06, 0x00, 0xFF   # Usage Page (Vendor 0xFF00)
0x09, 0x01,       # Usage (Vendor Usage 1)
0xA1, 0x01,       # Collection (Application)

0x09, 0x01,       # Usage (Vendor Usage 1)
0x15, 0x00,       #   Logical Minimum (0)
0x26, 0xFF, 0x00   #   Logical Maximum (255)
0x75, 0x08,       #   Report Size (8 bits)
0x95, 0x40,       #   Report Count (64 bytes)
0x81, 0x02,       #   Input (Data,Var,Abs)

0x09, 0x01,       # Usage (Vendor Usage 1)
0x15, 0x00,       #   Logical Minimum (0)
0x26, 0xFF, 0x00   #   Logical Maximum (255)
0x75, 0x08,       #   Report Size (8 bits)
0x95, 0x40,       #   Report Count (64 bytes)
0x91, 0x02,       #   Output (Data,Var,Abs)
0xC0,             # End Collection
eof

REPORT_DESC_TEMP_UPDATE="
	\\x06\\x00\\xFF
	\\x09\\x01
	\\xA1\\x01
	\\x09\\x01
	\\x15\\x00
	\\x26\\xFF\\x00
	\\x75\\x08
	\\x95\\x40
	\\x81\\x02
	\\x09\\x01
	\\x15\\x00
	\\x26\\xFF\\x00
	\\x75\\x08
	\\x95\\x40
	\\x91\\x02
	\\xC0
"

REPORT_LENGTH_UPDATE=64
fi

hid_func_create_mouse() {
	# step 1
	cd ${GADGET_ROOT_DIR}/functions

	# setp 2
	mkdir hid.0
	error_info "create hid func"

	cd hid.0
	echo 0 > protocol
	echo 0 > subclass
	echo ${REPORT_LENGTH_MOUSE} > report_length

	REPORT_DESC=`echo ${REPORT_DESC_TEMP_MOUSE} | sed s/[[:space:]]//g`

	echo -ne ${REPORT_DESC} > report_desc

	cd ..
	# setp 3
	ln -s hid.0 ../configs/c.1
}



hid1_func_create_keyboard() {
	# step 1
	cd ${GADGET_ROOT_DIR}/functions

	# setp 2
	mkdir hid.1
	error_info "create hid 1 func"

	cd hid.1
	echo 0 > protocol
	echo 0 > subclass
	echo ${REPORT_LENGTH_KEYBOARD} > report_length

	REPORT_DESC=`echo ${REPORT_DESC_TEMP_KEYBOARD} | sed s/[[:space:]]//g`

	echo -ne ${REPORT_DESC} > report_desc

	cd ..
	# setp 3
	ln -s hid.1 ../configs/c.1
}

hid2_func_create_touch_screen() {
	# step 1
	cd ${GADGET_ROOT_DIR}/functions

	# setp 2
	mkdir hid.2
	error_info "create hid 2 func"

	cd hid.2
	echo 0 > protocol
	echo 0 > subclass
	echo ${REPORT_LENGTH_TOUCH_SCREEN} > report_length

	REPORT_DESC=`echo ${REPORT_DESC_TEMP_TOUCH_SCREEN} | sed s/[[:space:]]//g`

	echo -ne ${REPORT_DESC} > report_desc

	cd ..
	# setp 3
	ln -s hid.2 ../configs/c.1
}

hid3_func_create_update() {
	# step 1
	cd ${GADGET_ROOT_DIR}/functions

	# setp 2
	mkdir hid.3
	error_info "create hid 3 func"

	cd hid.3
	echo 0 > protocol
	echo 0 > subclass
	echo ${REPORT_LENGTH_UPDATE} > report_length

	REPORT_DESC=`echo ${REPORT_DESC_TEMP_UPDATE} | sed s/[[:space:]]//g`

	echo -ne ${REPORT_DESC} > report_desc

	cd ..
	# setp 3
	ln -s hid.3 ../configs/c.1
}

hid_func_destroy() {
	# setp 1
	rm ../configs/c.1/hid.0

	# setp 2
	rmdir hid.0
	error_info "rm hid 0 func"
}

hid1_func_destroy() {
	# setp 1
	rm ../configs/c.1/hid.1

	# setp 2
	rmdir hid.1
	error_info "rm hid 1 func"
}

hid2_func_destroy() {
	# setp 1
	rm ../configs/c.1/hid.2

	# setp 2
	rmdir hid.2
	error_info "rm hid 2 func"
}

hid3_func_destroy() {
	# setp 1
	rm ../configs/c.1/hid.3

	# setp 2
	rmdir hid.3
	error_info "rm hid 3 func"
}

hid_start() {
	[ "$CFG_USB_HID_MOUSE_ENABLE" -eq 1 ] && hid_func_create_mouse
    [ "$CFG_USB_HID_KEYBOARD_ENABLE" -eq 1 ] && hid1_func_create_keyboard
    [ "$CFG_USB_HID_TOUCH_SCREEN_ENABLE" -eq 1 ] && hid2_func_create_touch_screen
    [ "$CFG_USB_HID_UPDATE_ENABLE" -eq 1 ] && hid3_func_create_update
}

hid_stop() {
	[ "$CFG_USB_HID_MOUSE_ENABLE" -eq 1 ] && hid_func_destroy
    [ "$CFG_USB_HID_KEYBOARD_ENABLE" -eq 1 ] && hid1_func_destroy
    [ "$CFG_USB_HID_TOUCH_SCREEN_ENABLE" -eq 1 ] && hid2_func_destroy
    [ "$CFG_USB_HID_UPDATE_ENABLE" -eq 1 ] && hid3_func_destroy
}

case "$1" in
	--list)
		echo "		hid"
		;;

	--start)
		hid_start
		;;

	--stop)
		hid_stop
		;;

	*)
		echo "[hid] invalid option, will exit..."
		exit 1
		;;
esac
