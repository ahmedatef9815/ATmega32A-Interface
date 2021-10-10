#include "External_Interrupts.h"
#include "LED.h"
#include "SW.h"
#include "ATmega32A_Configuration.h"
#include "avr/interrupt.h"


ISR(INT0_vect)
{
	Led_State_Set(LED0_OUT_REG, LED_0, LED_TOGGLE);
}


int main(void)
{
	ExternalInterruptEnable(EXTERNAL_INT0, RISING_EDGE_MODE);
	GlobalInterruptsStateSet(GLOBAL_INTERRUPTS_ENABLE);
	Switch_Init(SW2_DIR_REG, SW_2);
	Led_Init(LED0_DIR_REG, LED_0);	
    
	while (1) 
    {
    }
}

