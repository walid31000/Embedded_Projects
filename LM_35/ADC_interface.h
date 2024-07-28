#ifndef ADC_INTERFACE_H
#define ADC_INTERFACE_H

#include "ADC_cfg.h"


typedef enum
{
	ADC0_SINGLE_ENDED=0,
	ADC1_SINGLE_ENDED,
	ADC2_SINGLE_ENDED,
	ADC3_SINGLE_ENDED,
	ADC4_SINGLE_ENDED,
	ADC5_SINGLE_ENDED,
	ADC6_SINGLE_ENDED,
	ADC7_SINGLE_ENDED,
	ADC0_POS_ADC0_NEG_10X_GAIN,
	ADC1_POS_ADC0_NEG_10X_GAIN


}ADC_Channel_t;

void ADC_voidInit(void);
uint16  ADC_u16GetChannelReading(ADC_Channel_t copy_u8Channel);











#endif
