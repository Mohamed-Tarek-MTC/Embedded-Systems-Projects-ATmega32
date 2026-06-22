/*
 * LCD_Text_Display.c
 *
 * Created: 5/10/2026 1:28:02 AM
 *  Author: Cascoo
 */ 

#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "LCD.h"
#include "LCDconfig.h"

int main(void)
{
	
	LCD_init();
	char shift=0,once=0;
	char text1[] = "Mohamed Tarek   ";
	char text2[] = "Project";
	
    while(1)
    {
		
		LCD_send_string(text1);
		if (once==0)
		{
			LCD_MOVE_cursor(2,5);
			LCD_send_string(text2);
			once=1;
		}
		LCD_MOVE_cursor(1,1);
		LCD_send_string(&text1[15-shift]);
		shift++;
		if (shift>15)
		{
			shift=0;
		}		
		
    }
}