/*
 ============================================================================
 Name        : LCD.c
 Author      : Youssef Nashaat
 Description :
 Date        : Oct 24, 2022
 ============================================================================
 */

#include "LCD.h"
#include "GPIO.h"
#include "Macros.h"
#include <stdlib.h>
#include <util/delay.h>

void LCD_init(void)
{
	/*Set ENABLE Pin as output pin*/
	GPIO_setupPinDirection(LCD_ENABLE_PORT_ID, LCD_ENABLE_PIN_ID, PIN_OUTPUT);

	/*Set RS Pin as output pin*/
	GPIO_setupPinDirection(LCD_RS_PORT_ID, LCD_RS_PIN_ID, PIN_OUTPUT);

	_delay_ms(20);

#if(LCD_MODE_BITS == 4)

	/*Set the 4 Data pins as Output Pins*/
	GPIO_setupPinDirection(LCD_DATA_PORT_ID, LCD_DB4_PIN_ID, PIN_OUTPUT);
	GPIO_setupPinDirection(LCD_DATA_PORT_ID, LCD_DB5_PIN_ID, PIN_OUTPUT);
	GPIO_setupPinDirection(LCD_DATA_PORT_ID, LCD_DB6_PIN_ID, PIN_OUTPUT);
	GPIO_setupPinDirection(LCD_DATA_PORT_ID, LCD_DB7_PIN_ID, PIN_OUTPUT);

	/* Send for 4 bit initialization of LCD  */
	LCD_sendCommand(LCD_TWO_LINES_FOUR_BITS_MODE_INIT1);
	LCD_sendCommand(LCD_TWO_LINES_FOUR_BITS_MODE_INIT2);

	/* use 2-lines LCD + 4-bits Data Mode + 5*7 dot display Mode */
	LCD_sendCommand(LCD_TWO_LINES_FOUR_BITS_MODE);

#elif(LCD_MODE_BITS == 8)

	GPIO_setupPortDirection(LCD_DATA_PORT_ID, PORT_OUTPUT);

	LCD_sendCommand(LCD_TWO_LINES_EIGHT_BITS_MODE);

#endif

	LCD_sendCommand(LCD_DISPLAY_ON_CURSOR_OFF); /* cursor off */
	LCD_sendCommand(LCD_CLEAR_DISPLAY); /* clear LCD at the beginning */
}




void LCD_sendCommand(uint8 command)
{
	/*RS = LOGIC_LOW --> Transferring Instruction*/
	GPIO_writePin(LCD_RS_PORT_ID,LCD_RS_PIN_ID, LOGIC_LOW);

	_delay_us(1);		/*delay for LCD Hardware*/

	/*ENABLE = LOGIC_HIGH --> DATA ENABLE*/
	GPIO_writePin(LCD_ENABLE_PORT_ID, LCD_ENABLE_PIN_ID, LOGIC_HIGH);

	_delay_us(1);		/*T(DDR)*/

#if(LCD_MODE_BITS == 4)

	/*Writing Most-Significant 4 Bits*/
	GPIO_writePin(LCD_DATA_PORT_ID, LCD_DB4_PIN_ID, GET_BIT(command, PIN4_ID));
	GPIO_writePin(LCD_DATA_PORT_ID, LCD_DB5_PIN_ID, GET_BIT(command, PIN5_ID));
	GPIO_writePin(LCD_DATA_PORT_ID, LCD_DB6_PIN_ID, GET_BIT(command, PIN6_ID));
	GPIO_writePin(LCD_DATA_PORT_ID, LCD_DB7_PIN_ID, GET_BIT(command, PIN7_ID));

	_delay_ms(1);			/*Hold Time Delay*/

	/*Enable = LOGIC_LOW --> DATA DISABLE*/
	GPIO_writePin(LCD_ENABLE_PORT_ID, LCD_ENABLE_PIN_ID, LOGIC_LOW);

	_delay_ms(1);			/*Hardware Processing time delay*/

	/*Enable = LOGIC_LOW --> DATA DISABLE*/
	GPIO_writePin(LCD_ENABLE_PORT_ID, LCD_ENABLE_PIN_ID, LOGIC_HIGH);

	_delay_us(1);		/*T(DDR)*/

	/*Writing Most-Significant 4 Bits*/
	GPIO_writePin(LCD_DATA_PORT_ID, LCD_DB4_PIN_ID, GET_BIT(command, PIN0_ID));
	GPIO_writePin(LCD_DATA_PORT_ID, LCD_DB5_PIN_ID, GET_BIT(command, PIN1_ID));
	GPIO_writePin(LCD_DATA_PORT_ID, LCD_DB6_PIN_ID, GET_BIT(command, PIN2_ID));
	GPIO_writePin(LCD_DATA_PORT_ID, LCD_DB7_PIN_ID, GET_BIT(command, PIN3_ID));

#elif(LCD_MODE_BITS == 8)

	GPIO_writePort(LCD_DATA_PORT_ID, command);

#endif


	_delay_ms(1);			/*Hold Time Delay*/

	/*Enable = LOGIC_LOW --> DATA DISABLE*/
	GPIO_writePin(LCD_ENABLE_PORT_ID, LCD_ENABLE_PIN_ID, LOGIC_LOW);

	_delay_ms(1);

}




void LCD_displayCharacter(uint8 data)
{
	/*RS = LOGIC_LOW --> Transferring Character*/
	GPIO_writePin(LCD_RS_PORT_ID,LCD_RS_PIN_ID, LOGIC_HIGH);

	_delay_us(1);		/*delay for LCD Hardware*/

	/*ENABLE = LOGIC_HIGH --> DATA ENABLE*/
	GPIO_writePin(LCD_ENABLE_PORT_ID, LCD_ENABLE_PIN_ID, LOGIC_HIGH);

	_delay_us(1);		/*T(DDR)*/

#if(LCD_MODE_BITS == 4)

	/*Writing Most-Significant 4 Bits*/
	GPIO_writePin(LCD_DATA_PORT_ID, LCD_DB4_PIN_ID, GET_BIT(data, PIN4_ID));
	GPIO_writePin(LCD_DATA_PORT_ID, LCD_DB5_PIN_ID, GET_BIT(data, PIN5_ID));
	GPIO_writePin(LCD_DATA_PORT_ID, LCD_DB6_PIN_ID, GET_BIT(data, PIN6_ID));
	GPIO_writePin(LCD_DATA_PORT_ID, LCD_DB7_PIN_ID, GET_BIT(data, PIN7_ID));

	_delay_ms(1);			/*Hold Time Delay*/

	/*Enable = LOGIC_LOW --> DATA DISABLE*/
	GPIO_writePin(LCD_ENABLE_PORT_ID, LCD_ENABLE_PIN_ID, LOGIC_LOW);

	_delay_ms(1);			/*Hardware Processing time delay*/

	/*Enable = LOGIC_LOW --> DATA DISABLE*/
	GPIO_writePin(LCD_ENABLE_PORT_ID, LCD_ENABLE_PIN_ID, LOGIC_HIGH);

	_delay_us(1);		/*T(DDR)*/

	/*Writing Most-Significant 4 Bits*/
	GPIO_writePin(LCD_DATA_PORT_ID, LCD_DB4_PIN_ID, GET_BIT(data, PIN0_ID));
	GPIO_writePin(LCD_DATA_PORT_ID, LCD_DB5_PIN_ID, GET_BIT(data, PIN1_ID));
	GPIO_writePin(LCD_DATA_PORT_ID, LCD_DB6_PIN_ID, GET_BIT(data, PIN2_ID));
	GPIO_writePin(LCD_DATA_PORT_ID, LCD_DB7_PIN_ID, GET_BIT(data, PIN3_ID));

#elif(LCD_MODE_BITS == 8)

	GPIO_writePort(LCD_DATA_PORT_ID, data);

#endif


	_delay_ms(1);			/*Hold Time Delay*/

	/*Enable = LOGIC_LOW --> DATA DISABLE*/
	GPIO_writePin(LCD_ENABLE_PORT_ID, LCD_ENABLE_PIN_ID, LOGIC_LOW);

}




void LCD_displayString(const char *Str)
{
	uint8 i = 0;

	while(Str[i] != '\0')
	{
		LCD_displayCharacter(Str[i]);
		i++;
	}
}



void LCD_moveCursor(uint8 row,uint8 col)
{
	uint8 Location;

	switch(row)
	{
	case 0:
		Location = col;
		break;

	case 1:
		Location = 0x40 | col;
		break;

	case 2:
		Location = 0x10 | col;
		break;

	case 3:
		Location = 0x50 | col;
		break;
	}

	LCD_sendCommand(LCD_SET_CURSOR_POSITION | Location);
}



void LCD_displayStringRowColumn(uint8 row,uint8 col,const char *Str)
{
	LCD_moveCursor(row, col);
	LCD_displayString(Str);
}


void LCD_intgerToString(int data)
{
	char buffer[16];
	itoa(data,buffer,10);
	LCD_displayString(buffer);
}


void LCD_clearScreen(void)
{
	LCD_sendCommand(LCD_CLEAR_DISPLAY);
}
