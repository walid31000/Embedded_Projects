#ifndef  CLCD_CFG_H
#define  CLCD_CFG_H
/*provide macro to choose between 2 connection mode:1-EIGHT_BIT mode
 *                                                   2-FOUR_BIT mode */
#define  CLCD_u8CONNECTION_MODE   FOUR_BIT

/*provide macro for RW pin :1-ENABLED
 *                          2-DISABLED */

#define CLCD_u8READ_OPERATION_ENABLE     DISABLED

#if CLCD_u8CONNECTION_MODE ==  FOUR_BIT
#define CLCD_u8DB4_PIN         DIO_PIN3
#define CLCD_u8DB5_PIN         DIO_PIN4
#define CLCD_u8DB6_PIN         DIO_PIN5
#define CLCD_u8DB7_PIN         DIO_PIN6

#endif

#define CLCD_u8DATA_PORT         DIO_PORTA

#define CLCD_u8CTRL_PORT         DIO_PORTA
#define CLCD_u8RS_PIN            DIO_PIN1
#if CLCD_u8READ_OPERATION_ENABLE ==ENABLED
#define CLCD_u8RW_PIN            DIO_PIN0
#endif
#define CLCD_u8E_PIN             DIO_PIN2


#endif
