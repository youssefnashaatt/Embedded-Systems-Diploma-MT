#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
	/*Initialization*/
	unsigned char flag = 0;		//button flag
	DDRB &= ~(1<<PB0);			//PB0 push button
	PORTB |= (1<<PB0);			//Activate internal pull up PB0

	DDRC |= (1<<PC0);			//LED is initialized output
	PORTC |= (1<<PC0);			//LED is initialized off


	/*Super Loop*/
	while(1)
	{
		if(!(PINB & (1<<PB0)))
		{
			_delay_ms(30);

			if(!(PINB & (1<<PB0)))
			{
				if(flag == 0)
				{
					PORTC ^= (1<<PC0);
					flag = 1;
				}
			}
		}

		else
			flag = 0;
	}

}
