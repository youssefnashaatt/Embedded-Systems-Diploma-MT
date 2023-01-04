

#ifndef HELP_FUNCTIONS_CONTROL_H_
#define HELP_FUNCTIONS_CONTROL_H_

#include "Standard_Types.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

#define PASS_MAX_SIZE			5
#define HMI_READY_UART			0x00
#define CONTROL_READY_UART		0xFF
#define PASSWORD_MATCH			TRUE
#define PASSWORD_UNMATCH		FALSE
#define OPEN_DOOR_STATE			'+'
#define CHANGE_PASS_STATE		'-'
#define EEPROM_PASS_ADDRESS		0x0300
#define DOOR_MOTION_TIME		15
#define DOOR_HOLD_TIME			3
#define ALARM_TIME				60


/*******************************************************************************
 *                           Function Proto-types                              *
 *******************************************************************************/

bool Control_CompareTwoPasswords(uint8 *pass1 , uint8 *pass2);
void Control_StorePasswordInEEPROM(uint8 *pass);
bool Control_FetchExternalMemoryAndComparePassword(uint8 *pass_entered);

#endif /* HELP_FUNCTIONS_CONTROL_H_ */
