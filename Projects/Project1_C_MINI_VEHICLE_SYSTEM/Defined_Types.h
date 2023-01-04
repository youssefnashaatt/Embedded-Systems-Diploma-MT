#ifndef USER_DEFINED_VARIABLES_H_
#define USER_DEFINED_VARIABLES_H_

/*Defining boolean data type to indicate ON or OFF*/
typedef enum
{
	OFF,
	ON
}bool;


/*Defining a structure containing all CAR's members*/
typedef struct
{
	bool Engine_State;
	bool AC;
	int Vehicle_Speed;
	float Room_Temp;
	bool Engine_Temp_Controller;
	float Engine_Temp;
}CAR_STATE;

#endif
