#include "ATmega32A_Configuration.h"
#include "DIO.h"


#ifndef RELAY_H_
#define RELAY_H_

#define RELAY_DIR_REG (PORTA_DIR_REG)
#define RELAY_OUT_REG (PORTA_OUT_REG)
#define RELAY_PIN (DIO_PIN2)

typedef enum
{
	RELAY_OFF,
	RELAY_ON
}RelayStateEnum_t;

void Relay_init();
void Relay_Set_State(RelayStateEnum_t state);


#endif /* RELAY_H_ */