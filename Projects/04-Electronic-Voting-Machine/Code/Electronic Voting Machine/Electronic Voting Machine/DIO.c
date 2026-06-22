/*
 * DIO.c
 *
 * Created: 4/12/2026 3:01:02 AM
 *  Author: Cascoo
 */ 


#include <stdio.h>
#include <avr/io.h>
#include "Standard_Macros.h"

void set_pin_direction(char port,char pin,char direction)
{
	switch (port)
	{
		case 'A':
		case 'a':
			if (direction==1)
			{
				SET_BIT(DDRA,pin);
			}
			else
			{
				CLR_BIT(DDRA,pin);
			}
			break;
		
		case 'B':
		case 'b':
			if (direction==1)
			{
				SET_BIT(DDRB,pin);
			}
			else
			{
				CLR_BIT(DDRB,pin);
			}
			break;
		
		case 'C':
		case 'c':
			if (direction==1)
			{
				SET_BIT(DDRC,pin);
			}
			else
			{
				CLR_BIT(DDRC,pin);
			}
			break;
		
		case 'D':
		case 'd':
			if (direction==1)
			{
				SET_BIT(DDRD,pin);
			}
			else
			{
				CLR_BIT(DDRD,pin);
			}
	}
}

void DIO_write_pin(char port, char pin, char write_value)
{
	switch (port)
	{
		case 'A':
		case 'a':
			if (write_value==1)
			{
				SET_BIT(PORTA,pin);
			}
			else
			{
				CLR_BIT(PORTA,pin);
			}
			break;
		
		case 'B':
		case 'b':
			if (write_value==1)
			{
				SET_BIT(PORTB,pin);
			}
			else
			{
				CLR_BIT(PORTB,pin);
			}
			break;
		
		case 'C':
		case 'c':
			if (write_value==1)
			{
				SET_BIT(PORTC,pin);
			}
			else
			{
				CLR_BIT(PORTC,pin);
			}
			break;
		
		case 'D':
		case 'd':
			if (write_value==1)
			{
				SET_BIT(PORTD,pin);
			}
			else
			{
				CLR_BIT(PORTD,pin);
			}
	}
}

char DIO_read_pin(char port, char pin)
{
	char return_value;
	switch (port)
	{
		case 'A':
		case 'a':
			return_value=READ_BIT(PINA,pin);
			break;
		case 'B':
		case 'b':
			return_value=READ_BIT(PINB,pin);
			break;
		case 'C':
		case 'c':
			return_value=READ_BIT(PINC,pin);
			break;
		case 'D':
		case 'd':
			return_value=READ_BIT(PIND,pin);
			break;
	}
	return return_value;
}

void set_port_direction(char port, char direction)
{
	switch (port)
	{ 
		case 'A':
		case 'a':
			DDRA=direction;
			break;
		
		case 'B':
		case 'b':
			DDRB=direction;
			break;
		
		
		case 'C':
		case 'c':
			DDRC=direction;
			break;
		
		case 'D':
		case 'd':
			DDRD=direction;
	}
}

char DIO_read_port(char port)
{
	char return_value;

	switch (port)
	{
		case 'A':
		case 'a':
			return_value=PINA;
			break;
		
		case 'B':
		case 'b':
			return_value=PINB;
			break;
		
		
		case 'C':
		case 'c':
			return_value=PINC;
			break;
		
		case 'D':
		case 'd':
			return_value=PIND;
	}
	return return_value;
}

void DIO_write_port(char port, char value)
{
	switch(port)
	{
		case 'A':
		case 'a':
			PORTA=value;
			break;
		
		case 'B':
		case 'b':
			PORTB=value;
			break;
				
		case 'C':
		case 'c':
			PORTC=value;
			break;
				
		case 'D':
		case 'd':
			PORTD=value;
	}
}

void DIO_togl_port(char port)
{
	switch(port)
	{
		case 'A':
		case 'a':
		PORTA=~PORTA;
		break;
		
		case 'B':
		case 'b':
		PORTB=~PORTB;
		break;
		
		case 'C':
		case 'c':
		PORTC=~PORTC;
		break;
		
		case 'D':
		case 'd':
		PORTD=~PORTD;
	}
}

void DIO_write_high_nibble(char port, char data)
{	
	int value;
	value = data<<4;
	switch(port)
	{
		case 'A':
		case 'a':
		PORTA&=0x0F;
		PORTA|=value;
		break;
		
		case 'B':
		case 'b':
		PORTB&=0x0F;
		PORTB|=value;
		break;
		
		case 'C':
		case 'c':
		PORTC&=0x0F;
		PORTC|=value;
		break;
		
		case 'D':
		case 'd':
		PORTD&=0x0F;
		PORTD|=value;
	}
}

void DIO_write_low_nibble(char port, char data)
{
	switch(port)
	{
		case 'A':
		case 'a':
		PORTA&=0xF0;
		PORTA|=data;
		break;
		
		case 'B':
		case 'b':
		PORTB&=0x0F;
		PORTB|=data;
		break;
		
		case 'C':
		case 'c':
		PORTC&=0x0F;
		PORTC|=data;
		break;
		
		case 'D':
		case 'd':
		PORTD&=0x0F;
		PORTD|=data;
	}
}
