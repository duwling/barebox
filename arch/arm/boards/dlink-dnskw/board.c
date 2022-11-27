// SPDX-License-Identifier: GPL-2.0-or-later

#include <common.h>
#include <init.h>
#include <mach/bbu.h>
#include <envfs.h>

static int dnskw_devices_init(void)
{
	if (!of_machine_is_compatible("dlink,dns-325") &&
	    !of_machine_is_compatible("dlink,dns-320") &&
	    !of_machine_is_compatible("dlink,dns-320l") &&
	    !of_machine_is_compatible("dlink,dns-320-b"))
		return 0;

	mvebu_bbu_flash_register_handler("flash", "/dev/orion_nand0", 0, true);

	defaultenv_append_directory(defaultenv_dnskw);

	return 0;
}
device_initcall(dnskw_devices_init);
