#include "external_eeprom.h"
#include <util/delay.h>
#include "HELP_Functions_Control.h"




uint8 g_app_password[PASS_MAX_SIZE];


/*******************************************************************************
 *                            Functions Definition                             *
 *******************************************************************************/

bool Control_CompareTwoPasswords(uint8 *pass1 , uint8 *pass2)
{
	bool Passwords_Match = TRUE;
	uint8 i = 0;

	while(pass1[i] != '\0' || pass1[i] != '\0')
	{
		g_app_password[i] = pass1[i];
		if(pass1[i] != pass2[i])
		{
			Passwords_Match = FALSE;
			break;
		}

		i++;
	}


	if(Passwords_Match == TRUE)
	{
		return TRUE;
	}

	else
	{
		return FALSE;
	}
}


void Control_StorePasswordInEEPROM(uint8 *pass)
{
	uint8 i;

	for(i = 0 ; i < PASS_MAX_SIZE ; i++)
	{
		EEPROM_writeByte(0x0300 + i, *(pass + i));
		_delay_ms(20);
	}
}


bool Control_FetchExternalMemoryAndComparePassword(uint8 *pass_entered)
{
	uint8 i;
	uint8 pass_saved[PASS_MAX_SIZE];
	bool Passwords_Match = TRUE;

	/**************************Fetch Password from External Memory***************************/

	for(i = 0 ; i < PASS_MAX_SIZE ; i++)
	{
		EEPROM_readByte((EEPROM_PASS_ADDRESS + i), &pass_saved[i]);
		_delay_ms(20);
	}

	/******************************Compare Two Saved & Entered********************************/

	for(i = 0 ; i < PASS_MAX_SIZE ; i++)
	{
		if(pass_saved[i] != pass_entered[i])
		{
			Passwords_Match = FALSE;
			break;
		}
	}

	return Passwords_Match;
}
