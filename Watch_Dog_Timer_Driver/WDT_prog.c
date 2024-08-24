/*
 * WDT_prog.c
 *
 *  Created on: 24 Aug 2024
 *      Author: walid
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "Err_Type.h"

#include "WDT_interface.h"


#include "WDT_reg.h"
#include "WDT_prv.h"


uint8 WDT_SetTime(WDT_Time_t copy_u8Time)
{
	uint8 Local_u8ErrorState=OK;
	WDTCR &=WDT_Time_Mask;

	WDTCR |=copy_u8Time;
	/*Enable WDT*/

	SET_BIT(WDTCR,WDTCR_WDE);

	return Local_u8ErrorState;

}


/*function to disable watchdog timer*/

uint8 WDT_Stop(void)
{
	uint8 Local_u8ErrorState=OK;
	/*Disable WDT*/
	WDTCR=(1<<WDTCR_WDTOE)|(1<<WDTCR_WDE);//disable sequence 1:put 1 in WDTOE and WDE
	/*Turn off watchdog*/
	WDTCR=0X00;// in the next 4 clock cycles put 0 in WDE

	return Local_u8ErrorState;

}


/*function to reset WDT*/


void WDT_Reset(void)
{

	/*	Rest WDT*/

	__asm volatile ("WDR");//assembly instruction

}
