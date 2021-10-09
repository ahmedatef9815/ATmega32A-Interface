#include "ATmega32A_Configuration.h"
#include "DIO.h"


#ifndef BUZZER_H_
#define BUZZER_H_


#define BUZZER_DIR_REG (PORTA_DIR_REG)
#define BUZZER_OUT_REG (PORTA_OUT_REG)
#define BUZZER_PIN (DIO_PIN3)

typedef enum
{
	BUZZER_OFF,
	BUZZER_ON
}BuzzerStateEnum_t;

void Buzzer_Init();
void Buzzer_Set_State(BuzzerStateEnum_t state);


#endif /* BUZZER_H_ */