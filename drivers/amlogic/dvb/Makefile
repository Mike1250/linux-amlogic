obj-$(CONFIG_AMLOGIC_AUCPU) += aucpu/
obj-$(CONFIG_AMLOGIC_DVB_DMX) += demux/
obj-$(CONFIG_AMLOGIC_DVB_EXTERN) += aml_dvb_extern.o
obj-$(CONFIG_AMLOGIC_FE_EXTERN) += aml_fe_extern.o

aml_dvb_extern-objs = \
		aml_demod_common.o \
		aml_tuner.o \
		aml_atvdemod.o \
		aml_dtvdemod.o \
		aml_tuner_ops.o \
		aml_demod_ops.o \
		aml_dvb_extern_driver.o

aml_fe_extern-objs = \
		aml_avl68xx.o \
		aml_mxl608.o \
		avl6862.o \
		mxl608.o \
		aml_m88rs6060.o \
		m88rs6060.o

ccflags-y += -I.
ccflags-y += -I$(srctree)/drivers/media/dvb-core
ccflags-y += -I$(srctree)/drivers/media/tuners
ccflags-y += -I$(srctree)/include/media
