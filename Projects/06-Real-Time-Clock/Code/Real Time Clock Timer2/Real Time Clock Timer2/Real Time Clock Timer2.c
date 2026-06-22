/*
 * Time_Clock_Timer0.c
 *
 * Created: 5/13/2026 12:54:36 AM
 *  Author: Cascoo
 */ 


#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "7_SEG.h"
#include "DIO.h"
#include "Timers.h"
#include "KeyPad.h"
#include "LCD.h"
#include "LCDconfig.h"

volatile unsigned char sec_counter=0;


int main(void)
{
	unsigned char min_counter=0;
	unsigned char hr_counter=0;
	unsigned char press=NotPressed;
	unsigned char first_digit=NotPressed,second_digit=NotPressed;
	
	TIMER2_OVF_init_1s();
	sei();
	
	_7_SEG_init('D');
	LCD_init();
	keypad_init();
	
	// 7segments enable pins
	set_pin_direction('C',0,1);
	set_pin_direction('C',1,1);
	set_pin_direction('C',2,1);
	set_pin_direction('C',3,1);
	set_pin_direction('C',4,1);
	set_pin_direction('C',5,1);
	LCD_send_string("To Set Clock");
	LCD_MOVE_cursor(2,1);
	LCD_send_string("Press 1");
    while(1)
    {
		
		press=keypad_read();
		while(keypad_read()!=NotPressed);
		
		if (press!=NotPressed)
		{
			if (press=='1')
			{
				//setting hours
				LCD_CLR_screen();
				LCD_send_string("Hr=__");
				do 
				{
					second_digit=keypad_read();
				} while (second_digit==NotPressed);
				while(keypad_read()!=NotPressed);
				
				LCD_MOVE_cursor(1,4);
				LCD_send_char(second_digit);
				
				do
				{
					first_digit=keypad_read();
				} while (first_digit==NotPressed);
				while(keypad_read()!=NotPressed);
				LCD_MOVE_cursor(1,5);
				LCD_send_char(first_digit);
				_delay_ms(500);
				hr_counter=(second_digit-48)*10+(first_digit-48);
				
				//setting mins
				LCD_CLR_screen();
				LCD_send_string("Mins=__");
				do
				{
					second_digit=keypad_read();
				} while (second_digit==NotPressed);
				while(keypad_read()!=NotPressed);;
				LCD_MOVE_cursor(1,6);
				LCD_send_char(second_digit);
				
				do
				{
					first_digit=keypad_read();
				} while (first_digit==NotPressed);
				while(keypad_read()!=NotPressed);
				LCD_MOVE_cursor(1,7);
				LCD_send_char(first_digit);
				_delay_ms(500);
				min_counter=(second_digit-48)*10+(first_digit-48);
				
				//setting Sec
				LCD_CLR_screen();
				LCD_send_string("Sec=__");
				do
				{
					second_digit=keypad_read();
				} while (second_digit==NotPressed);
				while(keypad_read()!=NotPressed);
				LCD_MOVE_cursor(1,5);
				LCD_send_char(second_digit);
				
				do
				{
					first_digit=keypad_read();
				} while (first_digit==NotPressed);
				while(keypad_read()!=NotPressed);
				LCD_MOVE_cursor(1,6);
				LCD_send_char(first_digit);
				_delay_ms(500);
				sec_counter=(second_digit-48)*10+(first_digit-48);
				LCD_CLR_screen();
				LCD_send_string("To Set Clock");
				LCD_MOVE_cursor(2,1);
				LCD_send_string("Press 1");
			}
			else if (press!='1')
			{
				LCD_CLR_screen();
				LCD_send_string("Wrong Choice");
				_delay_ms(1000);
				LCD_CLR_screen();
				LCD_send_string("To Set Clock");
				LCD_MOVE_cursor(2,1);
				LCD_send_string("Press 1");
			}
		}
		
		DIO_write_pin('C',0,0);
		DIO_write_pin('C',1,1);
		DIO_write_pin('C',2,1);
		DIO_write_pin('C',3,1);
		DIO_write_pin('C',4,1);
		DIO_write_pin('C',5,1);
		_7_SEG_write('D',sec_counter%10);
		_delay_ms(1);
			
		DIO_write_pin('C',0,1);
		DIO_write_pin('C',1,0);
		DIO_write_pin('C',2,1);
		DIO_write_pin('C',3,1);
		DIO_write_pin('C',4,1);
		DIO_write_pin('C',5,1);
		_7_SEG_write('D',sec_counter/10);
		_delay_ms(1);
			
		DIO_write_pin('C',0,1);
		DIO_write_pin('C',1,1);
		DIO_write_pin('C',2,0);
		DIO_write_pin('C',3,1);
		DIO_write_pin('C',4,1);
		DIO_write_pin('C',5,1);
		_7_SEG_write('D',min_counter%10);
		_delay_ms(1);
			
		DIO_write_pin('C',0,1);
		DIO_write_pin('C',1,1);
		DIO_write_pin('C',2,1);
		DIO_write_pin('C',3,0);
		DIO_write_pin('C',4,1);
		DIO_write_pin('C',5,1);
		_7_SEG_write('D',min_counter/10);
		_delay_ms(1);
			
			
		DIO_write_pin('C',0,1);
		DIO_write_pin('C',1,1);
		DIO_write_pin('C',2,1);
		DIO_write_pin('C',3,1);
		DIO_write_pin('C',4,0);
		DIO_write_pin('C',5,1);
		_7_SEG_write('D',hr_counter%10);
		_delay_ms(1);
			
		DIO_write_pin('C',0,1);
		DIO_write_pin('C',1,1);
		DIO_write_pin('C',2,1);
		DIO_write_pin('C',3,1);
		DIO_write_pin('C',4,1);
		DIO_write_pin('C',5,0);
		_7_SEG_write('D',hr_counter/10);
		_delay_ms(1);
		
		if (sec_counter>=60)
		{
			sec_counter=0;
			min_counter++;
		}
		if (min_counter==60)
		{
			min_counter=0;
			hr_counter++;
		}
		if (hr_counter>=24)
		{
			hr_counter=0;
		}	
    }
}

ISR(TIMER2_OVF_vect)
{
	sec_counter++;
}

