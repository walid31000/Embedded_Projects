/*

 * main.c
 *
 *  Created on: 19 Apr 2023
 *      Author: Oxygen
 */
#include <util/delay.h>
#include <avr/io.h>
#include "BIT_MATH.h"
#include "STD_TYPES.h"

int main(void)
{
	DDRC=0xFF;

	//SET_BIT(DDRA,0);
  uint8 i;
	while(1)
	{
		for(i=7;i>=0;i--)
		{


	     SET_BIT(PORTC,i);

          _delay_ms(250);


       CLR_BIT(PORTC,i);
	     _delay_ms(250);

	    }
		for(i=0;i<=7;i++)
				{


			     SET_BIT(PORTC,i);

		          _delay_ms(250);


		       CLR_BIT(PORTC,i);
			     _delay_ms(250);

			    }
	}
}

