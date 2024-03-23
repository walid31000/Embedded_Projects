/*

 * main.c
 *
 *  Created on: 8 Jun 2023
 *      Author: Oxygen
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "Err_Type.h"
#include "DIO_interface.h"
#include "PORT_interface.h"

#define   MCUCR           *((volatile uint8*)0x55)
#define   GICR           *((volatile uint8*)0x5B)
#define   SREG           *((volatile uint8*)0x5F)

void main(void)
{
	PORT_voidInit ();

// configure INT0 trigger as falling edge
 CLR_BIT(MCUCR ,0);
 SET_BIT(MCUCR ,1);
 // configure INT1 trigger as falling edge
  CLR_BIT(MCUCR ,2);
  SET_BIT(MCUCR ,3);

 //Enable INT0 PIE

 SET_BIT(GICR ,6);
 //Enable INT1 PIE

  SET_BIT(GICR ,7);

 //Enable global interrupt GIE
 SET_BIT(SREG ,7);

 //set PD2 as input
 //DIO_u8SetPinDirection(DIO_PORTD,DIO_PIN2,DIO_PIN_INPUT);
 //activate pull up
 //DIO_u8SetPinValue(DIO_PORTD,DIO_PIN2,DIO_PIN_HIGH);
 while(1)
 {

 }



}
//ISR1 implementation
void __vector_1 (void) __attribute__((signal));
 void __vector_1 (void)
 {
	 DIO_u8SetPinValue(DIO_PORTA,DIO_PIN0,DIO_PIN_HIGH);
 }

 //ISR2 implementation
 void __vector_2 (void) __attribute__((signal));
  void __vector_2 (void)
  {
 	 DIO_u8SetPinValue(DIO_PORTA,DIO_PIN0,DIO_PIN_LOW);
  }

