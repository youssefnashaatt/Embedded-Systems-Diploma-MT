/*
 ==============================================================================================
 Name        : GPIO.h
 Author      : Youssef Nashaat
 Description : General Purpose Input/Output (header file) (Micro-controller abstraction layer)
 Date        : Oct 16, 2022
 =============================================================================================
 */
#include "Standard_Types.h"

#ifndef GPIO_H_
#define GPIO_H_


/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

/*Enum for I/O Ports on AVR Micro-controller*/
typedef enum
{
	PORTA_ID, PORTB_ID, PORTC_ID, PORTD_ID
}GPIO_PORT_ID;


/*Enum for I/O Pins in each port on AVR Micro-controller*/
typedef enum
{
	PIN0_ID, PIN1_ID, PIN2_ID, PIN3_ID, PIN4_ID, PIN5_ID, PIN6_ID, PIN7_ID, PIN8_ID
}GPIO_PIN_ID;


typedef enum
{
	PIN_INPUT, PIN_OUTPUT
}GPIO_PinDirectionType;


typedef enum
{
	PORT_INPUT, PORT_OUTPUT = 0xFF
}GPIO_PortDirectionType;



/*******************************************************************************
 *                           Function Proto-types                              *
 *******************************************************************************/

/*
 * Description:
 * GPIO Module function used to set the direction of an input/output PIN on any PORT on AVR MC.
 * Arguments: uint8: port_num		uint8: pin_num			GPIO_PinDirectionType: direction
 * Return-Type: void
 * Functionality: It use switch-case method to switch on all 4 I/O ports on AVR MC, then it
 * set or clear the pin specified in DDR Built-in register depends on pin direction parameter
 * by using Macros (SET_BIT or CLEAR_BIT)
 */
void GPIO_setupPinDirection(uint8 port_num, uint8 pin_num, GPIO_PinDirectionType direction);



/*
 * Description:
 * GPIO Module function used to set the direction of a whole input/output PORT on AVR MC.
 * Arguments: uint8: port_num			uint8: direction
 * Return-Type: void
 * Functionality: It use switch-case method to switch on all 4 I/O ports on AVR MC, then it
 * set or clear all the pins on DDR Built-in register on determined PORT depends on
 * direction parameter.
 */
void GPIO_setupPortDirection(uint8 port_num, uint8 direction);



/*
 * Description:
 * GPIO Module function used to write logic values on I/O pins on AVR MC.
 * Arguments: uint8: port_num		uint8: pin_num			uint8: value
 * Return-Type: void
 * Functionality: It use switch-case method to switch on all 4 I/O ports on AVR MC, then it
 * set or clear all the pins on PORT register on determined PORT depends on direction parameter.
 */
void GPIO_writePin(uint8 port_num, uint8 pin_num, uint8 value);



/*
 * Description:
 * GPIO Module function used to write logic values on I/O pins on AVR MC.
 * Arguments: uint8: port_num				uint8: value
 * Return-Type: void
 * Functionality: It use switch-case method to switch on all 4 I/O ports on AVR MC, then it
 * set or clear all the pins on PORT register by value argument.
 */
void GPIO_writePort(uint8 port_num, uint8 value);



/*
 * Description:
 * GPIO Module function used to read logic values from I/O pins on AVR MC.
 * Arguments: uint8: port_num				uint8: pin_num
 * Return-Type: void
 * Functionality: It use switch-case method to switch on all 4 I/O ports on AVR MC, then it
 * get the value of a specific pin on PIN register by using GET_BIT macro.
 */
uint8 GPIO_readPin(uint8 port_num, uint8 pin_num);



/*
 * Description:
 * GPIO Module function used to read logic values from I/O pins on AVR MC.
 * Arguments: uint8: port_num
 * Return-Type: void
 * Functionality: It use switch-case method to switch on all 4 I/O ports on AVR MC, then it
 * get the value of PIN register.
 */
uint8 GPIO_readPort(uint8 port_num);


#endif /* GPIO_H_ */
