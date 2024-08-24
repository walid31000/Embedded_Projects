/*
 * main_CTC.c
 *test CTC mode
 *  Created on: 8 Aug 2024
 *      Author: walid
 */





#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include <util/delay.h>

#include "Err_Type.h"
#include "PORT_interface.h"
#include "DIO_interface.h"
#include "LED_interface.h"


#include "Timer_interface.h"


#include "GIE_interface.h"


void TIMER0_u8CTC_Mode(void);
Led_config_t LED_RED={DIO_PORTC,DIO_PIN0,ACT_HIGH};
void main()
{
	PORT_voidIint();

	Timer_voidInit_CTC();


	TIMER0_u8SetCallBack(&TIMER_u8CTC_Mode);
	GIE_voidEnableGlobal();

	while(1)
	{

	}


}


void TIMER0_u8CTC_Mode(void)
{
	static volatile uint16 Counter=0;

	Counter++;
	if(Counter==1000)
	{


		LED_u8ToggleLed(&LED_RED);
		Counter=0;

	}
	else
	{
		/*Do nothing*/
	}





}
