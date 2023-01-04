/*
 ============================================================================
 Name        : DC_Motor.h\c
 Author      : Youssef Nashaat
 Description :
 Date        : Oct 7, 2022
 ============================================================================
 */


#include "DC_Motor.h"
#include "MACROS.h"
#include "GPIO.h"
#include "PWM.h"




void DcMotor_Init(void)
{
	GPIO_setupPinDirection(DC_MOTOR_PORT_ID, DC_MOTOR_PIN1_ID, PIN_OUTPUT);
	GPIO_setupPinDirection(DC_MOTOR_PORT_ID, DC_MOTOR_PIN2_ID, PIN_OUTPUT);

	GPIO_writePin(DC_MOTOR_PORT_ID, DC_MOTOR_PIN1_ID, LOGIC_LOW);
	GPIO_writePin(DC_MOTOR_PORT_ID, DC_MOTOR_PIN2_ID, LOGIC_LOW);
}

void DcMotor_Rotate(DcMotor_State state)
{
	GPIO_writePin(DC_MOTOR_PORT_ID, DC_MOTOR_PIN1_ID, GET_BIT(state, DC_MOTOR_PIN1_ID));
	GPIO_writePin(DC_MOTOR_PORT_ID, DC_MOTOR_PIN2_ID, GET_BIT(state, DC_MOTOR_PIN2_ID));

	PWM_Timer0_Start(100);
}
