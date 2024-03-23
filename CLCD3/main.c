/*Assignement 3 button calculator with LCD*/

#include "STD_TYPES.h"
#include <util/delay.h>
#include "BIT_MATH.h"
#include "Err_type.h"
#include "DIO_interface.h"
//#include "DIO_reg.h"
#include "PORT_interface.h"

//#include "PORT_cfg.h"
//#include "PORT_prv.h"
//#include "PORT_reg.h"
#include "CLCD_interface.h"
//#include "CLCD_prv.h"



#include "CLCD_cfg.h"

 sint32 Local_s32Num1=1;
 sint32 Local_s32Num2=1;
 sint32 Local_s32Result;
 sint8 Local_s8Iterator1;
char ch_Operation[4]={'+','-','*','/'};


void main(void)
{
	uint8  Local_u8MyPattern[8] ={0b100,0b1110,0b11111,0b100,0b100,0b100,0b100,0};
	uint8 Local_u8Xpos=0;
	uint8 Local_u8Ypos=1;
	uint8 Local_DDRAMXPos=0;
	uint8 Local_u8DDRAMYPos=0;


	uint8 Local_u8PinUPRead;
	uint8 Local_u8PinDownRead;
	uint8 Local_u8PinEnterRead;

	/*set CLCD pins as output */

	PORT_voidInit();
	CLCD_voidInit ();
	//CLCD_voidGoToXY(0u,1u);


	// CLCD_u8SendString("BTWA");
	//CLCD_u8SendString("walid");



	while(1)
	{
		CLCD_voidSendNumber(Local_s32Num1);
		CLCD_voidSendData ('+');
		CLCD_voidSendNumber(Local_s32Num2);

		CLCD_u8WriteSpecialCharacter(0u,Local_u8MyPattern,Local_u8Xpos,Local_u8Ypos);




		while(Local_u8Xpos<=4)
		{
			DIO_u8GetPinValue(CLCD_u8Cal_PORT, CLCD_u8UP_PIN ,&Local_u8PinUPRead);
			DIO_u8GetPinValue(CLCD_u8Cal_PORT, CLCD_u8DOWN_PIN ,&Local_u8PinDownRead);
			DIO_u8GetPinValue(CLCD_u8Cal_PORT, CLCD_u8ENTER_PIN ,&Local_u8PinEnterRead);


			if(Local_u8PinUPRead ==DIO_PIN_LOW)
			{
				switch (Local_u8Xpos)
				{
				case 0:CLCD_voidGoToXY (Local_u8Xpos,Local_u8DDRAMYPos);

				Local_s32Num1++;
				if(Local_s32Num1==10)
				{
					Local_s32Num1=0;
				}
				CLCD_voidSendNumber(Local_s32Num1);
				CLCD_voidGoToXY (8u,1u);
				CLCD_u8SendString ("UP");
				_delay_ms(250);
				CLCD_voidGoToXY (8u,1u);
				CLCD_u8SendString ("  ");
				_delay_ms(250);break;

				case 1:
					CLCD_voidGoToXY (Local_u8Xpos,Local_u8DDRAMYPos);
					Local_s8Iterator1++;

					if(Local_s8Iterator1==4)
					{
						Local_s8Iterator1=0;

					}

					CLCD_voidSendData(ch_Operation[Local_s8Iterator1]);

					_delay_ms(250);break;

				case 2:
					CLCD_voidGoToXY (Local_u8Xpos,Local_u8DDRAMYPos);

					Local_s32Num2++;
					if(Local_s32Num2==10)
					{
						Local_s32Num2=0;
					}
					CLCD_voidSendNumber(Local_s32Num2);
					if((Local_s8Iterator1==3)&&(Local_s32Num2==0))
										continue;
					CLCD_voidGoToXY (8u,1u);
					CLCD_u8SendString ("UP");
					_delay_ms(250);
					CLCD_voidGoToXY (8u,1u);
					CLCD_u8SendString ("  ");
					_delay_ms(250);

					_delay_ms(250);break;



				}
			}

			if(Local_u8PinDownRead ==DIO_PIN_LOW)
			{
				switch (Local_u8Xpos)
				{
				case 0:CLCD_voidGoToXY (Local_DDRAMXPos,Local_u8DDRAMYPos);

				Local_s32Num1--;
				if(Local_s32Num1==-1)
				{
					Local_s32Num1=9;
				}
				CLCD_voidSendNumber(Local_s32Num1);
				if((Local_s8Iterator1==3)&&(Local_s32Num2==0))
					continue;
				CLCD_voidGoToXY (8u,1u);
				CLCD_u8SendString ("DOWN");
				_delay_ms(250);
				CLCD_voidGoToXY (8u,1u);
				CLCD_u8SendString ("     ");
				_delay_ms(250);break;
				case 1://Local_DDRAMXPos++;
					CLCD_voidGoToXY (Local_u8Xpos,Local_u8DDRAMYPos);
					Local_s8Iterator1--;

					if(Local_s8Iterator1==-1)
					{
						Local_s8Iterator1=3;

					}
					CLCD_voidSendData(ch_Operation[Local_s8Iterator1]);
					_delay_ms(250);break;


				case 2:CLCD_voidGoToXY (Local_u8Xpos,Local_u8DDRAMYPos);

				Local_s32Num2--;
				if(Local_s32Num2==-1)
				{
					Local_s32Num2=9;
				}
				CLCD_voidSendNumber(Local_s32Num2);
				if((Local_s8Iterator1==3)&&(Local_s32Num2==0))
					continue;
				CLCD_voidGoToXY (8u,1u);
				CLCD_u8SendString ("DOWN");
				_delay_ms(250);
				CLCD_voidGoToXY (8u,1u);
				CLCD_u8SendString ("     ");
				_delay_ms(250);

				break;

				}

			}


			if(Local_u8PinEnterRead ==DIO_PIN_LOW)
			{

				switch (Local_u8Xpos)
				{
				case 0:CLCD_voidGoToXY (0u,1u);
				CLCD_u8SendString (" ");
				Local_u8Xpos++;

				CLCD_u8WriteSpecialCharacter(0u,Local_u8MyPattern,Local_u8Xpos,Local_u8Ypos);
				_delay_ms(250);
				CLCD_voidGoToXY (8u,1u);
				CLCD_u8SendString ("ENTER");
				_delay_ms(250);
				CLCD_voidGoToXY (8u,1u);
				CLCD_u8SendString ("     ");
				_delay_ms(250);break;





				case 1:CLCD_voidGoToXY (1u,1u);
				CLCD_u8SendString (" ");
				Local_u8Xpos++;
				CLCD_u8WriteSpecialCharacter(0u,Local_u8MyPattern,Local_u8Xpos,Local_u8Ypos);
				_delay_ms(250);
				CLCD_voidGoToXY (8u,1u);
				CLCD_u8SendString ("ENTER");
				_delay_ms(250);
				CLCD_voidGoToXY (8u,1u);
				CLCD_u8SendString ("     ");
				_delay_ms(250);
				break;

				case 2:
					CLCD_voidGoToXY (2u,1u);
					CLCD_u8SendString (" ");
					Local_u8Xpos++;
					CLCD_voidGoToXY (Local_u8Xpos,Local_u8DDRAMYPos);

					break;
				case 3:
					CLCD_voidSendData ('=');

					Local_u8Xpos++;
					CLCD_u8WriteSpecialCharacter(0u,Local_u8MyPattern,Local_u8Xpos,Local_u8Ypos);break;
				case 4:CLCD_voidGoToXY (4u,0u);
				CLCD_u8SendString ("         ");
				CLCD_voidGoToXY (Local_u8Xpos,Local_u8DDRAMYPos);

				CLCD_voidCalc();
				if(Local_s8Iterator1==3)
				{
					//do nothing
				}
				else
				{
					CLCD_voidSendNumber ( Local_s32Result);
				}
				_delay_ms(500);


				CLCD_voidGoToXY (4u,1u);
				CLCD_u8SendString (" ");
				Local_u8Xpos=0;
				Local_u8Ypos=1;
				CLCD_u8WriteSpecialCharacter(0u,Local_u8MyPattern,Local_u8Xpos,Local_u8Ypos);
				break;


				}

			}

		}

	}

}





