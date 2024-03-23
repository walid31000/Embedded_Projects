/*
 * main.c
 *
 *  Created on: 16 Mar 2024
 *      Author: walid
 */
#include "STD_TYPES.h"

#include "Err_Type.h"
#include <util/delay.h>
#include "DIO_interface.h"

int main()
{uint8 x;
     DIO_u8SetPinDirection(DIO_PORTA,DIO_PIN0,DIO_PIN_INPUT);
     DIO_u8SetPinValue(DIO_PORTA,DIO_PIN0,DIO_PIN_HIGH);//activate internal pull up

    DIO_u8SetPinDirection(DIO_PORTB,DIO_PIN0,DIO_PIN_OUTPUT);
	while(1)
	{
		 DIO_u8GetPinValue(DIO_PORTA,DIO_PIN0,&x);
	if(x==DIO_PIN_LOW)
		DIO_u8SetPinValue(DIO_PORTB,DIO_PIN0,DIO_PIN_HIGH);
	else
		DIO_u8SetPinValue(DIO_PORTB,DIO_PIN0,DIO_PIN_LOW);

	}
}
