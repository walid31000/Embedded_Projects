#ifndef CLCD_INTERFACE_H
#define CLCD_INTERFACE_H

void CLCD_voidSendCommand (uint8 copy_u8Command);
void CLCD_voidSendData (uint8 copy_u8Data);
void CLCD_voidInit (void);

uint8 CLCD_u8SendString (const char *copy_Chstring);
void CLCD_voidSendNumber (sint32 copy_s32Number);
void CLCD_voidGoToXY (uint8 copy_u8Xpos,uint8 copy_u8Ypos);
uint8 CLCD_u8WriteSpecialCharacter(uint8 copy_u8PatternNumber,uint8 copy_pu8PatternArr[],uint8 copy_u8Xpos,uint8 copy_u8Ypos);
//sint32  CLCD_voidCalc(sint32 Local_s32Num1,sint32 Local_s32Num2);
void  CLCD_voidCalc(void);

#endif 
