/*
 * ADC.c
 *
 * Created: 5/11/2026 3:40:59 PM
 *  Author: Cascoo
 */ 

#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "Standard_Macros.h"
#include "DIO.h"

void ADC_init()
{
	SET_BIT(ADCSRA,ADEN); //enable the ADC
	//PA0 is default channel for ADC
	
	SET_BIT(ADCSRA,ADPS1); //Select prescaler 64 to work on 125kH clock if CPU clock is 8MH
	SET_BIT(ADCSRA,ADPS2);
	
	//select the source of Vref
	SET_BIT(ADMUX,REFS0); // Vref = AVCC and conenct Cap on VREF to ground
}

unsigned short ADC_READ()
{
	unsigned short read_value;
	
	SET_BIT(ADCSRA,ADSC);
	while (READ_BIT(ADCSRA,ADSC)==1);
	
	read_value = ADCL;
	read_value|= (ADCH<<8);
	
	return read_value;
}

void ADC_SELECT_channel(char channel_pin)
{
	set_pin_direction('A',channel_pin,0);
	switch (channel_pin)
	{
		case 0:
			CLR_BIT(ADMUX,MUX0);
			CLR_BIT(ADMUX,MUX1);
			CLR_BIT(ADMUX,MUX2);
			break;
			
		case 1:
			SET_BIT(ADMUX,MUX0);
			CLR_BIT(ADMUX,MUX1);
			CLR_BIT(ADMUX,MUX2);
			break;
		
		case 2:
			CLR_BIT(ADMUX,MUX0);
			SET_BIT(ADMUX,MUX1);
			CLR_BIT(ADMUX,MUX2);
			break;
			
		case 3:
			SET_BIT(ADMUX,MUX0);
			SET_BIT(ADMUX,MUX1);
			CLR_BIT(ADMUX,MUX2);
			break;
			
		case 4:
			CLR_BIT(ADMUX,MUX0);
			CLR_BIT(ADMUX,MUX1);
			SET_BIT(ADMUX,MUX2);
			break;
			
		case 5:
			SET_BIT(ADMUX,MUX0);
			CLR_BIT(ADMUX,MUX1);
			SET_BIT(ADMUX,MUX2);
			break;
			
		case 6:
			CLR_BIT(ADMUX,MUX0);
			SET_BIT(ADMUX,MUX1);
			SET_BIT(ADMUX,MUX2);
			break;
			
		case 7:
			SET_BIT(ADMUX,MUX0);
			SET_BIT(ADMUX,MUX1);
			SET_BIT(ADMUX,MUX2);
			break;
	}
}


