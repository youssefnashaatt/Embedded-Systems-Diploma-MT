/*
 ===============================================================================================
 Name        : Timer1.c
 Author      : Youssef Nashaat
 Description : Timer1 Module Source File.
 Date        : Oct 24, 2022
 ===============================================================================================
 */

#include "Timer1.h"
#include <avr/io.h>
#include <avr/interrupt.h>
#include "Macros.h"


/* Global variables to hold the address of the call back function in the application */
static volatile void (*g_call_back_function)(void) = NULL_PTR;


/*
 * Timer Module Function used to set the configurations of the timer module in AVR and start counting
 * Parameters: Structure of configuration of type (Timer1_ConfigType)
 * The structure includes the initial value of the timer, compare value, mode of operation and prescaler value.
 * Return: void
 */
void Timer1_init(const Timer1_ConfigType * Config_Ptr)
{
	if(Config_Ptr->mode == NORMAL_MODE)
	{
		/*Add the Initial value passed in the configuration structure to the Initial Value Register (TCNT1)*/
		TCNT1 = Config_Ptr->initial_value;

		/*Enable Overflow Interrupt*/
		TIMSK = TIMSK | (1<<TOIE1);

		/*
		 * COM1A0/COM1A1 =	0 	Normal Port operation OC1A disconnected.
		 * COM1B0/COM1B1 =	0 	Normal Port operation OC1B disconnected.
		 * FOC1A 		 =	1 	Force Output Compare for Compare unit A (Overflow Mode)
		 * FOC1B 		 =	1 	Force Output Compare for Compare unit B (Overflow Mode)
		 * WGM1/1:0		 =  0	Normal Mode
		 */
		TCCR1A = (1<<FOC1A) | (1<<FOC1B);


		/*
		 * ICNC1		 =  0	Input Capture Noise Canceler
		 * ICES1		 =  0	CES1: Input Capture Edge Select
		 * WGM13:2		 =  0	Normal Mode
		 * CS12:0		 =	Config_Ptr->prescaler (Will be inserted as the pre-scale value passed in configuration structure)
		 */
		TCCR1B = ((Config_Ptr->prescaler)<<CS10);
	}


	else if(Config_Ptr->mode == COMPARE_MODE)
	{
		/*Add the Initial value passed in the configuration structure to the Initial Value Register (TCNT1)*/
		TCNT1 = Config_Ptr->initial_value;

		/*Add the Compare value passed in the configuration structure to the Compare Value Register (OCR1A)*/
		OCR1A = Config_Ptr->compare_value;

		/*Enable Compare Interrupt*/
		TIMSK = TIMSK | (1<<OCIE1A);

		/*
		 * COM1A0/COM1A1 =	0 	Normal Port operation OC1A disconnected.
		 * COM1B0/COM1B1 =	0 	Normal Port operation OC1B disconnected.
		 * FOC1A 		 =	1 	Force Output Compare for Compare unit A (Compare Mode)
		 * FOC1B 		 =	1 	Force Output Compare for Compare unit B (Compare Mode)
		 * WGM1/1:0		 =  0	Compare Mode
		 */
		TCCR1A = (1<<FOC1A);

		/*
		 * ICNC1		 =  0	Input Capture Noise Canceler
		 * ICES1		 =  0	CES1: Input Capture Edge Select
		 * WGM13:2		 =  0:1	Compare Mode
		 * CS12:0		 =	Config_Ptr->prescaler (Will be inserted as the pre-scale value passed in configuration structure)
		 */
		TCCR1B = (1<<WGM12) | ((Config_Ptr->prescaler)<<CS10);
	}
}



/*
 * Timer Module Function used to disable the Timer module in AVR
 * Parameters: void
 * Return: void
 */
void Timer1_deInit(void)
{
	TCNT1 = 0;						/*Timer initial register = 0*/
	OCR1A = 0;						/*Timer compare register = 0*/
	TIMSK = (TIMSK & ~(0x3C));		/*Disable Timer1 interrupt*/
	TCCR1A = 0;						/*Clear TCCR1A register*/
	TCCR1B = 0;						/*Clear TCCR1B register and stop Timer1*/
}


/*
 * Timer1 module function used to set the call back function of the module to the passed
 * pointer to function in the parameter of (Timer1_setCallBack)
 */
void Timer1_setCallBack(void(*a_ptr)(void))
{
	g_call_back_function = a_ptr;
}




ISR(TIMER1_OVF_vect)
{
	if(g_call_back_function != NULL_PTR)
	{
		(*g_call_back_function)();
	}
}





ISR(TIMER1_COMPA_vect)
{
	if(g_call_back_function != NULL_PTR)
	{
		(*g_call_back_function)();
	}

}

