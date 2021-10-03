#include "Buzzer.h"
#include "DIO.h"

void Buzzer_Init()
{
	Dio_ChannelDirectionSet(BUZZER_DIR_REG, BUZZER_PIN, DIO_OUTPUT);
}

void Buzzer_Set_State(BuzzerStateEnum_t state)
{
	Dio_ChannelWrite(BUZZER_OUT_REG, BUZZER_PIN, state);
}