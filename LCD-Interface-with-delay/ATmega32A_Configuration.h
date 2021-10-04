#ifndef ATMEGA32A_CONFIGURATION_H_
#define ATMEGA32A_CONFIGURATION_H_


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



#endif /* ATMEGA32A_CONFIGURATION_H_ */