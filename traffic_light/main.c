


#include <util/delay.h>
#include <avr/io.h>
#include "BIT_MATH.h"
#include "STD_TYPES.h"

void main(void)
{
	DDRC=0xFF;
	DDRD=0xFF;
	DDRB=0XFF;
	sint8 i,j;
	uint8 SSD_ARR[10]={0b00111111,0b00000110,0b01011011,0b01001111,0b01100110,0b01101101,0b01111101,0b00000111,0b01111111,0b01101111};

	while(1)
	{
		PORTB=0b00000001;//turn on led red
		j=1;

		PORTC=SSD_ARR[j];
		for(i=5;i>=0;i--)
		{
			PORTD=SSD_ARR[i];
			_delay_ms(1000);
		}

		j=0;
		PORTC=SSD_ARR[j];
		for(i=9;i>=0;i--)
		{
			PORTD=SSD_ARR[i];
			_delay_ms(1000);
		}
		PORTB=0b00000010;//turn on led green
		j=1;

		PORTC=SSD_ARR[j];
		for(i=5;i>=0;i--)
		{
			PORTD=SSD_ARR[i];
			_delay_ms(1000);
		}

		j=0;
		PORTC=SSD_ARR[j];
		for(i=9;i>=0;i--)
		{
			PORTD=SSD_ARR[i];
			_delay_ms(1000);
		}
		PORTB=0b00000100;//turn on led yellow
		for(i=3;i>=0;i--)
		{
			PORTD=SSD_ARR[i];
			_delay_ms(1000);
		}


	}
}
