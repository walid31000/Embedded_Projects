/*

 * main.c
 *
 *  Created on: 31 May 2023
 *      Author: walid
 */


#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include <util/delay.h>
#include "Err_Type.h"
#include "DIO_interface.h"

void main(void)
{

	DIO_u8SetPinDirection(DIO_PORTC,DIO_PIN0,DIO_PIN_OUTPUT);//C0 AS OUTPUT
     DIO_u8SetPinDirection(DIO_PORTD,DIO_PIN0,DIO_PIN_INPUT);//D0 AS INPUT
     DIO_u8SetPinValue(DIO_PORTD,DIO_PIN0,DIO_PIN_HIGH);//activate pull up res
	//DIO_SetPortDirection(DIO_PORTC,0xff);
	while(1)
	{
		uint8 Local_u8Press;
   //  DIO_SetPortValue(DIO_PORTC,0xf0);
	//DIO_u8SetPinValue(DIO_PORTA,DIO_PIN0,DIO_PIN_HIGH);
		DIO_u8GetPinValue(DIO_PORTD,DIO_PIN0,&Local_u8Press);
		if(Local_u8Press==0)
		{
			DIO_u8SetPinValue(DIO_PORTC,DIO_PIN0,DIO_PIN_HIGH);
		}
		else
		{
			DIO_u8SetPinValue(DIO_PORTC,DIO_PIN0,DIO_PIN_LOW);
		}
	//DIO_u8SetPinValue(DIO_PORTA,DIO_PIN0,DIO_PIN_LOW);

	}
}

