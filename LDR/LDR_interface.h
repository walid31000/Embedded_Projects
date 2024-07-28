#ifndef LDR_INTERFACE_H
#define LDR_INTERFACE_H


typedef struct
{
	    ADC_Channel_t  LDR_CH;
		uint16 Max_volt;

}LDR_Config_t;

uint8 LDR_GetLightLevel(LDR_Config_t* LDR_obj,uint8 *copy_u8LightLevel);









#endif
