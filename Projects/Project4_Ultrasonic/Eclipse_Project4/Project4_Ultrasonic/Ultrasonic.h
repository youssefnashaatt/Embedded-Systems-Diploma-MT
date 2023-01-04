#ifndef ULTRASONIC_H_
#define ULTRASONIC_H_

#include "Standard_Types.h"
#include "gpio.h"

/*******************************************************************************
 *                         Types Declaration                                   *
 *******************************************************************************/

/*Pointer to point on Ultra-sonic module call back function*/

/*Trigger PIN location on Micro-Controller*/
#define Ultrasonic_Trigger_PORT_ID		PORTB_ID
#define Ultrasonic_Trigger_PIN_ID		PIN5_ID



/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*Description:
 * Ultra-sonic Sensor Initialization
 * It creates a structure of Icu_ConfigType struct to initialize ICU module as required
 * Parameter: void
 * Return void
 */
void Ultrasonic_init(void);


/*Description:
 * Function used to initiate the trigger pulse
 * Duration of pulse must be within 10 us
 * Parameter void
 * Return void
 */
void Ultrasonic_Trigger(void);


/*Description:
 * Function that trigger the ICU to start calculating distance
 * Get the ICR value and convert it into distance
 * Parameters: void
 * Return (uint16)Distance
 */
uint16 Ultrasonic_readDistance(void);


/*Call Back Function will be called by ICU ISR*/
void Ultrasonic_edgeProcessing(void);



#endif /* ULTRASONIC_H_ */
