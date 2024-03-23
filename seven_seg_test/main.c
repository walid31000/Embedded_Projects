/*
 * main.c
 *test seven segement display
 *  Created on: 14 Mar 2024
 *      Author: walid
 */
#include<avr/io.h>
#include<util/delay.h>
#include "BIT_MATH.h"
#include "STD_TYPES.h"
void main(void)
{

	uint8 SSD_ARR[10]={0b00111111,0b00000110,0b01011011,0b01001111,0b01100110,0b01101101,0b01111101,0b00000111,0b01111111,0b01101111};
	DDRC=0xff;
	while(1)
	{
	for(sint8 i=0;i<10;i++)
	{
		PORTC=SSD_ARR[i];
		_delay_ms(1000);
	}
	}

}
