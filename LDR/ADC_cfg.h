#ifndef ADC_CFG_H
#define ADC_CFG_H

/*select voltage refrence option:1-AREF
 *                               2-AVCC
 *                               3-Two_point_fiftysix
 *
 *
 * */
#define  ADC_u8VolatageRefrence        AVCC


/*configure ADC prescaler division factors :1-DIVISION_BY_2
 *                                          2-DIVISION_BY_4
 *                                          3-DIVISION_BY_8
 *                                          4-DIVISION_BY_16
 *                                          5-DIVISION_BY_32
 *                                          6-DIVISION_BY_64
 *                                          7-DIVISION_BY_128*/


#define ADC_u8PRESCALER                DIVISION_BY_128

/*Cofigure ADC Resolution Options:1-EIGHT_BITS
 *                                2-TEN_BITS
 *
 *
*/

#define ADC_u8RESOLUTION           TEN_BITS

/*ADC autotrigger options:1-ENABLE
 *                         2-DISABLED*/

#define ADC_u8Auto_Trigger    DISABLED


/*Configure the interrupt Enable options:1-ENABLED
 *                                       2-DISABLED
 * */
#define  ADC_u8INT_EN                DISABLED



#endif
