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
		DIO_u8SetPinValue(DIO_PORTC,DIO_PIN7,DIO_PIN_HIGH);
		_delay_ms(1000);

		DIO_u8SetPinValue(DIO_PORTC,DIO_PIN7,DIO_PIN_LOW);
		_delay_ms(1000);


	}




}
