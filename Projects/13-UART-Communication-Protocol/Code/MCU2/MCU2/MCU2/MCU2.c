/*
 * MCU2.c
 *
 * Created: 5/18/2026 6:56:20 PM
 *  Author: Cascoo
 */ 

#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "LCD.h"
#include "LCDconfig.h"
#include "USART.h"

int main(void)
{

	UART_normal_init(9600);
	LCD_init();
	
	unsigned char data_received;
	
    while(1)
    {
        data_received = UART_Data_Recieve();
		LCD_send_char(data_received);
    }
}