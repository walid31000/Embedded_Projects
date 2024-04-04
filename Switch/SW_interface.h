#ifndef SSD_SWITCH_H
#define SSD_SWITCH_H



typedef enum
{
	PULL_UP,
	PULL_DOWN
}Pull_Type_t;

typedef enum
{
	pressed,realeased
}SW_State_t;



typedef struct
{
	Dio_Port_t   PORT;
	Dio_Pin_t    PIN;
	Pull_Type_t  pulling;
	
}SW_config_t;



uint8 SW_u8GetState(const SW_config_t* copySWObject,uint8* copy_SWState);











#endif
