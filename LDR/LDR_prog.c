#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "Err_Type.h"
#include "Dio_interface.h"
#include "ADC_prv.h"
#include "ADC_interface.h"
#include "ADC_cfg.h"
#include "LDR_interface.h"

#include "LDR_prv.h"
#include "LDR_cfg.h"








// Define ADC resolution constants
    	#define ADC_RES_EIGHT_BITS   256UL
    	#define ADC_RES_TEN_BITS     1024UL





uint8 LDR_GetLightLevel(LDR_Config_t* copy_LDR_obj,uint8 *copy_u8LightLevel)
{
	  uint8 Local_u8Errorstate=OK;
	  uint16 Local_u16Digital;
	  uint32 ADC_u8RES;

  if(copy_LDR_obj!=NULL)
  {
	  // Determine the ADC resolution value based on the config file
	         #if ADC_u8RESOLUTION == EIGHT_BITS
	             ADC_u8RES = ADC_RES_EIGHT_BITS;
	         #elif ADC_u8RESOLUTION == TEN_BITS
	             ADC_u8RES = ADC_RES_TEN_BITS;
	         #else
	             // Handle invalid resolution case
	 #error    "ERROR configuration"
	         #endif

	         Local_u16Digital = ADC_u16GetChannelReading(copy_LDR_obj->LDR_CH);

	 /*save the result in Temp_Reading variable using derefrencing */

	         *copy_u8LightLevel = (uint8)(((uint32)Local_u16Digital * 5000UL) / ADC_u8RES);



  }
  else
  {
	  return NULL_PTR;
  }
  return Local_u8Errorstate;

}
