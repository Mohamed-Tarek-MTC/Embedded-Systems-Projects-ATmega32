/*
 * SPI_Project_Slave.c
 *
 * Created: 5/18/2026 8:51:50 AM
 *  Author: Cascoo
 */ 

#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "SPI.h"
#include "LCDconfig.h"
#include "LCD.h"
#define DUMMY_DATA 0xFF

int main(void)
{
	SPI_Slave_init();
	LCD_init();
	
	unsigned char data_reveived;
    while(1)
    {
	    data_reveived = SPI_Slave_Data_Receive(DUMMY_DATA);
	    LCD_send_char(data_reveived);
    }
}