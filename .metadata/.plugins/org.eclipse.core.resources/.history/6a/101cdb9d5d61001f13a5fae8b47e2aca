/** ************************************************************
 * @file   ADC_prog.c
 *@brief   Implementation of Digital ADC functions.
 * @details This file contains the implementation of functions for configuring and manipulating the ADC module. Functions include initialization, starting conversions (synchronous and asynchronous), and handling ADC interrupts.
 * @author   Walid Megherbi
 *           <BR>
 *           <EM>
 *           Github: https://github.com/walid31000
 *           </EM>
 * @version   1.0.0
 * @date     31/5/2023
 * @copyright Walid Megherbi

 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "Err_Type.h"
#include "ADC_interface.h"
#include "ADC_prv.h"
#include "ADC_cfg.h"
#include "ADC_reg.h"


/** Global variables */
static uint16* ADC_pu16DigResult=NULL;//global array to save the result conversion of each channel

static void (*ADC_pvNotificationFunc)(void)=NULL;//global pointer to function to invoke the function notification
static uint8   ADC_u8BusyFlag=IDLE;// global flag to check the ADC status


static uint8 ADC_u8CurrentChannelIndex = 0;//variable to track the chanel index


const static ADC_Chain_t* ADC_chain_obj=NULL;//Global pointer to struct of type ADC_Chain_t

static uint8 ADC_u8ISRSource; //variable to track the interrupt source

/**
 * @brief Initializes the ADC module.
 * @details Configures the voltage reference, resolution, interrupt, prescaler, and enables the ADC.
 */

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

/**
 * @brief Starts an ADC conversion synchronously.
 * @param copy_u8Channel The ADC channel to convert.
 * @param copy_pu16DigResult Pointer to store the digital result.
 * @return Error state (OK, TIMEOUT_ERR, BUSY_ERR, NULL_PTR).
 */



uint8  ADC_u16StartSingleConversionSynch(ADC_Channel_t copy_u8Channel,uint16 *copy_pu16DigResult)
{

	uint8 Local_u8ErrorState=OK;


	if(copy_pu16DigResult!=NULL)
	{
		if(ADC_u8BusyFlag==IDLE)
		{

			uint32 Local_u32Counter=0u;//define counter inside the scope

			/*ADC is now busy*/
			ADC_u8BusyFlag=BUSY;

			/*set the required channel*/

			ADMUX &=CHANNEL_SELECTION_MASK  ; /*clear the channel selection bits*/
			ADMUX|=copy_u8Channel;


			/*start conversion*/
			SET_BIT(ADCSRA,ADCSRA_ADSC);

			/*wait (block) until conversion is completed or the timeout has not passed yet*/
			while(((GET_BIT(ADCSRA,ADCSRA_ADIF))==0)&& (Local_u32Counter<ADC_u32TIMEOUT_COUNT))
			{
				Local_u32Counter++;
			}

			if(Local_u32Counter==ADC_u32TIMEOUT_COUNT)
			{
				/*loop is broken because timeout has passed*/
				Local_u8ErrorState=TIMEOUT_ERR;
			}
			else /*loop is broken because flag has raised */
			{

				/*clear the conversion complete flag*/
				SET_BIT(ADCSRA,ADCSRA_ADIF);

#if ADC_u8RESOLUTION ==EIGHT_BITS

				*copy_pu16DigResult= (uint16)ADCH;
#elif ADC_u8RESOLUTION ==TEN_BITS
				*copy_pu16DigResult= ADC;
#endif

				/*Task is done ,ADC now is IDLE*/
				ADC_u8BusyFlag=IDLE;


			}

		}
		else
		{
			Local_u8ErrorState=BUSY_ERR;
		}
	}
	else
	{
		Local_u8ErrorState=NULL_PTR;
	}
	return Local_u8ErrorState;

}


/**
 * @brief Starts an ADC conversion asynchronously.
 * @param copy_u8Channel The ADC channel to convert.
 * @param copy_pu16DigResult Pointer to store the digital result.
 * @param copy_pvNotificationFunc Pointer to the notification function.
 * @return Error state (OK, BUSY_ERR, NULL_PTR).
 */

uint8  ADC_u16StartSingleConversionAsynch(ADC_Channel_t copy_u8Channel,uint16 *copy_pu16DigResult,void (*copy_pvNotificationFunc)(void))
{
	uint8 Local_u8ErrorState=OK;
	if((copy_pu16DigResult!=NULL) &&(copy_pvNotificationFunc!=NULL))
	{
		if(ADC_u8BusyFlag==IDLE)

		{

			/*ADC is now busy*/
			ADC_u8BusyFlag=BUSY;
			/*ISR source is single conversion asynch function */
			ADC_u8ISRSource=SINGLE_CONV_ASYNCH;

			/*convert digital result and notification function local variables into global*/

			ADC_pu16DigResult=copy_pu16DigResult;
			ADC_pvNotificationFunc=copy_pvNotificationFunc;



			/*set the required channel*/

			ADMUX &=CHANNEL_SELECTION_MASK  ; /*clear the channel selection bits*/
			ADMUX|=copy_u8Channel;


			/*start conversion*/
			SET_BIT(ADCSRA,ADCSRA_ADSC);

			/*Enable ADC conversion complete interrupt*/
			SET_BIT(ADCSRA,ADCSRA_ADIE);



		}
		else
		{
			Local_u8ErrorState=BUSY_ERR;

		}

	}
	else
	{

		return NULL_PTR;
	}


	return Local_u8ErrorState;


}


/**
 * @brief Starts a chain ADC conversion asynchronously.
 * @param copy_object Pointer to the ADC chain object.
 * @return Error state (OK, BUSY_ERR, NULL_PTR).
 */

uint8 ADC_u8StartChainConversionAsync(const ADC_Chain_t* copy_object)
{
	uint8 Local_u8ErrorState=OK;
	if(copy_object!=NULL)
	{

		if(ADC_u8BusyFlag==IDLE)
		{
			/*ADC is now busy*/
			ADC_u8BusyFlag=BUSY;

			/*ISR source is chain conversion asynch function */
			ADC_u8ISRSource=CHAIN_CONV_ASYNCH;

			/*Transform the local struct (copy_object)  into global */
			ADC_chain_obj=copy_object;

			ADC_u8CurrentChannelIndex=0u;

			/*set the first channel*/

			ADMUX &=CHANNEL_SELECTION_MASK  ; /*clear the channel selection bits*/
			ADMUX|=ADC_chain_obj->ChanelsArr[ADC_u8CurrentChannelIndex];


			/*start conversion*/
			SET_BIT(ADCSRA,ADCSRA_ADSC);

			/*Enable ADC conversion complete interrupt*/
			SET_BIT(ADCSRA,ADCSRA_ADIE);

		}
		else
		{
			Local_u8ErrorState=BUSY_ERR;
		}


	}
	else
	{

		return NULL_PTR;

	}


	return Local_u8ErrorState;
}
/**
 * @brief ADC conversion complete ISR.
 * @details This ISR handles the ADC conversion complete interrupt, stores the result, and invokes the notification function.
 */

/*ADC conversion complete ISR*/

void __vector_16 (void)  __attribute__((signal));
void __vector_16 (void)
{
	if(ADC_u8ISRSource==SINGLE_CONV_ASYNCH) //check the interrupt source first
	{

/* Read the conversion*/

#if ADC_u8RESOLUTION ==EIGHT_BITS

		*ADC_pu16DigResult= (uint16)ADCH;

#elif ADC_u8RESOLUTION ==TEN_BITS
		*ADC_pu16DigResult= ADC;
#endif

		/*ADC interrupt disable*/
		CLR_BIT(ADCSRA,ADCSRA_ADIE);

		/*Task is done ,ADC now is IDLE*/
		ADC_u8BusyFlag=IDLE;


		/*Invok the call back notification function*/

		if(ADC_pvNotificationFunc!=NULL)
		{
			ADC_pvNotificationFunc();
		}
		else
		{
			/*Do nothing*/
		}

	}
	else if(ADC_u8ISRSource==CHAIN_CONV_ASYNCH)
	{


		/*Read the conversion result*/

#if ADC_u8RESOLUTION ==EIGHT_BITS

		ADC_chain_obj->ResultArr[ADC_u8CurrentChannelIndex]= (uint16)ADCH;

#elif ADC_u8RESOLUTION ==TEN_BITS
		ADC_chain_obj->ResultArr[ADC_u8CurrentChannelIndex]= ADC;

#endif



		/*Increment conversion index*/

		ADC_u8CurrentChannelIndex++;

		if(ADC_u8CurrentChannelIndex == ADC_chain_obj->ChainSize)
		{
			/*All conversions are completed*/

			/*Task is done ,ADC now is IDLE*/
			ADC_u8BusyFlag=IDLE;

			/* ADC interrupt disable */
			CLR_BIT(ADCSRA, ADCSRA_ADIE);

			/*Invok the call back notification function*/

			if(ADC_chain_obj->NotificationFunc!=NULL)
			{
				ADC_chain_obj->NotificationFunc();
			}
			else
			{
				/*Do nothing*/
			}

		}

		else
		{
			/*chain is not finished yet*/
			/*set the next channel*/
			ADMUX &=CHANNEL_SELECTION_MASK  ; /*clear the channel selection bits*/
			ADMUX|=ADC_chain_obj->ChanelsArr[ADC_u8CurrentChannelIndex];

			SET_BIT(ADCSRA, ADCSRA_ADSC); /* Start conversion */





		}
	}
}


