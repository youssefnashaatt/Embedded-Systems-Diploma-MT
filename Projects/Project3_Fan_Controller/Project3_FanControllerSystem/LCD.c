/*
 ============================================================================
 Name        : LCD.c
 Author      : Youssef Nashaat
 Description :
 Date        : Oct 6, 2022
 ============================================================================
 */

#include "MACROS.h"
#include "LCD.h"
#include "gpio.h"
#include <util/delay.h>
#include <stdlib.h>



void LCD_init(void)
{
	/*Set RS & Enable pins as Output Pins*/
	GPIO_setupPinDirection(LCD_RS_PORT_ID, LCD_RS_PIN_ID, PIN_OUTPUT);
	GPIO_setupPinDirection(LCD_Enable_PORT_ID, LCD_Enable_PIN_ID, PIN_OUTPUT);

	_delay_ms(20);

#if(LCD_MODE_BITS == 4)

	/*Configure 4 pins as output pins*/
	GPIO_setupPinDirection(LCD_DATA_PORT_ID, LCD_DB4_ID, PIN_OUTPUT);
	GPIO_setupPinDirection(LCD_DATA_PORT_ID, LCD_DB5_ID, PIN_OUTPUT);
	GPIO_setupPinDirection(LCD_DATA_PORT_ID, LCD_DB6_ID, PIN_OUTPUT);
	GPIO_setupPinDirection(LCD_DATA_PORT_ID, LCD_DB7_ID, PIN_OUTPUT);

	/* Send for 4 bit initialization of LCD  */
	LCD_sendCommand(LCD_TWO_LINES_FOUR_BITS_MODE_INIT1);
	LCD_sendCommand(LCD_TWO_LINES_FOUR_BITS_MODE_INIT2);

	/* use 2-lines LCD + 4-bits Data Mode + 5*7 dot display Mode */
	LCD_sendCommand(LCD_TWO_LINES_FOUR_BITS_MODE);

#elif(LCD_MODE_BITS == 8)

	/*Configure LCD Data Port as Output Port*/
	GPIO_setupPortDirection(LCD_DATA_PORT_ID, PORT_OUTPUT);

	/*Initialize LCD 2 LINES 4 BITS Mode*/
	LCD_sendCommand(LCD_TWO_LINES_EIGHT_BITS_MODE);

#endif

	LCD_sendCommand(LCD_CURSOR_OFF); /* cursor off */
	LCD_sendCommand(LCD_CLEAR_COMMAND); /* clear LCD at the beginning */
}



/*Description:
 * Sending Command to LCD whether 8Bits mode or 4Bits mode.
 * Argument Type: uint8 (command value)
 * Return void
 */
void LCD_sendCommand(uint8 cmd)
{
	GPIO_writePin(LCD_RS_PORT_ID, LCD_RS_PIN_ID, LOGIC_LOW);			/*RS = 0 for Command Instruction*/
	_delay_ms(1);														/*Delay for Processing*/
	GPIO_writePin(LCD_Enable_PORT_ID, LCD_Enable_PIN_ID, LOGIC_HIGH);	/*Enable Pin = 1*/
	_delay_ms(1);														/*Delay for Processing*/

#if(LCD_MODE_BITS == 4)

	/*Transferring the Most-significant 4 bits of command value to LCD*/
	GPIO_writePin(LCD_DATA_PORT_ID, LCD_DB4_ID, GET_BIT(cmd,4));
	GPIO_writePin(LCD_DATA_PORT_ID, LCD_DB5_ID, GET_BIT(cmd,5));
	GPIO_writePin(LCD_DATA_PORT_ID, LCD_DB6_ID, GET_BIT(cmd,6));
	GPIO_writePin(LCD_DATA_PORT_ID, LCD_DB7_ID, GET_BIT(cmd,7));


	_delay_ms(1);		/*delay 1us for processing*/

	/*Disable LCD (Clear enable pin)*/
	GPIO_writePin(LCD_Enable_PORT_ID, LCD_Enable_PIN_ID, LOGIC_LOW);

	_delay_ms(1);/*delay 1us for processing*/

	/*Enable LCD (Set Enable Pin)*/
	GPIO_writePin(LCD_Enable_PORT_ID, LCD_Enable_PIN_ID, LOGIC_HIGH);

	/*Transferring the Least-significant 4 bits of command value to LCD*/
	GPIO_writePin(LCD_DATA_PORT_ID, LCD_DB4_ID, GET_BIT(cmd,0));
	GPIO_writePin(LCD_DATA_PORT_ID, LCD_DB5_ID, GET_BIT(cmd,1));
	GPIO_writePin(LCD_DATA_PORT_ID, LCD_DB6_ID, GET_BIT(cmd,2));
	GPIO_writePin(LCD_DATA_PORT_ID, LCD_DB7_ID, GET_BIT(cmd,3));

	_delay_ms(1);		/*delay for processing*/

	/*Disable LCD (Clear Enable pin)*/
	GPIO_writePin(LCD_Enable_PORT_ID, LCD_Enable_PIN_ID, LOGIC_LOW);
	_delay_ms(1);		/*delay for processing*/

#elif(LCD_MODE_BITS == 8)

	/*Transferring cmd value to LCD*/
	GPIO_writePort(LCD_DATA_PORT_ID, cmd);

	_delay_ms(1);		/*delay for processing*/

	/*Disable LCD (Clear Enable pin)*/
	GPIO_writePin(LCD_Enable_PORT_ID, LCD_Enable_PIN_ID, LOGIC_LOW);
	_delay_ms(1);		/*delay for processing*/

#endif

}


/*Description:
 * Sending Character to LCD whether 8Bits mode or 4Bits mode.
 * Argument Type: uint8 (command value)
 * Return void
 */
void LCD_displayCharacter(uint8 character)
{
	GPIO_writePin(LCD_RS_PORT_ID, LCD_RS_PIN_ID, LOGIC_HIGH);			/*RS = 1 for Displaying character*/
	_delay_ms(1);														/*Delay for Processing*/
	GPIO_writePin(LCD_Enable_PORT_ID, LCD_Enable_PIN_ID, LOGIC_HIGH);	/*Enable Pin = 1*/
	_delay_ms(1);														/*Delay for Processing*/

#if(LCD_MODE_BITS == 4)

	/*Transferring the Most-significant 4 bits of character value to LCD*/
	GPIO_writePin(LCD_DATA_PORT_ID, LCD_DB4_ID, GET_BIT(character,4));
	GPIO_writePin(LCD_DATA_PORT_ID, LCD_DB5_ID, GET_BIT(character,5));
	GPIO_writePin(LCD_DATA_PORT_ID, LCD_DB6_ID, GET_BIT(character,6));
	GPIO_writePin(LCD_DATA_PORT_ID, LCD_DB7_ID, GET_BIT(character,7));


	_delay_ms(1);		/*delay 1us for processing*/

	/*Disable LCD (Clear enable pin)*/
	GPIO_writePin(LCD_Enable_PORT_ID, LCD_Enable_PIN_ID, LOGIC_LOW);

	_delay_ms(1);/*delay 1us for processing*/

	/*Enable LCD (Set Enable Pin)*/
	GPIO_writePin(LCD_Enable_PORT_ID, LCD_Enable_PIN_ID, LOGIC_HIGH);

	/*Transferring the Least-significant 4 bits of character value to LCD*/
	GPIO_writePin(LCD_DATA_PORT_ID, LCD_DB4_ID, GET_BIT(character,0));
	GPIO_writePin(LCD_DATA_PORT_ID, LCD_DB5_ID, GET_BIT(character,1));
	GPIO_writePin(LCD_DATA_PORT_ID, LCD_DB6_ID, GET_BIT(character,2));
	GPIO_writePin(LCD_DATA_PORT_ID, LCD_DB7_ID, GET_BIT(character,3));

	_delay_ms(1);		/*delay for processing*/

	/*Disable LCD (Clear Enable pin)*/
	GPIO_writePin(LCD_Enable_PORT_ID, LCD_Enable_PIN_ID, LOGIC_LOW);
	_delay_ms(1);		/*delay for processing*/

#elif(LCD_MODE_BITS == 8)

	/*Transferring character value to LCD*/
	GPIO_writePort(LCD_DATA_PORT_ID, character);

	_delay_ms(1);		/*delay for processing*/

	/*Disable LCD (Clear Enable pin)*/
	GPIO_writePin(LCD_Enable_PORT_ID, LCD_Enable_PIN_ID, LOGIC_LOW);
	_delay_ms(1);		/*delay for processing*/

#endif

}



/*Description:
 * Sending Character to LCD whether 8Bits mode or 4Bits mode.
 * Argument Type: uint8 (command value)
 * Return void
 */
void LCD_displayString(const char *string)
{
	int i = 0;		/*Counter for characters in string*/

	while(string[i] != '\0')
	{
		LCD_displayCharacter(string[i]);

		i++;
	}
}


/*Description:
 * Move the cursor to any direction within 2x16 LCD.
 * Argument Type: uint8: row location & uint8: column location
 * Return void
 */
void LCD_moveCursor(uint8 row, uint8 col)
{
	uint8 lcd_memory_address = 0;

	switch(row)
	{
	case 0:
		lcd_memory_address = col;
		break;

	case 1:
		lcd_memory_address = 0x40 | col;
		break;

	case 2:
		lcd_memory_address = 0x10 | col;
		break;

	case 3:
		lcd_memory_address = 0x50 | col;
		break;
	}

	LCD_sendCommand(LCD_SET_CURSOR_LOCATION | lcd_memory_address);
}



/*Description :
 * Display the required string in a specified row and column index on the screen
 */
void LCD_displayStringRowColumn(uint8 row,uint8 col,const char *Str)
{
	LCD_moveCursor(row,col); /* go to to the required LCD position */
	LCD_displayString(Str); /* display the string */
}



/*Description :
 * Clear Screen Command Function
 */
void LCD_clearScreen(void)
{
	LCD_sendCommand(LCD_CLEAR_COMMAND);
}



/*Description :
 * Converting integer variable to string
 */
void LCD_intgerToString(int integer)
{
	char buffer[16];

	if(integer < 0)
	{
		LCD_displayCharacter('-');
		itoa(integer,(buffer),10);
		LCD_displayString(buffer);
	}

	else
	{
		itoa(integer,buffer,10);
		LCD_displayString(buffer);
	}
}

