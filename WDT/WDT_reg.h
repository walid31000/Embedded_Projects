#ifndef WDT_REG_H
#define WDT_REG_H


#define WDTCR               *((volatile uint8*)0X41)  // watchdog timer control register

#define WDTCR_WDTOE               4U   //watchdog rurn off enable
#define WDTCR_WDE                 3U   //watchdog enable


/*Watchdog timer prescaler*/
#define WDP2                 2U
#define WDP1                 1U
#define WDP0                 0U







#endif
