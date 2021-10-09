#include "DIO.h"

#ifndef LED_H_
#define LED_H_


#define LED0_DIR_REG (PORTC_DIR_REG)
#define LED0_OUT_REG (PORTC_OUT_REG)
#define LED0_PIN (DIO_PIN2)

#define LED1_DIR_REG (PORTC_DIR_REG)
#define LED1_OUT_REG (PORTC_OUT_REG)
#define LED1_PIN (DIO_PIN7)

#define LED2_DIR_REG (PORTD_DIR_REG)
#define LED2_OUT_REG (PORTD_OUT_REG)
#define LED2_PIN (DIO_PIN3)


typedef enum 
{
	LED_0 = LED0_PIN,
	LED_1 = LED1_PIN,
	LED_2 = LED2_PIN
}LedEnum_t;

typedef enum
{
	LED_OFF,
	LED_ON,
	LED_TOGGLE
}LedStateEnum_t;


void Led_Init(volatile uint8* led_reg, LedEnum_t led_no);
void Led_State_Set(volatile uint8* led_reg, LedEnum_t led_no, LedStateEnum_t state);


#endif /* LED_H_ */