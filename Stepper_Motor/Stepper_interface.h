#ifndef STEPPER_INTERFACE_H
#define STEPPER_INTERFACE_H



typedef struct
{

	Dio_Port_t     PORT_STEPPER;
	Dio_Pin_t      BLEU_PIN;
	Dio_Pin_t      PINK_PIN;
	Dio_Pin_t      YELLOW_PIN;
	Dio_Pin_t      ORANGE_PIN;

}Stepper_config_t;


void Stepper_voidComp_Rotation(Stepper_config_t* Stepper_Object);













#endif
