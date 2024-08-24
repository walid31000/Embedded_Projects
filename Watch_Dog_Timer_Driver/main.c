/*
Test watchdog timer driver

 * main.c
 *watchdog timer application
 *  Created on: 24 Aug 2024
 *      Author: WALID
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include <util/delay.h>
#include "Err_Type.h"
#include "PORT_interface.h"
#include "DIO_interface.h"
#include "WDT_interface.h"

#include "WDT_reg.h"

void main(void)
{
	PORT_voidIint();//intialize PINA0 as output

	DIO_u8SetPinValue(DIO_PORTA,DIO_PIN0,DIO_PIN_HIGH);
	_delay_ms(1000);
	DIO_u8SetPinValue(DIO_PORTA,DIO_PIN0,DIO_PIN_LOW);

	/*Set 1 sec sleep time in WDT*/
	 WDT_SetTime(One_sec);
	 /*Resets the Watchdog Timer:
	  *  When you execute the WDR instruction,
	  *  it resets the Watchdog Timer counter back to its initial value.
	  *   This prevents the microcontroller from resetting if the timer reaches 0.
	  *    Essentially, it gives you more time before the Watchdog Timer causes a system reset.*/
	 WDT_Reset();

	 /*disable WDT*/
	 //WDT_Stop();






	while(1)
	{



	}
}
