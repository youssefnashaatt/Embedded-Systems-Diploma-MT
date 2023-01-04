/*
 ===============================================================================================
 Name        : KEYPAD.h
 Author      : Youssef Nashaat
 Description :
 Date        : Oct 24, 2022
 ===============================================================================================
 */



#ifndef KEYPAD_H_
#define KEYPAD_H_

#include "Standard_Types.h"

/*
#define KEYPAD_STANDARD_MODE
*/

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
/*Define KEYPAD Mode of operation*/

#define KEYPAD_NO_OF_ROWS		4
#define KEYPAD_NO_OF_COLUMNS	4

/*
 * Define Row Select
 * Keypad Pull-up Resistance => LOGIC_LOW.
 * Keypad Pull-down Resistance => LOGIC_HIGH.
 */
#define KEYPAD_ROW_SELECT		LOGIC_LOW

/*
 * Define Row Select
 * Keypad Pull-up Resistance => LOGIC_LOW.
 * Keypad Pull-down Resistance => LOGIC_HIGH.
 */
#define KEYPAD_BUTTON_PRESSED	LOGIC_LOW


/***************************ROWS PINS CONFIGURATION*****************************/
#define KEYPAD_ROWS_PORT_ID		PORTA_ID

#define KEYPAD_ROW0_PIN_ID		PIN0_ID
#define KEYPAD_ROW1_PIN_ID		PIN1_ID
#define KEYPAD_ROW2_PIN_ID		PIN2_ID
#define KEYPAD_ROW3_PIN_ID		PIN3_ID


/***************************COLUMNS PINS CONFIGURATION*****************************/
#define KEYPAD_COLS_PORT_ID		PORTA_ID

#define KEYPAD_COL0_PIN_ID		PIN4_ID
#define KEYPAD_COL1_PIN_ID		PIN5_ID
#define KEYPAD_COL2_PIN_ID		PIN6_ID
#define KEYPAD_COL3_PIN_ID		PIN7_ID





uint8 KEYPAD_getPressedKey(void);




#endif /* KEYPAD_H_ */
