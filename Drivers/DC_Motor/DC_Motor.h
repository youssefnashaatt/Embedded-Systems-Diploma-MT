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

typedef enum
{
	STOP, CLOCKWISE, ANTI_CLOCKWISE
}DcMotor_State;


void DcMotor_Init(void);
void DcMotor_Rotate(DcMotor_State state,uint8 speed);


#endif /* DC_MOTOR_H_ */
