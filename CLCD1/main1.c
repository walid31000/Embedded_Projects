/*
* main1.c
 *
 *  Created on: 8 Jul 2023
 *      Author: walid
 */

#include "STD_TYPES.h"
#include <util/delay.h>
#include "BIT_MATH.h"
#include "Err_type.h"
#include "DIO_interface.h"

#include "PORT_interface.h"

#include "CLCD_interface.h"

#include "CLCD_cfg.h"
void main(void)
{

	uint8  Local_u8MyPattern[8] ={0b100,0b1110,0b11111,0b100,0b100,0b100,0b100,0};
	uint8 Local_u8Xpos=0;
	uint8 Local_u8Ypos=0;
	PORT_voidInit();
		CLCD_voidInit ();
		CLCD_u8WriteSpecialCharacter(0u,Local_u8MyPattern,Local_u8Xpos,Local_u8Ypos);

		while(1)
		{
			for (Local_u8Xpos=0;Local_u8Xpos<=15;Local_u8Xpos++)
			{
				CLCD_u8WriteSpecialCharacter(0u,Local_u8MyPattern,Local_u8Xpos,Local_u8Ypos);
			}
		}
}
