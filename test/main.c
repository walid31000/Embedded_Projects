/*

 * main.c

 *
 *  Created on: 19 Apr 2023
 *      Author: Oxygen
 */
#include<avr/io.h>
int main(void)
{
	//step 1 configure pin zero in port a as an output pin
	DDRC=1;
// turn on led
	PORTC =0b1;
	return 0;
}
