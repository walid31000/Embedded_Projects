/*
 * main.c
 *
 *  Created on: 13 Mar 2024
 *      Author: walid
 */
#include <avr/io.h>
#include <util/delay.h>
int main()
{
	DDRC=0xff;//port A as output
	while(1)
	{
	PORTC|=(1<<0);//pinc0 A as  high
    _delay_ms(1000);
    PORTC &=~(1<<0);//pinc1 A as  low
    _delay_ms(1000);
	}
}
