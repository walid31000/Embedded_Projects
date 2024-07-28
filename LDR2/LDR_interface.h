#ifndef LDR_INTERFACE_H
#define LDR_INTERFACE_H


typedef struct
{
	    ADC_Channel_t  LDR_CH;
		uint16 Max_volt;
		uint8  Light_Level;

}LDR_Config_t;

uint8 LDR_GetLightLevel(LDR_Config_t* copy_LDR_obj,sint8 *Local_u8LightLevel);









#endif
