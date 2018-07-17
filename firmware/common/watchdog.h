#ifndef __WATCHDOG

#include <libopencm3/cm3/common.h>
#include <libopencm3/lpc43xx/memorymap.h>

/* Watchdog mode register */
#define WWDT_MOD                        MMIO32(WWDT_BASE + 0x000)
#define WWDT_MOD_WDEN      (1<<0)
#define WWDT_MOD_WDRESET   (1<<1)
#define WWDT_MOD_WDTOF     (1<<2)
#define WWDT_MOD_WDINT     (1<<3)
#define WWDT_MOD_WDPROTECT (1<<4)

/* Watchdog timer constant register */
#define WWDT_TC                         MMIO32(WWDT_BASE + 0x004)

/* Watchdog feed sequence register */
#define WWDT_FEED                       MMIO32(WWDT_BASE + 0x008)
#define WWDT_FEED_SEQUENCE WWDT_FEED = 0xAA; WWDT_FEED = 0x55

/* Watchdog timer value register */
#define WWDT_TV                         MMIO32(WWDT_BASE + 0x00C)

/* Watchdog warning interrupt register */
#define WWDT_WARNINT                    MMIO32(WWDT_BASE + 0x014)

/* Watchdog timer window register */
#define WWDT_WINDOW                     MMIO32(WWDT_BASE + 0x018)

/* Reset LPC4330 in timeout*4 clock cycles (min 256, max 2^24) */
void watchdog_reset(uint32_t timeout);
void watchdog_feed();

#endif



