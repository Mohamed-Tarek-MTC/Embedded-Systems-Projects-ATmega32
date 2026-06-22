/*
 * Traffic_Lights.c
 *
 * Created: 5/12/2026 10:59:34 PM
 *  Author: Cascoo
 */ 

#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "7_SEG.h"
#include "DIO.h"
#include "Timers.h"
#include "LED.h"
#include "Standard_Macros.h"

volatile unsigned char MS_counter=0;

int main(void)
{
	signed char sec_counter=90;
	TIMER0_CTC_init_10ms();
	sei();
	_7_SEG_init('C');
	
	//multiplexing pins
	set_pin_direction('D',0,1);		//E1
	set_pin_direction('D',1,1);		//E2
	
	//LEDs pins
	LED_init('D',5);
	LED_init('D',6);
	LED_init('D',7);
	
	LED_on('D',5);
	LED_off('D',7);
	
    while(1)
    {
        
		DIO_write_pin('D',0,1);
		DIO_write_pin('D',1,0);
		DIO_write_pin('D',2,1);
		DIO_write_pin('D',3,1);
		_7_SEG_write('C',sec_counter/10);
		_delay_ms(2);
		
		DIO_write_pin('D',0,0);
		DIO_write_pin('D',1,1);
		DIO_write_pin('D',2,1);
		DIO_write_pin('D',3,1);
		_7_SEG_write('C',sec_counter%10);
		_delay_ms(2);
		
		if (MS_counter>=100)
		{
			sec_counter--;
			if (sec_counter<0)
			{
				sec_counter=90;
				TOGL_LED('D',5);
				TOGL_LED('D',7);
			}
			MS_counter=0;
		}
		
		if (sec_counter<=10)
		{
			LED_on('D',6);
		}
		else
		{
			LED_off('D',6);
		}			
    }
}

ISR(TIMER0_COMP_vect)
{
	MS_counter++;
}