/*
 * main1.c
 *function to map between adc reading and servo angle
 *  Created on: 20 Aug 2024
 *      Author: walid
 */


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "Map.h"
#include "Err_Type.h"
#include "PORT_interface.h"
#include "DIO_interface.h"
#include "ADC_interface.h"
#include "Timer_interface.h"
#include "Timer_reg.h"

void main()
{
	uint16 Local_u16Digital;

	PORT_voidIint();
	ADC_voidInit();


	Timer1_voidInit();
	while(1)
	{
		ADC_u16StartSingleConversionSynch(ADC0_SINGLE_ENDED,&Local_u16Digital);// convert analog value comming from the potentiometer using AN0 channel
		Map_ADC_Potentiometer(Local_u16Digital);//map the analog value converted with the angle corresponding


	}




}
