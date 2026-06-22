/*
 * LCD.c
 *
 * Created: 4/21/2026 11:28:52 PM
 *  Author: Cascoo
 */


#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>
#include "LCDconfig.h"
#include "DIO.h"
#include "LCD20x4.h"

#if defined(EIGHT_BITS)
void LCD_init(void)
{
	_delay_ms(100);
	set_port_direction(LCD_port,0xFF);
	set_pin_direction(LCD_control_port,RS,1);
	LCD_send_cmd(0x38); //cmd for 8 bits mode
	_delay_ms(1);
	LCD_send_cmd(0x0C); // display on cursor off
	_delay_ms(1);
	LCD_send_cmd(0x01); // clr screen
	_delay_ms(1);
	LCD_send_cmd(0x06); // Entry mode (move cursor to the right)
	_delay_ms(1);

}

void LCD_send_char(char data)
{
	DIO_write_pin(LCD_control_port,RS,1);
	DIO_write_port(LCD_port,data);
	PULSE();
}

void LCD_send_cmd(char cmd)
{
	DIO_write_pin(LCD_control_port,RS,0);
	DIO_write_port(LCD_port,cmd);
	PULSE();
}

#elif defined(FOUR_BITS)
void LCD_init(void)
{
	_delay_ms(100);
	set_pin_direction(LCD_port,4,1);
	set_pin_direction(LCD_port,5,1);
	set_pin_direction(LCD_port,6,1);
	set_pin_direction(LCD_port,7,1);
	set_pin_direction(LCD_control_port,RS,1);
	LCD_send_cmd(0x02); // cmd for return home (first step of 4 bits mode)
	_delay_ms(10);
	LCD_send_cmd(0x28); // cmd for 4 bits mode
	_delay_ms(1);
	LCD_send_cmd(0x0E); // display on cursor on
	_delay_ms(1);
	LCD_send_cmd(0x01); // clr screen
	_delay_ms(1);
	LCD_send_cmd(0x06); // Entry mode (move cursor to the right)
	_delay_ms(1);

}

void LCD_send_char(char data)
{
	DIO_write_pin(LCD_control_port,RS,1);
	DIO_write_high_nibble(LCD_port,data>>4);
	PULSE();
	DIO_write_high_nibble(LCD_port,data);
	PULSE();
}

void LCD_send_cmd(char cmd)
{
	DIO_write_pin(LCD_control_port,RS,0);
	DIO_write_high_nibble(LCD_port,cmd>>4);
	PULSE();
	DIO_write_high_nibble(LCD_port,cmd);
	PULSE();

}

 #endif

 void LCD_send_string(char* data)
 {
	 while(*data!=0)
	 {
		 LCD_send_char(*data);
		 data++;
	 }
 }

 void PULSE(void)
 {
	 set_pin_direction(LCD_control_port,E,1);
	 DIO_write_pin(LCD_control_port,E,0);
	 _delay_ms(2);
	 DIO_write_pin(LCD_control_port,E,1);
	 _delay_ms(2);
	 DIO_write_pin(LCD_control_port,E,0);
	 _delay_ms(2);
 }


//special commands

void LCD_CLR_screen()
{
	LCD_send_cmd(0x01);
	_delay_ms(10);
}

void LCD_RETURN_home()
{
	LCD_send_cmd(0x02);
	_delay_ms(10);
}

void LCD_MOVE_cursor(char row, char column)
{
	if (row>4 || row<1 || column>20 || column<1)
	{
		LCD_send_cmd(0x80);
	}
	else
	{
		if (row==1)
		{
			LCD_send_cmd(0x80+column-1);
		}
		else if (row==2)
		{
			LCD_send_cmd(0xC0+column-1);
		}
		else if (row==3)
		{
			LCD_send_cmd(0x94+column-1);
		}
		else if (row==4)
		{
			LCD_send_cmd(0xD4+column-1);
		}
	}
}

void move_cursor_right()
{
	LCD_send_cmd(0x14);
	_delay_ms(1);
}

void move_cursor_left()
{
	LCD_send_cmd(0x10);
	_delay_ms(1);
}

void shift_display_right()
{
	LCD_send_cmd(0x1C);
	_delay_ms(1);
}

void shift_display_left()
{
	LCD_send_cmd(0x18);
	_delay_ms(1);
}






