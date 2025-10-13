#ifndef _TBS5530_H_
#define _TBS5530_H_

#define DVB_USB_LOG_PREFIX "tbs5530"
#include "dvb-usb.h"

/* --- Kernel 4.9 compatibility shim ---
 * Fallbacks and aliases to compile this driver with Linux 4.9.
 */
#ifndef request_firmware_direct
#define request_firmware_direct request_firmware
#endif


/* Add additional missing API mappings here if the compiler complains. */
/* --- End compatibility shim --- */


#define deb_xfer(args...) dprintk(dvb_usb_tbs5530_debug, 0x02, args)
#endif
