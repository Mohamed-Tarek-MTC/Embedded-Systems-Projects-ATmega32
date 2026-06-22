/*
 * Ulrta_Sonic.c
 *
 * Created: 5/15/2026 2:16:10 AM
 *  Author: Cascoo
 */ 

#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "Ultra Sonic.h"
#include "DIO.h"
#include "Standard_Macros.h"


void Ultra_Sonic_init()
{
	set_pin_direction(US_port,US_TRIG_pin,1);
	set_pin_direction('D',6,0);
}


unsigned int Ultra_Sonic_read()
{
	unsigned short first_edge,second_edge;
	float period;
	unsigned int distance;
	
	SET_BIT(TCCR1B,ICNC1);
	//setting timer1 mode to be normal mode
	CLR_BIT(TCCR1A,WGM10);
	CLR_BIT(TCCR1A,WGM11);
	CLR_BIT(TCCR1B,WGM12);
	CLR_BIT(TCCR1B,WGM13);
	
	//setting timer1 clock to be 1MHz , CPU clock/8
	CLR_BIT(TCCR1B,CS10);
	SET_BIT(TCCR1B,CS11);
	CLR_BIT(TCCR1B,CS12);
	
	//setting ICP1 to detect rising
	SET_BIT(TCCR1B,ICES1);
	SET_BIT(TIFR,ICF1);
	//sending trigger signal on trig pin for time >= 10uS
	DIO_write_pin(US_port,US_TRIG_pin,1);
	_delay_us(20);
	//TCNT1=0;
	DIO_write_pin(US_port,US_TRIG_pin,0);
	
	SET_BIT(TIFR,ICF1);
	while(READ_BIT(TIFR,ICF1)==0);
	first_edge=ICR1;
	SET_BIT(TIFR,ICF1);
	
	//setting ICP1 to detect falling
	CLR_BIT(TCCR1B,ICES1);
	SET_BIT(TIFR,ICF1);
	while(READ_BIT(TIFR,ICF1)==0);
	second_edge=ICR1;
	SET_BIT(TIFR,ICF1);
	
	period=(second_edge-first_edge)*(8.0/F_CPU);
	distance=period*sound_speed/2;
	
	return distance;
	
}

/*
LCD_CLR_screen();
LCD_send_char(second_edge/10000+48);
LCD_send_char(second_edge%10000/1000+48);
LCD_send_char(second_edge%1000/100+48);
LCD_send_char(second_edge%100/10+48);
LCD_send_char(second_edge%10+48);
LCD_MOVE_cursor(2,1);
LCD_send_char(first_edge/10000+48);
LCD_send_char(first_edge%10000/1000+48);
LCD_send_char(first_edge%1000/100+48);
LCD_send_char(first_edge%100/10+48);
LCD_send_char(first_edge%10+48);
_delay_ms(3000);
*/