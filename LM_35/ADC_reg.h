#ifndef ADC_REG_H
#define ADC_REG_H


#define    ADMUX                  *((volatile uint8*)0X27)  /*ADC multiplexer selection register */
#define    ADMUX_REFS1                 7U     /*Refrence selection Bit1 */
#define    ADMUX_REFS0                 6U     /*Refrence selection Bit0 */
#define    ADMUX_ADLAR                 5U      /*Left adjust result */
#define    ADMUX_MUX4                 4U
#define    ADMUX_MUX3                 3U
#define    ADMUX_MUX2                 2U
#define    ADMUX_MUX1                 1U
#define    ADMUX_MUX0                 0U



#define    ADCSRA                  *((volatile uint8*)0X26)  /*ADC control and status register A */
#define    ADCSRA_ADEN                7U                    /*Enable*/
#define    ADCSRA_ADSC                6U                      /*Start conversion*/
#define    ADCSRA_ADATE                5U                     /*Auto trigger Enable*/
#define    ADCSRA_ADIF                4U                     /*Interrupt flag*/
#define    ADCSRA_ADIE                3U                       /*Interrupt Enable*/
#define    ADCSRA_ADPS2                2U
#define    ADCSRA_ADPS1                1U
#define    ADCSRA_ADPS0                0U





#define    ADCH                  *((volatile uint8*)0X25) /*data high register*/
#define    ADCL                 *((volatile uint8*)0X24)   /*Data low register*/
#define    ADC                 *((volatile uint16*)0X24)  /*ADC data register pointer for 10bits register*/








#endif
