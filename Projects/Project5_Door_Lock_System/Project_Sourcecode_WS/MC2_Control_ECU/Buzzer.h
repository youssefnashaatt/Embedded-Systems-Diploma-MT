/*
 ===============================================================================================
 Name        : Buzzer.h
 Author      : Youssef Nashaat
 Description :
 Date        : Oct 24, 2022
 ===============================================================================================
 */
#ifndef BUZZER_H_
#define BUZZER_H_


/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

#define BUZZER_PORT_ID	PORTD_ID
#define BUZZER_PIN_ID	PIN7_ID


/*******************************************************************************
 *                           Function Proto-types                              *
 *******************************************************************************/

/*
 * Description:
 * Setup the direction for the buzzer pin as output pin through the GPIO driver.
 * Turn off the buzzer through the GPIO
 * Inputs: void
 * Return: void
 */
void Buzzer_init(void);


/*
 * Description:
 * Function to enable the Buzzer through the GPIO
 * Input: void
 * Return: void
 */
void Buzzer_on(void);


/*
 * Description:
 * Function to disable the Buzzer through the GPIO.
 * Input: void
 * Return: void
 */
void Buzzer_off(void);


#endif /* BUZZER_H_ */
