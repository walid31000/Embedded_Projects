/*


 * main.c
 *
 *  Created on: 24 Apr 2023
 *      Author: walid
 */


#include <util/delay.h>
#include <avr/io.h>
#include "BIT_MATH.h"
#include "STD_TYPES.h"

int main(void)
{
	DDRC=0xFF;
uint8 SSD_ARR[10]={0b00111111,0b00000110,0b01011011,0b01001111,0b01100100,0b01101101,0b01111101,0b00000111,0b01111111,0b01101111};

	//SET_BIT(DDRA,0);
 // uint8 i;
	while(1)
	{
	PORTC=SSD_ARR[0];
	_delay_ms(300);
	PORTC=SSD_ARR[1];
		_delay_ms(300);
		PORTC=SSD_ARR[2];
			_delay_ms(300);
			PORTC=SSD_ARR[3];
				_delay_ms(300);
				PORTC=SSD_ARR[4];
					_delay_ms(300);
					PORTC=SSD_ARR[5];
						_delay_ms(300);
						PORTC=SSD_ARR[6];
							_delay_ms(300);
							PORTC=SSD_ARR[7];
								_delay_ms(300);
								PORTC=SSD_ARR[8];
									_delay_ms(300);
									PORTC=SSD_ARR[9];
										_delay_ms(300);

	}
}
