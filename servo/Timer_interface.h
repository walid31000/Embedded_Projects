#ifndef TIMER_INTERFACE_H
#define TIMER_INTERFACE_H



void Timer_voidInit(void);// Normal overflow mode
void Timer_voidInit_CTC(void); // CTC mode
uint8 TIMER_u8SetCallBack(void(*copy_pvFuncPtr)(void));

void Timer_voidInit_PWM(void);

void Timer1_voidInit(void);

void Get_Servo_Angle(uint8 Angle);

void Map_ADC_Potentiometer(uint16 copy_u16Digital_Reading);





#endif
