/*


 * main.c
 *
 *  Created on: 13 May 2023
 *      Author: Oxygen
 */



#include "STD_TYPES.h"
#include<util/delay.h>
#include "Err_Type.h"
#include "DIO_interface.h"

void main(void)
{
	//uint8 pin_reading;
	/*set PORTC as output*/
	//DIO_u8SetPortDirection(DIO_PORTC,0xff);
	/*activate internal pull up */
	//DIO_u8SetPinDirection(DIO_PORTA, DIO_PIN0, DIO_PIN_INPUT);
	//DIO_u8SetPinValue(DIO_PORTA, DIO_PIN0, DIO_PIN_HIGH);
	DIO_u8SetPinDirection(DIO_PORTD,DIO_PIN0, DIO_PIN_OUTPUT);

	while(1)
	{

		//DIO_u8GetPinValue(DIO_PORTD,DIO_PIN0,& pin_reading);



			DIO_u8SetPinValue(DIO_PORTD, DIO_PIN0, DIO_PIN_HIGH);
		_delay_ms(2000);

			DIO_u8SetPinValue(DIO_PORTD, DIO_PIN0, DIO_PIN_LOW);
			_delay_ms(2000);
	}




}
