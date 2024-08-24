/**
 * @file ADC_interface.h
 * @brief Interface file for ADC module.
 * @details This file contains the function prototypes and data structures needed for interacting with the ADC module.
 * @version 1.0.0
 * @date 31/5/2023
 * @author Walid Megherbi
 * @copyright Walid Megherbi
 */

#ifndef ADC_INTERFACE_H
#define ADC_INTERFACE_H

/** ADC Channels enumeration */

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


/** ADC Chain structure */
typedef struct {
    uint8 ChainSize;                  /**< Size of the ADC chain */
    ADC_Channel_t* ChanelsArr;        /**< Array of ADC channels */
    uint16* ResultArr;                /**< Array to store the results */
    void (*NotificationFunc)(void);   /**< Callback function */
} ADC_Chain_t;


/** Function Prototypes */

void ADC_voidInit(void);
uint8  ADC_u16StartSingleConversionSynch(ADC_Channel_t copy_u8Channel,uint16 *copy_pu16DigResult);
uint8  ADC_u16StartSingleConversionAsynch(ADC_Channel_t copy_u8Channel,uint16 *copy_pu16DigResult,void (*copy_pvNotificationFunc)(void));
uint8 ADC_u8StartChainConversionAsync(const ADC_Chain_t* copy_object);











#endif
