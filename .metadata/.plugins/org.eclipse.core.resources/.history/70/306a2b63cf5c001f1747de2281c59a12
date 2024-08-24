/*
 * main.c
 *
 *  Created on: 10 Jun 2023
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
#include "Timer_prv.h"
#include "Timer_cfg.h"


#include "Timer_reg.h"



#include "GIE_interface.h"

void TIMER_Callback(void);
Led_config_t LED_RED={DIO_PORTC,DIO_PIN0,ACT_HIGH};
void main()
{
	PORT_voidIint();

	Timer_voidInit();


	TIMER_u8SetCallBack(&TIMER_Callback);
	GIE_voidEnableGlobal();
	TCNT0 =192;
	while(1)
	{

	}


}


void TIMER_Callback(void)
{
	static uint16 Counter=0;

	Counter++;
	if(Counter==3907)
	{

		TCNT0 =192;
		LED_u8ToggleLed(&LED_RED);
		Counter=0;

	}





}
