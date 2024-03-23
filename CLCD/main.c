/*


 * simple lcd application that display the charachter and its ascii number at the same time
 *
 *  Created on: 14 May 2023
 *      Author: walid
 */

#include"STD_TYPES.h"
#include <util/delay.h>
#include"DIO_interface.h"
#include "PORT_interface.h"
#include"CLCD_interface.h"


void main(void)
{

	uint8 Local_u8Char;

	PORT_voidInit();
	CLCD_voidInit ();
	CLCD_voidGoToXY(0u,0u);
	CLCD_u8SendString("CHAR :");
	CLCD_voidGoToXY(0u,1u);
	CLCD_u8SendString("ASCII:");

	while(1)
	{

		for(Local_u8Char='A';Local_u8Char<='Z';Local_u8Char++)
		{CLCD_voidGoToXY(8u,0u);
		CLCD_voidSendData(Local_u8Char);
		//_delay_ms(1000);

		CLCD_voidGoToXY(8u,1u);
		CLCD_voidSendNumber(Local_u8Char);
		_delay_ms(200);




		}

	}
	}
