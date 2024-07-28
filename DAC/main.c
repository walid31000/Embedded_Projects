/*
 * main.c
 *
 *  Created on: 29 Jun 2024
 *      Author: walid
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "Err_Type.h"
#include "util/delay.h"
#include "DIO_interface.h"
#include "PORT_interface.h"
#include "DAC_interface.h"
#include "DAC_CFG.h"

void main (void)
{
	sint16 Local_s16Volt=0;
	PORT_voidIint();
	while(1)
	{


		while(Local_s16Volt<=5000)
		{
			DIO_u8SetPortValue(DAC_u8PORT,DAC_voidSetAnalogVolt(Local_s16Volt ));
			_delay_ms(100);
			Local_s16Volt+=200;
		}
		_delay_ms(1000);
		Local_s16Volt=5000;
		while(Local_s16Volt>=0)
		{
			DIO_u8SetPortValue(DAC_u8PORT,DAC_voidSetAnalogVolt(Local_s16Volt ));
			_delay_ms(100);
			Local_s16Volt-=200;
		}
		_delay_ms(1000);

	}



}
