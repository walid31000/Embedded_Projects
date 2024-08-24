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

#include "GIE_interface.h"
#include "CLCD_interface.h"


volatile uint16 ICU_Reading1=0u,ICU_Reading2=0u,ICU_Reading3=0u;


void ICU_HW(void);

void main()
{
	PORT_voidIint();


	CLCD_voidInit();
	Timer0_voidInit_PWM();
	ICU_HW_void_Init();

	ICU_HW_SetCallBack(&ICU_HW);



	GIE_voidEnableGlobal();

	while(1)
	{
		/* wait until values are set*/
		while((ICU_Reading1==0)|| (ICU_Reading2==0)||(ICU_Reading3==0));
		CLCD_voidGoToXY(0,0);
		CLCD_voidSendNumber((ICU_Reading2-ICU_Reading1)*4); //periode time ticks
		CLCD_voidGoToXY(0,1);
		CLCD_voidSendNumber(4*(ICU_Reading3-ICU_Reading2));//On Time ticks
	}



}


void ICU_HW(void)
{
	static volatile uint8 Local_u8Counter=0;
	Local_u8Counter++;
	if(Local_u8Counter==1)
	{
		/*Read ICR1*/
		ICU_Reading1=TIMER1_u16GetICR1_Val();


	}
	else if(Local_u8Counter==2)
	{
		/*read timer1*/
		ICU_Reading2=TIMER1_u16GetICR1_Val();//periode time ticks

		/*change trigger source to falling edge*/
		ICU_Set_SenseCtrl(FALLING_EDGE);
	}
	else if(Local_u8Counter==3)
	{
		ICU_Reading3=TIMER1_u16GetICR1_Val();//periode time ticks+On Time ticks
        /*Disable interrupt*/
		ICU_DisableINT();

	}




}
