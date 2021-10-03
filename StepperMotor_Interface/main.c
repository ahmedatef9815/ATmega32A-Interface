#include "StepperMotor.h"
#include "util/delay.h"
#include "SW.h"


int main(void)
{
	Switch_Init(SW0_DIR_REG, SW_0);
	Switch_Init(SW1_DIR_REG, SW_1);
	StepperMotorInit();
		
    while (1) 
    {
		SwitchStateEnum_t sw0_state = Switch_Get_State(SW0_INP_REG, SW_0);
		SwitchStateEnum_t sw1_state = Switch_Get_State(SW1_INP_REG, SW_1);
		if(sw0_state == SW_PRESSED)
		{
			StepperMotorTurnClockwise();
		}
		else if(sw1_state == SW_PRESSED)
		{
			StepperMotorTurnCounterClockwise();
		}
    }
}

