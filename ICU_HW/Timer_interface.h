#ifndef TIMER_INTERFACE_H
#define TIMER_INTERFACE_H


#define  RISING_EDGE           1U

#define  FALLING_EDGE           2U

void Timer_voidInit(void);// Normal overflow mode
void Timer_voidInit_CTC(void); // CTC mode
uint8 ICU_HW_SetCallBack(void(*copy_pvFuncPtr)(void));

void Timer0_voidInit_PWM(void);

void TIMER0_void_SetCompVal(uint8 copy_u8CompVal);

void TIMER1_void_Init(void);
uint16 TIMER1_u16GetTimerVal(void);
void TIMER1_voidSetTimerVal(uint16 copy_u16Val);
void ICU_Set_SenseCtrl(uint8 copy_u8SenseCtrl);
void ICU_HW_void_Init(void);
void ICU_DisableINT(void);
void ICU_EnableINT(void);
uint16 TIMER1_u16GetICR1_Val(void);




#endif
