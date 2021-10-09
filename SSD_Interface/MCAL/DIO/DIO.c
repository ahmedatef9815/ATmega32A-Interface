#include "DIO.h"
#include "Macros.h"
#include "Std_Types.h"
#include "ATmega32A_Configuration.h"

void Dio_ChannelDirectionSet(volatile uint8* port_reg, DioPinEnum_t channel, DioPinDirectionEnum_t direction)
{

	switch(direction)
	{
		case DIO_INPUT:
			CLEAR_BIT(*port_reg, channel);
			break;
		case DIO_OUTPUT:
			SET_BIT(*port_reg, channel);
			break;
		default:
			break;
	}
}


DioPinStateEnum_t Dio_ChannelRead(volatile uint8* port_reg, DioPinEnum_t channel)
{
	DioPinStateEnum_t u8LocalPinValue = READ_BIT(*port_reg, channel);
	return (u8LocalPinValue);
}


void Dio_ChannelWrite(volatile uint8* port_reg, DioPinEnum_t channel, DioPinStateEnum_t state)
{
	switch(state)
	{
		case DIO_LOW:
			CLEAR_BIT(*port_reg, channel);
			break;
		case DIO_HIGH:
			SET_BIT(*port_reg, channel);
			break;
		default:
			break;
	}
}


void Dio_ChannelToggle(volatile uint8* port_reg, DioPinEnum_t channel)
{
	TOGGLE_BIT(*port_reg, channel);
}


void Dio_PortWrite(volatile uint8* port_reg, uint8 value)
{
	*port_reg = value;
}


uint8 Dio_PortRead(volatile uint8* port_reg)
{
	uint8 u8LocalPortValue = *port_reg;
	return u8LocalPortValue;
}