#include "DC_Motor.h"
#include "Temp_Sensor.h"
#include "LCD.h"
#include "ADC.h"



int main(void)
{
	ADC_ConfigType config = {AVCC, F_ADC8};
	int temp_value;
	DcMotor_State state = STOP;

	ADC_init(&config);
	LCD_init();
	DcMotor_Init();

	LCD_displayStringRowColumn(0, 4, "FAN is ");
	LCD_displayStringRowColumn(1, 4, "TEMP is    C");


	while(1)
	{
		temp_value = LM35_getTemperature();


		if(temp_value < 30)
		{

			state = STOP;					/*Declare state as Stop*/
			LCD_moveCursor(0,11);			/*Move Cursor to type in Fan state Position*/
			LCD_displayString("OFF");		/*Type the state of Fan (OFF)*/
			LCD_moveCursor(1,12);			/*Move Cursor to type the temperature in right position*/
			LCD_intgerToString(temp_value);	/*Convert temperature value to string and display it on LCD*/
			LCD_displayCharacter(' ');		/*Display a space character to maintain correct integer display*/

			DcMotor_Rotate(state, 0);
		}

		else if((temp_value >= 30) && (temp_value < 60))
		{
			state = CLOCKWISE;					/*Declare state as Stop*/
			LCD_moveCursor(0,11);			/*Move Cursor to type in Fan state Position*/
			LCD_displayString("ON ");		/*Type the state of Fan (OFF)*/
			LCD_moveCursor(1,12);			/*Move Cursor to type the temperature in right position*/
			LCD_intgerToString(temp_value);	/*Convert temperature value to string and display it on LCD*/
			LCD_displayCharacter(' ');		/*Display a space character to maintain correct integer display*/

			DcMotor_Rotate(state, 25);
		}

		else if((temp_value >= 60) && (temp_value < 90))
		{
			state = CLOCKWISE;					/*Declare state as Stop*/
			LCD_moveCursor(0,11);			/*Move Cursor to type in Fan state Position*/
			LCD_displayString("ON ");		/*Type the state of Fan (OFF)*/
			LCD_moveCursor(1,12);			/*Move Cursor to type the temperature in right position*/
			LCD_intgerToString(temp_value);	/*Convert temperature value to string and display it on LCD*/
			LCD_displayCharacter(' ');		/*Display a space character to maintain correct integer display*/

			DcMotor_Rotate(state, 50);
		}

		else if((temp_value >= 90) && (temp_value < 120))
		{
			state = CLOCKWISE;					/*Declare state as Stop*/
			LCD_moveCursor(0,11);			/*Move Cursor to type in Fan state Position*/
			LCD_displayString("ON ");		/*Type the state of Fan (OFF)*/
			LCD_moveCursor(1,12);			/*Move Cursor to type the temperature in right position*/
			LCD_intgerToString(temp_value);	/*Convert temperature value to string and display it on LCD*/

			if(temp_value < 100)
				LCD_displayCharacter(' ');		/*Display a space character to maintain correct integer display*/


			DcMotor_Rotate(state, 75);
		}


		else if(temp_value >= 120)
		{
			state = CLOCKWISE;					/*Declare state as Stop*/
			LCD_moveCursor(0,11);			/*Move Cursor to type in Fan state Position*/
			LCD_displayString("ON ");		/*Type the state of Fan (OFF)*/
			LCD_moveCursor(1,12);			/*Move Cursor to type the temperature in right position*/
			LCD_intgerToString(temp_value);	/*Convert temperature value to string and display it on LCD*/

			DcMotor_Rotate(state, 100);
		}


	}

}
