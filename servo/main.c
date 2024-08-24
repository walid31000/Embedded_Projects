
/*function to control the servo according to angle needed*/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "Map.h"
#include "Err_Type.h"
#include "PORT_interface.h"
#include "DIO_interface.h"
#include "ADC_interface.h"
#include "Timer_interface.h"
#include "Timer_reg.h"

uint16 Local_u16Digital;
void main()
{
  uint8 Local_u8Angle_Nedded=30;
	PORT_voidIint();
	ADC_voidInit();


	 Timer1_voidInit();
	 Get_Servo_Angle(Local_u8Angle_Nedded);
	while(1)
	{

	}




}
