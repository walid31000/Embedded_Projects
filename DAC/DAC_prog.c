#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "Err_Type.h"
#include "DIO_interface.h"

#include "DAC_interface.h"
#include "DAC_CFG.h"



uint8 DAC_voidSetAnalogVolt(uint16 copy_u16Volt)
{
	uint8 Local_u8Step;
	uint8 Local_u8Digital;


/*calculate the step*/
	Local_u8Step=5000/256;/*step=ref_voltage/resolution 2^8*/
	/*calculate the Digital*/
	//Local_u8Digital=(uint8)(copy_u16Volt/19);
	Local_u8Digital=(uint8)((copy_u16Volt*256)/5000);
    return Local_u8Digital;
}
