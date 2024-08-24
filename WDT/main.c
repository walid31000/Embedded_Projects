/*

 * main.c
 *watchdog timer application
 *  Created on: 24 Aug 2024
 *      Author: Oxygen
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include <util/delay.h>
#include "Err_Type.h"
#include "PORT_interface.h"
#include "DIO_interface.h"


#include "WDT_reg.h"

void main(void)
{
	PORT_voidIint();//intialize PINA0 as output

	DIO_u8SetPinValue(DIO_PORTA,DIO_PIN0,DIO_PIN_HIGH);
	_delay_ms(1000);
	DIO_u8SetPinValue(DIO_PORTA,DIO_PIN0,DIO_PIN_LOW);
	/*Set 1 sec sleep time in WDT*/
	SET_BIT(WDTCR,WDP2);
	SET_BIT(WDTCR,WDP1);
	CLR_BIT(WDTCR,WDP0);

/*Enable WDT*/
	SET_BIT(WDTCR,WDTCR_WDE);
/*Disable WDT*/
	WDTCR=(1<<WDTCR_WDTOE)|(1<<WDTCR_WDE);//disable sequence 1:put 1 in WDTOE and WDE
/*Turn off watchdog*/
	WDTCR=0X00;// in the next 4 clock cycles put 0 in WDE



	while(1)
	{



	}
}
