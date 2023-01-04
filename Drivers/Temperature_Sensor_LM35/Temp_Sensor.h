/*
 ============================================================================
 Name        : 	Temp_Sensor.h
 Author      : Youssef Nashaat
 Description :
 Date        : Oct 7, 2022
 ============================================================================
 */

#ifndef TEMP_SENSOR_H_
#define TEMP_SENSOR_H_

#include "Standard_Types.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

#define ADC_CHANNEL_ID	2
#define SENSOR_MAX_VOLT		1.5
#define SENSOR_MAX_TEMP		150


/*******************************************************************************
 *                              Functions Prototypes                           *
 *******************************************************************************/

uint8 LM35_getTemperature(void);

#endif /* TEMP_SENSOR_H_ */
