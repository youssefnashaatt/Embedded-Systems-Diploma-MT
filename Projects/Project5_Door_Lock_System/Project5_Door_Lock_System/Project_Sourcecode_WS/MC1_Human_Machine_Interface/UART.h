/*
 ===============================================================================================
 Name        : UART.h
 Author      : Youssef Nashaat
 Description :
 Date        : Oct 24, 2022
 ===============================================================================================
 */



#ifndef UART_H_
#define UART_H_

#include "Standard_Types.h"


/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

/*Data Bits possible values*/
typedef enum
{
	Bits_5, Bits_6, Bits_7, Bits_8
}UART_BitData;


/*Parity bit possible states*/
typedef enum
{
	Disabled, Even_Parity = 2, Odd_Parity
}UART_Parity;


/*Number of stop bits in UART frame*/
typedef enum
{
	One_Bit, Two_Bits
}UART_StopBit;


/*BaudRate standard values:
 * 10, 300, 600, 1200, 2400, 4800, 9600, 14400, 19200, 38400, 57600, 115200, 128000, 256000 bps.
 */
typedef uint32 UART_BaudRate;


/*Configuration Structure*/
typedef struct{
 UART_BitData bit_data;
 UART_Parity parity;
 UART_StopBit stop_bit;
 UART_BaudRate baud_rate;
}UART_ConfigType;



/*******************************************************************************
 *                           Function Proto-types                              *
 *******************************************************************************/



/*
 * UART Module Initialization function
 * Used t initialize the UART Module with a pre-defined structure with all UART Configurations
 * Input: UART_ConfigType Structure
 * Return: void
 */
void UART_init(const UART_ConfigType *Config_Ptr);



/*
 * UART Module function
 * Responsible for sending byte to another UART device.
 */
void UART_sendByte(const uint8 data);



/*
 * UART Module function
 * Responsible for receiving byte from another UART device.
 */
uint8 UART_receiveByte(void);



/*
 * UART Module function
 * Responsible for sending string to another UART device.
 */
void UART_sendString(const uint8 *Str);



/*
 * UART Module function
 * Responsible for receiving string from another UART device.
 */
void UART_receiveString(uint8 *Str);

#endif /* UART_H_ */
