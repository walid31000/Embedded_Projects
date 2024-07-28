/*
 * main.c
 *application: turn stepper motor to 180° clock wise direction and 180° counter clock wise
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
	PORT_voidIint();////set the first 4 pins in PORTB as output in configuration file
	//DIO_u8SetPortDirection(DIO_PORTD,0x0F);//set the first 4 pins as output

	Stepper_config_t Stepper={DIO_PORTD,DIO_PIN0,DIO_PIN1,DIO_PIN2,DIO_PIN3};
	Stepper_u8Stepper_Rotate(&Stepper,20,Clock_Wise_ROT);
	/*while(1)
	{
		Stepper_u8Stepper_Rotate(&Stepper,90,Counter_Clock_Wise_ROT);
		//_delay_ms(500);

		//Stepper_u8Stepper_Rotate(&Stepper,180,Counter_Clock_Wise_ROT);
		//_delay_ms(500);
	}*/
}



