#ifndef ADC_REGISTER_H_
#define ADC_REGISTER_H_

#define ADMUX            *((volatile uint8*) 0X27)  /*ADC multiplexer selection register */
#define ADMUX_REFS1       7                          /*Refrence selection Bit1 */
#define ADMUX_REFS0       6                          /*Refrence selection Bit0 */
#define ADMUX_ADLAR       5                          /*Left adjust result */


#define ADCSRA            *((volatile uint8*) 0X26)  /*ADC controland ststus register A */
#define ADCSRA_ADEN         7                        /*Enable*/
#define ADCSRA_ADSC         6                        /*Start conversion*/
#define ADCSRA_ADATE        5                        /*Auto trigger Enable*/
#define ADCSRA_ADIF         4                        /*Interrupt flag*/
#define ADCSRA_ADIE         3                        /*Interrupt Enable*/


#define ADCH            *((volatile uint8*) 0X25)  /*Data high register */
#define ADCL            *((volatile uint8*) 0X24)  /*Data low register */
#define ADC            *((volatile uint8*) 0X24)  /*ADC Data register */


#endif
