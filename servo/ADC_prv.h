#ifndef ADC_PRV_H
#define ADC_PRV_H


#define PRESCALER_MASK        0b11111000

#define CHANNEL_SELECTION_MASK          0b11100000

#define  AVCC                      1u
#define  AREF                      2u
#define Two_point_fiftysix         3u




#define DIVISION_BY_2         1U
#define DIVISION_BY_4         2U
#define DIVISION_BY_8         3U
#define DIVISION_BY_16        4U
#define DIVISION_BY_32        5U
#define DIVISION_BY_64        6U
#define DIVISION_BY_128       7U

#define   EIGHT_BITS           1U
#define   TEN_BITS             2U

#define   ENABLED               1
#define   DISABLED              2


#define IDLE                  0U
#define BUSY                  1U


#define   CHAIN_CONV_ASYNCH     1U
#define   SINGLE_CONV_ASYNCH    0
#endif
