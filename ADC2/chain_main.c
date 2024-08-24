/*
 * chain_main.c
 *Test ADC_u8StartChainConversionAsync function
 *  Created on: 6 Aug 2024
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
#include "CLCD_interface.h"
#include "LED_interface.h"
#include "GIE_interface.h"

void ADC_Callback(void);
uint8 Local_u8LedVal;
uint16 Local_u16CH0_Digital;
uint16 Local_u16CH1_Digital;
uint16 ADC_ArrResult[2];
Led_config_t Red_Led={DIO_PORTC,DIO_PIN0,ACT_HIGH};
void main(void)
{
	PORT_voidIint();
	ADC_voidInit();
	CLCD_voidInit();
	GIE_voidEnableGlobal();//Enable global interrupt
	/*add Led for debugging*/


	ADC_Channel_t  ADC_ChanelsArr[2]={ADC0_SINGLE_ENDED,ADC1_SINGLE_ENDED};

	ADC_Chain_t ADC_Obj={2,ADC_ChanelsArr,ADC_ArrResult,&ADC_Callback};



	while(1)
	{
		//Local_u16Digital=ADC_u16GetChannelReading(ADC0_SINGLE_ENDED);
		//ADC_u16StartConversionSynch(ADC0_SINGLE_ENDED,&Local_u16Digital);
		ADC_u8StartChainConversionAsync(&ADC_Obj);

		_delay_ms(10);
		//	Local_u8LedVal= Map(0,1023,0,255,Local_u16Digital);


		//DIO_u8SetPortValue(DIO_PORTB,Local_u8LedVal);




	}



}


void ADC_Callback(void)
{

	/*display the  digital value of chanel 0 & 1*/





	CLCD_voidGoToXY(0,0);
	CLCD_u8SendString("chanel 0 =");
	CLCD_voidClearGide(10,0,3);// clear the grides before displaying
	CLCD_voidGoToXY(10,0);

	CLCD_voidSendNumber(ADC_ArrResult[0]);

	CLCD_voidGoToXY(0,1);
	CLCD_u8SendString("chanel 1 =");
	CLCD_voidClearGide(10,1,3);// clear the grides before displaying
	CLCD_voidGoToXY(10,1);

	CLCD_voidSendNumber(ADC_ArrResult[1]);

	LED_u8ToggleLed(&Red_Led );
	_delay_ms(1000);

}
