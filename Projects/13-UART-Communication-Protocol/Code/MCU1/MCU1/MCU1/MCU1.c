/*
 * MCU1.c
 *
 * Created: 5/18/2026 6:48:00 PM
 *  Author: Cascoo
		
 */ 


#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "KeyPad.h"
#include "USART.h"
#include "Standard_Macros.h"

int main(void)
{
	keypad_init();
	UART_normal_init(9600);
	
	unsigned char press;
	
	UART_Send_String("Mohamed tarek");
	
    while(1)
    {
		
        do 
        {
			press=keypad_read();
        } while (press==NotPressed);
		while(keypad_read()!=NotPressed);
		
		UART_Data_Tarnsmit(press);
         
    }
}