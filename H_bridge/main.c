/*
 * main.c
 *test buzzer
 *  Created on: 20 Apr 2024
 *      Author: walid
 */


#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "Err_Type.h"
#include <util/delay.h>
#include "DIO_interface.h"
#include "PORT_interface.h"

void main()
{
	PORT_voidIint();
	while(1)
	{
		/*deactivate T2 and T3*/
		DIO_u8SetPinValue(DIO_PORTC,DIO_PIN0,DIO_PIN_LOW);

		/*Activate T1 and T4*/
		DIO_u8SetPinValue(DIO_PORTC,DIO_PIN1,DIO_PIN_HIGH);


		_delay_ms(500);

		/*deactivate T1 and T4*/
		DIO_u8SetPinValue(DIO_PORTC,DIO_PIN1,DIO_PIN_LOW);

		/*Activate T2 and T3*/
		DIO_u8SetPinValue(DIO_PORTC,DIO_PIN0,DIO_PIN_HIGH);


		_delay_ms(500);
	}




}
