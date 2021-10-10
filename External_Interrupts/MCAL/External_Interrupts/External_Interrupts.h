
#ifndef EXTERNAL_INTERRUPTS_H_
#define EXTERNAL_INTERRUPTS_H_

typedef enum
{
	EXTERNAL_INT0,
	EXTERNAL_INT1,
	EXTERNAL_INT2	
}ExternalInterruptSourceEnum_t;

typedef enum
{
	RISING_EDGE_MODE,
	FALLING_EDGE_MODE,
	EDGE_TRIGGER_MODE,
	LOW_LEVEL_MODE
}ExternalInterruptModeEnum_t;

typedef enum
{
	GLOBAL_INTERRUPTS_DISABLE,
	GLOBAL_INTERRUPTS_ENABLE,
}GlobalInterruptsStateEnum_t;


// These two bits for choosing which event will Interrupt0 happen at (Rising edge, Falling edge, Low level) 
#define INT0_ISC00        (0U)      
#define INT0_ISC01        (1U)
// These two bits for choosing which event will Interrupt1 happen at (Rising edge, Falling edge, Low level)
#define INT1_ISC10        (2U)
#define INT1_ISC11        (3U)
// This bit for choosing which event will Interrupt1 happen at (Rising edge, Falling edge)
#define INT2_ISC2         (6U)

#define INT0_ENABLE_BIT               (6U)
#define INT1_ENABLE_BIT               (7U)
#define INT2_ENABLE_BIT               (5U)
#define GLOBAL_INTERRUPTS_ENABLE_BIT  (7U)     // I Bit


void ExternalInterruptEnable(ExternalInterruptSourceEnum_t source, ExternalInterruptModeEnum_t mode);
void ExternalInterruptDisable(ExternalInterruptSourceEnum_t source); 
void GlobalInterruptsStateSet(GlobalInterruptsStateEnum_t state);


#endif /* EXTERNAL_INTERRUPTS_H_ */