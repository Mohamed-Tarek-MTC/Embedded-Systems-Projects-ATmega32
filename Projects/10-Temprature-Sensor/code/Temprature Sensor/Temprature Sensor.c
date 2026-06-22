/*
 * Temprature_Sensor.c
 *
 * Created: 5/11/2026 11:40:08 PM
 *  Author: Cascoo
 */ 

#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "ADC.h"
#include "LCD.h"
#include "LCDconfig.h"

#define AVCC 2.0

int main(void)
{
	LCD_init();
	ADC_init();
	ADC_SELECT_channel(0);
	
	//Vref = 2V on AVCC

	float step = AVCC/1023;
	unsigned short Temprature;
	LCD_send_string("Temprature=");
    while(1)
    {
		Temprature = ADC_READ()*step*100; // (ADC_READ()*step)*1000 = value in mV, /senstivity (10mV) = temp
		if (Temprature<10)
		{
			LCD_MOVE_cursor(1,12);
			LCD_send_char(Temprature+48);
			LCD_send_char(0xDF);
			LCD_send_char('C');
			LCD_send_char(' ');
			LCD_send_char(' ');
		}
		else if (Temprature<100)
		{
			LCD_MOVE_cursor(1,12);
			LCD_send_char((Temprature/10)+48);
			LCD_send_char((Temprature%10)+48);
			LCD_send_char(0xDF);
			LCD_send_char('C');
			LCD_send_char(' ');
		}
		else
		{
			LCD_MOVE_cursor(1,12);
			LCD_send_char((Temprature/100)+48);
			LCD_send_char((Temprature%100/10)+48);
			LCD_send_char((Temprature%10)+48);
			LCD_send_char(0xDF);
			LCD_send_char('C');	
		}
	}
}