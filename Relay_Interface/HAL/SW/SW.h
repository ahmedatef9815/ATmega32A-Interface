#include "DIO.h"
#include "ATmega32A_Configuration.h"

#ifndef SW_H_
#define SW_H_


#define SW0_DIR_REG (PORTB_DIR_REG)
#define SW0_INP_REG (PORTB_INP_REG)
#define SW0_PIN (DIO_PIN0)

#define SW1_DIR_REG (PORTD_DIR_REG)
#define SW1_INP_REG (PORTD_INP_REG)
#define SW1_PIN (DIO_PIN6)

#define SW2_DIR_REG (PORTD_DIR_REG)
#define SW2_INP_REG (PORTD_INP_REG)
#define SW2_PIN (DIO_PIN2)



typedef enum
{
	SW_0 = SW0_PIN,
	SW_1 = SW1_PIN,
	SW_2 = SW2_PIN
}SwitchEnum_t;

typedef enum 
{
	SW_RELEASED,
	SW_PRESSED
}SwitchStateEnum_t;


void Switch_Init(volatile uint8* sw_reg, SwitchEnum_t sw_no);
SwitchStateEnum_t Switch_Get_State(volatile uint8* sw_reg, SwitchEnum_t sw_no);


#endif /* SW_H_ */