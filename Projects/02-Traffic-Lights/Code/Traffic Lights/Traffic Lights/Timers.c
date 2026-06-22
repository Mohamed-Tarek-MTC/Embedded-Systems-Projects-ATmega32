/*
 * Timers.c
 *
 * Created: 5/12/2026 10:36:55 PM
 *  Author: Cascoo
 */ 

#define F_CPU 8000000UL
#include <avr/io.h>
#include <avr/interrupt.h>
#include "Standard_Macros.h"
#include "DIO.h"

void TIMER0_init()
{
	//setting the timer clock with 1024 prescaler = 8kH clock
	SET_BIT(TCCR0,CS00);
	SET_BIT(TCCR0,CS02);
	
	//default mode with WGM00,WGM01 = 0 means normal mode (overflow)
	
	sei(); //enable golable interupt
	SET_BIT(TIMSK,TOIE0); //enable overflow interrupt
}

void TIMER0_CTC_init_10ms()
{
	//setting the timer clock with 1024 prescaler = 8kH clock
	SET_BIT(TCCR0,CS00);
	SET_BIT(TCCR0,CS02);
	
	//setting mode to CTC mode
	CLR_BIT(TCCR0,WGM00);
	SET_BIT(TCCR0,WGM01);
	
	sei(); //enable golable interupt
	SET_BIT(TIMSK,OCIE0); //enable CTC interrupt
	
	OCR0=80;
}