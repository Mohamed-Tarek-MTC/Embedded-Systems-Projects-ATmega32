/*
 * _7_SEG.c
 *
 * Created: 4/18/2026 8:59:31 PM
 *  Author: Cascoo
 */ 

#define cc
#include <avr/io.h>
#include "DIO.h"
#include "7_SEG.h"

void _7_SEG_init(char port)
{
	switch(port)
	{
		case 'a':
		case 'A':
			set_port_direction('A',0xFF);
			break;
		case 'b':
		case 'B':
			set_port_direction('B',0xFF);
			break;
		case 'c':
		case 'C':
			set_port_direction('C',0xFF);
			break;
		case 'd':
		case 'D':
			set_port_direction('D',0xFF);
			break;
	}
}

void _7_SEG_write(char port, char value)
{
	#ifdef cc
	unsigned char display[] = {0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x47,0x7f,0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71};
	#else
	unsigned char display[] = {~0x3f,~0x06,~0x5b,~0x4f,~0x66,~0x6d,~0x7d,~0x47,~0x7f,~0x6f,~0x77,~0x7c,~0x39,~0x5e,~0x79,~0x71};
	#endif
	
	switch(port)
	{
		case 'a':
		case 'A':
			DIO_write_port('A',display[value]);
			break;
		case 'b':
		case 'B':
			DIO_write_port('B',display[value]);
			break;
		case 'c':
		case 'C':
			DIO_write_port('C',display[value]);
			break;
		case 'd':
		case 'D':
			DIO_write_port('D',display[value]);
			break;
		}
	
}