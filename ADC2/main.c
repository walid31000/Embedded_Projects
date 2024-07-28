/*
 * main.c
 *ADC application on 8LEDs
 *  Created on: 10 Jul 2024
 *      Author: walid
 */



#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include <util/delay.h>
#include "Map.h"
#include "Err_Type.h"
#include "PORT_interface.h"
#include "DIO_interface.h"
#include "ADC_interface.h"
#include "GIE_interface.h"

void convert(void);
uint8 Local_u8LedVal;
uint16 Local_u16Digital;

void main(void)
{
	PORT_voidIint();
	ADC_voidInit();
   GIE_voidEnableGlobal();//Enable global interrupt
	while(1)
	{
		//Local_u16Digital=ADC_u16GetChannelReading(ADC0_SINGLE_ENDED);
		//ADC_u16StartConversionSynch(ADC0_SINGLE_ENDED,&Local_u16Digital);
		ADC_u16StartConversionAsynch(ADC0_SINGLE_ENDED,&Local_u16Digital,&convert);

    _delay_ms(10);
	//	Local_u8LedVal= Map(0,1023,0,255,Local_u16Digital);


		//DIO_u8SetPortValue(DIO_PORTB,Local_u8LedVal);



	}



}


void convert(void)
{
	Local_u8LedVal=  (uint8)(((uint32)(Local_u16Digital*255UL)/1023UL));

	DIO_u8SetPortValue(DIO_PORTB,Local_u8LedVal);


}
