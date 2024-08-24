/*Test overflow timer mode*/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "Err_Type.h"
#include "Map.h"
#include "ADC_interface.h"

#include "Timer_prv.h"
#include "Timer_cfg.h"

#include "Timer_interface.h"




#include "Timer_reg.h"







void Timer_voidInit_PWM(void)
{

	/*choose PWM mode */
	SET_BIT(TCCR0,TCCR0_WGM01);
	SET_BIT(TCCR0,TCCR0_WGM00);

/*output compare mode :OC0 :Set on top clear on compare*/
CLR_BIT(TCCR0,TCCR0_COM00);
SET_BIT(TCCR0,TCCR0_COM01);

/*choose prescaler 64*/

TCCR0 &=PRESCALER_MESK; /*clear the bits CS0,1,2*/
TCCR0|=TIMER_PRESCALER;



}

void Timer1_voidInit(void)
{


	/*choose waveform generation mode 14 fast pwm mode*/
	CLR_BIT(TCCR1A,TCCR1A_WGM10);
	SET_BIT(TCCR1A,TCCR1A_WGM11);
	SET_BIT(TCCR1B,TCCR1B_WGM12);
	SET_BIT(TCCR1B,TCCR1B_WGM13);

	/*Enable OC1A mode:set on top clear on compare*/
		SET_BIT(TCCR1A,TCCR1A_COM1A1);
		CLR_BIT(TCCR1A,TCCR1A_COM1A0);

	/*choose prescaler 8*/

	TCCR1B  &=PRESCALER_MESK; /*clear the bits CS0,1,2*/
	TCCR1B |=TIMER_PRESCALER;
	/*compare value*/
	//OCR1A=OCR_Val;


	/*Top value*/
	ICR1=20000;

}

/*function to control the servo according to angle needed*/
void Get_Servo_Angle(uint8 Angle)
{
	OCR1A=Map(0,180,450,2500,Angle);


}


/*function to map between adc reading and servo angle*/

void Map_ADC_Potentiometer(uint16 copy_u16Digital_Reading)
{
	OCR1A=Map(0,1023,450,2500,copy_u16Digital_Reading);


}

