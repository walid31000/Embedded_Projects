#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include <util/delay.h>
#include "DIO_interface.h"
#include "Stepper_interface.h"






void Stepper_voidComp_Rotation(Stepper_config_t* Stepper_Object)
{

	while(1)
	{
		DIO_u8SetPinValue(Stepper_Object->PORT_STEPPER,Stepper_Object->BLEU_PIN,DIO_PIN_LOW);
		DIO_u8SetPinValue(Stepper_Object->PORT_STEPPER,Stepper_Object->PINK_PIN,DIO_PIN_HIGH);
		DIO_u8SetPinValue(Stepper_Object->PORT_STEPPER,Stepper_Object->YELLOW_PIN,DIO_PIN_HIGH);
		DIO_u8SetPinValue(Stepper_Object->PORT_STEPPER,Stepper_Object->ORANGE_PIN,DIO_PIN_HIGH);
		_delay_ms(500);


		DIO_u8SetPinValue(Stepper_Object->PORT_STEPPER,Stepper_Object->BLEU_PIN,DIO_PIN_HIGH);
		DIO_u8SetPinValue(Stepper_Object->PORT_STEPPER,Stepper_Object->PINK_PIN,DIO_PIN_LOW);
		DIO_u8SetPinValue(Stepper_Object->PORT_STEPPER,Stepper_Object->YELLOW_PIN,DIO_PIN_HIGH);
		DIO_u8SetPinValue(Stepper_Object->PORT_STEPPER,Stepper_Object->ORANGE_PIN,DIO_PIN_HIGH);
		_delay_ms(500);


		DIO_u8SetPinValue(Stepper_Object->PORT_STEPPER,Stepper_Object->BLEU_PIN,DIO_PIN_HIGH);
		DIO_u8SetPinValue(Stepper_Object->PORT_STEPPER,Stepper_Object->PINK_PIN,DIO_PIN_HIGH);
		DIO_u8SetPinValue(Stepper_Object->PORT_STEPPER,Stepper_Object->YELLOW_PIN,DIO_PIN_LOW);
		DIO_u8SetPinValue(Stepper_Object->PORT_STEPPER,Stepper_Object->ORANGE_PIN,DIO_PIN_HIGH);
		_delay_ms(500);


		DIO_u8SetPinValue(Stepper_Object->PORT_STEPPER,Stepper_Object->BLEU_PIN,DIO_PIN_HIGH);
		DIO_u8SetPinValue(Stepper_Object->PORT_STEPPER,Stepper_Object->PINK_PIN,DIO_PIN_HIGH);
		DIO_u8SetPinValue(Stepper_Object->PORT_STEPPER,Stepper_Object->YELLOW_PIN,DIO_PIN_HIGH);
		DIO_u8SetPinValue(Stepper_Object->PORT_STEPPER,Stepper_Object->ORANGE_PIN,DIO_PIN_LOW);
		_delay_ms(500);

       }
/******** to reverse direction **************/
	/*while(1)
		{
			DIO_u8SetPinValue(Stepper_Object->PORT_STEPPER,Stepper_Object->BLEU_PIN,DIO_PIN_HIGH);
			DIO_u8SetPinValue(Stepper_Object->PORT_STEPPER,Stepper_Object->PINK_PIN,DIO_PIN_HIGH);
			DIO_u8SetPinValue(Stepper_Object->PORT_STEPPER,Stepper_Object->YELLOW_PIN,DIO_PIN_HIGH);
			DIO_u8SetPinValue(Stepper_Object->PORT_STEPPER,Stepper_Object->ORANGE_PIN,DIO_PIN_LOW);
			_delay_ms(1000);


			DIO_u8SetPinValue(Stepper_Object->PORT_STEPPER,Stepper_Object->BLEU_PIN,DIO_PIN_HIGH);
			DIO_u8SetPinValue(Stepper_Object->PORT_STEPPER,Stepper_Object->PINK_PIN,DIO_PIN_HIGH);
			DIO_u8SetPinValue(Stepper_Object->PORT_STEPPER,Stepper_Object->YELLOW_PIN,DIO_PIN_LOW);
			DIO_u8SetPinValue(Stepper_Object->PORT_STEPPER,Stepper_Object->ORANGE_PIN,DIO_PIN_HIGH);
			_delay_ms(1000);


			DIO_u8SetPinValue(Stepper_Object->PORT_STEPPER,Stepper_Object->BLEU_PIN,DIO_PIN_HIGH);
			DIO_u8SetPinValue(Stepper_Object->PORT_STEPPER,Stepper_Object->PINK_PIN,DIO_PIN_LOW);
			DIO_u8SetPinValue(Stepper_Object->PORT_STEPPER,Stepper_Object->YELLOW_PIN,DIO_PIN_HIGH);
			DIO_u8SetPinValue(Stepper_Object->PORT_STEPPER,Stepper_Object->ORANGE_PIN,DIO_PIN_HIGH);
			_delay_ms(1000);


			DIO_u8SetPinValue(Stepper_Object->PORT_STEPPER,Stepper_Object->BLEU_PIN,DIO_PIN_LOW);
			DIO_u8SetPinValue(Stepper_Object->PORT_STEPPER,Stepper_Object->PINK_PIN,DIO_PIN_HIGH);
			DIO_u8SetPinValue(Stepper_Object->PORT_STEPPER,Stepper_Object->YELLOW_PIN,DIO_PIN_HIGH);
			DIO_u8SetPinValue(Stepper_Object->PORT_STEPPER,Stepper_Object->ORANGE_PIN,DIO_PIN_HIGH);
			_delay_ms(1000);

	       }*/





}
