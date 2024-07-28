/*
 * main.c
 *application to test the driver
 *
 *  Created on: 12 May 2024
 *      Author: walid
 */


#include "STD_TYPES.h"
#include "Err_Type.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "PORT_interface.h"
#include "EXTI_interface.h"
#include "GIE_interface.h"

void INT0ISR(void);
void INT1ISR(void);


void main (void)
{
	PORT_voidIint();
	EXTI_voidInit();

	EXTI_u8SetCallBack(INT0,&INT0ISR);
	EXTI_u8SetCallBack(INT1,&INT1ISR);


	GIE_voidEnableGlobal();
	while(1)
	{


	}

}

void INT0ISR(void)
{
	DIO_u8SetPinValue(DIO_PORTA,DIO_PIN0,DIO_PIN_HIGH);
}


void INT1ISR(void)

{
	DIO_u8SetPinValue(DIO_PORTA,DIO_PIN0,DIO_PIN_LOW);
}
