



#include <util/delay.h>
#include <avr/io.h>
#include "BIT_MATH.h"
#include "STD_TYPES.h"

int main(void)
{
	DDRC=0xFF;

	//SET_BIT(DDRA,0);
  uint8 i;
	while(1)
	{

		for(i=4;i>=0;i++)
				{


			     SET_BIT(PORTC,i);
			     SET_BIT(PORTC,(7-i));
		          _delay_ms(300);


		       CLR_BIT(PORTC,i);
		       CLR_BIT(PORTC,(7-i));
			     _delay_ms(300);



	}

}
