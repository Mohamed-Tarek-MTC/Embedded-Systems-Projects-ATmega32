/*
 * Smart_Home_Security_MCU.c
 *
 * Created: 6/1/2026 5:23:14 AM
 *  Author: Cascoo
 */ 

#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>

#include "KeyPad.h"
#include "EEPROM.h"
#include "LCD.h"
#include "LCDconfig.h"
#include "LED.h"
#include "motors.h"


#define password_first_byte_location	0x0100
#define password_second_byte_location	0x0101
#define password_third_byte_location	0x0102
#define password_forth_byte_location	0x0103

#define check_password_location			0X0120

#define MAX_TRIES	3

int main(void)
{
	unsigned char i,press,check[4],password_checked=1,enter_home=0,tries=MAX_TRIES;
	
	LCD_init();
	LED_init('D',1);
	keypad_init();
	
	//setting password for the first time
	if (EEPROM_read(check_password_location)==0xFF)
	{
		LCD_send_string("sett Password");
		LCD_MOVE_cursor(2,1);
		for (i=0;i<4;i++)
		{
			do
			{
				press=keypad_read();
				
			} while (press==NotPressed);
			while (keypad_read()!=NotPressed);
			
			EEPROM_write(press,password_first_byte_location+i);
			LCD_send_char(press);
			_delay_ms(300);
			move_cursor_left();
			LCD_send_char('*');
		}
		EEPROM_write(0x00,check_password_location);
		LCD_CLR_screen();
		LCD_send_string("Password Sett");
		LCD_MOVE_cursor(2,1);
		LCD_send_string("Correctly");
		_delay_ms(1000);
	}
    while(1)
    {
		password_checked = 1;
       
	     //if not first time
		LCD_CLR_screen();
		LCD_send_string("Enter Password");
	    LCD_MOVE_cursor(2,1);
	        
	    for (i=0;i<4;i++)
        {
			do
			{
		        press=keypad_read();
			        
		    } while (press==NotPressed);
		    while (keypad_read()!=NotPressed);
		        
		    check[i]=press;
		        
		    LCD_send_char(press);
		    _delay_ms(300);
	        move_cursor_left();
	        LCD_send_char('*');
	    }
	    
		
		for (i=0;i<4;i++)
		{
			if (check[i]!=EEPROM_read(password_first_byte_location+i))
			{
				password_checked = 0;
				break;
			}
		}
		
		if (password_checked!=1)
		{
			if (tries>1)
			{
				tries--;
				LCD_CLR_screen();
				LCD_send_string("Wrong Password");
				LCD_MOVE_cursor(2,1);
				LCD_send_string("Tries left=");
				LCD_send_char(tries+48);
				_delay_ms(1000);
			}
			else
			{
				LED_on('D',1);
				LCD_CLR_screen();
				LCD_send_string("House Locked");
				LCD_MOVE_cursor(2,1);
				LCD_send_string("wait 15 sec");
				_delay_ms(15000);
				LED_off('D',1);
				tries=MAX_TRIES;
			}
		}
		else
		{
			LCD_CLR_screen();
			LCD_send_string("Door Opened");
			LCD_MOVE_cursor(2,1);
			LCD_send_string("Welcome!");
			Servo_motor_angle_timer1(90);		//connected to OC1A pin which is PD5 pin
			_delay_ms(30000);					//wait 30 sec before closing again
			Servo_motor_angle_timer1(0);
			tries=MAX_TRIES;
		}    
	}
}