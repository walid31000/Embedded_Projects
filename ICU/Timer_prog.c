/*Test overflow timer mode*/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "Err_Type.h"
#include "Timer_prv.h"
#include "Timer_cfg.h"

#include "Timer_interface.h"




#include "Timer_reg.h"





static void (*TIMER_pfuncptr)(void)=NULL;

void Timer0_voidInit_PWM(void)
{

	/*choose PWM mode */
	SET_BIT(TCCR0,TCCR0_WGM01);
	SET_BIT(TCCR0,TCCR0_WGM00);

/*output compare mode :OC0 :Set on top clear on compare*/
CLR_BIT(TCCR0,TCCR0_COM00);
SET_BIT(TCCR0,TCCR0_COM01);


/*output compare value =64*/
OCR0=64;

/*choose prescaler 64*/

TCCR0 &=PRESCALER_MESK; /*clear the bits CS0,1,2*/
TCCR0|=TIMER_PRESCALER;



}


uint16 TIMER1_u16GetTimerVal(void)
{
	return TCNT1;
}

void TIMER0_void_SetCompVal(uint8 copy_u8CompVal)
{
	OCR0=copy_u8CompVal;
}

void TIMER1_void_Init(void)
{
	/*Normal mode (the default mode)*/
	CLR_BIT(TCCR1A,TCCR1A_WGM10);
	CLR_BIT(TCCR1A,TCCR1A_WGM11);

	CLR_BIT(TCCR1B,TCCR1B_WGM12);
	CLR_BIT(TCCR1B,TCCR1B_WGM13);

	/*choose prescaler 64*/

	TCCR1B &=PRESCALER_MESK; /*clear the bits CS0,1,2*/
	TCCR1B|=TIMER_PRESCALER;
}

void TIMER1_voidSetTimerVal(uint16 copy_u16Val)
{
	TCNT1=copy_u16Val;
}
uint8 TIMER0_u8SetCallBack(void(*copy_pvFuncPtr)(void))
{
	uint8 Local_u8Errorstate=OK;
	if(copy_pvFuncPtr!=NULL)
	{
		TIMER_pfuncptr=copy_pvFuncPtr;


	}
	else
	{
		return NULL_PTR;
	}

	return Local_u8Errorstate;

}

