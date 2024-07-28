#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "Err_Type.h"
#include "ADC_interface.h"
#include "ADC_prv.h"
#include "ADC_cfg.h"
#include "ADC_reg.h"






void ADC_voidInit(void)
{
	/*Refrence selection */
#if ADC_u8VolatageRefrence ==AVCC
	SET_BIT(ADMUX,ADMUX_REFS0);
	CLR_BIT(ADMUX,ADMUX_REFS1);

#elif ADC_u8VolatageRefrence==AREF
	CLR_BIT(ADMUX,ADMUX_REFS0);
	CLR_BIT(ADMUX,ADMUX_REFS1);

#elif 	ADC_u8VolatageRefrence==Two_point-fiftysix
	SET_BIT(ADMUX,ADMUX_REFS0);
	SET_BIT(ADMUX,ADMUX_REFS1);

#else
#error wrong ADC_u8VolatageRefrence configuration option
#endif


#if ADC_u8RESOLUTION ==EIGHT_BITS
	SET_BIT(ADMUX,ADMUX_ADLAR);
#elif  ADC_u8RESOLUTION ==TEN_BITS
	   CLR_BIT(ADMUX,ADMUX_ADLAR);



#else
#error "WRONG ADC_u8RESOLUTION configuration value"
#endif

/*check ADC interrupt */
#if ADC_u8INT_EN==ENABLED
	SET_BIT(ADCSRA,ADCSRA_ADIE);
#elif ADC_u8INT_EN==DISABLED
	CLR_BIT(ADCSRA,ADCSRA_ADIE);
#else
#error wrong ADC_u8INT_EN configuration option
#endif


	/*check on prescaler configuration  setting*/

	ADCSRA &=PRESCALER_MASK;   /*clear the prescaler bits*/
	ADCSRA |=ADC_u8PRESCALER;


	/*ADC enable*/
	SET_BIT(ADCSRA,ADCSRA_ADEN);

}


uint16  ADC_u16GetChannelReading(ADC_Channel_t copy_u8Channel)
{

	/*set the required channel*/

	ADMUX &=CHANNEL_SELECTION_MASK  ; /*clear the channel selection bits*/
	ADMUX|=copy_u8Channel;


	/*start conversion*/
	SET_BIT(ADCSRA,ADCSRA_ADSC);

	/*wait (block) until conversion is completed*/
	while((GET_BIT(ADCSRA,ADCSRA_ADIF))==0);

	/*clear the conversion complete flag*/
	SET_BIT(ADCSRA,ADCSRA_ADIF);

#if ADC_u8RESOLUTION ==EIGHT_BITS

	return (uint16)ADCH;
#elif ADC_u8RESOLUTION ==TEN_BITS
	return ADC;
#endif
}
