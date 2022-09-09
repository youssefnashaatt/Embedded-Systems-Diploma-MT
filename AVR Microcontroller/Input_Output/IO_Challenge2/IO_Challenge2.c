#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	/*Initialization*/
	DDRA &= ~(0x18);			//Push buttons on PA3, PA4

	DDRD = 0xFF;				//8 LEDs on PORTD
	PORTD = 0x00;				//All LEDs are off


	while(1)
	{
		if(PINA & (1<<PA3))
		{
			_delay_ms(30);

			if(PINA & (1<<PA3))
			{
				while(PINA & (1<<PA3))
				{
					PORTD = 0xAA;
					_delay_ms(500);
					PORTD = 0x00;
					_delay_ms(500);
				}
			}
		}

		else if(!(PINA & (1<<PA3)) && (PINA & (1<<PA4)))
		{
			_delay_ms(30);

			if(!(PINA & (1<<PA3)) && (PINA & (1<<PA4)))
			{
				while(!(PINA & (1<<PA3)) && (PINA & (1<<PA4)))
				{
					PORTD = ~(0xAA);
					_delay_ms(500);
					PORTD = 0;
					_delay_ms(500);
				}
			}
		}

		else
			PORTD = 0;


	}

}
