/*
 * MaxLinear MxL608 tuner driver wrapper for aml_dvb_extern module
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
#include "mxl608.h"

struct dvb_frontend *aml_mxl608_attach(struct dvb_frontend *fe,
				       const struct tuner_config *cfg)
{
	struct mxl608_config mxl608cfg = {
		.xtal_freq_hz = cfg->xtal,
		.if_freq_hz = cfg->if_hz,
		.agc_type = cfg->if_agc,
		.i2c_address = cfg->i2c_addr,
		.xtal_cap = cfg->xtal_cap,
		.gain_level = cfg->if_amp,
		.if_out_gain_level = 11,
		.agc_set_point = 66,
		.agc_invert_pol = 0,
		.invert_if = cfg->if_invert,
		.loop_thru_enable = cfg->lt_out,
		.clk_out_enable = 1,
		.clk_out_div = 0,
		.clk_out_ext = 0,
		.xtal_sharing_mode = cfg->xtal_mode,
		.single_supply_3_3V = cfg->dual_power ? 0 : 1, /* dual_power: 0: 3.3v, 1: 1.8v and 3.3v. */
	};
	return mxl608_attach(fe, &mxl608cfg, cfg->i2c_adap);
}

EXPORT_SYMBOL(aml_mxl608_attach);

MODULE_DESCRIPTION("MaxLinear MxL608 tuner driver wrapper for aml_dvb_extern module");
MODULE_AUTHOR("Marek Czerski <ma.czerski@mail.com>");
MODULE_LICENSE("GPL");
