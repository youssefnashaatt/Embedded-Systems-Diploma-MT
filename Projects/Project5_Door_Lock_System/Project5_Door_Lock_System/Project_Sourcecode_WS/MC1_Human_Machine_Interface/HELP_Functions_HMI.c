#include <util/delay.h>
#include "KEYPAD.h"
#include "LCD.h"
#include "HELP_Functions_HMI.h"





void HMI_TakePasswordFromUser(uint8 *password)
{
	uint8 i;

	for(i = 0 ; i < PASS_MAX_SIZE ; i++)
	{
		password[i] = KEYPAD_getPressedKey();	/*Get character from Keypad*/
		LCD_displayCharacter('*');				/*Display '*' by taking each character*/
		_delay_ms(270);
	}

	while(KEYPAD_getPressedKey() != '#');		/*Wait till the user enter '#' as enter*/

	password[5] = '#';							/*Assign the last character as '#'*/
	password[6] = '\0';							/*Terminate string to be sent by UART*/

}


