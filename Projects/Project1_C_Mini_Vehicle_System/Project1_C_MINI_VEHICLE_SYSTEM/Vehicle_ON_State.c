/**************************************************************************************************
 Name        : Vehicle_ON_State.c
 Author      : Youssef Nashaat
 Created on	 : Aug 26, 2022
 Description : Vehicle ON set menu and implementation of CAR operations functions
 **************************************************************************************************/
#include <stdio.h>
#include "Vehicle_ON_State.h"
#include "Defined_Types.h"
#include "Vehicle_State_Control.h"


/*Initialize CAR_ON Structure*/
CAR_STATE CAR_ON = {ON, OFF, 15, 35.0, OFF, 90};


/*Vehicle ON Set Menu*/
char Vehicle_ON_Menu(void)
{
	char input;

	printf("a. Turn off the engine\n");
	printf("b. Set the Traffic Light color\n");
	printf("c. Set the room temperature\n");
	printf("d. Set the engine temperature\n\n");
	fflush(stdout);
	scanf(" %c", &input);

	return input;
}


/*Vehicle On Switch case*/
void Vehicle_ON(void)
{
	printf("\n");

	switch(Vehicle_ON_Menu())
	{
	case 'a':
	case 'A':
		/*Vehicle is turned off and jumps back to Vehicle state control*/
		printf("Vehicle is Turned Off.\n\n");
		Vehicle_Control();
		break;

	case 'b':
	case 'B':
		/*Set traffic light case*/
		CASE_B_Vehicle_ON();
		Display_Car_State();		/*Displaying Car State after execution of any operation*/
		Vehicle_ON();
		break;


	case 'c':
	case 'C':
		/*Set room temperature case*/
		CASE_C_Vehicle_ON();
		Display_Car_State();
		Vehicle_ON();
		break;


	case 'd':
	case 'D':
		/*Set engine temperature case*/
		CASE_D_Vehicle_ON();
		Display_Car_State();
		Vehicle_ON();
		break;

	default:
		/*Default case in case user entered a wrong choice*/
		printf("You entered a wrong choice\n");
		Vehicle_ON();
		break;

	}
}



/*Set Traffic Light Case*/
void CASE_B_Vehicle_ON(void)
{
	char traffic_color;

	/*User choosing traffic light GREEN, ORANGE, RED*/
	printf("Please choose traffic light color: {G, O, R}\n");
	fflush(stdout);
	scanf(" %c", &traffic_color);

	/*If traffic light is green set vehicle speed to 100 km/h*/
	if(traffic_color == 'G' || traffic_color == 'g')
		CAR_ON.Vehicle_Speed = 100;

	/*If traffic light is orange set vehicle speed into 30 km/h*/
	else if(traffic_color == 'O' || traffic_color == 'o')
		Vehicle_speed_30(); /*Function setting vehicle speed and AC Mode and Room Temp.*/

	/*If traffic light is red make the vehicle to stop (0 km/h */
	else if(traffic_color == 'R' || traffic_color == 'r')
		CAR_ON.Vehicle_Speed = 0;


	/*Else case in case user entered a wrong choice it will ask for traffic light again*/
	else
	{
		printf("You have entered a wrong color.\n\n");
		CASE_B_Vehicle_ON();
	}


}


/*Set Room Temperature Case*/
void CASE_C_Vehicle_ON(void)
{
	int room_temp;

	/*User Setting Room Temperature*/
	printf("Please enter room temperature: ");
	fflush(stdout);
	scanf(" %d", &room_temp);

	/*If room temperature less than 10C or more than 30C*/
	/*Turn AC ON and set room temperature to 20C*/
	if(room_temp < 10 || room_temp > 30)
	{
		CAR_ON.AC = ON;
		CAR_ON.Room_Temp = 20;
	}

	/*Any different room temperature -> Turn AC Off*/
	else
	{
		CAR_ON.AC = OFF;
		CAR_ON.Room_Temp = room_temp;
	}

}


/*Set Engine Temperature case*/
void CASE_D_Vehicle_ON(void)
{
	int engine_temp;

	/*User entering Engine temperature*/
	printf("Please enter engine temperature: ");
	fflush(stdout);
	scanf(" %d", &engine_temp);

	/*If temperature is less than 100C or more than 150C*/
	/*Turn on Engine temp. controller and set engine temp to 25C*/
	if(engine_temp < 100 || engine_temp > 150)
	{
		CAR_ON.Engine_Temp_Controller = ON;
		CAR_ON.Engine_Temp = 125;
	}

	/*Otherwise turn off engine temp. controller*/
	else
	{
		CAR_ON.Engine_Temp_Controller = OFF;
		CAR_ON.Engine_Temp = engine_temp;
	}
}


/*Vehicle speed 30 km/h function*/
void Vehicle_speed_30(void)
{
	/*Turn on AC and set room temperature*/
	CAR_ON.AC = ON;
	CAR_ON.Room_Temp = CAR_ON.Room_Temp * (5 / 4) + 1;

	/*Turn on engine controller and set engine temperature*/
	CAR_ON.Engine_Temp_Controller = ON;
	CAR_ON.Engine_Temp = CAR_ON.Engine_Temp * (5 / 4) + 1;
}


/*Function to display CAR statuses*/
void Display_Car_State(void)
{
	printf("\n");
	printf("Engine State: %s\n", check_ON_OFF(CAR_ON.Engine_State));
	printf("AC: %s\n", check_ON_OFF(CAR_ON.AC));
	printf("Vehicle speed: %d km/h\n", CAR_ON.Vehicle_Speed);
	printf("Room Temperature: %.1f C\n", CAR_ON.Room_Temp);
	printf("Engine Temperature Controller: %s\n", check_ON_OFF(CAR_ON.Engine_Temp_Controller));
	printf("Engine Temperature: %.1f C\n\n", CAR_ON.Engine_Temp);
}


/*Function to check if boolean data type is on or off*/
char * check_ON_OFF(bool v)
{
	if(v == ON)
		return "ON";

	else
		return "OFF";
}
