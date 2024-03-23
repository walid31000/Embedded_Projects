#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "Err_TYPE.h"
#include <util/delay.h>
#include "DIO_interface.h"
#include "CLCD_interface.h"
#include "CLCD_CFG.h"
#include "CLCD_PRV.h"

#if  CLCD_u8CONNECTION_MODE ==FOUR_BIT

static void void_SendHalfData(uint8 copy_u8HalfDataPort)
{
	DIO_u8SetPinValue(CLCD_u8DATA_PORT,CLCD_u8DB4_PIN,GET_BIT(copy_u8HalfDataPort,0));
	DIO_u8SetPinValue(CLCD_u8DATA_PORT,CLCD_u8DB5_PIN,GET_BIT(copy_u8HalfDataPort,1));
	DIO_u8SetPinValue(CLCD_u8DATA_PORT,CLCD_u8DB6_PIN,GET_BIT(copy_u8HalfDataPort,2));
	DIO_u8SetPinValue(CLCD_u8DATA_PORT,CLCD_u8DB7_PIN,GET_BIT(copy_u8HalfDataPort,3));
}
#endif
static void void_SendEnablePulse(void)
{
	DIO_u8SetPinValue(CLCD_u8CTRL_PORT,CLCD_u8E_PIN,DIO_PIN_HIGH );
	_delay_ms(2);
	DIO_u8SetPinValue(CLCD_u8CTRL_PORT,CLCD_u8E_PIN,DIO_PIN_LOW );

}
void CLCD_voidSendCommand(uint8 copy_u8Command)
{
	/*1-set RS pin to low for command */
	DIO_u8SetPinValue(CLCD_u8CTRL_PORT,CLCD_u8RS_PIN,DIO_PIN_LOW );
	/*2-set RW pin to low to write */
#if CLCD_u8RS_PIN ==ENABLED
	DIO_u8SetPinValue(CLCD_u8CTRL_PORT,CLCD_u8RW_PIN,DIO_PIN_LOW );
#endif
	/*3-send the command*/
#if CLCD_u8CONNECTION_MODE == EIGHT_BIT

	DIO_u8SetPortValue(CLCD_u8DATA_PORT,copy_u8Command);
	/*4-send enable pulse*/
	void_SendEnablePulse();
#elif CLCD_u8CONNECTION_MODE ==FOUR_BIT
	/*send the 4 higher bit*/
	void_SendHalfData(copy_u8Command>>4);
	void_SendEnablePulse();
  /*send the 4 lower bit of the command*/
	void_SendHalfData(copy_u8Command);
	void_SendEnablePulse();
#endif
}
void CLCD_voidSendData(uint8 copy_u8Data)
{
	/*1-set RS pin to high for data */
	DIO_u8SetPinValue(CLCD_u8CTRL_PORT,CLCD_u8RS_PIN,DIO_PIN_HIGH );
	/*2-set RW pin to low to write */
#if CLCD_u8RS_PIN ==ENABLED
	DIO_u8SetPinValue(CLCD_u8CTRL_PORT,CLCD_u8RW_PIN,DIO_PIN_LOW );
#endif
	/*3-send the data*/
#if CLCD_u8CONNECTION_MODE == EIGHT_BIT

	DIO_u8SetPortValue(CLCD_u8DATA_PORT,copy_u8Data);
	/*4-send enable pulse*/
	void_SendEnablePulse();
#elif CLCD_u8CONNECTION_MODE ==FOUR_BIT
	/*send the 4 higher bit*/
	void_SendHalfData(copy_u8Data>>4);
	void_SendEnablePulse();
  /*send the 4 lower bit of the command*/
	void_SendHalfData(copy_u8Data);
	void_SendEnablePulse();
#endif
}
void CLCD_voidInit(void)
{
	/*wait for more than 30 ms*/
	_delay_ms(2);
	/*function set*/
#if CLCD_u8CONNECTION_MODE == EIGHT_BIT

	CLCD_voidSendCommand(0b00111000);
#elif CLCD_u8CONNECTION_MODE ==FOUR_BIT
	void_SendHalfData(0b0010);
	void_SendEnablePulse();
	void_SendHalfData(0b0010);
	void_SendEnablePulse();
	void_SendHalfData(0b1000);

	void_SendEnablePulse();
#endif
	/*Display on off control*/
	CLCD_voidSendCommand(0b00001100);
	/*Display clear*/
	CLCD_voidSendCommand(1);

}
uint8 CLCD_u8SendString(const char *copy_chString)
{
	uint8 Local_u8ErrorStat=OK;
	if(copy_chString!=NULL)
	{
		while(*copy_chString!='\0')
		{
			CLCD_voidSendData(*copy_chString);
			copy_chString++;

		}

	}
	else
	{
		return NULL_PTR;
	}

	return Local_u8ErrorStat;

}
void CLCD_voidSendNumber(uint32 copy_u32Number)
{
	uint8  Local_u8Arr[20],Local_u8Iterator1;
	sint8 Local_u8Iterator2;
	if(copy_u32Number==0)
	{
		CLCD_voidSendData('0');
		return;
	}
	else if(copy_u32Number<0)
	{
		CLCD_voidSendData('-');
		copy_u32Number *=-1;
	}

	while(copy_u32Number)
	{
		Local_u8Arr[Local_u8Iterator1]=(uint8)((uint32)(copy_u32Number%10)+'0');
		copy_u32Number/=10;
		Local_u8Iterator1++;

	}
	for(Local_u8Iterator2=(sint8)(Local_u8Iterator1-1);Local_u8Iterator2>=0;Local_u8Iterator2--)
	{
		CLCD_voidSendData(Local_u8Arr[Local_u8Iterator2]);
	}


}
