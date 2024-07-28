/*
 * main.c
 *ADC application on 8LEDs
 *  Created on: 10 Jul 2024
 *      Author: walid
 */



#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "Err_Type.h"
#include "PORT_interface.h"
#include "DIO_interface.h"
#include "ADC_interface.h"

void main(void)
{
uint16 Local_u16Digital;
uint8 Local_u8LedVal;
	PORT_voidIint();
	ADC_voidInit();

	/*while(1)
	{
		Local_u16Digital=ADC_u16GetChannelReading(ADC0_SINGLE_ENDED);

		Local_u8LedVal=  (uint8)(((uint32)(Local_u16Digital*255UL)/1023UL));

		DIO_u8SetPortValue(DIO_PORTB,Local_u8LedVal);



	}*/
 while(1)
 {
		DIO_u8SetPortValue(DIO_PORTB,ADC_GetChanelReading(ADC0_SINGLE_ENDED ));
 }


}
