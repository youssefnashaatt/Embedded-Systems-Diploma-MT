#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
	DDRC &= ~(1<<PC0);

	DDRB |= (1<<PB0);
	PORTB &= ~(1<<PB0);


	while(1)
	{
		if(PINC & (1<<PC0))
		{
			_delay_ms(30);

			if(PINC & (1<<PC0))
			{
				PORTB |= (1<<PB0);
			}
		}

		else
			PORTB &= ~(1<<PB0);
	}
}
