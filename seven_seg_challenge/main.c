/*
 * main.c
 *
 *  Created on: 1 Apr 2024
 *      Author: Oxygen
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "Err_Type.h"
#include "util/delay.h"
#include "DIO_interface.h"

void main(void)
{
	DIO_u8SetPortDirection(DIO_PORTC,0xff);
	DIO_u8SetPinDirection(DIO_PORTD,DIO_PIN0,DIO_PIN_OUTPUT);
	DIO_u8SetPinDirection(DIO_PORTD,DIO_PIN1,DIO_PIN_OUTPUT);

	uint8 SSD_ARR[10]={0b00111111,0b00000110,0b01011011,0b01001111,0b01100110,0b01101101,0b01111101,0b00000111,0b01111111,0b01101111};
	uint8 Local_u8Iterator;
	while (1)
	{
		for(Local_u8Iterator=0;Local_u8Iterator<10;Local_u8Iterator++)
		{
			DIO_u8SetPinValue(DIO_PORTD,DIO_PIN0,DIO_PIN_HIGH);
			DIO_u8SetPinValue(DIO_PORTD,DIO_PIN1,DIO_PIN_LOW);
			DIO_u8SetPortValue(DIO_PORTC,SSD_ARR[Local_u8Iterator]);
			_delay_ms(10);
			Dio_u8TogglePin(DIO_PORTD,DIO_PIN0);
			Dio_u8TogglePin(DIO_PORTD,DIO_PIN1);
			DIO_u8SetPortValue(DIO_PORTC,SSD_ARR[9-Local_u8Iterator]);
			_delay_ms(10);


		}


	}


}

