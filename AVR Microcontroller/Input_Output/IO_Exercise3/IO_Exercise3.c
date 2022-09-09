#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
	/*Micro-controller Initialization*/
	DDRB &= ~(1<<PB0);
	DDRB &= ~(1<<PB1);

	DDRC |= (1<<PC0);
	DDRC |= (1<<PC1);

	PORTC |= (1<<PC0);
	PORTC |= (1<<PC1);


	/*Super Loop*/
	while(1)
	{
		if(PINB & (1<<PB0))
		{
			_delay_ms(30);

			if(PINB & (1<<PB0))
			{
				PORTC &= ~(1<<PC0);
			}
		}

		else
		{
			PORTC |= (1<<PC0);
		}



		if(PINB & (1<<PB1))
		{
			_delay_ms(30);

			if(PINB & (1<<PB1))
			{
				PORTC &= ~(1<<PC1);
			}
		}

		else
		{
			PORTC |= (1<<PC1);
		}

	}
}
