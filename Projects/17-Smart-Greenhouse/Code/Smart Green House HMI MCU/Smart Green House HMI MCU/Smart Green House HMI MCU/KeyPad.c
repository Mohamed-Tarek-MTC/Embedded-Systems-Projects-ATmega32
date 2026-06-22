/*
 * KeyPad.c
 *
 * Created: 4/23/2026 1:29:02 AM
 *  Author: Cascoo
 */ 


#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>



#include "KeyPad.h"
#include "DIO.h"


unsigned char row = 0; 
unsigned char column = 0;
unsigned char read;

#if defined(keypad_4x4)

char press[4][4]={{'7','8','9','/'},{'4','5','6','*'},{'1','2','3','-'},{'C','0','=','+'}};

void keypad_init()
{
	set_port_direction(KeyPad_port,0x0F);
	DIO_write_port(KeyPad_port,0xFF);
}

char keypad_read()
{
	char value=NotPressed;

	for (row=0;row<=3;row++)
	{
		DIO_write_pin(KeyPad_port,row,0);
			
		for (column=0;column<=3;column++)
		{
			read = DIO_read_pin(KeyPad_port,column+4);
			if(read==0)
			{
				value = press[row][column];
				break;
			}
		}
		DIO_write_pin(KeyPad_port,row,1);
		if(read==0)
		{
			break;
		}
			
	}
	//_delay_ms(200);
	return value;
}



#elif defined(keypad_4x3)

char press[4][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'},{'*','0','#'}};

void keypad_init()
{
	set_port_direction(KeyPad_port,0x0F);
	DIO_write_pin(KeyPad_port,0,1);
	DIO_write_pin(KeyPad_port,1,1);
	DIO_write_pin(KeyPad_port,2,1);
	DIO_write_pin(KeyPad_port,3,1);
	DIO_write_pin(KeyPad_port,4,1);
	DIO_write_pin(KeyPad_port,5,1);
	DIO_write_pin(KeyPad_port,6,1);
}

unsigned char keypad_read()
{
	char value=NotPressed;
	
	for (row=0;row<=3;row++)
	{
		DIO_write_pin(KeyPad_port,row,0);
	
		for (column=0;column<=2;column++)
		{
			read=DIO_read_pin(KeyPad_port,column+4);
			if(read==0)
			{
				value = press[row][column];
				break;
			}
		}
		DIO_write_pin(KeyPad_port,row,1);
		if(read==0)
		{
			break;
		}
	}
	//_delay_ms(200);
	return value;
}

 #endif

