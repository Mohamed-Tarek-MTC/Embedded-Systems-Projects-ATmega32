/*
 * Ultra_Sonic_Project.c
 *
 * Created: 5/16/2026 12:05:34 AM
 *  Author: Cascoo
 */ 

#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "Ultra Sonic.h"
#include "LCD.h"

int main(void)
{
	unsigned int distance;
	Ultra_Sonic_init();
	LCD_init();
	
	//LCD_send_string("no object");
	
    while(1)
    {
         distance=Ultra_Sonic_read();
		 
		 if (distance<10)
		 {
			 LCD_MOVE_cursor(1,1);
			 LCD_send_string("distance=");
			 LCD_send_char(distance+48);
			 LCD_send_string("cm");
			 LCD_send_string(" ");
		 }
		 else if (distance<100)
		 {
			 LCD_MOVE_cursor(1,1);
			 LCD_send_string("distance=");
			 LCD_send_char((distance/10)+48);
			 LCD_send_char((distance%10)+48);
			 LCD_send_string("cm");
		 }		
		 else
		 {
			 LCD_MOVE_cursor(1,1);
			 LCD_send_string("no object		  ");
		 }	
		  
    }
}