#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
	/*Micro-controller Initialization*/
	DDRC |= 0x7;
	PORTC = 0xF8;


	/*Super Loop*/
	while(1)
	{
		PORTC = (PORTC & 0xF8) | 0x01;   // Turn on the first led only (PC0=1,PC1=0,PC2=0)
		_delay_ms(500);

		PORTC = (PORTC & 0xF8) | 0x02;   // Turn on the second led only (PC0=0,PC1=1,PC2=0)
		_delay_ms(500);

		PORTC = (PORTC & 0xF8) | 0x04;   // Turn on the third led only (PC0=0,PC1=0,PC2=1)
		_delay_ms(500);
	}
}
