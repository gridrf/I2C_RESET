#include "watchdog.h"


void watchdog_reset(uint32_t timeout) {
    WWDT_MOD = WWDT_MOD_WDEN | WWDT_MOD_WDRESET;
    timeout &= 0xFFFFFF;
    WWDT_TC = timeout;
    WWDT_FEED_SEQUENCE;
}

void watchdog_feed(uint32_t timeout)
{
    WWDT_TC = timeout & 0xFFFFFF;
    WWDT_FEED_SEQUENCE;
}
