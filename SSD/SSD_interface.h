#ifndef SSD_INTERFACE_H
#define SSD_INTERFACE_H


typedef enum
{
	ANODE,
	CATHODE
	
}Type_t;





typedef struct
{
	Type_t Type;              //type of SSD common cathode or common anode
	Dio_Port_t PORT;         //PORT connected to ssd
	Dio_Port_t Enable_Port; //port contain enable pin (common)
	Dio_Pin_t Enable_PIN;  // common pin
	
}SSD_Config_t;








uint8 SSD_u8SetNumber(const SSD_Config_t* copy_SSD_Config,uint8 copy_u8Number);
uint8 SSD_u8EnableSSD(const SSD_Config_t* copy_SSD_Config);
uint8 SSD_u8DisableSSD(const SSD_Config_t* copy_SSD_Config);

#endif
