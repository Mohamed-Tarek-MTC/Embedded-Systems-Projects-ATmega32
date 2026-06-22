/*
 * Frequency_and_Duity_Cylce_detector.c
 *
 * Created: 5/14/2026 6:11:42 AM
 *  Author: Cascoo
 */ 

#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "DIO.h"
#include "LCD.h"
#include "LCDconfig.h"
#include "Timers.h"

int main(void)
{
	unsigned long Frequency;
	unsigned char Duty_cycle; 
	
	LCD_init();
	
    while(1)
    {
		Frequency = TIMER1_detect_freq_ICU();
		Duty_cycle = TIMER1_detect_Duty_Cycle_ICU();
		
		
		LCD_send_string("freq= ");
		
		if (Frequency<10)
		{
			LCD_send_char(Frequency+48);
			LCD_send_string("Hz");
			LCD_send_string(" ");
			LCD_send_string(" ");
			LCD_send_string(" ");
			LCD_send_string(" ");
			LCD_send_string(" ");
		}
		else if (Frequency<100)
		{
			LCD_send_char((Frequency/10)+48);
			LCD_send_char((Frequency%10)+48);
			LCD_send_string("Hz");
			LCD_send_string(" ");
			LCD_send_string(" ");
			LCD_send_string(" ");
			LCD_send_string(" ");
		}
		else if (Frequency<1000)
		{
			LCD_send_char((Frequency/100)+48);
			LCD_send_char(((Frequency%100)/10)+48);
			LCD_send_char((Frequency%10)+48);
			LCD_send_string("Hz");
			LCD_send_string(" ");
			LCD_send_string(" ");
			LCD_send_string(" ");
		}
		else if (Frequency<10000)
		{
			LCD_send_char((Frequency/1000)+48);
			LCD_send_char(((Frequency%1000)/100)+48);
			LCD_send_char(((Frequency%100)/10)+48);
			LCD_send_char((Frequency%10)+48);
			LCD_send_string("Hz");
			LCD_send_string(" ");
			LCD_send_string(" ");
		}
		else if (Frequency<100000)
		{
			LCD_send_char((Frequency/10000)+48);
			LCD_send_char(((Frequency%10000)/1000)+48);
			LCD_send_char(((Frequency%1000)/100)+48);
			LCD_send_char(((Frequency%100)/10)+48);
			LCD_send_char((Frequency%10)+48);
			LCD_send_string("Hz");
			LCD_send_string(" ");
		}
		else if (Frequency<1000000)
		{
			LCD_send_char((Frequency/100000)+48);
			LCD_send_char(((Frequency%100000)/10000)+48);
			LCD_send_char(((Frequency%10000)/1000)+48);
			LCD_send_char(((Frequency%1000)/100)+48);
			LCD_send_char(((Frequency%100)/10)+48);
			LCD_send_char((Frequency%10)+48);
			LCD_send_string("Hz");
		}
		else
		{
			LCD_CLR_screen();
			LCD_send_string("out of range");
		}
	
		LCD_MOVE_cursor(1,1);
		LCD_send_string("Duty Cycle= ");
		LCD_send_char((Duty_cycle/10)+48);
		LCD_send_char((Duty_cycle%10)+48);
		LCD_send_string("%");
		LCD_MOVE_cursor(2,1);
    }
}