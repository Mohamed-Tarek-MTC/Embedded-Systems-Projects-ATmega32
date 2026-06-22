/*
 * Button.c
 *
 * Created: 4/18/2026 8:43:54 PM
 *  Author: Cascoo
 */ 


#include <avr/io.h>
#include "DIO.h"
#include "Button.h"

void BUTTON_inti(char port, char pin)
{
	switch (port)
	{
		case 'a':
		case 'A':
			set_pin_direction('A',pin,0);
			break;
		case 'b':
		case 'B':
			set_pin_direction('B',pin,0);
			break;
		case 'c':
		case 'C':
			set_pin_direction('C',pin,0);
			break;
		case 'd':
		case 'D':
			set_pin_direction('D',pin,0);
			break;
	}	
}


char BUTTON_read(char port, char pin)
{
	char Button_value;
	
	switch (port)
	{
		case 'a':
		case 'A':
			Button_value = DIO_read_pin('A',pin);
			break;
		case 'b':
		case 'B':
			Button_value = DIO_read_pin('B',pin);
			break;
		case 'c':
		case 'C':
			Button_value = DIO_read_pin('C',pin);
			break;
		case 'd':
		case 'D':
			Button_value = DIO_read_pin('D',pin);
			break;
	}
	return Button_value;
}