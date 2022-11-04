/*
 ============================================================================
 Name        : Timer0.h
 Author      : Youssef Nashaat
 Description :
 Date        : Oct 7, 2022
 ============================================================================
 */

#include "Timer0.h"
#include "gpio.h"
#include <avr/io.h>

void PWM_Timer0_Start(uint8 duty_cycle)
{

	/*Timer0 Initialization
	 * FOC0 	= 0		PWM mode
	 * WGM0:1	= 1,1	Fast PWM
	 * COM0:1	= 0,1	Non-Inverting Mode
	 * CS0:2	= 0,1,0	Pre-Scale 8
	 */
	TCCR0 = (1<<WGM01) | (1<<WGM00) | (1<<COM01) | (1<<CS01);

	/*Determine duty cycle based on passed Argument of function*/
	OCR0 = (uint8)((uint16)(MAX_COMPARE_REG_VALUE * duty_cycle)/MAX_PERCENTAGE);

	GPIO_setupPinDirection(PORTB_ID, PIN3_ID, PIN_OUTPUT);
}
