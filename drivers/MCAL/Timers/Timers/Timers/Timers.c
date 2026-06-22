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

void TIMER0_init(void)
{
	//setting the timer clock with 1024 prescaler = 8kH clock
	SET_BIT(TCCR0,CS00);
	SET_BIT(TCCR0,CS02);
	
	//default mode with WGM00,WGM01 = 0 means normal mode (overflow)
	
	sei(); //enable golable interupt
	SET_BIT(TIMSK,TOIE0); //enable overflow interrupt
}

void TIMER0_CTC_init_10ms(void)
{
	//setting the timer clock with 1024 prescaler / timer clock = 8000000/1024=7812.5Hz
	SET_BIT(TCCR0,CS00);
	SET_BIT(TCCR0,CS02);
	
	//setting mode to CTC mode
	CLR_BIT(TCCR0,WGM00);
	SET_BIT(TCCR0,WGM01);
	
	sei(); //enable golable interupt
	SET_BIT(TIMSK,OCIE0); //enable CTC interrupt
	
	//exact tick time = 1 / 7812.5 = 0.000128 s = 128 uS
	// so if we need 10 ms out compare match interrupt OCR0 = 10000/128 = 78.125 = 78
	OCR0=78;
}

void TIMER2_OVF_init_1s(void)
{
	//SETTING TIMER CLOCK TO BE EXTERNAL CLOCK
	//we must connect and external crystal oscillator 32.768KHz on pins TOSC1 and TOSC2
	//so the max value is 256 and the frequency of the timer is 256Hz
	
	//setting AS2 bit in ASSR register to select clock to be external 
	SET_BIT(ASSR,AS2);
	
	//setting the timer clock with 128 prescaler 
	SET_BIT(TCCR2,CS20);
	SET_BIT(TCCR2,CS22);
	
	//setting mode to OVF mode
	CLR_BIT(TCCR2,WGM20);
	CLR_BIT(TCCR2,WGM21);
	
	sei(); //enable golable interupt
	SET_BIT(TIMSK,TOIE2); //enable TOV interrupt
}

// Wave Generation Mode

void TIMER0_PWM_init(float duity_cycle)
{
	//set pin OC0 to be output 
	SET_BIT(DDRB,3);
	
	//setting the timer clock with 1024 prescaler / timer clock = 8000000/1024=7812.5Hz
	SET_BIT(TCCR0,CS00);
	SET_BIT(TCCR0,CS02);
	
	//setting mode to PWM mode
	SET_BIT(TCCR0,WGM00);
	SET_BIT(TCCR0,WGM01);
	
	OCR0= (duity_cycle*256);
	
	//Clear OC0 on compare match, set OC0 at BOTTOM
	SET_BIT(TCCR0,COM01);
	CLR_BIT(TCCR0,COM00);
}

void TIMER0_phase_correct_PWM_init(float duity_cycle)
{
	//set pin OC0 to be output
	SET_BIT(DDRB,3);
	
	//setting the timer clock with 1024 prescaler / timer clock = 8000000/1024=7812.5Hz
	SET_BIT(TCCR0,CS00);
	SET_BIT(TCCR0,CS02);
	
	//setting mode to phase corrct PWM mode
	SET_BIT(TCCR0,WGM00);
	CLR_BIT(TCCR0,WGM01);
	
	OCR0= (duity_cycle*256);
	
	// Clear OC0 on compare match when up-counting. Set OC0 on compare match when downcounting
	SET_BIT(TCCR0,COM01);
	CLR_BIT(TCCR0,COM00);
}

volatile unsigned char TIMER1_overflow_counter=0;
unsigned long TIMER1_detect_freq_ICU(void)
{
	//frequency detection of input wave on ICP1 which is PD6
	
	//define the variables used to store ticks ot the TCNT1
	double T_on=0, T_off=0,period;
	unsigned long frequency;
	
	//setting ICP1 as input
	set_pin_direction('D',6,0);
	
	//setting timer clock as CPU clock
	SET_BIT(TCCR1B,CS10);
	CLR_BIT(TCCR1B,CS11);
	CLR_BIT(TCCR1B,CS12);
	#define TICK_TIME (1/F_CPU)
	
	//setting timer mode to be normal
	CLR_BIT(TCCR1A,WGM10);
	CLR_BIT(TCCR1A,WGM11);
	CLR_BIT(TCCR1B,WGM12);
	CLR_BIT(TCCR1B,WGM13);
	
	//setting ICU to detect rising edge 
	SET_BIT(TCCR1B,ICES1);
	while(READ_BIT(TIFR,ICF1)==0);
	SET_BIT(TIFR,ICF1);
	SET_BIT(TIMSK,TOIE1); //enable timer1 overflow interrupt 
	TCNT1=0;
	
	
	//setting ICU to detect falling edge 
	CLR_BIT(TCCR1B,ICES1);
	while(READ_BIT(TIFR,ICF1)==0);
	SET_BIT(TIFR,ICF1);
	T_on=ICR1 * (TIMER1_overflow_counter * 65535) * TICK_TIME; //numbers of ticks while high level of the wave detected = ICR1
	TIMER1_overflow_counter=0;
	TCNT1=0;
	
	//setting ICU to detect rising edge
	SET_BIT(TCCR1B,ICES1);
	while(READ_BIT(TIFR,ICF1)==0);
	SET_BIT(TIFR,ICF1);
	T_off=ICR1 * (TIMER1_overflow_counter * 65535) * TICK_TIME; //numbers of ticks while low level of the wave detected = ICR1
	TIMER1_overflow_counter=0;
	CLR_BIT(TIMSK,TOIE1);
	
	period=(T_on+T_off)*TICK_TIME;
	
	frequency=1/period;
	
	return frequency;
}

char TIMER1_detect_Duity_Cycle_ICU(void)
{
	//frequency detection of input wave on ICP1 which is PD6
	
	//define the variables used to store ticks of the TCNT1
	double T_on=0, T_off=0,period;
	unsigned char Duity_Cycle;
	
	//setting ICP1 as input
	set_pin_direction('D',6,0);
	
	//setting timer clock as CPU clock
	SET_BIT(TCCR1B,CS10);
	CLR_BIT(TCCR1B,CS11);
	CLR_BIT(TCCR1B,CS12);
	#define TICK_TIME (1/F_CPU)
	
	//setting timer mode to be normal
	CLR_BIT(TCCR1A,WGM10);
	CLR_BIT(TCCR1A,WGM11);
	CLR_BIT(TCCR1B,WGM12);
	CLR_BIT(TCCR1B,WGM13);
	
	//setting ICU to detect rising edge
	SET_BIT(TCCR1B,ICES1);
	while(READ_BIT(TIFR,ICF1)==0);
	SET_BIT(TIFR,ICF1);
	SET_BIT(TIMSK,TOIE1);	//enable timer1 overflow interrupt 
	TCNT1=0;
	
	
	//setting ICU to detect falling edge
	CLR_BIT(TCCR1B,ICES1);
	while(READ_BIT(TIFR,ICF1)==0);
	SET_BIT(TIFR,ICF1);
	T_on=ICR1 *(TIMER1_overflow_counter*65535) * TICK_TIME; //numbers of ticks while high level of the wave detected = ICR1
	TIMER1_overflow_counter=0;
	TCNT1=0;
	
	//setting ICU to detect rising edge
	SET_BIT(TCCR1B,ICES1);
	while(READ_BIT(TIFR,ICF1)==0);
	SET_BIT(TIFR,ICF1);
	T_off=ICR1 *(TIMER1_overflow_counter*65535) * TICK_TIME; //numbers of ticks while low level of the wave detected = ICR1
	TIMER1_overflow_counter=0;
	CLR_BIT(TIMSK,TOIE1);	//disable timer1 overflow interrupt 
	
	Duity_Cycle=T_on/(T_on+T_off)*100;
	
	return Duity_Cycle ;
}

ISR(TIMER1_OVF_vect)
{
	TIMER1_overflow_counter++;
}