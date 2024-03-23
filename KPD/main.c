/*

 * main.c
 *
 *  Created on: 22 Aug 2023
 *      Author: walid
 */


#include "STD_TYPES.h"
//#include "Err_Type.h"
#include "BIT_MATH.h"
#include "PORT_interface.h"
#include "DIO_interface.h"
#include "CLCD_interface.h"
#include "KPD_interface.h"




void main(void)

{
	uint8 Local_u8Num=0xff;
	PORT_voidInit ();
	CLCD_voidInit ();

	while(1)
	{



		do {


	        Local_u8Num=KPD_u8GetPressedKey();
		   }  while(Local_u8Num==0xff);
		CLCD_voidSendNumber(Local_u8Num);
	 }

}
