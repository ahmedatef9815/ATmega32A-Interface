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

/* PortD Registers */
#define PORTD_DIR_REG     ((volatile uint8*)0x31U)
#define PORTD_INP_REG     ((volatile uint8*)0x30U)
#define PORTD_OUT_REG     ((volatile uint8*)0x32U)


/* External Interrupts Registers */
#define MCU_CTRL_REG		          	((volatile uint8*)0x55U)  /* MCUCR */
#define MCU_CTRL_STATUS_REG		        ((volatile uint8*)0x54U)  /* MCUCSR */
#define GENERAL_INTERRUPT_CTRL_REG		((volatile uint8*)0x5BU)  /* GICR */
#define AVR_STATUS_REG			        ((volatile uint8*)0x5FU)  /* SREG */


/* ADC Registers */
#define ADC_MUX_REG                 ((volatile uint8*)0x27U)     // ADMUX
#define ADC_CTRL_STATUS_REG_A       ((volatile uint8*)0x26U)     // ADCSRA
#define ADC_DATA_HIGH_REG           ((volatile uint8*)0x25U)     // ADCH
#define ADC_DATA_LOW_REG            ((volatile uint8*)0x24U)     // ADCL
#define ADC_SPECIAL_FUNC_IO_REG     ((volatile uint8*)0x50U)     // SFIOR


/* Timer_0 Registers */
#define TIMER0_CTRL_REG      ((volatile uint8*)0x53U)        // TCCR0
#define TIMER0_COUNTER_REG   ((volatile uint8*)0x52U)        // TCNT0
#define TIMER0_OUT_CMP_REG   ((volatile uint8*)0x5CU)        // OCR0


/* Timer_1 Registers */
#define TIMER1_CTRL_REG_A           ((volatile uint8*)0x4FU)         // TCCR1A
#define TIMER1_CTRL_REG_B           ((volatile uint8*)0x4EU)         // TCCR1B
#define TIMER1_COUNTER_LOW_REG      ((volatile uint8*)0x4CU)         // TCNT1L
#define TIMER1_COUNTER_HIGH_REG     ((volatile uint8*)0x4DU)         // TCNT1H
#define TIMER1_OUT_CMP_REG_A_LOW    ((volatile uint8*)0x4AU)         // OCR1AL
#define TIMER1_OUT_CMP_REG_A_HIGH   ((volatile uint8*)0x4BU)         // OCR1AH
#define TIMER1_OUT_CMP_REG_B_LOW    ((volatile uint8*)0x48U)         // OCR1BL
#define TIMER1_OUT_CMP_REG_B_HIGH   ((volatile uint8*)0x49U)         // OCR1BH
 

/* Timer_2 Registers */
#define TIMER2_CTRL_REG                  ((volatile uint8*)0x45U)             // TCCR2
#define TIMER2_COUNTER_REG               ((volatile uint8*)0x44U)             // TCNT2
#define TIMER2_OUT_CMP_REG               ((volatile uint8*)0x43U)             // OCR2
#define TIMER2_ASYNCHRONOUS_STATUS_REG   ((volatile uint8*)0x42U)             // ASSR
  

/* General Registers for all timers */
#define TIMER_INTERRUPT_MASK_REG   ((volatile uint8*)0x59U)   // TIMSK
#define TIMER_INTERRUPT_FLAG_REG   ((volatile uint8*)0x58U)   // TIFR


#endif /* ATMEGA32A_CONFIGURATION_H_ */