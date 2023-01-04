

#ifndef HELP_FUNCTIONS_HMI_H_
#define HELP_FUNCTIONS_HMI_H_

#include "Standard_Types.h"


/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

#define PASS_MAX_SIZE		5
#define HMI_READY_UART		0x00
#define CONTROL_READY_UART 	0xFF
#define PASSWORD_MATCH		TRUE
#define PASSWORD_UNMATCH	FALSE
#define DOOR_MOTION_TIME	15
#define DOOR_HOLD_TIME		3
#define ALARM_TIME			60


/*******************************************************************************
 *                           Function Proto-types                              *
 *******************************************************************************/

void HMI_TakePasswordFromUser(uint8 *password);

#endif /* HELP_FUNCTIONS_HMI_H_ */
