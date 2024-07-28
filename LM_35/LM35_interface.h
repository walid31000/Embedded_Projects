#ifndef LM35_INTERFACE_H
#define LM35_INTERFACE_H
#include "ADC_interface.h"
//#include "ADC_prv.h"
//#include "ADC_cfg.h"





// Configuration structure for LM35
typedef struct
{
	ADC_Channel_t  LM_35_CH;
	uint16 Max_volt;


} LM35_config_t;






uint8 LM35_u8GetTemp(LM35_config_t *copy_LM35_Obj,uint8 *Temp_Reading);




#endif
