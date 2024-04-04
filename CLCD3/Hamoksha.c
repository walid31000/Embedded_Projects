/*
 * main1.c
 *
 *  Created on: 8 Jul 2023
 *      Author: walid
 *      HAMOKSHA
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

	uint8  Local_u8MyPattern[8] ={0B01110, 0B01010,0B01110,0B00101,0B11111,0B10100,0B01010,0B10001};
	uint8  Local_u8MyPattern2[8] ={0B01110,0B01010,0B01110,0B10100,0B11111,0B00101,0B11010,0B00010};
	uint8  Local_u8MyPattern3[8] ={ 0B11111,0B10001,0B11111,0B10100,0B11100,0B10000,0B00000,0B00000};
	uint8  Local_u8MyPattern4[8] ={ 0B00000,0B11111,0B00000,0B00000,0B00000,0B00000,0B00000,0B00000};
	uint8  Local_u8MyPattern5[8] ={0B00000,0B00000,0B11001,0B01111,0B11001,0B00000,0B00000,0B00000};
	uint8  Local_u8MyPattern6[8] ={ 0B00000,0B00000,0B00000,0B00000,0B00000,0B01110,0B01110,0B01110};

	uint8 Local_u8Xpos=0;
	uint8 Local_u8Ypos=0;
	uint8 Local_u8counter;
	PORT_voidInit();
	CLCD_voidInit ();
	CLCD_u8WriteSpecialCharacter(0u,Local_u8MyPattern,Local_u8Xpos,Local_u8Ypos);

	while(1)
	{
		CLCD_u8SendStringAtPos(0u,1u,"Hi I'm HAMOKSHA");
		_delay_ms(1000);
		/*Display clear */
		CLCD_voidSendCommand(1);
		CLCD_u8SendStringAtPos(2u,1u,"I CAN RUN");
		for (Local_u8Xpos=0;Local_u8Xpos<=15;Local_u8Xpos++)
		{
			CLCD_u8WriteSpecialCharacter(0u,Local_u8MyPattern,Local_u8Xpos,Local_u8Ypos);
			_delay_ms(150);
			CLCD_voidClearGide(Local_u8Xpos,Local_u8Ypos,1 );
			_delay_ms(150);

			CLCD_u8WriteSpecialCharacter(1u,Local_u8MyPattern2,Local_u8Xpos,Local_u8Ypos);
			_delay_ms(150);
			CLCD_voidClearGide(Local_u8Xpos,Local_u8Ypos,1 );
			_delay_ms(150);

		}

		/*Display clear */
		CLCD_voidSendCommand(1);
		CLCD_u8SendStringAtPos(2u,1u,"I CAN DANCE");
		_delay_ms(1000);
		for(Local_u8counter=0;Local_u8counter<=10;Local_u8counter++)
		{
			CLCD_u8WriteSpecialCharacter(0u,Local_u8MyPattern,7u,0u);
			_delay_ms(150);
			CLCD_u8WriteSpecialCharacter(1u,Local_u8MyPattern2,7u,0u);
			_delay_ms(150);
		}

		/*Display clear */
		CLCD_voidSendCommand(1);
		CLCD_u8SendStringAtPos(0u,1u,"I PLAY FOOTBAL");
		_delay_ms(1000);
		for (Local_u8Xpos=0;Local_u8Xpos<=15;Local_u8Xpos++)
		{
			//CLCD_u8SendStringAtPos(Local_u8Xpos,0,".");
			CLCD_u8WriteSpecialCharacter(5u,Local_u8MyPattern6,Local_u8Xpos,Local_u8Ypos);
			_delay_ms(50);
			//	CLCD_voidClearGide(Local_u8Xpos,Local_u8Ypos,1 );
			//	_delay_ms(150);
			CLCD_u8WriteSpecialCharacter(0u,Local_u8MyPattern,Local_u8Xpos,Local_u8Ypos);
			_delay_ms(50);
			CLCD_voidClearGide(Local_u8Xpos,Local_u8Ypos,1 );
			_delay_ms(50);

			CLCD_u8WriteSpecialCharacter(1u,Local_u8MyPattern2,Local_u8Xpos,Local_u8Ypos);
			_delay_ms(50);
			CLCD_voidClearGide(Local_u8Xpos,Local_u8Ypos,1 );
			_delay_ms(50);


		}

		/*Display clear */
		CLCD_voidSendCommand(1);
		CLCD_u8SendStringAtPos(0u,1u,"DONT KILL ME");
		_delay_ms(1000);

		CLCD_u8WriteSpecialCharacter(2u,Local_u8MyPattern3,0u,0u);
		CLCD_u8WriteSpecialCharacter(0u,Local_u8MyPattern,15,0);
		_delay_ms(1000);
		for (Local_u8Xpos=1;Local_u8Xpos<=14;Local_u8Xpos++)
		{
			CLCD_u8WriteSpecialCharacter(3u,Local_u8MyPattern4,Local_u8Xpos,Local_u8Ypos);
			_delay_ms(50);
				CLCD_voidClearGide(Local_u8Xpos,Local_u8Ypos,1 );
				_delay_ms(50);

		}

		CLCD_u8WriteSpecialCharacter(4u,Local_u8MyPattern5,15,0);
		_delay_ms(1000);
		/*Display clear */
			CLCD_voidSendCommand(1);
			_delay_ms(1000);

		}
	}
