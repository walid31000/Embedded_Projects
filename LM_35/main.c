/*
 * main.c
 *
 *  Created on: 16 Jul 2024
 *      Author: WALID
 */


/*
 * main.c
 *test driver LM35
 *  Created on: 16 Jul 2024
 *      Author: walid
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "Err_Type.h"
#include "PORT_interface.h"
#include "CLCD_interface.h"
#include "DIO_interface.h"
#include "ADC_interface.h"
#include "LM35_interface.h"

void main(void)
{
	PORT_voidIint();
	ADC_voidInit();
	CLCD_voidInit();
	uint8 Local_u8Temp;

	LM35_config_t LM_OBJECT={ADC0_SINGLE_ENDED,5000};

	while(1)
	{
		LM35_u8GetTemp(&LM_OBJECT,&Local_u8Temp);


		CLCD_voidGoToXY(0,0);
		CLCD_u8SendString("TEMP =");
		CLCD_voidGoToXY(0,1);
        CLCD_voidSendNumber(Local_u8Temp);
		CLCD_voidGoToXY(3,1);

        CLCD_voidSendData('C');


	}



}

