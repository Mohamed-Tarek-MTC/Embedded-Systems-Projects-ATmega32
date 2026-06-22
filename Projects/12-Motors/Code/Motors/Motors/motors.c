/*
 * motors.c
 *
 * Created: 5/15/2026 12:43:54 AM
 *  Author: Cascoo
 */ 

#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "Standard_Macros.h"

void DC_motor_duty_cycle_timer0(unsigned char duty_cycle)
{
	//generating PWM on OCR0 pin to control motor
	SET_BIT(DDRB,3); //setting OC0 pin as ouput
	
	//setting timer0 mode to fast PWM
	SET_BIT(TCCR0,WGM00);
	SET_BIT(TCCR0,WGM01);
	
	//setting timer0 to Clear OC0 on compare match, set OC0 at BOTTOM
	CLR_BIT(TCCR0,COM00);
	SET_BIT(TCCR0,COM01);
	
	//setting timer0 clock to be cpu clock/1024
	SET_BIT(TCCR0,CS00);
	CLR_BIT(TCCR0,CS01);
	SET_BIT(TCCR0,CS02);
	
	OCR0=(duty_cycle/100.0)*255;
	
}

void Servo_motor_angle_timer1(signed char angle)
{
	//using timer1 to generate PWM on OC1A pin to control angle of servo motor
	SET_BIT(DDRD,5); //setting OC1A pin as output
	
	//selecting mode to be Fast PWM using ICR1 register as compare register 
	CLR_BIT(TCCR1A,WGM10);
	SET_BIT(TCCR1A,WGM11);
	SET_BIT(TCCR1B,WGM12);
	SET_BIT(TCCR1B,WGM13);
	
	//setting timer1 clock to be cpu clock/8  to get 1MHz clock
	CLR_BIT(TCCR1B,CS10);
	SET_BIT(TCCR1B,CS11);
	CLR_BIT(TCCR1B,CS12);
	
	//setting timer1 PWM signal to Clear OC1A on compare match, set OC1A at BOTTOM
	CLR_BIT(TCCR1A,COM1A0);
	SET_BIT(TCCR1A,COM1A1);
	
	ICR1=19999;	//we need 20000 tick to get period of 20ms then reset TCNT1
	
	if (angle<=90 && angle>=-90)
	{
		OCR1A=1500+(angle*(500/90.0));
	}
	else
	{
		OCR1A=1500;
	}
	
}
