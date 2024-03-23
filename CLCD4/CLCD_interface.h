#ifndef CLCD_INTERFACE_H
#define CLCD_INTERFACE_H


void CLCD_voidSendCommand(uint8 copy_u8Command);
void CLCD_voidSendData(uint8 copy_u8Data);
void CLCD_voidInit(void);
uint8 CLCD_u8SendString(const char *copy_chString);
void CLCD_voidSendNumber(uint32 copy_u32Number);



#endif
