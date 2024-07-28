/*
 * main.c
 *
 *  Created on: 2 Jun 2024
 *      Author: walid
 */

#include "STD_TYPES.h"
#include "Err_Type.h"
#include "BIT_MATH.h"
#include <util/delay.h>
#include "DIO_interface.h"
#include "PORT_interface.h"
#include "EXTI_interface.h"
#include "GIE_interface.h"
#include "CLCD_interface.h"
#include "KPD_interface.h"
#include "DC_interface.h"

uint16 Local_u16ID;
uint16 Local_u16Pass;
uint8 Local_u8Counter=3;
DC_config_t DC_Motor={DIO_PORTD,DIO_PIN6,DIO_PIN7};
/* Global variable to track restart flag */
volatile uint8 flag=0;
/*ISR function*/
void INT0ISR();


/*function to get the ID from user*/
uint16 Get_ID()
{
	uint16 Local_u16_ID=0;
	uint8 Local_u8Key=0xff;
	uint8 Local_u8Counter=0;


	do
	{
		Local_u8Key=KPD_u8GetPressedKey();

		if((Local_u8Key>=0) && (Local_u8Key<=9))
		{
			CLCD_voidSendNumber(Local_u8Key);

			Local_u16_ID=Local_u16_ID*10+Local_u8Key;
			Local_u8Counter++;

		}
	}while(Local_u8Counter!=4 );

	return Local_u16_ID;
}

/*function to get the password from user*/
uint16 Get_Pass()
{
	uint16 Local_u16Pass=0;
	uint8 Local_u8Key=0xff;
	sint8 Local_u8Counter=0;
	uint8 Local_u8Xpos=8;

	do
	{
		Local_u8Key=KPD_u8GetPressedKey();

		if((Local_u8Key>=0) && (Local_u8Key<=9))
		{
			CLCD_voidSendNumber(Local_u8Key);
			_delay_ms(250);


			CLCD_voidClearGide(Local_u8Xpos,0,1);
			CLCD_voidSendData('*');
			Local_u8Xpos++;

			Local_u16Pass=Local_u16Pass*10+Local_u8Key;
			Local_u8Counter++;

		}
	}while(Local_u8Counter!=4 );

	return Local_u16Pass;
}
/*function to calculate the password*/

uint16 Calc_pass(uint16 copy_u16ID)
{
	uint16 Local_u16Pass=0;
	while(copy_u16ID)
	{
		uint16 Local_u16Digit=copy_u16ID%10;
		Local_u16Pass=Local_u16Pass*10+Local_u16Digit;
		copy_u16ID/=10;


	}

	return Local_u16Pass;


}
void restart_system(void)
{
	DIO_u8SetPinValue(DIO_PORTC,DIO_PIN1,DIO_PIN_LOW);
	CLCD_voidSendCommand(1);

	Hamoksha();
	CLCD_u8SendString("Enter ID:");
	Local_u16ID=Get_ID();
	_delay_ms(500);

	CLCD_voidSendCommand(1);
	CLCD_u8SendString("Password:");


}

void system_off(void)
{
	CLCD_voidSendCommand(1);
	Motor_voidStop(&DC_Motor);
	CLCD_u8SendString("system off");
 //   flag=0;
}

void main()
{
	PORT_voidIint();
	CLCD_voidInit ();
	EXTI_voidInit();
	EXTI_u8SetCallBack(INT0,&INT0ISR);
	//EXTI_u8IntEnable(INT0);
	GIE_voidEnableGlobal();
	 EXTI_u8IntDisable(INT0);


	 restart_system();
	while(1)
	{

		while(Local_u8Counter!=0)
		{
			EXTI_u8IntDisable(INT0);


			Local_u16Pass=Get_Pass();

			if(Local_u16Pass!=Calc_pass(Local_u16ID))
			{
			//	EXTI_u8IntDisable(INT0);
				CLCD_voidSendCommand(1);
			//	EXTI_u8Clear_flag(INT0);


				CLCD_u8SendString("wrong Password:");
				_delay_ms(500);
				 EXTI_u8IntDisable(INT0);

				CLCD_voidSendCommand(1);
				CLCD_u8SendString("Password:");

				Local_u8Counter--;
				if(Local_u8Counter==0)
				{
					CLCD_voidSendCommand(1);

					CLCD_u8SendString("no more trial");
					CLCD_u8SendStringAtPos(0,1,"system off");


					DIO_u8SetPinValue(DIO_PORTC,DIO_PIN1,DIO_PIN_HIGH);
					//    EXTI_u8Clear_flag(INT0);
					EXTI_u8IntEnable(INT0);
					if(flag==1)
					{
				        restart_system();


					}

				}

			//	Local_u8Counter=3;	break;

			}

			else
			{
				CLCD_voidSendCommand(1);
				CLCD_u8SendString("welcome:");
				CLCD_voidSendNumber(Local_u16ID);
				flag=1;
				while(1)
				{
					DIO_u8SetPinValue(DIO_PORTC,DIO_PIN0,DIO_PIN_HIGH);
					Motor_voidRotateCW(&DC_Motor);
					_delay_ms(3000);

					Motor_voidStop(&DC_Motor);
					_delay_ms(3000);
					EXTI_u8Clear_flag(INT0);
					EXTI_u8IntEnable(INT0);
					//GIE_voidEnableGlobal();
					//	Motor_voidRotateCCW(&DC_Motor);
					//_delay_ms(3000);
				}
			}

		}
	}

}



void INT0ISR()
{
	// GIE_voidDisableGlobal();
	    if (flag == 0)
	    {

	        flag=1;
	    }
	    else if (flag == 1)
	    {
	        system_off();
	    }
	  //  EXTI_u8Clear_flag(INT0); // Clear INT0 flag
	  // GIE_voidEnableGlobal();



}
