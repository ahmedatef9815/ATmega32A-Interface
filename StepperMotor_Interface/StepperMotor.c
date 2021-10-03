#include "StepperMotor.h"
#include "util/delay.h"

//g for global , a for array , u8 for uint8
uint8 gau8StepperRotation[4U] = {0x10U, 0x20U, 0x40U, 0x80U};

void StepperMotorInit(void)
{
	Dio_ChannelDirectionSet(STEPPER_MOTOR_DIR_REG, STEPPER_MOTOR_IN1_PIN, DIO_OUTPUT);
	Dio_ChannelDirectionSet(STEPPER_MOTOR_DIR_REG, STEPPER_MOTOR_IN2_PIN, DIO_OUTPUT);
	Dio_ChannelDirectionSet(STEPPER_MOTOR_DIR_REG, STEPPER_MOTOR_IN3_PIN, DIO_OUTPUT);
	Dio_ChannelDirectionSet(STEPPER_MOTOR_DIR_REG, STEPPER_MOTOR_IN4_PIN, DIO_OUTPUT);
}

void StepperMotorTurnClockwise(void)
{
	uint8 u8LocalLoopIndex;
	for (u8LocalLoopIndex = 0U; u8LocalLoopIndex < 4U; u8LocalLoopIndex++)
	{
		
		*STEPPER_MOTOR_OUT_REG &= 0x0FU;              //lazem asfar el 4 bits el 3ayz akteb feehom kol mara
		*STEPPER_MOTOR_OUT_REG |= gau8StepperRotation[u8LocalLoopIndex];
		_delay_ms(STEPPER_MOTOR_STEP_DELAY_MS);
	}
		
}

void StepperMotorTurnCounterClockwise(void)
{
	sint8 s8LocalLoopIndex;
	for (s8LocalLoopIndex = 3; s8LocalLoopIndex >= 0; s8LocalLoopIndex--)
	{
		
		*STEPPER_MOTOR_OUT_REG &= 0x0FU;              //lazem asfar el 4 bits el 3ayz akteb feehom kol mara
		*STEPPER_MOTOR_OUT_REG |= gau8StepperRotation[s8LocalLoopIndex];
		_delay_ms(STEPPER_MOTOR_STEP_DELAY_MS);
	}
}
