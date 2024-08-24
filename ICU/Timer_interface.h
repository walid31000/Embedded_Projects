#ifndef TIMER_INTERFACE_H
#define TIMER_INTERFACE_H



void Timer_voidInit(void);// Normal overflow mode
void Timer_voidInit_CTC(void); // CTC mode
uint8 TIMER_u8SetCallBack(void(*copy_pvFuncPtr)(void));

void Timer0_voidInit_PWM(void);

void TIMER0_void_SetCompVal(uint8 copy_u8CompVal);

void TIMER1_void_Init(void);
uint16 TIMER1_u16GetTimerVal(void);
void TIMER1_voidSetTimerVal(uint16 copy_u16Val);





#endif
