/*
 * Digital_Voltameter.c
 *
 * Created: 5/12/2026 1:37:57 AM
 *  Author: Cascoo
 */  

#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "ADC.h"
#include "LCD.h"
#include "LCDconfig.h"

#define AVCC 5.0

int main(void)
{
	LCD_init();
	ADC_init();
	ADC_SELECT_channel(0);
	
	//Vref = 5V on AVCC

	float step = AVCC/1023;
	unsigned short Volt;
	LCD_send_string("Volt= ");
    while(1)
    {
		Volt = ADC_READ()*step*1000; // ADC_READ()*step = value in V
		if (Volt<10)
		{
			LCD_MOVE_cursor(1,6);
			LCD_send_char((Volt)+48);
			LCD_send_string("mV");
			LCD_send_char(' ');
			LCD_send_char(' ');
			LCD_send_char(' ');
		}
		else if (Volt<100)
		{
			LCD_MOVE_cursor(1,6);
			LCD_send_char((Volt/10)+48);
			LCD_send_char((Volt%10)+48);
			LCD_send_string("mV");
			LCD_send_char(' ');
			LCD_send_char(' ');
		}
		else if (Volt<1000)
		{
			LCD_MOVE_cursor(1,6);
			LCD_send_char((Volt/100)+48);
			LCD_send_char((Volt%100)/10+48);
			LCD_send_char((Volt%10)+48);
			LCD_send_string("mV");
			LCD_send_char(' ');
		}
		else if (Volt<=AVCC*1000)
		{
			LCD_MOVE_cursor(1,6);
			LCD_send_char((Volt/1000)+48);
			LCD_send_char('.');
			LCD_send_char((Volt%1000)/100+48);
			LCD_send_char((Volt%100)/10+48);
			LCD_send_char((Volt%10)+48);
			LCD_send_char('V');
		}
		else
		{
			LCD_CLR_screen();
			LCD_send_string("Value is Out");
			LCD_MOVE_cursor(2,1);
			LCD_send_string("Of Range");
				
		}
	}
}