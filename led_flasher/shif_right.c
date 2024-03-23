/*

 * shif_right.c
 *
 *  Created on: 26 Apr 2023
 *      Author: Oxygen
 */


#include <util/delay.h>
#include <avr/io.h>
#include "BIT_MATH.h"
#include "STD_TYPES.h"

void main(void)
{
	DDRC=0xFF;


  uint8 i;
	while(1)
	{

		for(i=0;i<=7;i++)
		{
			SET_BIT(PORTC,i);
			_delay_ms(250);
			CLR_BIT(PORTC,i);
			_delay_ms(250);
		}
	}
}
