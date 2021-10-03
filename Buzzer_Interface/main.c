#include "util/delay.h"
#include "LED.h"
#include "SW.h"
#include "Buzzer.h"
#include "ATmega32A_Configuration.h"


int main(void)
{
	Switch_Init(SW0_DIR_REG, SW_0);
	Switch_Init(SW1_DIR_REG, SW_1);
	Buzzer_Init();
	
	while (1)
	{
		SwitchStateEnum_t sw0_state = Switch_Get_State(SW0_INP_REG, SW_0);
		SwitchStateEnum_t sw1_state = Switch_Get_State(SW1_INP_REG, SW_1);
		if(sw0_state == SW_PRESSED)
		{
			Buzzer_Set_State(BUZZER_ON);
		}
		else if(sw1_state == SW_PRESSED)
		{
			Buzzer_Set_State(BUZZER_OFF);
		}
	}
}
