#include "LCD.h"
#include "Ultrasonic.h"
#include <avr/io.h>
#include <util/delay.h>



int main(void)
{
	uint16 Distance = 0;
	LCD_init();
	Ultrasonic_init();

	SREG |= (1<<7);

	LCD_displayString("Distance =    cm");
	while(1)
	{
		Distance = Ultrasonic_readDistance();
		LCD_moveCursor(0,11);
		LCD_intgerToString(Distance);

		if(Distance < 100)
			LCD_displayCharacter(' ');

		else if(Distance < 10)
			LCD_displayString("  ");
	}
}
