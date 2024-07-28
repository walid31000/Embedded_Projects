/*
 * main.c
 *
 *  Created on: 8 May 2024
 *      Author: walid
 */


#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "Err_Type.h"
#include "DIO_interface.h"
#include "PORT_interface.h"


#define  SREG                *((volatile uint8*)0x5F)
#define  SREG_I                7U


#define  MCUCR                *((volatile uint8*)0x55)
#define  MCUCR_ISC00            0U
#define  MCUCR_ISC01            1U
#define  MCUCR_ISC10            2U
#define  MCUCR_ISC11            3U

#define  GICR                *((volatile uint8*)0x5B)
#define  GICR_INT1             7U
#define  GICR_INT0             6U
#define  GICR_INT2             5U


void main()
{
	PORT_voidIint();
	/*configure INT0 as falling edge*/
	CLR_BIT(MCUCR,MCUCR_ISC00);
	SET_BIT(MCUCR,MCUCR_ISC01);

	/*configure INT1 as falling edge*/
	CLR_BIT(MCUCR,MCUCR_ISC10);
	SET_BIT(MCUCR,MCUCR_ISC11);

	/*Enable INT0 PIE*/
	SET_BIT(GICR,GICR_INT0);
	/*Enable INT1 PIE*/
		SET_BIT(GICR,GICR_INT1);

	/*Enable INT0 GIE*/
	SET_BIT(SREG,SREG_I);




    while(1)
	{

	}

}

void __vector_1 (void) __attribute__ ((signal));
void __vector_1 (void)
{
	DIO_u8SetPinValue(DIO_PORTA,DIO_PIN0,DIO_PIN_HIGH);



}

void __vector_2 (void) __attribute__ ((signal));
void __vector_2 (void)
{
	DIO_u8SetPinValue(DIO_PORTA,DIO_PIN0,DIO_PIN_LOW);



}

