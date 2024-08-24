/*

 * main.c
 *
 *  Created on: 31 May 2023
 *      Author: walid
 */


/**  *******************************************************
 * @mainpage Test the DIO driver
 * @brief    Turn on the Led with each press on the switch
 * @author   Walid Megherbi
 *           <BR>
 *           <EM>
 *           Github: https://github.com/walid31000
 *           </EM>
 * @version   1.0.0
 * @date     31/5/2023
 * @copyright Walid Megherbi
 *
 *
 * @image  html "../DIO_test.png " "Hardware schematic"
 *         <BR>
 * @details <B> Details </B>
 *          <B> Turn on the Led with each press on the switch
 *          <BR>
 *          <B> Target </B> ATMEGA 32
 *          <BR>
 *          <B> internal clock </B> 8MHZ
 *          <BR>
 *          <B> Compiler </B>  GCC
 */



#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include <util/delay.h>
#include "Err_Type.h"
#include "DIO_interface.h"


/**
 * @brief Main function to test the DIO driver.
 *
 * This function sets up the necessary pin directions and values.
 * It continuously checks the state of a switch and toggles an LED accordingly.
 */
void main(void)
{

	DIO_u8SetPinDirection(DIO_PORTC,DIO_PIN0,DIO_PIN_OUTPUT);//C0 AS OUTPUT
     DIO_u8SetPinDirection(DIO_PORTD,DIO_PIN0,DIO_PIN_INPUT);//D0 AS INPUT
     DIO_u8SetPinValue(DIO_PORTD,DIO_PIN0,DIO_PIN_HIGH);//activate pull up res
	//DIO_SetPortDirection(DIO_PORTC,0xff);
	while(1)
	{
		uint8 Local_u8Press;
   //  DIO_SetPortValue(DIO_PORTC,0xf0);
	//DIO_u8SetPinValue(DIO_PORTA,DIO_PIN0,DIO_PIN_HIGH);
		DIO_u8GetPinValue(DIO_PORTD,DIO_PIN0,&Local_u8Press);
		if(Local_u8Press==0)
		{
			DIO_u8SetPinValue(DIO_PORTC,DIO_PIN0,DIO_PIN_HIGH);
		}
		else
		{
			DIO_u8SetPinValue(DIO_PORTC,DIO_PIN0,DIO_PIN_LOW);
		}
	//DIO_u8SetPinValue(DIO_PORTA,DIO_PIN0,DIO_PIN_LOW);

	}
}

