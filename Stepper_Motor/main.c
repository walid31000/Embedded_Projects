/*
 * main.c
 *application: activation of stepper motor full rotation
 *  Created on: 22 Apr 2024
 *      Author: walid
 */


#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include <util/delay.h>
#include "DIO_interface.h"
#include "PORT_interface.h"
#include "Stepper_interface.h"





void main(void)
{
	PORT_voidIint();
	DIO_u8SetPortDirection(DIO_PORTD,0x0F);//set the first 4 pins as output

	Stepper_config_t Stepper={DIO_PORTD,DIO_PIN0,DIO_PIN1,DIO_PIN2,DIO_PIN3};

	Stepper_voidComp_Rotation(&Stepper);




}



