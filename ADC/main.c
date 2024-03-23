#include "STD_TYPES.h"
#include "Err_type.h"

#include "ADC_interface.h"
#include "DIO_interface.h"
#include "PORT_interface.h"

void main(void)
{
	uint16 Local_u16DigitalValue;
	uint8 Local_u8LedVal;
	PORT_voidInit();
	ADC_voidInit ();

	while(1)
	{
		 Local_u16DigitalValue= ADC_u16GetChannelReading (ADC0_SINGLE_ENDED);
		 Local_u8LedVal= (uint8)(((uint32)Local_u16DigitalValue*255UL)/1023UL);
		DIO_u8SetPortValue(DIO_PORTD,Local_u8LedVal);
	}
}


