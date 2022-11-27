// SPDX-License-Identifier: GPL-2.0-or-later

#include <common.h>
#include <linux/sizes.h>
#include <asm/barebox-arm.h>
#include <asm/barebox-arm-head.h>
#include <mach/lowlevel.h>

#define kw_entry_(model)					\
	ENTRY_FUNCTION(start_dlink_##model, r0, r1, r2)		\
	{							\
		extern char __dtb_kirkwood_##model##_start[];	\
		void *fdt;					\
								\
		arm_cpu_lowlevel_init();			\
								\
		fdt = __dtb_kirkwood_##model##_start		\
			+ get_runtime_offset();			\
								\
		kirkwood_barebox_entry(fdt);			\
	}
kw_entry_(dns325);
kw_entry_(dns320);
