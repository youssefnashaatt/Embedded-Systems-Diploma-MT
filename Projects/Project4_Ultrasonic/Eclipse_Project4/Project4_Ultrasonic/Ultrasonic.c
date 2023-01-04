#include "Ultrasonic.h"
#include "Standard_Types.h"
#include "ICU.h"
#include "gpio.h"
#include <util/delay.h>



/*******************************************************************************
 *                           Global Variables                                  *
 *******************************************************************************/

static volatile uint8 g_edge_counter = 0;				/*Variable used to count the edges of the Echo pin*/
static volatile boolean g_echo_received = FALSE;	/*Variable used to indicate that Ultra-sonic sensor is waiting for ultra-sonic waves to reflect*/


/*Description:
 * Ultra-sonic Sensor Initialization
 * It creates a structure of Icu_ConfigType struct to initialize ICU module as required
 */
void Ultrasonic_init(void)
{
	/*Defining a structure and send it as a parameter in ICU configuration function*/
	Icu_ConfigType config = {F_CPU_8, RISING};
	Icu_init(&config);

	/*Setting the call-back function to be Ultrasonic_edgeProcessing*/
	Icu_setCallBack(Ultrasonic_edgeProcessing);

	/*set the trigger pin as output pin*/
	GPIO_setupPinDirection(Ultrasonic_Trigger_PORT_ID, Ultrasonic_Trigger_PIN_ID, PIN_OUTPUT);
}


/*Description:
 * Function used to initiate the trigger pulse
 * Duration of pulse must be within 10 us
 */
void Ultrasonic_Trigger(void)
{
	/*Write a logic high on trigger Pin*/
	GPIO_writePin(Ultrasonic_Trigger_PORT_ID, Ultrasonic_Trigger_PIN_ID, LOGIC_HIGH);

	_delay_us(15);		/*delay of pulse >= 10 micro-sec.*/

	/*Write a logic low on trigger Pin*/
	GPIO_writePin(Ultrasonic_Trigger_PORT_ID, Ultrasonic_Trigger_PIN_ID, LOGIC_LOW);
}


/*Description:
 * Function that trigger the ICU to start calculating distance
 * Get the ICR value and convert it into distance
 * Parameters: void
 * Return (uint16)Distance
 */
uint16 Ultrasonic_readDistance(void)
{
	uint16 ICR_value = 0;
	uint16 distance = 0;

	/*Trigger Ultra-sonic to initiate the 8 pulses and start measuring*/
	Ultrasonic_Trigger();

	/*Wait till the ultra-sonic wave return to echo*/
	while(g_echo_received == FALSE);

	/*Reset Echo Received Signal to its initial value*/
	g_echo_received = FALSE;

	/*Get the timer/counter register captured by ICU*/
	ICR_value = Icu_getInputCaptureValue();

	/*Calculate distance and assign it to distance variable*/
	distance = (uint16)(ICR_value/(float32)58.8 + 1);

	return distance;
}



/*Call Back Function will be called by ICU ISR*/
void Ultrasonic_edgeProcessing(void)
{
	g_edge_counter++;

	if(g_edge_counter == 1)
	{
		Icu_clearTimerValue();
		Icu_setEdgeDetectionType(FALLING);
	}

	else if(g_edge_counter == 2)
	{
		g_echo_received = TRUE;
		Icu_setEdgeDetectionType(RISING);
		Icu_clearTimerValue();
		g_edge_counter = 0;
	}
}
