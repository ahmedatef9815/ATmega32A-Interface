#include "ATmega32A_Configuration.h"
#include "Macros.h"
#include "Gpt.h"



void Gpt_Init(const Gpt_ConfigType *ConfigPtr)
{
	switch (ConfigPtr->GptNumber)
	{
		case GPT_TIMER0:
			// Clear Registers before applying configuration
			*TIMER0_CTRL_REG = 0x00U;
			// Apply the configuration
			switch(ConfigPtr->GptMode)
			{
				case GPT_NORMAL_MODE:
					*TIMER0_CTRL_REG |= GPT_NORMAL_MODE;
					*TIMER_INTERRUPT_MASK_REG |= ConfigPtr->GptInterruptState;
					break;
					
				case GPT_CTC_MODE:
					*TIMER0_CTRL_REG |= GPT_CTC_MODE;
					*TIMER_INTERRUPT_MASK_REG |= ConfigPtr->GptInterruptState << TIMER0_OUT_CMP_MATCH_INTERRUPT_ENABLE_BIT;
					*TIMER0_OUT_CMP_REG = (ConfigPtr->GptCmpValue - 1);
					break;
					
				default:
					break;
			}
			break;
			
			
		case GPT_TIMER1:
			// Clear Registers before applying configuration
			*TIMER1_CTRL_REG_A = 0x00U;
			*TIMER1_CTRL_REG_B = 0x00U;
			*(uint16*)TIMER1_COUNTER_LOW_REG = 0x0000U;
			// Apply configuration
			switch(ConfigPtr->GptMode)
			{
				case GPT_NORMAL_MODE:
					*TIMER_INTERRUPT_MASK_REG |= (ConfigPtr->GptInterruptState << TIMER1_OVERFLOW_INTERRUPT_ENABLE_BIT);
					break;
				
				case GPT_CTC_MODE:
					*TIMER1_CTRL_REG_B |= GPT_CTC_MODE;
					*TIMER_INTERRUPT_MASK_REG |= (ConfigPtr->GptInterruptState << TIMER1_OUT_CMP_A_MATCH_INTERRUPT_ENABLE_BIT);
					*(uint16*)TIMER1_OUT_CMP_REG_A_LOW = (ConfigPtr->GptCmpValue - 1);
					break;
					
				default:
					break;		
			}
			*TIMER1_CTRL_REG_B |= ConfigPtr->GptPrescaleType;
			break;
			
			
		case GPT_TIMER2:
			// Clear Registers before applying configuration
			*TIMER2_CTRL_REG = 0x00U;
			// Apply the configuration
			switch(ConfigPtr->GptMode)
			{
				case GPT_NORMAL_MODE:
					*TIMER2_CTRL_REG |= GPT_NORMAL_MODE;
					*TIMER_INTERRUPT_MASK_REG |= ConfigPtr->GptInterruptState << TIMER2_OVERFLOW_INTERRUPT_ENABLE_BIT;
					break;
				
				case GPT_CTC_MODE:
					*TIMER0_CTRL_REG |= GPT_CTC_MODE;
					*TIMER_INTERRUPT_MASK_REG |= ConfigPtr->GptInterruptState << TIMER2_OUT_CMP_MATCH_INTERRUPT_ENABLE_BIT;
					*TIMER0_OUT_CMP_REG = (ConfigPtr->GptCmpValue - 1);
					break;
				
				default:
					break;
			}
			break;			
			
		default:
			break;
	}
}



Gpt_StatusType Gpt_StatusGet(Gpt_ChannelType Channel)
{
	Gpt_StatusType LocalGptStatus = GPT_STATUS_RUNNING;
	switch(Channel)
	{
		case GPT_TIMER0:
			switch(gGpt_Configuration[GPT_TIMER0].GptMode)
			{
				case GPT_NORMAL_MODE:
					if(READ_BIT(*TIMER_INTERRUPT_FLAG_REG, TIMER0_OVERFLOW_FLAG_BIT))
					{
						LocalGptStatus = GPT_STATUS_OVERFLOW_CMP;
						// Clear The TOV bit
						SET_BIT(*TIMER_INTERRUPT_FLAG_REG, TIMER0_OVERFLOW_FLAG_BIT);
					}
					else
					{
						// DO NOTHING
					}
					break;
				
				case GPT_CTC_MODE:
					if (READ_BIT(*TIMER_INTERRUPT_FLAG_REG, TIMER0_OUT_CMP_FLAG_BIT))
					{
						LocalGptStatus = GPT_STATUS_OVERFLOW_CMP;
						// Clear The OCF bit
						SET_BIT(*TIMER_INTERRUPT_FLAG_REG, TIMER0_OUT_CMP_FLAG_BIT);
					}
					else
					{
						// DO NOTHING
					}
					break;
					
				default:
					break;
			}
			break;
			
			
		case GPT_TIMER1:
			switch(gGpt_Configuration[GPT_TIMER1].GptMode)
			{
				case GPT_NORMAL_MODE:
					if (READ_BIT(*TIMER_INTERRUPT_FLAG_REG, TIMER1_OVERFLOW_FLAG_BIT))
					{
						LocalGptStatus = GPT_STATUS_OVERFLOW_CMP;
						// Clear The TOV bit 
						SET_BIT(*TIMER_INTERRUPT_FLAG_REG, TIMER1_OVERFLOW_FLAG_BIT);
					}
					else
					{
						// Do Nothing 
					}
					break;
					
				case GPT_CTC_MODE:
					if (READ_BIT(*TIMER_INTERRUPT_FLAG_REG, TIMER1_OUT_CMP_A_MATCH_FLAG_BIT))
					{
						LocalGptStatus = GPT_STATUS_OVERFLOW_CMP;
						// Clear The TOV bit 
						SET_BIT(*TIMER_INTERRUPT_FLAG_REG, TIMER1_OUT_CMP_A_MATCH_FLAG_BIT);
					}
					else
					{
						// Do Nothing 
					}
					break;
				default:
					break;
			}
			break;
			
			
		case GPT_TIMER2:
			switch(gGpt_Configuration[GPT_TIMER2].GptMode)
			{
				case GPT_NORMAL_MODE:
					if(READ_BIT(*TIMER_INTERRUPT_FLAG_REG, TIMER2_OVERFLOW_FLAG_BIT))
					{
						LocalGptStatus = GPT_STATUS_OVERFLOW_CMP;
						// Clear The TOV bit
						SET_BIT(*TIMER_INTERRUPT_FLAG_REG, TIMER2_OVERFLOW_FLAG_BIT);
					}
					else
					{
						// DO NOTHING
					}
					break;
				
				case GPT_CTC_MODE:
					if (READ_BIT(*TIMER_INTERRUPT_FLAG_REG, TIMER2_OUT_CMP_FLAG_BIT))
					{
						LocalGptStatus = GPT_STATUS_OVERFLOW_CMP;
						// Clear The OCF bit
						SET_BIT(*TIMER_INTERRUPT_FLAG_REG, TIMER2_OUT_CMP_FLAG_BIT);
					}
					else
					{
						// DO NOTHING
					}
					break;
				
				default:
					break;
			}
			break;
		
		
		default:
			break;
	}
	return (LocalGptStatus);
}