/*
 * main.c

 *  Created on: 19 Mar 2024
 *      Author: walid
 */
#include "STD_TYPES.h"
#include "DIO_interface.h"
#include "CLCD_interface.h"

void main()
{
	/*SET LCD pins at output*/
	DIO_u8SetPortDirection(DIO_PORTA,0xff);
	DIO_u8SetPinDirection(DIO_PORTB,DIO_PIN0,DIO_PIN_OUTPUT);
	DIO_u8SetPinDirection(DIO_PORTB,DIO_PIN1,DIO_PIN_OUTPUT);
	DIO_u8SetPinDirection(DIO_PORTB,DIO_PIN2,DIO_PIN_OUTPUT);
	CLCD_voidInit();

	CLCD_voidSendData('A');
	while(1)
	{

	}


}

