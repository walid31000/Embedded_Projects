/*

 * main2.c
 *
 *  Created on: 9 Jul 2023
 *      Author: move your name in arabic sinusoidaly
 */
#include"STD_TYPES.h"
#include <util/delay.h>
#include"DIO_interface.h"
#include "PORT_interface.h"
#include"CLCD_interface.h"


void main(void)
{
	sint8 Local_s8Xpos=15;
    sint8 Local_s8Ypos=0;
	PORT_voidInit();
	CLCD_voidInit ();
uint8 Pattern1[8]={ 0b01110, 0b01010, 0b01110, 0b00010, 0b00010, 0b01110, 0b00000, 0b00000 };
uint8 Pattern2[8]={ 0b00001, 0b00001, 0B00001, 0B11111, 0B00000, 0B00000, 0B00000, 0B00000 };
uint8 Pattern3[8]= { 0B00000, 0B00000, 0B00001, 0B11111, 0B00000,0B01010, 0B00000, 0B00000 };
uint8 Pattern4[8]={ 0B01000, 0B00100, 0B00010, 0B11111,0B00000, 0B00000, 0B00000, 0B00000 };

while(1)
{


	for(Local_s8Ypos=0;Local_s8Ypos<=1;Local_s8Ypos++)
	{
CLCD_u8WriteSpecialCharacter(0u,Pattern1,Local_s8Xpos,Local_s8Ypos);

CLCD_u8WriteSpecialCharacter(1u,Pattern2,--Local_s8Xpos,Local_s8Ypos);
CLCD_u8WriteSpecialCharacter(2u,Pattern3,--Local_s8Xpos,Local_s8Ypos);
CLCD_u8WriteSpecialCharacter(3u,Pattern4,--Local_s8Xpos,Local_s8Ypos);
CLCD_voidClearGide( Local_s8Xpos+6,Local_s8Ypos,4);

if(Local_s8Xpos==0)
{
	Local_s8Xpos=0;
}
	}

}
}
