#include "Macros.h"
#include "Std_Types.h"
#include "LED.h"
#include "SW.h"
#include "util/delay.h"


int main(void)
{
	Led_Init(LED0_DIR_REG, LED_0);
	Switch_Init(SW0_DIR_REG, SW_0);
	
    while (1) 
    {
		SwitchStateEnum_t sw_state = Switch_Get_State(SW0_INP_REG, SW_0);
		if(sw_state == SW_PRESSED)
		{
			Led_State_Set(LED0_OUT_REG, LED_0, LED_TOGGLE);
		}
    }
}

