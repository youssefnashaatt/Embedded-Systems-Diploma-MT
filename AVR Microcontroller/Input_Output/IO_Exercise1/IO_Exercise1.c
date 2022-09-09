#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	/*Micro-controller Initialization*/
	DDRD &= ~(1<<PD2); 		//PIN2 PORTD is cleared (input pin)
	DDRC |= (1<<PC1);		//PIN1 PORTC is set to 1 (output pin)
	PORTC &= ~(1<<PC1);		//PC1 is initialized to off (positive logic)


	/*Code*/
	while(1)
	{
		if(!(PIND & (1<<PD2)))
		{
			_delay_ms(30);

			if(!(PIND & (1<<PD2)))
			{
				PORTC |= (1<<PC1);
			}
		}

		else
		{
			PORTC &= ~(1<<PC1);
		}
	}
}
