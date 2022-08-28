/**************************************************************************************************
 Name        : Vehicle_State_Control.c
 Author      : Youssef Nashaat
 Created on	 : Aug 26, 2022
 Description : Control the State of the Vehicle (Turned ON, Turned Off, Shutted Down)
 **************************************************************************************************/
#include <stdio.h>
#include "Vehicle_State_Control.h"
#include "Vehicle_ON_State.h"



char Vehicle_State(void)
{
	char input;

	/*Ask the user of what he/she wants to (turn on, turn off or shut the vehicle down)*/
	printf("a. Turn on the vehicle engine\n");
	printf("b. Turn off the vehicle engine\n");
	printf("c. Quit the system\n\n");
	fflush(stdout);
	scanf(" %c", &input);

	return input;
}


void Vehicle_Control(void)
{
	/*Check on input form user by Vehicle_State function and return character for switch statement*/
	switch(Vehicle_State())
	{
	case 'a':
	case 'A':
		/*Turn On Vehicle and transfer control to Vehicle_ON file*/
		Vehicle_ON();
		break;

	case 'b':
	case 'B':
		/*Turn off Vehicle and present vehicle control menu until vehicle turned on or shutted*/
		printf("Vehicle is Turned Off.\n\n");
		Vehicle_Control();
		break;

	case 'c':
	case 'C':
		/*Shut down the vehicle*/
		printf("Vehicle has shutted down.\n\n");
		break;

	default:
		/*Show the vehicle control menu till a correct choice is made*/
		printf("You have entered a wrong choice.\n\n");
		Vehicle_Control();
		break;
	}

}



