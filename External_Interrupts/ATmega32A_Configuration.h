#ifndef ATMEGA32A_CONFIGURATION_H_
#define ATMEGA32A_CONFIGURATION_H_

#include "Std_Types.h"

#define F_CPU 16000000U

/* PortA Registers */
#define PORTA_DIR_REG     ((volatile uint8*)0x3AU)
#define PORTA_INP_REG     ((volatile uint8*)0x39U)
#define PORTA_OUT_REG     ((volatile uint8*)0x3BU)

/* PortB Registers */
#define PORTB_DIR_REG     ((volatile uint8*)0x37U)
#define PORTB_INP_REG     ((volatile uint8*)0x36U)
#define PORTB_OUT_REG     ((volatile uint8*)0x38U)

/* PortC Registers */
#define PORTC_DIR_REG     ((volatile uint8*)0x34U)
#define PORTC_INP_REG     ((volatile uint8*)0x33U)
#define PORTC_OUT_REG     ((volatile uint8*)0x35U)

/* PortC Registers */
#define PORTD_DIR_REG     ((volatile uint8*)0x31U)
#define PORTD_INP_REG     ((volatile uint8*)0x30U)
#define PORTD_OUT_REG     ((volatile uint8*)0x32U)

/* External Interrupts Registers*/
#define MCU_CTRL_REG                ((volatile uint8*)0x55U)    // MCUCR
#define MCU_CTRL_STATUS_REG         ((volatile uint8*)0x54U)    // MCUCSR
#define GENERAL_INTERRUPT_CTRL_REG  ((volatile uint8*)0x5BU)    // GICR for enabling external interrupt source
#define AVR_STATUS_REG_I_BIT              ((volatile uint8*)0x5FU)    //da elly feeh el I bit elly btet7akem fel global interrupt

#endif /* ATMEGA32A_CONFIGURATION_H_ */