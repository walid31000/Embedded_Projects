#ifndef TIMER_REG_H
#define TIMER_REG_H

#define   TCCR0              *((volatile uint8*) 0X53)

#define    TCCR0_WGM01          3U
#define    TCCR0_WGM00          6U

#define    TCCR0_COM00          4U
#define    TCCR0_COM01          5U


#define   TCNT0              *((volatile uint8*) 0X52)    // Timer0 register

#define   TIMSK              *((volatile uint8*) 0X59) //overflow timer Enable

#define   TIMSK_TOIE0        0U

#define   TIMSK_OCIE0        1U  /*Enable Timer output compare match  interrupt*/

#define   TIMSK_TOIE1        2U  /*Enable Timer 1 overflow  interrupt*/

#define   TIMSK_TICIE1        5U  /*Enable Timer 1 Input capture  interrupt*/


#define   OCR0              *((volatile uint8*) 0X5C) // timer output compare register

#define   TCCR1A              *((volatile uint8*) 0X4F) // timer control registerA

#define   TCCR1A_COM1A1             7U // compare output mode for channel A
#define   TCCR1A_COM1A0             6U // compare output mode for channel A

#define   TCCR1A_WGM10             0U // waveforme generation mode for channel A
#define   TCCR1A_WGM11             1U // waveforme generation mode for channel A

#define   OCR1A              *((volatile uint16*) 0X4A) // output comare register 1A

#define   ICR1              *((volatile uint16*) 0X46) // input capture register

#define   TCCR1B              *((volatile uint8*) 0X4E) // timer control registerA

#define   TCCR1B_WGM12        3U
#define   TCCR1B_WGM13         4U

#define   TCNT1              *((volatile uint16*) 0X4C)    // Timer1 register

#define   TCCR1B_ICES1         6U    //Input capture EDGE Select
#endif
