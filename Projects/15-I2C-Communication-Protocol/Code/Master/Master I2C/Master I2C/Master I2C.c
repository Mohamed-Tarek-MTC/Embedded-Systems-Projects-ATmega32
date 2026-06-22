/*
 * Master_I2C.c
 *
 * Created: 5/23/2026 4:56:34 PM
 *  Author: Cascoo
 */ 

#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "I2C.h"
#include "KeyPad.h"
#include "LCD.h"
#include "LCDconfig.h"


int main(void)
{
	
	I2C_master_init(50000);
	keypad_init();
	LCD_init();
	OWN_Address_Sett(0b10101011);

	unsigned char press=NotPressed;
    while(1)
    {
		do 
		{
			press = keypad_read();
		} while (press==NotPressed);
		while (keypad_read()!=NotPressed);
		
		LCD_send_char(press);
		
		Start_Con();
		I2C_Transmit_Slave_AddressW(0b11001100);
		I2C_Master_Transmit_Data(press);
		STOP_Con();
		
	}
}