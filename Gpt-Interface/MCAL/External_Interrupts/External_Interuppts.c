#include "External_Interrupts.h"
#include "Macros.h"
#include "ATmega32A_Configuration.h"



void ExternalInterruptEnable(ExternalInterruptSourceEnum_t source, ExternalInterruptModeEnum_t mode)
{
	switch(source)
	{
		case EXTERNAL_INT0:
			// Configure INT0 Mode
			switch(mode)
			{
				case RISING_EDGE_MODE:
					SET_BIT(*MCU_CTRL_REG, INT0_ISC00);
					SET_BIT(*MCU_CTRL_REG, INT0_ISC01);
					break;
				case FALLING_EDGE_MODE:
					CLEAR_BIT(*MCU_CTRL_REG, INT0_ISC00);
					SET_BIT(*MCU_CTRL_REG, INT0_ISC01);
					break;
				case LOW_LEVEL_MODE:
					CLEAR_BIT(*MCU_CTRL_REG, INT0_ISC00);
					CLEAR_BIT(*MCU_CTRL_REG, INT0_ISC01);
					break;
				case EDGE_TRIGGER_MODE:
					SET_BIT(*MCU_CTRL_REG, INT0_ISC00);
					CLEAR_BIT(*MCU_CTRL_REG, INT0_ISC01);
					break;
				default:
					break;
			}
			// Enable INT0
			SET_BIT(*GENERAL_INTERRUPT_CTRL_REG, INT0_ENABLE_BIT);
			break;
			
			
		case EXTERNAL_INT1:
			// Configure INT1 Mode
			switch(mode)
			{
				case RISING_EDGE_MODE:
					SET_BIT(*MCU_CTRL_REG, INT1_ISC10);
					SET_BIT(*MCU_CTRL_REG, INT1_ISC11);
					break;
				case FALLING_EDGE_MODE:
					CLEAR_BIT(*MCU_CTRL_REG, INT1_ISC10);
					SET_BIT(*MCU_CTRL_REG, INT1_ISC11);
					break;
				case LOW_LEVEL_MODE:
					CLEAR_BIT(*MCU_CTRL_REG, INT1_ISC10);
					CLEAR_BIT(*MCU_CTRL_REG, INT1_ISC11);
					break;
				case EDGE_TRIGGER_MODE:
					SET_BIT(*MCU_CTRL_REG, INT1_ISC10);
					CLEAR_BIT(*MCU_CTRL_REG, INT1_ISC11);
					break;
				default:
					break;
			}
			// Enable INT1
			SET_BIT(*GENERAL_INTERRUPT_CTRL_REG, INT1_ENABLE_BIT);
			break;
			
			
		case EXTERNAL_INT2:
			// Configure INT2 Mode
			switch(mode)
			{
				case RISING_EDGE_MODE:
					SET_BIT(*MCU_CTRL_STATUS_REG, INT2_ISC2);
					break;
				case FALLING_EDGE_MODE:
					CLEAR_BIT(*MCU_CTRL_STATUS_REG, INT2_ISC2);
					break;
				default:
					break;
			}
			// ENABLE INT2
			SET_BIT(*GENERAL_INTERRUPT_CTRL_REG, INT2_ENABLE_BIT);
			break;
			
			
		default:
			break;
	}
}

void ExternalInterruptDisable(ExternalInterruptSourceEnum_t source)
{
	switch(source)
	{
		case EXTERNAL_INT0:
			CLEAR_BIT(*GENERAL_INTERRUPT_CTRL_REG, INT0_ENABLE_BIT);
			break;
		case EXTERNAL_INT1:
			CLEAR_BIT(*GENERAL_INTERRUPT_CTRL_REG, INT1_ENABLE_BIT);
			break;
		case EXTERNAL_INT2:
			CLEAR_BIT(*GENERAL_INTERRUPT_CTRL_REG, INT2_ENABLE_BIT);
			break;
		default:
			break;
	}
}

void GlobalInterruptsStateSet(GlobalInterruptsStateEnum_t state)
{
	switch (state)
	{
		case GLOBAL_INTERRUPTS_DISABLE:
			CLEAR_BIT(*AVR_STATUS_REG, GLOBAL_INTERRUPTS_ENABLE_BIT);
			break;
		case GLOBAL_INTERRUPTS_ENABLE:
			SET_BIT(*AVR_STATUS_REG, GLOBAL_INTERRUPTS_ENABLE_BIT);
			break;
		default:
			break;
	}
}
