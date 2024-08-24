/*
 *
 *
 * */

#include "STD_TYPES.h"
#include "BIT_MATH.h"


#include "Err_Type.h"
#include "PORT_interface.h"
#include "DIO_interface.h"

#include "Timer_interface.h"
#include "Timer_reg.h"
#include "EXTI_interface.h"
#include "GIE_interface.h"
#include "CLCD_interface.h"


volatile uint16 ICU_Reading1=0u,ICU_Reading2=0u;


void ICU_SW(void);

void main()
{
	PORT_voidIint();
	EXTI_voidInit();

	CLCD_voidInit();
	Timer0_voidInit_PWM();
	TIMER1_void_Init();

	EXTI_u8SetCallBack(INT0,&ICU_SW);



	GIE_voidEnableGlobal();

	while(1)
	{
		/* wait until values are set*/
		while((ICU_Reading1==0)|| (ICU_Reading2==0));
		CLCD_voidGoToXY(0,0);
		CLCD_voidSendNumber(ICU_Reading1);
		CLCD_voidGoToXY(0,1);
		CLCD_voidSendNumber(ICU_Reading2-ICU_Reading1);//On Time ticks
	}



}


void ICU_SW(void)
{
	static volatile uint8 Local_u8Counter=0;
	Local_u8Counter++;
	if(Local_u8Counter==1)
	{
		/*clear Timer*/
		DIO_u8SetPinValue(DIO_PORTC,DIO_PIN0,DIO_PIN_HIGH);


		TIMER1_voidSetTimerVal(0);

	}
	else if(Local_u8Counter==2)
	{
		/*read timer1*/
		ICU_Reading1=TIMER1_u16GetTimerVal();//periode time ticks

		/*change trigger source to falling edge*/
		EXTI_u8SetSenseCtrl(INT0,FALLING_EDGE);
	}
	else if(Local_u8Counter==3)
	{
		ICU_Reading2=TIMER1_u16GetTimerVal();//periode time ticks+On Time ticks
		EXTI_u8IntDisable(INT0);
		DIO_u8SetPinValue(DIO_PORTC,DIO_PIN0,DIO_PIN_HIGH);

	}




}
