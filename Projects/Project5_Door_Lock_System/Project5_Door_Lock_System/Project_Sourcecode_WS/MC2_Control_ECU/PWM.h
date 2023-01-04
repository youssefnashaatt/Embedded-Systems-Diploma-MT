/*
 ============================================================================
 Name        : Timer0.h
 Author      : Youssef Nashaat
 Description :
 Date        : Oct 7, 2022
 ============================================================================
 */

#ifndef PWM_H_
#define PWM_H_


#include "Standard_Types.h"

#define MAX_COMPARE_REG_VALUE	255
#define MAX_PERCENTAGE			100

void PWM_Timer0_Start(uint8 duty_cycle);

#endif /* PWM_H_ */
