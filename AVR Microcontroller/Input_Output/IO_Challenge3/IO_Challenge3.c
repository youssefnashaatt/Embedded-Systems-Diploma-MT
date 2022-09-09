#include <avr/io.h>
#include <util/delay.h>


void display_0(void);
void display_1(void);
void display_2(void);
void display_3(void);
void display_4(void);
void display_5(void);
void display_6(void);
void display_7(void);
void display_8(void);
void display_9(void);

void (*ptr_2_function[10])(void) = {display_0, display_1, display_2, display_3, display_4, display_5, display_6, display_7, display_8, display_9};


int main(void)
{
	/*Initialization*/
	int index = 0;
	unsigned char flag = 0;
	DDRD &= ~(0x0C);		//Push buttons direction input PD2 & PD3

	DDRA |= (0xFE);			//7-Segment direction output PA1-PA7
	PORTA &= ~(0xFE);		//Turning off 7-Segment
	PORTA |= 0x7E;

	DDRC |= (1<<PC6);		//7-Segment enable bit direction output
	PORTC |= (1<<PC6);		//Enable bit set to logic high


	/*Super Loop*/
	while(1)
	{
		if(!(PIND & (1<<PD2)))
		{
			_delay_ms(30);

			if(!(PIND & (1<<PD2)))
			{
				if((flag == 0) && (index < 9))
				{
					index++;
					flag = 1;
				}
			}
		}

		else if(!(PIND & (1<<PD3)))
		{
			_delay_ms(30);

			if(!(PIND & (1<<PD3)))
			{
				if((flag == 0) && index > 0)
				{
					index--;
					flag = 1;
				}
			}
		}

		else
		{
			flag = 0;
		}


		(*ptr_2_function[index])();

	}
}




void display_0(void)
{
	PORTA = (PORTA & ~(0xFE)) | (0x7E);
	return;
}

void display_1(void)
{
	PORTA = (PORTA & ~(0xFE)) | (0x0C);
	return;
}

void display_2(void)
{
	PORTA = (PORTA & ~(0xFE)) | (0xB6);
	return;
}

void display_3(void)
{
	PORTA = (PORTA & ~(0xFE)) | (0x9E);
	return;
}

void display_4(void)
{
	PORTA = (PORTA & ~(0xFE)) | (0xCC);
	return;
}

void display_5(void)
{
	PORTA = (PORTA & ~(0xFE)) | (0xDA);
	return;
}

void display_6(void)
{
	PORTA = (PORTA & ~(0xFE)) | (0xFA);
	return;
}

void display_7(void)
{
	PORTA = (PORTA & ~(0xFE)) | (0x0E);
	return;
}

void display_8(void)
{
	PORTA = (PORTA & ~(0xFE)) | (0xFE);
	return;
}

void display_9(void)
{
	PORTA = (PORTA & ~(0xFE)) | (0xCE);
	return;
}


