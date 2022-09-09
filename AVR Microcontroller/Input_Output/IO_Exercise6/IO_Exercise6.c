#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
	unsigned char flag = 0;
	unsigned char num = 0;
	DDRD &= ~(1<<PD4);			//PIN4 PORTD as input

	DDRC |= 0x0F;				//First 4 pins in PORTC are output
	PORTC &= ~(0x0F);				//Initialize them to logical high so they are off


	while(1)
	{
		if(PIND & (1<<PD4))
		{
			_delay_ms(30);

			if(PIND & (1<<PD4))
			{
				if(flag == 0)
				{
					if((PORTC & (0x0F)) == 9)
						num = 0;

					else
						num++;

					PORTC = (PORTC & (0xF0)) | num;
					flag = 1;
				}
			}
		}

		else
			flag = 0;

	}
}
