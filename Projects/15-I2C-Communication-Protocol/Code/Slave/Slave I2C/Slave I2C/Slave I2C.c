/*
 * Slave_I2C.c
 *
 * Created: 5/23/2026 5:18:28 PM
 *  Author: Cascoo
 */ 

#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "LCD.h"
#include "LCDconfig.h"
#include "I2C.h"

int main(void)
{
	
	LCD_init();
	OWN_Address_Sett(0b11001101);
	char received_data;
	
    while(1)
    {
        I2C_Slave_Receive_own_AddressW();
		received_data= I2C_Slave_Receive_Data();
		LCD_send_char(received_data);
    }
}