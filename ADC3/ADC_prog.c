#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "Err_Type.h"
#include "ADC_interface.h"
#include "ADC_cfg.h"
#include "ADC_reg.h"
#include "ADC_prv.h"





void ADC_voidInit(void)
{
	/*Refrence selection Avcc*/
	SET_BIT(ADMUX, ADMUX_REFS0);
	CLR_BIT(ADMUX, ADMUX_REFS1);

	/*Prepare left adjust for 8 bit mode*/
	SET_BIT(ADMUX,ADMUX_ADLAR);

	/*Prescaler setting*/
	ADCSRA &= PRSECALER_MASK; /*clear the prescaler bit*/
	ADCSRA|=ADC_u8PRESCALER ;

	/*ADC Enable*/
	SET_BIT(ADCSRA,  ADCSRA_ADEN);



}
uint8 ADC_GetChanelReading(ADC_Chanel_t copy_Chanel)
{
	/*set the required channel*/
	ADMUX &=0b11100000;  /*clear channel's bit*/
	ADMUX |=copy_Chanel;


  /*start conversion*/
	SET_BIT(ADCSRA,  ADCSRA_ADSC);
	/*pooling with blocking*/
	while(GET_BIT(ADCSRA,ADCSRA_ADIF)==0);
	/*Clear the flag*/
    SET_BIT(ADCSRA,ADCSRA_ADIF);
    /*Read the data*/
    return ADCH;

}
