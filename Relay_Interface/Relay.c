#include "DIO.h"
#include "Relay.h"


void Relay_init()
{
	Dio_ChannelDirectionSet(RELAY_DIR_REG, RELAY_PIN, DIO_OUTPUT);
}

void Relay_Set_State(RelayStateEnum_t state)
{
	Dio_ChannelWrite(RELAY_OUT_REG, RELAY_PIN, state);
}