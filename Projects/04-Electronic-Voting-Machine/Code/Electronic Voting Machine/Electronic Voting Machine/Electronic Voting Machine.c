/*
 * Electronic_Voting_Machine.c
 *
 * Created: 4/26/2026 7:02:55 AM
 *  Author: Cascoo
 */ 


//Electronic Voting Machine up to 999 voter for each Candidate

#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "Button.h"
#include "LCD.h"
#include "LCDconfig.h"

int main(void)
{
	BUTTON_init('D',0);
	BUTTON_init('D',1);
	BUTTON_init('D',2);
	BUTTON_init('D',3);
	LCD_init();
	
	short counter1=0, counter2=0, counter3=0, counter4=0;
	char button_value;
	
	LCD_MOVE_cursor(1,1);
	LCD_send_string("A=000");
	LCD_MOVE_cursor(1,11);
	LCD_send_string("B=000");
	LCD_MOVE_cursor(2,1);
	LCD_send_string("C=000");
	LCD_MOVE_cursor(2,11);
	LCD_send_string("D=000");
	
    while(1)
    {
	   
	   if (BUTTON_read('D',0)==1)
	   {
		   if (counter1<999)
		   {
			   counter1++;
			   LCD_MOVE_cursor(1,3);
			   LCD_send_char((counter1/100)+48);
			   LCD_send_char(((counter1%100)/10)+48);
			   LCD_send_char((counter1%10)+48);
		   }
		   else
		   {
			   counter1=0;
		   }
		   
	   }
	   
	   else if (BUTTON_read('D',1)==1)
	   {
		   if (counter2<999)
		   {
			   counter2++;
			   LCD_MOVE_cursor(1,13);
			   LCD_send_char(counter2/100+48);
			   LCD_send_char((counter2%100)/10+48);
			   LCD_send_char(counter2%10+48);
		   }
		   else
		   {
			   counter2=0;
		   }		
	   }
	   
	   else if (BUTTON_read('D',2)==1)
	   {
		   if (counter3<999)
		   {
			   counter3++;
			   LCD_MOVE_cursor(2,3);
			   LCD_send_char(counter3/100+48);
			   LCD_send_char((counter3%100)/10+48);
			   LCD_send_char(counter3%10+48);
		   }
		   else
		   {
			   counter3=0;
		   }   
		}
		
		else if (BUTTON_read('D',3)==1)
		{
			if (counter4<999)
			{
				counter4++;
				LCD_MOVE_cursor(2,13);
				LCD_send_char(counter4/100+48);
				LCD_send_char((counter4%100)/10+48);
				LCD_send_char(counter4%10+48);
			}
			else
			{
				counter4=0;
			}
		}
		_delay_ms(300);
    }
}