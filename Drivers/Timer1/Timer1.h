/*
 ===============================================================================================
 Name        : Timer1.h
 Author      : Youssef Nashaat
 Description :
 Date        : Oct 24, 2022
 ===============================================================================================
 */

#ifndef TIMER1_H_
#define TIMER1_H_

#include "Standard_Types.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/


typedef enum
{
	NO_CLK_SOURCE, CLK_PRESCALER_1, CLK_PRESCALER_8, CLK_PRESCALER_64, CLK_PRESCALER_256, CLK_PRESCALER_1024
}Timer1_Prescaler;


typedef enum
{
	NORMAL_MODE, COMPARE_MODE = 4
}Timer1_Mode;


typedef struct {
 uint16 initial_value;
 uint16 compare_value; // it will be used in compare mode only.
 Timer1_Prescaler prescaler;
 Timer1_Mode mode;
} Timer1_ConfigType;


/*******************************************************************************
 *                           Function Proto-types                              *
 *******************************************************************************/

/*
 * Timer Module Function used to set the configurations of the timer module in AVR and start counting
 * Parameters: Structure of configuration of type (Timer1_ConfigType)
 * The structure includes the initial value of the timer, compare value, mode of operation and prescaler value.
 * Return: void
 */
void Timer1_init(const Timer1_ConfigType * Config_Ptr);


/*
 * Timer Module Function used to disable the Timer module in AVR
 * Parameters: void
 * Return: void
 */
void Timer1_deInit(void);


/*
 * Timer1 module function used to set the call back function of the module to the passed
 * pointer to function in the parameter of (Timer1_setCallBack)
 */
void Timer1_setCallBack(void(*a_ptr)(void));


#endif /* TIMER1_H_ */
