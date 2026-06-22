/*
 * SPI_Project_Master.c
 *
 * Created: 5/18/2026 8:42:13 AM
 *  Author: Cascoo
 */ 

#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "SPI.h"
#include "KeyPad.h"

int main(void)
{
	keypad_init();
	SPI_Master_init();
	
	unsigned char press=NotPressed;
	
	while(1)
    {
        do
        {
	        press=keypad_read();
	        
        } while (press==NotPressed);
        while(keypad_read()!=NotPressed);
        
		SPI_Master_Data_Transmit(press);
		_delay_ms(100);

    }
}