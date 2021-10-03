#include "LED.h"
#include "DIO.h"

void Led_Init(volatile uint8* led_reg, LedEnum_t led_no)
{
	Dio_ChannelDirectionSet(led_reg, led_no, DIO_OUTPUT);
}


void Led_State_Set(volatile uint8* led_reg, LedEnum_t led_no, LedStateEnum_t state)
{
	if(state == LED_TOGGLE)
	{
		Dio_ChannelToggle(led_reg, led_no);
	}
	else
	{
		Dio_ChannelWrite(led_reg, led_no, state);
	}
}
