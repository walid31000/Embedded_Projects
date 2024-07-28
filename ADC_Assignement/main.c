/*
 * main.c
 *voltmeter application
 *  Created on: 10 Jul 2024
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
uint16 Local_u16Digital;
uint16 Local_u16Analog;

	PORT_voidIint();
	ADC_voidInit();
CLCD_voidInit();
	while(1)
	{
		Local_u16Digital=ADC_u16GetChannelReading(ADC0_SINGLE_ENDED);

        CLCD_voidGoToXY(0,0);
		 CLCD_u8SendString("Digital =");
		 CLCD_voidSendNumber(Local_u16Digital);
	//	Local_u8LedVal=  (uint8)(((uint32)(Local_u16Digital*255UL)/1023UL));
		Local_u16Analog=(uint16)(((uint32)Local_u16Digital*5000UL)/1023UL);


        CLCD_voidGoToXY(0,1);
        CLCD_u8SendString("Analog =");

       CLCD_voidSendNumber(Local_u16Analog);
       CLCD_u8SendString(" mv");






	}



}
