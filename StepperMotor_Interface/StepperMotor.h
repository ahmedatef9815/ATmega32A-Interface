
#ifndef STEPPERMOTOR_H_
#define STEPPERMOTOR_H_

#include "DIO.h"
#include "ATmega32A_Configuration.h"


#define STEPPER_MOTOR_DIR_REG         (PORTA_DIR_REG)
#define STEPPER_MOTOR_OUT_REG         (PORTA_OUT_REG)

#define STEPPER_MOTOR_IN1_PIN         (DIO_PIN4)
#define STEPPER_MOTOR_IN2_PIN         (DIO_PIN5)
#define STEPPER_MOTOR_IN3_PIN         (DIO_PIN6)
#define STEPPER_MOTOR_IN4_PIN         (DIO_PIN7)

#define STEPPER_UPPER_PORT            (1U)   //1: Upper port , 0: Lower port

#define STEPPER_MOTOR_STEP_DELAY_MS   (5U)

void StepperMotorInit(void);
void StepperMotorTurnClockwise(void);
void StepperMotorTurnCounterClockwise(void);




#endif /* STEPPERMOTOR_H_ */