#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "Err_type.h"

#include "ADC_interface.h"
#include "ADC_prv.h"
#include "ADC_cfg.h"
#include "ADC_reg.h"



void ADC_voidInit (void)
{
	/*Reference selection :AVCC pin   */
	SET_BIT(ADMUX, ADMUX_REFS0);
	CLR_BIT(ADMUX, ADMUX_REFS1);

#if ADC_u8RESOLUTION ==EIGHT_BITS
	SET_BIT(ADMUX, ADMUX_ADLAR);
#elif ADC_u8RESOLUTION ==TEN_BITS
	CLR_BIT(ADMUX, ADMUX_ADLAR);
#else
#error wrong ADC_u8RESOLUTION configuration value
#endif
	/*Activate left adjust result for 8 bits resolution */
	SET_BIT(ADMUX ,ADMUX_ADLAR);
  /*check on prescaler configuration setting */
	ADCSRA &=PRESCALER_MASK;  /*clear the prescaler bit*/
	ADCSRA |= ADC_u8PRESCALER;


	/*ADC Enable */
	SET_BIT (ADCSRA,ADCSRA_ADEN);

}
uint16 ADC_u16GetChannelReading (ADC_Channel_t copy_Channel)
{
  /*Set the required channel */
	ADCSRA &=CHANNEL_SELECTION_MASK ;/*clear the channel selection bits */
	ADCSRA |=copy_Channel;
	/* Start conversion*/
	SET_BIT(ADCSRA,ADCSRA_ADSC);
	/*wait (block) until conversion is completed*/
	while((GET_BIT(ADCSRA,ADCSRA_ADIF))==0);

	/*clear the conversion complete flag*/
	SET_BIT(ADCSRA,ADCSRA_ADIF);
#if ADC_u8RESOLUTION == EIGHT_BITS
	return (uint16)ADCH;

#elif ADC_u8RESOLUTION == TEN_BITS
	return ADC;
#endif


}
