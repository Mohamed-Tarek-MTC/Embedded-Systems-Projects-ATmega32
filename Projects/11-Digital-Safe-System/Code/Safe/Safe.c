/*
 * Safe.c
 *
 * Created: 5/10/2026 5:18:23 AM
 *  Author: Cascoo
 */ 

#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "LCD.h"
#include "LCDconfig.h"
#include "KeyPad.h"
#include "EEPROM.h"
#include "LED.h"
#define Location1 0x050
#define Location2 0x051
#define Location3 0x052
#define Location4 0x053
#define state_location 0x030
#define Max_Tries 3

int main(void)
{
	char pressed,i,flag,tries=Max_Tries;
	char pass[4];
	LCD_init();
	keypad_init();
	LED_init('A',2);
	LED_init('A',3);
	
    while(1)
    {
		flag=0;
		if (EEPROM_read(state_location)!=0x00)
		{
			LCD_send_string("Set Password:");
			LCD_MOVE_cursor(2,1);
			for (int i=0;i<4;i++)
			{
				do
				{
					pressed=keypad_read();
				} while (pressed==NotPressed);
				
				EEPROM_write(pressed,Location1+i);
				LCD_send_char(pressed);
				_delay_ms(100);
				move_cursor_left();
				LCD_send_char('*');
			}
			EEPROM_write(0x00,state_location);
			LCD_CLR_screen();
		}
		else
		{
			LCD_send_string("Enter Password: ");
			LCD_MOVE_cursor(2,1);
			for (i=0;i<4;i++)
			{
				do 
				{
					pressed=keypad_read();
				} while (pressed==NotPressed);
				
				pass[i]=pressed;
				LCD_send_char(pressed);
				_delay_ms(50);
				move_cursor_left();
				LCD_send_char('*');
			}
			LCD_CLR_screen();
			
			for (i=0;i<4;i++)
			{
				if (pass[i]!=EEPROM_read(Location1+i))
				{
					flag=1;
					break;
				}
			}
			if (flag==0)
			{
				LCD_send_string("Correct Password");
				_delay_ms(100);
				LED_on('A',2);
				LCD_MOVE_cursor(2,1);
				LCD_send_string("Safe Opened");
				_delay_ms(1000);
				LCD_CLR_screen();
				LCD_send_string("Reset Pass?");
				LCD_MOVE_cursor(2,1);
				LCD_send_string("Press #");
				
				do 
				{
					pressed=keypad_read();
				} while (pressed==NotPressed);
				
				if (pressed=='#')
				{
					EEPROM_write(0xFF,state_location);
					LED_off('A',2);
					LCD_CLR_screen();
				}
				else
				{
					LCD_CLR_screen();
					LCD_send_string("Password not");
					LCD_MOVE_cursor(2,1);
					LCD_send_string("changed");
					//wait untill door is closed logic to be added
					LED_off('A',2);
					LCD_CLR_screen();
					
				}
			}
			else if (tries>1)
			{
				tries--;
				LCD_send_string("Wrong Password");
				LCD_MOVE_cursor(2,1);
				LCD_send_string("Tries left: ");
				LCD_send_char(tries+48);
				_delay_ms(100);
				LCD_CLR_screen();
			}
			else
			{
				LCD_send_string("No More Tries");
				LCD_MOVE_cursor(2,1);
				LCD_send_string("Safe Is Locked");
				LED_on('A',3);
				while(1);
			}
		}			
        
    }
}