/*
 ============================================================================
 Name        : DC_Motor.h
 Author      : Youssef Nashaat
 Description :
 Date        : Oct 7, 2022
 ============================================================================
 */

#ifndef DC_MOTOR_H_
#define DC_MOTOR_H_

#include "Standard_Types.h"

/*Define of DC_Motor Port location on MC*/
#define DC_MOTOR_PORT_ID	PORTB_ID

/*Define of DC_Motor 2 pins location on MC*/
#define DC_MOTOR_PIN1_ID	PIN0_ID
#define DC_MOTOR_PIN2_ID	PIN1_ID

typedef enum
{
	STOP,  ANTI_CLOCKWISE, CLOCKWISE
}DcMotor_State;


void DcMotor_Init(void);
void DcMotor_Rotate(DcMotor_State state);


#endif /* DC_MOTOR_H_ */
