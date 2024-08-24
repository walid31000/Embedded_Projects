/**
 * @file ADC_reg.h
 * @brief Register definitions for ADC module.
 * @details This file contains the register definitions and bit positions for configuring and controlling the ADC module.
 * @version 1.0.0
 * @date 31/5/2023
 * Author Walid Megherbi
 * @copyright Walid Megherbi
 */

#ifndef ADC_REG_H
#define ADC_REG_H

/** ADC multiplexer selection register */

#define    ADMUX                  *((volatile uint8*)0X27)  /*ADC multiplexer selection register */

/** Bit positions in ADMUX register */

#define ADMUX_REFS1 7U /**< Reference selection bit 1 */
#define ADMUX_REFS0 6U /**< Reference selection bit 0 */
#define ADMUX_ADLAR 5U /**< Left adjust result */
#define ADMUX_MUX4  4U /**< MUX bit 4 */
#define ADMUX_MUX3  3U /**< MUX bit 3 */
#define ADMUX_MUX2  2U /**< MUX bit 2 */
#define ADMUX_MUX1  1U /**< MUX bit 1 */
#define ADMUX_MUX0  0U /**< MUX bit 0 */

/** ADC control and status register A */

#define ADCSRA *((volatile uint8*)0X26)

/** Bit positions in ADCSRA register */

#define ADCSRA_ADEN  7U /**< ADC enable */
#define ADCSRA_ADSC  6U /**< ADC start conversion */
#define ADCSRA_ADATE 5U /**< ADC auto trigger enable */
#define ADCSRA_ADIF  4U /**< ADC interrupt flag */
#define ADCSRA_ADIE  3U /**< ADC interrupt enable */
#define ADCSRA_ADPS2 2U /**< ADC prescaler select bit 2 */
#define ADCSRA_ADPS1 1U /**< ADC prescaler select bit 1 */
#define ADCSRA_ADPS0 0U /**< ADC prescaler select bit 0 */

/** ADC data registers */

#define ADCH *((volatile uint8*)0X25) /**< ADC data high register */
#define ADCL *((volatile uint8*)0X24) /**< ADC data low register */
#define ADC  *((volatile uint16*)0X24) /**< ADC data register (10 bits) */

#endif /* ADC_REG_H */
