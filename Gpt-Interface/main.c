#include "Gpt.h"
#include "LED.h"
#include "External_Interrupts.h"
#include <avr/interrupt.h>


#define ONE_SECOND_GPT_OVF_NUM    (244U)     // I need the timer to make 244 overflows to make a delay of 1 second

volatile uint8 gu8GptCounter_0 = 0;
volatile uint8 gu8GptCounter_2 = 0; 

ISR(TIMER0_OVF_vect)
{
	gu8GptCounter_0++;	
}

ISR(TIMER1_COMPA_vect)
{
	Led_State_Set(LED1_OUT_REG, LED_1, LED_TOGGLE);
}

ISR(TIMER2_OVF_vect)
{
	gu8GptCounter_2++;
}


int main(void)
{
	Gpt_Init(&gGpt_Configuration[GPT_TIMER0]);
	Gpt_Init(&gGpt_Configuration[GPT_TIMER1]);
	Gpt_Init(&gGpt_Configuration[GPT_TIMER2]);
	Led_Init(LED0_DIR_REG, LED_0);
	Led_Init(LED1_DIR_REG, LED_1);
	Led_Init(LED2_DIR_REG, LED_2);
	GlobalInterruptsStateSet(GLOBAL_INTERRUPTS_ENABLE);
	
    while (1) 
    {
		if (gu8GptCounter_0 >= ONE_SECOND_GPT_OVF_NUM)
		{
			Led_State_Set(LED0_DIR_REG, LED_0, LED_TOGGLE);
			gu8GptCounter_0 = 0;
		}
    }
}

