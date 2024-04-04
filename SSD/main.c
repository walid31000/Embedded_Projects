/*
 * main.c
 *
 *  Created on: 3 Apr 2024
 *      Author: walid
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include"Err_Type.h"
#include <util/delay.h>
#include "DIO_interface.h"
#include "SSD_interface.h"
#include "SSD_prv.h"

void main()
{
	SSD_Config_t data={CATHODE,DIO_PORTC,DIO_PORTD,DIO_PIN0};
	SSD_u8EnableSSD(&data);

	while(1)
	{
		uint8 Local_u8counter;
		for(Local_u8counter=0;Local_u8counter<10;Local_u8counter++)
		{
			SSD_u8SetNumber(&data,Local_u8counter);
			_delay_ms(250);
		}

	}

}
