/*
 *
main.c
 *
 *  Created on: 24 Apr 2023
 *      Author: Oxygen
 */

#include <util/delay.h>
#include <avr/io.h>
#include "BIT_MATH.h"
#include "STD_TYPES.h"

int main(void)
{
	CLR_BIT(DDRB,0);
	SET_BIT(PORTB,0);//activate internal pull up for pinb0

	CLR_BIT(PINB,1);
	SET_BIT(PORTB,1);//activate internal pull up for pinb1
	DDRC=0XFF;//port c as output

	//uint8 SSD_ARR[10]={0b00111111,0b00000110,0b01011011,0b01001111,0b01100110,0b01101101,0b01111101,0b00000111,0b01111111,0b01101111};
    //uint8 counter=0;
    //PORTC=SSD_ARR[counter];
	while(1)
	{
	   uint8 x=GET_BIT(PINB,0);
	   uint8 y=GET_BIT(PINB,1);
	   if(x==0) //if pinb0 is pressed led on portc0 is on
	    {
		  PORTC=0b1;
	    }

	   else if(y==0)//if pinb1 is pressed led on portC1 is on
	  	    {
	  		  PORTC=0b10;
	  	    }
	  	   else
	  	   {
	  		   PORTC=0;
	  	   }

	}
}

