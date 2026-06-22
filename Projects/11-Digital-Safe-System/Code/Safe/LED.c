/*
 * LED.c
 *
 * Created: 4/18/2026 8:17:20 PM
 *  Author: Cascoo
 */ 


#include <avr/io.h>
#include "DIO.H"


void LED_init(char port, char pin)
{
	switch (port)
	{
		case 'a':
		case 'A':
			set_pin_direction('A',pin,1);
			break;
		case 'b':
		case 'B':
			set_pin_direction('B',pin,1);
			break;
		case 'c':
		case 'C':
			set_pin_direction('C',pin,1);
			break;
		case 'd':
		case 'D':
			set_pin_direction('D',pin,1);
			break;
	}	
}

void LED_on(char port, char pin)
{
	switch (port)
	{
		case 'a':
		case 'A':
			DIO_write_pin('A',pin,1);
			break;
		case 'b':
		case 'B':
			DIO_write_pin('B',pin,1);
			break;
		case 'c':
		case 'C':
			DIO_write_pin('C',pin,1);
			break;
		case 'd':
		case 'D':
			DIO_write_pin('D',pin,1);
			break;
	}
}	

void LED_off(char port, char pin)
{
	switch (port)
	{
		case 'a':
		case 'A':
			DIO_write_pin('A',pin,0);
			break;
		case 'b':
		case 'B':
			DIO_write_pin('B',pin,0);
			break;
		case 'c':
		case 'C':
			DIO_write_pin('C',pin,0);
			break;
		case 'd':
		case 'D':
			DIO_write_pin('D',pin,0);
		break;
	}				
}

char LED_state(char port, char pin)
{
	char led_state;
	
	switch (port)
	{
		case 'a':
		case 'A':
			led_state = DIO_read_pin('A',pin);
			break;
		case 'b':
		case 'B':
			led_state = DIO_read_pin('B',pin);
			break;
		case 'c':
		case 'C':
			led_state = DIO_read_pin('C',pin);
			break;
		case 'd':
		case 'D':
			led_state = DIO_read_pin('D',pin);
			break;
	}
	return led_state;	
}