#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include <util/delay.h>
#include "DIO_interface.h"
#include "DIO_reg.h"
#include "PORT_interface.h"
//#include <avr/io.h>



void SSD_voidDisplay(uint8 copy_Number);
void main(void)
{
	PORT_voidInit();
	uint8 SSD_ARR[10]={0b00111111,0b00000110,0b01011011,0b01001111,0b01100110,0b01101101,0b01111101,0b00000111,0b01111111,0b01101111};

	//SET_BIT(DDRA,0);
	sint8 i,j;
	while(1)
	{
		for(i=0;i<=9;i++)
		{/*activate SSD 1 */
			DIO_u8SetPinValue(DIO_PORTA,DIO_PIN7,DIO_PIN_LOW);
			/*Deactivate SSD 2 */
			DIO_u8SetPinValue(DIO_PORTA,DIO_PIN6,DIO_PIN_HIGH);


			SSD_voidDisplay(~SSD_ARR[i]);
			_delay_ms(500);




				/*Deactivate SSD 1 */
				DIO_u8SetPinValue(DIO_PORTA,DIO_PIN7,DIO_PIN_HIGH);
				/*activate SSD 2 */
				DIO_u8SetPinValue(DIO_PORTA,DIO_PIN6,DIO_PIN_LOW);



				SSD_voidDisplay(~SSD_ARR[9-i]);
				_delay_ms(500);
			}

		}

	}
	void SSD_voidDisplay(uint8 copy_Number)
	{
		DIO_u8SetPortValue(DIO_PORTC, copy_Number);

	}




