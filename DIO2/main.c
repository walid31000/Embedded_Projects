#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "Err_type.h"
#include <util/delay.h>
#include "DIO_interface.h"
#include "DIO_reg.h"

void main(void)

{
	uint8 SSD_ARR[10]={0b00111111,0b00000110,0b01011011,0b01001111,0b01100110,0b01101101,0b01111101,0b00000111,0b01111111,0b01101111};
	uint8 i;
	DIO_u8SetPortDirection(DIO_PORTD,0Xff);
	while(1)
	{
		for(i=0;i<=9;i++)
		{
	     DIO_u8SetPortValue(DIO_PORTD,~SSD_ARR[i]);
	     _delay_ms(500);
		}

	}
}

