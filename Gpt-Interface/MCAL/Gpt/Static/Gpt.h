#ifndef GPT_H_
#define GPT_H_


#include "Std_Types.h"
#include "Gpt_Pcfg.h"


typedef enum
{
	GPT_TIMER0,
	GPT_TIMER1,
	GPT_TIMER2
}Gpt_ChannelType;

typedef enum
{
	GPT_NO_CLK_SOURCE,
	GPT_NO_PRESCALE,
	GPT_PRESCALE_8,
	GPT_PRESCALE_64,
	GPT_PRESCALE_256,
	GPT_PRESCALE_1024,
	GPT_EXT_CLK_T0_FALLING,
	GPT_EXT_CLK_T0_RISING
}Gpt_PrescaleType;

typedef enum
{
	GPT_NORMAL_MODE = 0x00U,
	GPT_CTC_MODE    = 0x08U
}Gpt_ModeType;

typedef enum
{
	GPT_INTERRUPT_DIABLE,
	GPT_INTERRUPT_ENABLE
}Gpt_InterruptStateType;

typedef enum
{
	GPT_STATUS_OVERFLOW_CMP,
	GPT_STATUS_RUNNING
}Gpt_StatusType;

typedef uint16 Gpt_ValueType;

typedef struct 
{
	Gpt_ChannelType            GptNumber;
	Gpt_PrescaleType           GptPrescaleType;
	Gpt_ModeType               GptMode;
	Gpt_InterruptStateType     GptInterruptState;
	Gpt_ValueType              GptCmpValue;             
}Gpt_ConfigType;



void Gpt_Init(const Gpt_ConfigType *ConfigPtr);
Gpt_StatusType Gpt_StatusGet(Gpt_ChannelType Channel);

extern const Gpt_ConfigType gGpt_Configuration[GPT_CHANNELS_NUMBER];


#endif /* GPT_H_ */