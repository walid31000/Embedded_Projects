/*

 * main2.c
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

	//SET_BIT(DDRA,0);
  //uint8 i;
	while(1)
	{
		PORTC=0xFF;
		   _delay_ms(500);
		   PORTC=0;
		   _delay_ms(500);
	}
}



