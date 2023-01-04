/*
 ================================================================================================
 Name        : MC1.c
 Author      : Mohamed Tarek
 Description : MC1 Code in Exercise3
 Date        : 19/9/2014
 ================================================================================================
 */

#include <avr/io.h>
#include <util/delay.h>
#include "UART.h"
#include "I2C.h"
#include "Timer1.h"
#include "DC_Motor.h"
#include "Buzzer.h"
#include "HELP_Functions_Control.h"


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

void Control_CompareAndStorePassword(void);
void Control_OpenDoor_state(void);
void Control_ChangePass_state(void);
void OpeningAndClosingDoor(void);
void Control_AlarmMode(void);
void Timer_CallBackFunction(void);



/*******************************************************************************
 *                                    MAIN                                     *
 *******************************************************************************/

int main(void)
{
	/*************************Initialization Structures**************************/

	/*Initialize UART module: Data Size: 8 bits / Parity_status: Disabled / BaudRate: 9600*/
	UART_ConfigType uart_config = {Bits_8, Disabled, One_Bit, 9600};
	/*Initialize I2C module: Address of MC: 0x01 / Bit_Rate: 400 Kbps*/
	TWI_ConfigType i2c_config = {0x01, 400};


	/*************************Initialization Functions***************************/
	UART_init(&uart_config);
	TWI_init(&i2c_config);
	DcMotor_Init();
	Buzzer_init();
	SREG |= (1<<7);


	Control_CompareAndStorePassword();

	/*Main Options pending for notification byte (All other ways return to this while 1 after executing it's function*/
	while(1)
	{
		uint8 notification_byte;

		/*Establishing connection between two ECUs*/
		while(UART_receiveByte() != HMI_READY_UART);
		UART_sendByte(CONTROL_READY_UART);

		notification_byte = UART_receiveByte();


		if(notification_byte == OPEN_DOOR_STATE)
		{
			Control_OpenDoor_state();
		}

		else if(notification_byte == CHANGE_PASS_STATE)
		{
			Control_ChangePass_state();
		}

	}
}



/*
 * Description:
 * Used to Receive and Compare the two passwords entered by user
 * If passwords entered match it store password in EEPROM and send to HMI_ECU Confirmation byte
 * If not it send to HMI_ECU that the two passwords un-match and call it self again waiting for the two passwords
 */
void Control_CompareAndStorePassword(void)
{

	uint8 password_first[PASS_MAX_SIZE + 1];
	uint8 password_second[PASS_MAX_SIZE + 1];
	bool Passwords_Match;

	/*****************************Receive First Password****************************/
	/*Send Ready byte to HMI_ECU to start sending password string*/
	UART_sendByte(CONTROL_READY_UART);

	/* Receive String from HMI through UART */
	UART_receiveString(password_first);


	/****************************Receive Second Password***************************/
	/*Send Ready byte to HMI_ECU to start sending password string*/
	UART_sendByte(CONTROL_READY_UART);

	/*Receive String from HMI through UART*/
	UART_receiveString(password_second);


	/************************Compare Two Received Passwords*************************/

	/*Calling Compare function defined in HELP_Functions_Control file*/
	Passwords_Match = Control_CompareTwoPasswords(password_first, password_second);


	/*****************************Send Confirmation***********************************/
	/*Wait for HMI_ECU to be ready*/
	while(UART_receiveByte() != HMI_READY_UART){}

	if(Passwords_Match)
	{
		UART_sendByte(PASSWORD_MATCH);
		Control_StorePasswordInEEPROM(password_first);
	}

	else
	{
		UART_sendByte(PASSWORD_UNMATCH);
		Control_CompareAndStorePassword();
	}
}



void Control_OpenDoor_state(void)
{
	uint8 password[PASS_MAX_SIZE + 1];
	bool Passwords_Match;

	/******************************Receiving User's Password******************************/

	/*Establishing connection between two ECUs*/
	while(UART_receiveByte() != HMI_READY_UART);
	UART_sendByte(CONTROL_READY_UART);

	UART_receiveString(password);		/*Receive Password sent by HMI_ECU*/


	/************Fetch Password from External Memory and Compare with entered************/

	Passwords_Match = Control_FetchExternalMemoryAndComparePassword(password);


	/*******************Sequence of Opening and Closing Door between two ECUs***************/

	/*Establishing connection between two ECUs*/
	while(UART_receiveByte() != HMI_READY_UART);
	UART_sendByte(CONTROL_READY_UART);


	if(Passwords_Match)
	{
		UART_sendByte(PASSWORD_MATCH);
		g_incorrect_pass_count = 0;
		OpeningAndClosingDoor();
	}

	else
	{

		UART_sendByte(PASSWORD_UNMATCH);			/*Sending to HMI_ECU that passwords un-match to enter its sequence of displaying*/
		g_incorrect_pass_count++;

		if(g_incorrect_pass_count == 3)
		{
			Control_AlarmMode();
		}

		else
		{
			Control_OpenDoor_state();
		}
	}

}


void Control_ChangePass_state(void)
{
	uint8 password[PASS_MAX_SIZE + 1];
	bool Passwords_Match;

	/******************************Receiving User's Password******************************/

	/*Establishing connection between two ECUs*/
	while(UART_receiveByte() != HMI_READY_UART);
	UART_sendByte(CONTROL_READY_UART);

	UART_receiveString(password);		/*Receive Password sent by HMI_ECU*/


	/************Fetch Password from External Memory and Compare with entered************/

	Passwords_Match = Control_FetchExternalMemoryAndComparePassword(password);


	/**********************Sequence of Changing Pass between two ECUs********************/

	/*Establishing connection between two ECUs*/
	while(UART_receiveByte() != HMI_READY_UART);
	UART_sendByte(CONTROL_READY_UART);


	if(Passwords_Match)
	{
		UART_sendByte(PASSWORD_MATCH);
		g_incorrect_pass_count = 0;
		Control_CompareAndStorePassword();
	}

	else
	{

		UART_sendByte(PASSWORD_UNMATCH);			/*Sending to HMI_ECU that passwords un-match to enter its sequence of displaying*/
		g_incorrect_pass_count++;

		if(g_incorrect_pass_count == 3)
		{
			Control_AlarmMode();
		}

		else
		{
			Control_ChangePass_state();
		}
	}

}




void OpeningAndClosingDoor(void)
{
	Timer1_init(&g_timer1_config);
	Timer1_setCallBack(&Timer_CallBackFunction);

	g_ticks = 0;
	DcMotor_Rotate(CLOCKWISE);
	while(g_ticks < DOOR_MOTION_TIME);

	g_ticks = 0;
	DcMotor_Rotate(STOP);
	while(g_ticks < DOOR_HOLD_TIME);

	g_ticks = 0;
	DcMotor_Rotate(ANTI_CLOCKWISE);
	while(g_ticks < DOOR_MOTION_TIME);

	DcMotor_Rotate(STOP);
	Timer1_deInit();
}


void Control_AlarmMode(void)
{
	Timer1_init(&g_timer1_config);
	Timer1_setCallBack(&Timer_CallBackFunction);

	Buzzer_on();

	g_ticks = 0;
	while(g_ticks < ALARM_TIME);

}


void Timer_CallBackFunction(void)
{
	g_ticks++;
}


