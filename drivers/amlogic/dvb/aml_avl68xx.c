/*
 * Availink avl6862 demod driver wrapper for aml_dvb_extern module
 *
 * Copyright (C) 2025 Marek Czerski <ma.czerski@gmail.com>
 *
 *    This program is free software; you can redistribute it and/or modify
 *    it under the terms of the GNU General Public License as published by
 *    the Free Software Foundation; either version 2 of the License, or
 *    (at your option) any later version.
 *
 *    This program is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *    GNU General Public License for more details.
 *
 *    You should have received a copy of the GNU General Public License along
 *    with this program; if not, write to the Free Software Foundation, Inc.,
 *    51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#include <linux/amlogic/aml_demod_common.h>
#include <linux/amlogic/aml_tuner.h>
#include "avl6862.h"

struct dvb_frontend *aml_avl68xx_attach(const struct demod_config *cfg)
{
	struct avl6862_config avl68xxcfg = {
		.demod_address = cfg->i2c_addr,
		.tuner_address = 0,
		.ts_serial = cfg->ts_out_mode ? 0 : 1, /* ts_out_mode: serial or parallel; 0: serial, 1: parallel. */
		.gpio_lock_led = 0,
	};

	return avl6862_attach(&avl68xxcfg, cfg->i2c_adap);
}

EXPORT_SYMBOL_GPL(aml_avl68xx_attach);

MODULE_DESCRIPTION("Availink avl68xx DVB demodulator driver wrapper for aml_dvb_extern module");
MODULE_AUTHOR("Marek Czerski (ma.czerski@gmail.com)");
MODULE_LICENSE("GPL");
