/*
 * Buzzer.c
 *
 * Created: 4/18/2026 8:54:28 PM
 *  Author: Cascoo
 */ 


#include <avr/io.h>
#include "DIO.h"
#include "Buzzer.h"

void BUZZER_inti(char port, char pin)
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

void BUZZER_on(char port, char pin)
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

void BUZZER_off(char port, char pin)
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