/*
 * main.c
 *Test LDR Driver
 *  Created on: 27 Jul 2024
 *      Author: Walid
 */


#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include <util/delay.h>
#include "Map.h"
#include "Err_Type.h"
#include "PORT_interface.h"
#include "CLCD_interface.h"
#include "DIO_interface.h"
#include "ADC_interface.h"
#include "LDR_interface.h"

void main(void)
{
	/*Initilization*/

	PORT_voidIint();
	ADC_voidInit();
	CLCD_voidInit();
	sint8 Local_u8LightLevel;

	LDR_Config_t LDR_OBJECT={ADC0_SINGLE_ENDED,5000};

	while(1)
	{

		 LDR_GetLightLevel(&LDR_OBJECT,&Local_u8LightLevel);
		 // Ensure light level is within the range 1-10
			               if (Local_u8LightLevel > 10)
			               {
			                   Local_u8LightLevel = 10;
			               }
			               else if (Local_u8LightLevel < 1)
			               {
			                   Local_u8LightLevel = 1;
			               }

		if(Local_u8LightLevel>5)

		{
			CLCD_voidGoToXY(0,0);
			CLCD_voidClearGide(13,0,2);//clear the old result before displaying the new one
			CLCD_u8SendStringAtPos(0,0,"Light Level=");

			CLCD_voidSendNumber(Local_u8LightLevel);
			CLCD_voidGoToXY(0,1);
			CLCD_u8SendString("Morning");
			DIO_u8SetPinValue(DIO_PORTB,DIO_PIN0,DIO_PIN_LOW);
     _delay_ms(200);

		}
		else
		{
			DIO_u8SetPinValue(DIO_PORTB,DIO_PIN0,DIO_PIN_HIGH);
			CLCD_voidGoToXY(0,0);
			CLCD_voidClearGide(13,0,2);
			CLCD_u8SendStringAtPos(0,0,"Light Level=");

			CLCD_voidSendNumber(Local_u8LightLevel);
			CLCD_voidGoToXY(0,1);
			CLCD_u8SendString("Evening");
			  _delay_ms(200);

		}

	}




}
