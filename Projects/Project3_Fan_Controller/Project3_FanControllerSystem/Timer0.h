/*
 ============================================================================
 Name        : Timer0.h
 Author      : Youssef Nashaat
 Description :
 Date        : Oct 7, 2022
 ============================================================================
 */

#ifndef TIMER0_H_
#define TIMER0_H_


#include "Standard_Types.h"

#define MAX_COMPARE_REG_VALUE	255
#define MAX_PERCENTAGE			100

void PWM_Timer0_Start(uint8 duty_cycle);

#endif /* TIMER0_H_ */
