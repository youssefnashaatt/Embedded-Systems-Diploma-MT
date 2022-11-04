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
#include "gpio.h"
#include "Timer0.h"




void DcMotor_Init(void)
{
	GPIO_setupPinDirection(PORTB_ID, PIN0_ID, PIN_OUTPUT);
	GPIO_setupPinDirection(PORTB_ID, PIN1_ID, PIN_OUTPUT);

	GPIO_writePin(PORTB_ID, PIN0_ID, LOGIC_LOW);
	GPIO_writePin(PORTB_ID, PIN1_ID, LOGIC_LOW);
}


void DcMotor_Rotate(DcMotor_State state,uint8 speed)
{
	GPIO_writePin(PORTB_ID, PIN0_ID, GET_BIT(state, PIN0_ID));
	GPIO_writePin(PORTB_ID, PIN1_ID, GET_BIT(state, PIN1_ID));

	PWM_Timer0_Start(speed);
}
