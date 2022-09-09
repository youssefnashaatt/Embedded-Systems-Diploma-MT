#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	/*Initialization*/
	DDRD &= ~(1<<PD3);

	DDRC |= (1<<PC5);
	PORTC &= ~(1<<PC5);

	while(1)
	{
		if(!(PIND & (1<<PD3)))
		{
			_delay_ms(30);

			if(!(PIND & (1<<PD3)))
			{
				PORTC |= (1<<PC5);
			}
		}

		else
			PORTC &= ~(1<<PC5);
	}
}
