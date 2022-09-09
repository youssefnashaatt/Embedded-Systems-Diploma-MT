#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	/*Micro-controller Initialization*/
	DDRC |= (1<<PC2);		/*configuring led (PC2) as output*/
	PORTC &= ~(1<<PC2);		/*clearing PC2 starting as led off*/


	/*Super Loop*/
	while(1)
	{
		PORTC ^= (1<<PC2);
		_delay_ms(1000);
	}
}
