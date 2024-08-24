/*using timer 0 with pwm mode to control Led intensity  and dc motor speed
 * PWM signal is generated from OC0 pin(PB3)
 *
 *
 * */

#include "STD_TYPES.h"
#include "BIT_MATH.h"


#include "Err_Type.h"
#include "PORT_interface.h"
#include "DIO_interface.h"
#include "ADC_interface.h"
#include "Timer_interface.h"
#include "Timer_reg.h"


void main()
{
	PORT_voidIint();
	ADC_voidInit();
	Timer0_voidInit_PWM();
	uint16 Local_u16Digital;
	while(1)
	{
		ADC_u16StartSingleConversionSynch(ADC0_SINGLE_ENDED,&Local_u16Digital);// convert analog value comming from the potentiometer using AN0 channel
		OCR0= Local_u16Digital; //Load the OCR0register with converted value from ADC
	}




}
