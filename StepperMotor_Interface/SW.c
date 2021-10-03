#include "SW.h"
#include "DIO.h"
#include "ATmega32A_Configuration.h"
#include "util/delay.h"


#define DEBOUNCE_PERIOD (20U)


DioPinStateEnum_t SwitchPreviousState = SW_RELEASED;

void Switch_Init(volatile uint8* sw_reg, SwitchEnum_t sw_no)
{
	Dio_ChannelDirectionSet(sw_reg, sw_no, DIO_INPUT);
}


SwitchStateEnum_t Switch_Get_State(volatile uint8* sw_reg, SwitchEnum_t sw_no)
{
	SwitchStateEnum_t SwitchLocalState = SW_RELEASED;
	if(SwitchPreviousState != Dio_ChannelRead(sw_reg, sw_no))
	{
		_delay_ms(DEBOUNCE_PERIOD);
		SwitchPreviousState = Dio_ChannelRead(sw_reg, sw_no);
		if(SwitchPreviousState == DIO_HIGH)
		{
			SwitchLocalState = SW_PRESSED;
		}
		else 
		{
			SwitchLocalState = SW_RELEASED;
		}
	}
	return SwitchLocalState;
}