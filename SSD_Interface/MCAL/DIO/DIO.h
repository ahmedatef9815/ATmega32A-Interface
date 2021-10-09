#include "Std_Types.h"

#ifndef DIO_H_
#define DIO_H_


//Defines an enumerated list of all the channels (pins) on the MCU device.
typedef enum
{
    DIO_PIN0,
    DIO_PIN1,
    DIO_PIN2,
    DIO_PIN3,
    DIO_PIN4,
    DIO_PIN5,
    DIO_PIN6,
    DIO_PIN7,
}DioPinEnum_t;


 //Defines the possible states for a digital output pin.
 typedef enum
 {
    DIO_LOW,             
    DIO_HIGH             
 }DioPinStateEnum_t;


//Defines the GPIO direction : Input or output
typedef enum
{
    DIO_INPUT,
    DIO_OUTPUT
}DioPinDirectionEnum_t;

void Dio_ChannelDirectionSet(volatile uint8* port_reg, DioPinEnum_t channel, DioPinDirectionEnum_t direction);
DioPinStateEnum_t Dio_ChannelRead(volatile uint8* port_reg, DioPinEnum_t channel);
void Dio_ChannelWrite(volatile uint8* port_reg, DioPinEnum_t channel, DioPinStateEnum_t state);
void Dio_ChannelToggle(volatile uint8* port_reg, DioPinEnum_t channel);
void Dio_PortWrite(volatile uint8* port_reg, uint8 value);
uint8 Dio_PortRead(volatile uint8* port_reg);



#endif /* DIO_H_ */