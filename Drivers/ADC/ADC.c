/*
 ============================================================================
 Name        : ADC.c
 Author      : Youssef Nashaat
 Description : 
 Date        : Oct 6, 2022
 ============================================================================
 */

#include "ADC.h"
#include <avr/io.h>
#include "MACROS.h"

#if(ADC_Technique == Interrupt)
	volatile uint16 g_adcResult = 0;
#endif


void ADC_init(const ADC_ConfigType * Config_Ptr)
{
	/*ADMUX Register
	 * REFS0:1 	= Reference Volt in Argument Structure
	 * ADLAR	= 0 right adjusted
	 * MUX4:0  	= 00000 to choose channel 0 as initialization
	 */
	ADMUX = ((Config_Ptr->ref_volt) << 6);

#if(ADC_Technique == Polling)

	/* ADCSRA Register Bits Description:
	 * ADEN    = 1 Enable ADC
	 * ADIE    = 0 Disable ADC Interrupt
	 * ADATE   = 0 Disable Auto Trigger
	 * ADPS2:0 = Pre-Scaler Volt in Argument Structure
	 */
	ADCSRA = (1<<ADEN) | (Config_Ptr->prescale);

#elif(ADC_Technique == Interrupt)

	/* ADCSRA Register Bits Description:
		 * ADEN    = 1 Enable ADC
		 * ADIE    = 1 Enable ADC Interrupt
		 * ADATE   = 0 Disable Auto Trigger
		 * ADPS2:0 = Pre-Scaler Volt in Argument Structure
		 */
		ADCSRA = (1<<ADEN) | (1<<ADIE) | (Config_Ptr->prescale);

#endif
}


#if(ADC_Technique == Polling)

uint16 ADC_readChannel(uint8 channel_num)
{
	ADMUX = ((ADMUX & ~(0b11111)) | channel_num);		/*Insert ADC Channel in ADMUX Register BITS0:4*/
	SET_BIT(ADCSRA,ADSC);								/*Set Start Conversion Bit*/
	while(BIT_IS_CLEAR(ADCSRA,ADIF));					/*Polling until Conversion flag is set*/
	SET_BIT(ADCSRA,ADIF);								/*Clear ADC Conversion Flag*/

	return ADC;											/*Return ADC Register 10 Bits containing conversion value*/
}

#elif(ADC_Technique == Interrupt)

void ADC_readChannel(uint8 channel_num)
{
	ADMUX = ((ADMUX & ~(0b11111)) | channel_num);		/*Insert ADC Channel in ADMUX Register BITS0:4*/
	SET_BIT(ADCSRA,ADSC);								/*Set Start Conversion Bit*/
}

ISR(ADC_vect)
{
	/* Read ADC Data after conversion complete */
	g_adcResult = ADC;
}
#endif
