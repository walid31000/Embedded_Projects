/*
 * main.c
 *seven segment with push button
 *  Created on: 15 Mar 2024
 *      Author: Oxygen
 */



#include <util/delay.h>
#include <avr/io.h>
#include "BIT_MATH.h"
#include "STD_TYPES.h"

int main(void)
{
	CLR_BIT(DDRA,0);
	SET_BIT(PORTA,0);//activate internal pull up for pina0


	DDRD=0XFF;//PORTD output

	uint8 SSD_ARR[10]={0b00111111,0b00000110,0b01011011,0b01001111,0b01100110,0b01101101,0b01111101,0b00000111,0b01111111,0b01101111};
    uint8 counter=0;
    PORTD=~SSD_ARR[counter];//i am using common anode seven segment
	while(1)
	{
	   uint8 x=GET_BIT(PINA,0);

	   if(x==0) //if pinA0 is pressed led on increment seven segment
	    {
		   counter++;
		   PORTD=~SSD_ARR[counter];
		   _delay_ms(250);
	    }



	}
}

