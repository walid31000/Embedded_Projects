/*

 * converging_diverging.c
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


  sint8 i;
  DDRC=0xFF;
	while(1)
	{


		for(i=3;i>=0;i--)
		{

			SET_BIT(PORTC,i);
			SET_BIT(PORTC,7-i);
			_delay_ms(250);
			CLR_BIT(PORTC,i);
			CLR_BIT(PORTC,7-i);
			_delay_ms(250);
		}

		for(i=0;i<=3;i++)
		{

			SET_BIT(PORTC,i);
			SET_BIT(PORTC,7-i);
			_delay_ms(250);
			CLR_BIT(PORTC,i);
			CLR_BIT(PORTC,7-i);
			_delay_ms(250);
		}

	}

}


