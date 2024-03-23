#include "STD_TYPES.h"
#include <util/delay.h>
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "DIO_reg.h"
#include "PORT_interface.h"
//#include <avr/io.h>




void main(void)
{
	PORT_voidInit();
	uint8 SSD_ARR[10]={0b00111111,0b00000110,0b01011011,0b01001111,0b01100110,0b01101101,0b01111101,0b00000111,0b01111111,0b01101111};

uint8 Local_u8Counter=0;
PORTD=~SSD_ARR[Local_u8Counter];
	while(1)
	{
		//uint8 Local_u8PinARead=DIO_u8GetPinValue(DIO_PORTA,DIO_PIN0,&Local_u8PinARead);
		uint8 Local_u8PinARead=GET_BIT(PINA,0);
		if(Local_u8PinARead==DIO_PIN_LOW)
		{
			Local_u8Counter++;

			PORTD= ~SSD_ARR[Local_u8Counter];
			_delay_ms(250);
		}


	}

}



