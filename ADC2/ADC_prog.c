#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "Err_Type.h"
#include "ADC_interface.h"
#include "ADC_prv.h"
#include "ADC_cfg.h"
#include "ADC_reg.h"


static uint16* ADC_pu16DigResult=NULL;
static void (*ADC_pvNotificationFunc)(void)=NULL;
static uint8   ADC_u8BusyFlag=IDLE;


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


uint8  ADC_u16StartConversionSynch(ADC_Channel_t copy_u8Channel,uint16 *copy_pu16DigResult)
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



uint8  ADC_u16StartConversionAsynch(ADC_Channel_t copy_u8Channel,uint16 *copy_pu16DigResult,void (*copy_pvNotificationFunc)(void))
{
	uint8 Local_u8ErrorState=OK;
	if((copy_pu16DigResult!=NULL) &&(copy_pvNotificationFunc!=NULL))
	{
		if(ADC_u8BusyFlag==IDLE)

		{

            /*ADC is now busy*/
			ADC_u8BusyFlag=BUSY;


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


/*ADC conversion complete ISR*/

void __vector_16 (void)  __attribute__((signal));
void __vector_16 (void)
{
#if ADC_u8RESOLUTION ==EIGHT_BITS

	*ADC_pu16DigResult= (uint16)ADCH;
#elif ADC_u8RESOLUTION ==TEN_BITS
	*ADC_pu16DigResult= ADC;
#endif

	/*ADC interuupt disable*/
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


