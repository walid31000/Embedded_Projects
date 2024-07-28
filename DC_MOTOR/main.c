/*
 * main.c
 *test DC motor driver
 *Application :rotate motore clock wise and stope then counter clock wise rotation
 *  Created on: 21 Apr 2024
 *      Author: walid
 */


#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include <util/delay.h>
#include "DIO_interface.h"
#include "PORT_interface.h"
#include "DC_interface.h"


void main()

{
	PORT_voidIint();
	DC_config_t Motor={DIO_PORTD,DIO_PIN6,DIO_PIN7 };
	while(1)
	{

		Motor_voidRotateCW(&Motor);
		_delay_ms(100);
		Motor_voidStop(&Motor);
		_delay_ms(3000);
		Motor_voidRotateCCW(&Motor);
		_delay_ms(100);
		Motor_voidStop(&Motor);
		_delay_ms(3000);





	}



}
