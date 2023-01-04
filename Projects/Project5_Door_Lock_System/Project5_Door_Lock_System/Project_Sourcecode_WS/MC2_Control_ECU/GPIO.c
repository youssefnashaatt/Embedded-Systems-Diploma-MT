/*
 ===============================================================================================
 Name        : GPIO.c
 Author      : Youssef Nashaat
 Description : General Purpose Input/Output (source code) (Micro-controller abstraction layer)
 Date        : Oct 16, 2022
 ===============================================================================================
 */

#include "GPIO.h"
#include "Macros.h"
#include <avr/io.h>



/*
 * Description:
 * GPIO Module function used to set the direction of an input/output PIN on any PORT on AVR MC.
 * Arguments: uint8: port_num		uint8: pin_num			GPIO_PinDirectionType: direction
 * Return-Type: void
 * Functionality: It use switch-case method to switch on all 4 I/O ports on AVR MC, then it
 * set or clear the pin specified in DDR Built-in register depends on pin direction parameter
 * by using Macros (SET_BIT or CLEAR_BIT)
 */
void GPIO_setupPinDirection(uint8 port_num, uint8 pin_num, GPIO_PinDirectionType direction)
{
	switch(port_num)
	{
	default:
		/*Do Nothing*/
		break;

	case PORTA_ID:
		if(direction == PIN_INPUT)
			CLEAR_BIT(DDRA, pin_num);

		else
			SET_BIT(DDRA, pin_num);

		break;

	case PORTB_ID:
		if(direction == PIN_INPUT)
			CLEAR_BIT(DDRB, pin_num);

		else
			SET_BIT(DDRB, pin_num);

		break;

	case PORTC_ID:
		if(direction == PIN_INPUT)
			CLEAR_BIT(DDRC, pin_num);

		else
			SET_BIT(DDRC, pin_num);

		break;

	case PORTD_ID:
		if(direction == PIN_INPUT)
			CLEAR_BIT(DDRD, pin_num);

		else
			SET_BIT(DDRD, pin_num);

		break;
	}
}



/*
 * Description:
 * GPIO Module function used to set the direction of a whole input/output PORT on AVR MC.
 * Arguments: uint8: port_num			uint8: direction
 * Return-Type: void
 * Functionality: It use switch-case method to switch on all 4 I/O ports on AVR MC, then it
 * set or clear all the pins on DDR Built-in register on determined PORT depends on
 * direction parameter.
 */
void GPIO_setupPortDirection(uint8 port_num, uint8 direction)
{
	switch(port_num)
	{
	default:
		/*Do Nothing*/
		break;

	case PORTA_ID:
		DDRA = direction;
		break;

	case PORTB_ID:
		DDRB = direction;
		break;

	case PORTC_ID:
		DDRC = direction;
		break;

	case PORTD_ID:
		DDRD = direction;
		break;
	}
}




/*
 * Description:
 * GPIO Module function used to write logic values on I/O pins on AVR MC.
 * Arguments: uint8: port_num		uint8: pin_num			uint8: value
 * Return-Type: void
 * Functionality: It use switch-case method to switch on all 4 I/O ports on AVR MC, then it
 * set or clear all the pins on PORT register on determined PORT depends on direction parameter.
 */
void GPIO_writePin(uint8 port_num, uint8 pin_num, uint8 value)
{
	switch(port_num)
	{
	default:
		/*Do Nothing*/
		break;

	case PORTA_ID:
		if(value == LOGIC_LOW)
			CLEAR_BIT(PORTA, pin_num);

		else
			SET_BIT(PORTA, pin_num);

		break;

	case PORTB_ID:
		if(value == LOGIC_LOW)
			CLEAR_BIT(PORTB, pin_num);

		else
			SET_BIT(PORTB, pin_num);

		break;

	case PORTC_ID:
		if(value == LOGIC_LOW)
			CLEAR_BIT(PORTC, pin_num);

		else
			SET_BIT(PORTC, pin_num);

		break;

	case PORTD_ID:
		if(value == LOGIC_LOW)
			CLEAR_BIT(PORTD, pin_num);

		else
			SET_BIT(PORTD, pin_num);

		break;
	}
}


/*
 * Description:
 * GPIO Module function used to write logic values on I/O pins on AVR MC.
 * Arguments: uint8: port_num				uint8: value
 * Return-Type: void
 * Functionality: It use switch-case method to switch on all 4 I/O ports on AVR MC, then it
 * set or clear all the pins on PORT register by value argument.
 */
void GPIO_writePort(uint8 port_num, uint8 value)
{
	switch(port_num)
	{
	default:
		/*Do Nothing*/
		break;

	case PORTA_ID:
		PORTA = value;
		break;

	case PORTB_ID:
		PORTB = value;
		break;

	case PORTC_ID:
		PORTC = value;
		break;

	case PORTD_ID:
		PORTD = value;
		break;
	}
}



/*
 * Description:
 * GPIO Module function used to read logic values from I/O pins on AVR MC.
 * Arguments: uint8: port_num				uint8: pin_num
 * Return-Type: void
 * Functionality: It use switch-case method to switch on all 4 I/O ports on AVR MC, then it
 * get the value of a specific pin on PIN register by using GET_BIT macro.
 */
uint8 GPIO_readPin(uint8 port_num, uint8 pin_num)
{
	uint8 pin_read = LOGIC_LOW;

	switch(port_num)
	{
	default:
		/*Do Nothing*/
		break;

	case PORTA_ID:
		pin_read = GET_BIT(PINA, pin_num);
		break;

	case PORTB_ID:
		pin_read = GET_BIT(PINB, pin_num);
		break;

	case PORTC_ID:
		pin_read = GET_BIT(PINC, pin_num);
		break;

	case PORTD_ID:
		pin_read = GET_BIT(PIND, pin_num);
		break;
	}

	return pin_read;
}


/*
 * Description:
 * GPIO Module function used to read logic values from I/O pins on AVR MC.
 * Arguments: uint8: port_num
 * Return-Type: void
 * Functionality: It use switch-case method to switch on all 4 I/O ports on AVR MC, then it
 * get the value of PIN register.
 */
uint8 GPIO_readPort(uint8 port_num)
{
	uint8 port_read = LOGIC_LOW;

	switch(port_num)
	{
	default:
		/*Do Nothing*/
		break;

	case PORTA_ID:
		port_read = PINA;
		break;

	case PORTB_ID:
		port_read = PINB;
		break;

	case PORTC_ID:
		port_read = PINC;
		break;

	case PORTD_ID:
		port_read = PIND;
		break;
	}

	return port_read;
}

