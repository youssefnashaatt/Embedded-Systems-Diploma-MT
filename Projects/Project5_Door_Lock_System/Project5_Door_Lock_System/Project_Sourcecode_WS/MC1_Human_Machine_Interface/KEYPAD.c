/*
 ===============================================================================================
 Name        : KEYPAD.c
 Author      : Youssef Nashaat
 Description :
 Date        : Oct 24, 2022
 ===============================================================================================
 */


#include "KEYPAD.h"
#include "GPIO.h"
#include <util/delay.h>

/*******************************************************************************
 *                        Private Functions Proto-type                         *
 *******************************************************************************/

#ifndef KEYPAD_STANDARD_MODE
static uint8 KEYPAD_adjustKeyNumber(uint8 button_number);
#endif


/*******************************************************************************
 *                            Functions Definition                             *
 *******************************************************************************/

/*
 * Description:
 * KEYPAD Module Function used to scan for a pressed key.
 * Arguments: uint8: void
 * Return-Type: uint8: value of key pressed
 * Functionality: Operates on Polling technique waiting for a key to be pressed on keypad.
 * After the key is pressed, if KEYPAD_STANDARD_MODE is defined, the function will return the index of the key incremented by one.
 * If the KEYPAD_STANDARD_MODE is not defined the index of the key will be passed to KEYPAD_adjustKeyNumber() function
 * to substitute the scanned index with the real value on keypad.
 */
uint8 KEYPAD_getPressedKey(void)
{
	uint8 rows_count;			/*Rows index*/
	uint8 cols_count;			/*Columns index*/
	uint8 key_index;			/*Keys index increment by incrementing each key scanning*/

	/*Set the direction of rows pins as input*/
	GPIO_setupPinDirection(KEYPAD_ROWS_PORT_ID, KEYPAD_ROW0_PIN_ID, PIN_INPUT);
	GPIO_setupPinDirection(KEYPAD_ROWS_PORT_ID, KEYPAD_ROW1_PIN_ID, PIN_INPUT);
	GPIO_setupPinDirection(KEYPAD_ROWS_PORT_ID, KEYPAD_ROW2_PIN_ID, PIN_INPUT);
	GPIO_setupPinDirection(KEYPAD_ROWS_PORT_ID, KEYPAD_ROW3_PIN_ID, PIN_INPUT);

	/*Set the direction of columns pins as input*/
	GPIO_setupPinDirection(KEYPAD_COLS_PORT_ID, KEYPAD_COL0_PIN_ID, PIN_INPUT);
	GPIO_setupPinDirection(KEYPAD_COLS_PORT_ID, KEYPAD_COL1_PIN_ID, PIN_INPUT);
	GPIO_setupPinDirection(KEYPAD_COLS_PORT_ID, KEYPAD_COL2_PIN_ID, PIN_INPUT);
#if(KEYPAD_NO_OF_COLUMNS == 4)
	GPIO_setupPinDirection(KEYPAD_COLS_PORT_ID, KEYPAD_COL3_PIN_ID, PIN_INPUT);
#endif


	while(1)
	{
		/*Looping on each Row */
		for(rows_count = 0 , key_index = 1 ; rows_count < KEYPAD_NO_OF_ROWS ; rows_count++)
		{
			/*Direction of Row to be scanned as output and all other rows input*/
			GPIO_setupPinDirection(KEYPAD_ROWS_PORT_ID, KEYPAD_ROW0_PIN_ID + rows_count , PIN_OUTPUT);

			/*Select this specific row
			 * LOGIC_LOW => KEYPAD Pull-up Resistance
			 * LOGIC_HIGH => KEYPAD Pull-down Resistance
			 */
			GPIO_writePin(KEYPAD_ROWS_PORT_ID, KEYPAD_ROW0_PIN_ID + rows_count , KEYPAD_ROW_SELECT);

			/*Looping on each column in a specific Row*/
			for(cols_count = 0 ; cols_count < KEYPAD_NO_OF_COLUMNS ; cols_count++)
			{
				/*
				 * KEYPAD button is pressed
				 * LOGIC_LOW => Pull-up Resistance
				 * LOGIC_HIGH => Pull-down Resistance
				 */
				if(GPIO_readPin(KEYPAD_COLS_PORT_ID, KEYPAD_COL0_PIN_ID + cols_count) == KEYPAD_BUTTON_PRESSED)
				{

					if(GPIO_readPin(KEYPAD_COLS_PORT_ID, KEYPAD_COL0_PIN_ID + cols_count) == KEYPAD_BUTTON_PRESSED)
					{

						_delay_us(800);
						/*Return scanned Row as Input again*/
						/*GPIO_setupPinDirection(KEYPAD_ROWS_PORT_ID, KEYPAD_ROW0_PIN_ID + rows_count , PIN_INPUT);*/

#ifndef KEYPAD_STANDARD_MODE
						/*Substitute the index of key with the equivalent number or letter on keypad*/
						return KEYPAD_adjustKeyNumber(key_index);
#else
						/*Return the index of key incremented by one*/
						return ((rows_count*KEYPAD_NO_OF_COLUMNS)+cols_count+1);
#endif
					}
				}

				key_index++;
			}

			/*Return scanned Row as Input again*/
			GPIO_setupPinDirection(KEYPAD_ROWS_PORT_ID, KEYPAD_ROW0_PIN_ID + rows_count , PIN_INPUT);

		}
	}
}




#ifndef KEYPAD_STANDARD_MODE
/*
 * Description:
 * KEYPAD Module Function used to convert the index of the key to its equivalent value from keypad.
 * Arguments: uint8: button_number
 * Return-Type: uint8: value of key pressed
 * Functionality: Switch on all the possible values of key indexes and return the value of the
 * annotated keypad key.
 */
static uint8 KEYPAD_adjustKeyNumber(uint8 button_number)
{
	uint8 key_value;

	switch(button_number)
	{
	case 1:
		key_value = 7;
		break;

	case 2:
		key_value = 8;
		break;

	case 3:
		key_value = 9;
		break;

	case 4:
		key_value = '/';
		break;

	case 5:
		key_value = 4;
		break;

	case 6:
		key_value = 5;
		break;

	case 7:
		key_value = 6;
		break;

	case 8:
		key_value = 'x';
		break;

	case 9:
		key_value = 1;
		break;

	case 10:
		key_value = 2;
		break;

	case 11:
		key_value = 3;
		break;

	case 12:
		key_value = '-';
		break;

#if(KEYPAD_NO_OF_COLUMNS == 4)
	case 13:
		key_value = '#';
		break;

	case 14:
		key_value = 0;
		break;

	case 15:
		key_value = '=';
		break;

	case 16:
		key_value = '+';
		break;

#endif
	}

	return key_value;
}

#endif
