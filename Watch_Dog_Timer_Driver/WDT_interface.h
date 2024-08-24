#ifndef WDT_INTERFACE_H
#define WDT_INTERFACE_H


/* WDT Times enumeration */

typedef enum
{
	syxteen_point_three_ms,
	Thirty_Two_point_five_ms,
	sixty_five_ms,
	O_Point_Thirteen_sec,
	O_point_twenty_six_sec,
	O_point_fifty_two_sec,
	One_sec,
	Two_Point_one_sec




}WDT_Time_t;




uint8 WDT_SetTime(WDT_Time_t copy_u8Time);
uint8 WDT_Stop(void);//disable timer
void WDT_Reset(void);










#endif
