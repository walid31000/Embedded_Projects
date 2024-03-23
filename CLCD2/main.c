/*


 * simple lcd application
 *
 *  Created on: 14 May 2023
 *      Author: walid
 */

#include"STD_TYPES.h"
#include"DIO_interface.h"
#include "PORT_interface.h"
#include"CLCD_interface.h"


void main(void)
{
	uint8 Local_u8MyPattern[8]={0,0b00010001,0b00010001,0b00011111,0b00011111,0b00000100,0b00000100,0};
	/*Set LCD pins as output*/
	//DIO_u8SetPortDirection(DIO_PORTA,0xff);
	PORT_voidInit();
	//DIO_u8SetPinDirection(DIO_PORTB,DIO_PIN0,DIO_PIN_OUTPUT);
	//DIO_u8SetPinDirection(DIO_PORTB,DIO_PIN1,DIO_PIN_OUTPUT);
	//DIO_u8SetPinDirection(DIO_PORTB,DIO_PIN2,DIO_PIN_OUTPUT);
	CLCD_voidInit();
	CLCD_u8WriteSpecialCharacter(0u,Local_u8MyPattern,0u,0u);
	//CLCD_voidGoToXY(0u,1u);
	//CLCD_voidSendData('k');
	while(1)
	{

	}
}
