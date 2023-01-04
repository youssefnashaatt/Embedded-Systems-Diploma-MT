/*
 ============================================================================
 Name        : 	Temp_Sensor.c
 Author      : Youssef Nashaat
 Description :
 Date        : Oct 7, 2022
 ============================================================================
 */

#include "Temp_Sensor.h"
#include "ADC.h"


uint8 LM35_getTemperature(void)
{
	uint8 temp_value = 0;		/*Temperature measured value*/
	uint16 ADC_value = 0;		/*value converted from ADC*/

	ADC_value =  ADC_readChannel(ADC_CHANNEL_ID);	/*Read Temperature sensor value*/

	/* Calculate the temperature from the ADC value*/
	temp_value = (uint8)(((uint32)ADC_value*SENSOR_MAX_TEMP*ADC_REF_VOLT_VALUE)/(ADC_MAXIMUM_VALUE*SENSOR_MAX_VOLT));

	return temp_value;
}
