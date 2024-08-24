/*Test overflow timer mode*/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "Err_Type.h"
#include "Timer_prv.h"
#include "Timer_cfg.h"

#include "Timer_interface.h"




#include "Timer_reg.h"







void Timer0_voidInit_PWM(void)
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
