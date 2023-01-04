/*
 ================================================================================================
 Name        : MC2.c
 Author      : Mohamed Tarek
 Description : MC2 Code in Exercise3
 Date        : 19/9/2014
 ================================================================================================
 */ 

#include <avr/io.h>
#include <util/delay.h>
#include "UART.h"
#include "KEYPAD.h"
#include "LCD.h"
#include "Timer1.h"
#include "HELP_Functions_HMI.h"


/*******************************************************************************
 *                               Global-Variables                              *
 *******************************************************************************/

uint8 volatile g_ticks;			/*Variable to count seconds in timer module*/
uint8 g_incorrect_pass_count = 0;  /*Variable to count numbers of incorrect pass entered*/


/*Initialization structure Timer1 module: Initial value: 0 / Compare value: 3906 / CLK_Prescaler: 256 / Compare mode
 * second per increment
 */
Timer1_ConfigType g_timer1_config = {0, 3906, CLK_PRESCALER_256, COMPARE_MODE};


/*******************************************************************************
 *                             Functions_Prototypes                            *
 *******************************************************************************/

void HMI_CreatePassword(void);
void HMI_OpenDoor(void);
void HMI_ChangePass(void);
void HMI_AlarmMode(void);
void Timer_CallBackFunction(void);





/*******************************************************************************
 *                                    MAIN                                     *
 *******************************************************************************/

int main(void)
{
	uint8 Str[20];

	/*************************Initialization Structures**************************/
	UART_ConfigType uart_config = {Bits_8, Disabled, One_Bit, 9600};


	/*************************Initialization Functions***************************/
	UART_init(&uart_config);
	LCD_init();
	SREG |= (1<<7);


	LCD_clearScreen();

	HMI_CreatePassword();

	/*Main Options set menu (All other ways return to this while 1 after executing it's function*/
	while(1)
	{
		uint8 key_pressed;

		LCD_clearScreen();
		LCD_displayString("+ : Open Door");
		LCD_displayStringRowColumn(1,0,"- : Change Pass");



		key_pressed = KEYPAD_getPressedKey();

		/*Establishing connection between HMI and Control*/
		UART_sendByte(HMI_READY_UART);
		while(UART_receiveByte() != CONTROL_READY_UART);

		UART_sendByte(key_pressed);		/*Sending state notification byte*/

		/*Transferring control to HMI_OpenDoor() or HMI_ChangePass based on user entered symbol*/
		if(key_pressed == '+')
		{
			LCD_clearScreen();
			_delay_ms(200);
			HMI_OpenDoor();
		}

		else if(key_pressed == '-')
		{
			LCD_clearScreen();
			_delay_ms(200);
			HMI_ChangePass();
		}
	}
}



void HMI_CreatePassword(void)
{
	uint8 password_first[PASS_MAX_SIZE + 2];				/*User First enter password*/
	uint8 password_second[PASS_MAX_SIZE + 2];				/*User Second enter password*/
	bool Passwords_Match;

	/*****************************User First Enter Password*****************************/
	LCD_displayString("Enter Password:");
	LCD_moveCursor(1,0);

	HMI_TakePasswordFromUser(password_first);

	LCD_clearScreen();

	_delay_ms(100);

	/****************************User Second Enter Password****************************/
	LCD_displayString("Re-Enter Pass:");
	LCD_moveCursor(1,0);

	HMI_TakePasswordFromUser(password_second);


	/******************************Sending First Password******************************/

	/* Wait until MC2 is ready to receive the string */
	while(UART_receiveByte() != CONTROL_READY_UART){}

	/* Send the required string to MC2 through UART */
	UART_sendString(password_first);


	/*****************************Sending Second Password*****************************/

	/*Wait until MC2 is ready to receive the string*/
	while(UART_receiveByte() != CONTROL_READY_UART){}

	/*Send the required string to MC2 through UART*/
	UART_sendString(password_second);


	/***********************Display Passwords Matching Feedback************************/

	LCD_clearScreen();
	_delay_ms(300);

	/* Send MC2_READY byte to MC1 to ask it to send the string */
	UART_sendByte(HMI_READY_UART);

	/* Receive Confirmation byte from MC1 through UART */
	Passwords_Match = UART_receiveByte();

	if(Passwords_Match)
	{
		LCD_displayString("PASSWORDS MATCH");
		LCD_displayStringRowColumn(1, 0, "PASS SAVED");
		_delay_ms(500);
		LCD_clearScreen();
	}

	else
	{
		LCD_displayString("PASSWORD UNMATCH");
		_delay_ms(500);
		LCD_clearScreen();
		HMI_CreatePassword();
	}

}


void HMI_OpenDoor(void)
{
	uint8 password[PASS_MAX_SIZE + 2];
	bool Passwords_Match;

	/********************************User Enter Password********************************/

	LCD_clearScreen();
	LCD_displayString("Enter Password:");
	LCD_moveCursor(1,0);

	HMI_TakePasswordFromUser(password);

	/******************************Sending User's Password******************************/

	/*Establishing connection between HMI and Control*/
	UART_sendByte(HMI_READY_UART);
	while(UART_receiveByte() != CONTROL_READY_UART);

	UART_sendString(password);


	/**************************Receiving Password Entered Feedback************************/

	/*Establishing connection between HMI and Control*/
	UART_sendByte(HMI_READY_UART);
	while(UART_receiveByte() != CONTROL_READY_UART);

	/* Receive Confirmation byte from MC1 through UART */
	Passwords_Match = UART_receiveByte();


	/*****************************Display Open Door Sequence**************************/

	if(Passwords_Match)
	{
		g_incorrect_pass_count = 0;

		Timer1_init(&g_timer1_config);
		Timer1_setCallBack(&Timer_CallBackFunction);

		g_ticks = 0;
		LCD_clearScreen();
		LCD_displayString("Door Opening");
		while(g_ticks < DOOR_MOTION_TIME);

		g_ticks = 0;
		LCD_clearScreen();
		LCD_displayString("Door Open");
		while(g_ticks < DOOR_HOLD_TIME);

		g_ticks = 0;
		LCD_clearScreen();
		LCD_displayString("Door Closing");
		while(g_ticks < DOOR_MOTION_TIME);

		Timer1_deInit();
	}


	else
	{
		LCD_clearScreen();
		LCD_displayString("Pass Incorrect");

		_delay_ms(200);

		g_incorrect_pass_count++;

		if(g_incorrect_pass_count == 3)
			HMI_AlarmMode();

		else
			HMI_OpenDoor();
	}

}


void HMI_ChangePass(void)
{
	uint8 password[PASS_MAX_SIZE + 2];
	bool Passwords_Match;

	/********************************User Enter Password********************************/

	LCD_clearScreen();
	LCD_displayString("Enter Password:");
	LCD_moveCursor(1,0);

	HMI_TakePasswordFromUser(password);

	/******************************Sending User's Password******************************/

	/*Establishing connection between HMI and Control*/
	UART_sendByte(HMI_READY_UART);
	while(UART_receiveByte() != CONTROL_READY_UART);

	UART_sendString(password);


	/**************************Receiving Password Entered Feedback************************/

	/*Establishing connection between HMI and Control*/
	UART_sendByte(HMI_READY_UART);
	while(UART_receiveByte() != CONTROL_READY_UART);

	/* Receive Confirmation byte from MC1 through UART */
	Passwords_Match = UART_receiveByte();


	/*****************************Display Open Door Sequence**************************/

	if(Passwords_Match)
	{
		LCD_clearScreen();
		LCD_displayString("Pass Correct");
		_delay_ms(200);

		HMI_CreatePassword();
	}


	else
	{
		LCD_clearScreen();
		LCD_displayString("Pass Incorrect");
		_delay_ms(200);

		g_incorrect_pass_count++;

		if(g_incorrect_pass_count == 3)
			HMI_AlarmMode();

		else
			HMI_ChangePass();
	}
}


void HMI_AlarmMode(void)
{
	Timer1_init(&g_timer1_config);
	Timer1_setCallBack(&Timer_CallBackFunction);

	LCD_clearScreen();
	LCD_displayString("ERROR");

	g_ticks = 0;
	while(g_ticks < ALARM_TIME);
}



void Timer_CallBackFunction(void)
{
	g_ticks++;
}








//		/******Test********/
//
//		_delay_ms(500);
//		uint8 Test[10];
//
//		/* Send MC2_READY byte to MC1 to ask it to send the string */
//		UART_sendByte(HMI_READY_UART);
//		while(UART_receiveByte() != CONTROL_READY_UART);
//
//		/* Receive String from MC1 through UART */
//		UART_receiveString(Test);
//
//		LCD_clearScreen();
//		/* Display the received string on the LCD display */
//		LCD_displayString(Test);
//
//		_delay_ms(500);
//
//		/*******End Test******/



