/*
 * lm35.c
 *LM35 application
 *  Created on: 16 Jul 2024
 *      Author: walid
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "Map.h"
#include "Err_Type.h"
#include "PORT_interface.h"
#include "CLCD_interface.h"
#include "DIO_interface.h"
#include "ADC_interface.h"

void main(void)
{
uint16 Local_u8Digital;
uint8 Local_u8Temp;

	PORT_voidIint();
	ADC_voidInit();
CLCD_voidInit();
	while(1)
	{
		Local_u8Digital=(uint8)ADC_u16GetChannelReading(ADC0_SINGLE_ENDED);

        CLCD_voidGoToXY(0,0);
		 CLCD_u8SendString("Digital =");
		 CLCD_voidSendNumber(Local_u8Digital);

		 Local_u8Temp=(uint8)(((uint32)Local_u8Digital*500UL)/256UL);


        CLCD_voidGoToXY(0,1);
        CLCD_u8SendString("TEMP =");

       CLCD_voidSendNumber(Local_u8Temp);
       CLCD_u8SendString(" C");






	}



}

