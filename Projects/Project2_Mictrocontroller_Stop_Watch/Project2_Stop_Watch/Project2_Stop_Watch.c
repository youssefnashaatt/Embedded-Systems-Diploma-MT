#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>



/*Global Variables*/
unsigned char seconds_units = 0;
unsigned char seconds_tens = 0;
unsigned char minutes_units = 0;
unsigned char minutes_tens = 0;
unsigned char hours_units = 0;
unsigned char hours_tens = 0;


/*Timer 1 Initialization*/
void TIMER1_Init_CTC(void)
{
	/*Frequency of CPU is 1MHz, Frequency of Timer Increment is 1MHz / 16 = 15,625 Hz
	 * Time Required for one increment in counter register is 64 us.
	 * Compare register = (1sec.) / (64usec.) = 15,625 count
	 * Interrupt Enable to increment second each ISR.
	 */

	TCNT1 = 0;					//Timer/Counter1 count Register
	OCR1A = 15625;				//Compare Register
	TIMSK |= (1<<OCIE1A);		//Timer Interrupt Enable

	/* CTC Mode / N = 64 */
	TCCR1A = (1<<FOC1A);
	TCCR1B = (1<<WGM12) | (1<<CS11) | (1<<CS10);
}


/*Interrupt 0 Initialization*/
void INT0_Init(void)
{
	MCUCR |= (1<<ISC01);		//Sensing Falling Edge
	GICR |= (1<<INT0);			//Enable Module Interrupt (INT0)
}


/*Interrupt 1 Initialization*/
void INT1_Init(void)
{
	MCUCR |= (1<<ISC11) | (1<<ISC10);	//Sensing Rising Edge
	GICR |= (1<<INT1);					//Enable Module Interrupt (INT1)
}


/*Interrupt 2 Initialization*/
void INT2_Init(void)
{
	MCUCSR &= ~(1<<ISC2);		//Sensing Falling Edge
	GICR |= (1<<INT2);			//Enable Module Interrupt (INT2)
}


int main(void)
{
	/*Initialization*/
	DDRA |= (0x3F);					//First 6 pins of PORTA as output pins (Enable/Disable 7-Segments)
	PORTA &= ~(0x3F);				//Clearing first 6 pins of PORTA (ALL 7-Segments OFF)

	DDRB &= (1<<PB2);				//Push Button INT2
	PORTB |= (1<<PB2);				//Internal Pull-up resistor Enable

	DDRC |= (0x0F);					//First 4 pins of PORTC as output (Decoder)
	PORTC &= ~(0x0F);				//Clearing first 4 pins of PORTC

	DDRD &= ~((1<<PD2) | (1<<PD3));	//Push Button INT0 & INT1
	PORTD |= (1<<PD2);				//Internal Pull-up resistor Enable



	SREG |= (1<<7);					//Global Interrupt Enable

	TIMER1_Init_CTC();				//Timer1 Initialization
	INT0_Init();					//Interrupt 0 Initialization
	INT1_Init();					//Interrupt 1 Initialization
	INT2_Init();					//Interrupt 2 Initialization


	while(1)
	{

		/*Displaying 1st 7-segment*/
		PORTA = (PORTA & (0xC0)) | (1<<PC0);
		PORTC = (PORTC & (0xF0)) | (seconds_units);
		_delay_us(25);

		/*Displaying 2nd 7-segment*/
		PORTA = (PORTA & (0xC0)) | (1<<PC1);
		PORTC = (PORTC & (0xF0)) | (seconds_tens);
		_delay_us(25);

		/*Displaying 3rd 7-segment*/
		PORTA = (PORTA & (0xC0)) | (1<<PC2);
		PORTC = (PORTC & (0xF0)) | (minutes_units);
		_delay_us(25);

		/*Displaying 4th 7-segment*/
		PORTA = (PORTA & (0xC0)) | (1<<PC3);
		PORTC = (PORTC & (0xF0)) | (minutes_tens);
		_delay_us(25);

		/*Displaying 5th 7-segment*/
		PORTA = (PORTA & (0xC0)) | (1<<PC4);
		PORTC = (PORTC & (0xF0)) | (hours_units);
		_delay_us(25);

		/*Displaying 6th 7-segment*/
		PORTA = (PORTA & (0xC0)) | (1<<PC5);
		PORTC = (PORTC & (0xF0)) | (hours_tens);
		_delay_us(25);
	}


}


/*Timer1 Compare ISR*/
ISR(TIMER1_COMPA_vect)
{
	if(seconds_units != 9)
		seconds_units++;

	else if((seconds_units == 9) && (seconds_tens != 5))
	{
		seconds_units = 0;
		seconds_tens++;
	}

	else if((seconds_units == 9) && (seconds_tens == 5) && (minutes_units != 9))
	{
		seconds_units = 0;
		seconds_tens = 0;
		minutes_units++;
	}

	else if((seconds_units == 9) && (seconds_tens == 5) && (minutes_units == 9) && (minutes_tens != 5))
	{
		seconds_units = 0;
		seconds_tens = 0;
		minutes_units = 0;
		minutes_tens++;
	}

	else if((seconds_units == 9) && (seconds_tens == 5) && (minutes_units == 9) && (minutes_tens == 5) && (hours_units != 9))
	{
		seconds_units = 0;
		seconds_tens = 0;
		minutes_units = 0;
		minutes_tens = 0;
		hours_units++;
	}

	else if((seconds_units == 9) && (seconds_tens == 5) && (minutes_units == 9) && (minutes_tens == 5) && (hours_units == 9) && (hours_tens != 2))
	{
		seconds_units = 0;
		seconds_tens = 0;
		minutes_units = 0;
		minutes_tens = 0;
		hours_units = 0;
		hours_tens++;
	}

	else if((seconds_units == 9) && (seconds_tens == 5) && (minutes_units == 9) && (minutes_tens == 5) && (hours_units != 3) && (hours_tens == 2))
	{
		seconds_units = 0;
		seconds_tens = 0;
		minutes_units = 0;
		minutes_tens = 0;
		hours_units++;
	}

	else
	{
		seconds_units = 0;
		seconds_tens = 0;
		minutes_units = 0;
		minutes_tens = 0;
		hours_units = 0;
	}
}

/*INT0 ISR*/
ISR(INT0_vect)
{
	seconds_units = 0;
	seconds_tens = 0;
	minutes_units = 0;
	minutes_tens = 0;
	hours_units = 0;
	hours_tens = 0;
	_delay_ms(200);
}


/*INT1 ISR*/
ISR(INT1_vect)
{
	TCCR1B &= ~(0x07);
}


/*INT2 ISR*/
ISR(INT2_vect)
{
	TCCR1B |= (1<<CS11) | (1<<CS10);
}
