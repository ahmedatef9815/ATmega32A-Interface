#include "StepperMotor.h"
#include "util/delay.h"
#include "SW.h"


int main(void)
{
	StepperMotorInit();
	Switch_Init(SW0_DIR_REG, SW_1);
	Switch_Init(SW1_DIR_REG, SW_2);
		
    while (1) 
    {
		while(Switch_Get_State(SW1_INP_REG, SW_1) == SW_PRESSED)
		{
			StepperMotorTurnClockwise();
		}
		while(Switch_Get_State(SW2_INP_REG, SW_2) == SW_PRESSED)
		{
			StepperMotorTurnCounterClockwise();
		}
    }
}

