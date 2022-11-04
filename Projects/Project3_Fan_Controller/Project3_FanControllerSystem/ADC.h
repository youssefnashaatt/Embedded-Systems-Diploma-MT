/*
 ============================================================================
 Name        : ADC.h
 Author      : Youssef Nashaat
 Description : ADC Module
 Date        : Oct 6, 2022
 ============================================================================
 */

#ifndef ADC_H_
#define ADC_H_

#include "Standard_Types.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

/*Please enter to operate ADC as Polling or Interrupt Technique*/
#define ADC_Technique Polling

#define Polling		0
#define Interrupt	1


#define ADC_MAXIMUM_VALUE    1023
#define ADC_REF_VOLT_VALUE   5

#define ADC0	0
#define ADC1	1
#define ADC2	2
#define ADC3	3
#define ADC4	4
#define ADC5	5
#define ADC6	6
#define ADC7	7


/*******************************************************************************
 *                               Types Declaration                             *
 *******************************************************************************/


/*Defining an enum for Voltage Reference Selection (2 Bits)*/
typedef enum
{
	AREF, AVCC, InternalVoltageReference = 3
}ADC_ReferenceVolatge;


/*Defining an enum for ADC Pre-scaler*/
typedef enum
{
	F_ADC0, F_ADC2, F_ADC4, F_ADC8, F_ADC16, F_ADC32, F_ADC64, F_ADC128
}ADC_Prescaler;


/*Defining a configuration structure as a parameter for initialization function*/
/*A Structure of ADC_ConfigType must be provided to initialization function*/
typedef struct
{
	ADC_ReferenceVolatge ref_volt;
	ADC_Prescaler prescale;
}ADC_ConfigType;


#if(ADC_Technique == Interrupt)
/*******************************************************************************
 *                       External Variables                                    *
 *******************************************************************************/

/* Extern Public global variables to be used by other modules */
extern volatile uint16 g_adcResult;

#endif


/*******************************************************************************
 *                              Functions Prototypes                           *
 *******************************************************************************/

/*
 * Description :
 * Initialize ADC Module with pre-given arguments.
 * Argument type is from (ADC_ConfigType Structure).
 * Arguments contain ADC_ReferenceVoltage enum and ADC_Prescaler enum.
 */
void ADC_init(const ADC_ConfigType * Config_Ptr);


/*
 * Description :
 * Start Channel Conversion Function.
 * Argument is ADC Channel.
 * Insert this channel in ADMUX Register BITS0:4
 * Return uint16 data-type containing the conversion value first 10 bits
 */

uint16 ADC_readChannel(uint8 channel_num);

#endif /* ADC_H_ */
