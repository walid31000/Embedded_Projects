/*
 * moving your name on LCD
.c
 *
 *  Created on: 8 Jul 2023
 *      Author: walid
 */
#include"STD_TYPES.h"
#include <util/delay.h>
#include"DIO_interface.h"
#include "PORT_interface.h"
#include"CLCD_interface.h"


void main(void)
{


	PORT_voidInit();
	CLCD_voidInit ();
	char str[]="salamaleykoum";
	uint8 Local_u8Xpos=0;
	uint8 Local_u8Ypos=0;
	uint8 i=0;

//CLCD_u8SendStringAtPos(2,0,str);
//CLCD_voidClearGide(5,0,3);

	while(1)
	{
		CLCD_voidGoToXY(Local_u8Xpos,Local_u8Ypos);
		CLCD_u8SendString(str);
		  Local_u8Xpos++;
		//  CLCD_u8SendString(str);

		if(Local_u8Xpos==15)
		{
			Local_u8Xpos=0;



		}
		_delay_ms(50);

		CLCD_voidSendCommand(1);
	}



}


