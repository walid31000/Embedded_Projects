/*
 * main.c
 *Test LDR Driver
 *  Created on: 27 Jul 2024
 *      Author: Walid
 */


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "Err_Type.h"
#include "PORT_interface.h"
#include "CLCD_interface.h"
#include "DIO_interface.h"
#include "ADC_interface.h"
#include "LDR_interface.h"

void main(void)
{
	PORT_voidIint();
	ADC_voidInit();
	CLCD_voidInit();
	uint8 Local_u8LighLevel;

	LDR_Config_t LDR_OBJECT={ADC0_SINGLE_ENDED,5000};

	while(1)
	{

		 LDR_GetLightLevel(&LDR_OBJECT,&Local_u8LighLevel);

		if(Local_u8LighLevel>2)
		{
			DIO_u8SetPinValue(DIO_PORTC,DIO_PIN0,DIO_PIN_LOW);


		}
		else
		{
			DIO_u8SetPinValue(DIO_PORTC,DIO_PIN0,DIO_PIN_HIGH);

		}

	}




}
