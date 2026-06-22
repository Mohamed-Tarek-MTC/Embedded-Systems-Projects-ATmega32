/*
 * Smart_Green_House_Land_MCU.c
 *
 * Created: 6/4/2026 7:56:06 AM
 *  Author: Cascoo
 */ 

#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#include "ADC.h"
#include "USART.h"
#include "Ultra Sonic.h"
#include "LED.h"
#include "LCD20x4.h"
#include "Standard_Macros.h"

#define Vref (5.0)
#define STEP (Vref/1023)

enum COMMANDS
{
	//CMD
	//for temperature
	TURN_AC_ON = 0x10,
	TURN_AC_OFF = 0x11,
	TURN_HEATER_ON = 0x12,
	TURN_HEATER_OFF = 0x13,
	
	//for soil moisture
	TURN_WATER_PUMP_ON = 0x14,
	TURN_WATER_PUMP_OFF = 0x15,
	
	//for air humidity
	TURN_FAN_ON = 0x16,
	TURN_FAN_OFF = 0x17,
	TURN_Humidifier_ON = 0x18,
	TURN_Humidifier_OFF = 0x19,
	
	//for water tank indicator
	TURN_LED_ON = 0x20,
	TURN_LED_OFF = 0x21,
	
	NO_CHANGE = 0x50,
	
	//Readings
	TEMP_Changed = 0x22,
	Mois_Changed = 0x23,
	Humidity_Changed = 0x24,
	WATER_TANK_Level_Changed = 0x25,
};

volatile unsigned char CMD_Received = 0;
volatile unsigned char CMD = 0;

int main(void)
{
	UART_normal_init(9600);
	Ultra_Sonic_init();
	ADC_init();
	LCD_init();
	
	//all motors controls pins will be treated as LEDs
	LED_init('B',0);
	LED_init('B',1);
	LED_init('B',2);
	LED_init('B',3);
	LED_init('B',4);
	LED_init('B',5);
	LED_init('B',6);
	
	//initially all motors are off
	LED_off('B',0);
	LED_off('B',1);
	LED_off('B',2);
	LED_off('B',3);
	LED_off('B',4);
	LED_off('B',5);
	LED_off('B',6);
	unsigned char first_readings_flag=0;
	unsigned char Current_Temp=255, Current_Moisture=255, Current_Humidity=255, Current_Water_Tank_Level=255;

    while(1)
    {
        
		_delay_ms(300);
		ADC_SELECT_channel(0);					
		Current_Temp = ADC_READ()*STEP*100.0;					//LM35 sens is 10mV/1C
		
		
		ADC_SELECT_channel(1);
		Current_Humidity = ADC_READ()*STEP*(1000.0/31.8);		//HIH-5030 sens is 31.8mV/1RH	 
		
		ADC_SELECT_channel(2);
		Current_Moisture = ADC_READ()*STEP*(1000.0/30);			//Capacitive Soil Moisture v1.2 will be replaced by variable voltage source form 0V - 3V
																//so the sens will be (3V-0V)/(100%-0%) = 30mV/1%
		
		//assume the Tank Hight is 1 Meter
		Current_Water_Tank_Level = 100 - Ultra_Sonic_read();
		
		
	
		//For Temp 
		LCD_MOVE_cursor(1,1);
		LCD_send_string("TEMP : ");
		if (Current_Temp>=10)
		{
			LCD_send_char(Current_Temp/10+48);
			LCD_send_char(Current_Temp%10+48);
		}
		else if (Current_Temp<10)
		{
			LCD_send_string(" ");
			LCD_send_char(Current_Temp%10+48);
		}
		LCD_send_char(0xDF);
		LCD_send_char('C');
		UART_Data_Tarnsmit(TEMP_Changed);
		UART_Data_Tarnsmit(Current_Temp);
		_delay_ms(200);
		
		//For Moisture 
		LCD_MOVE_cursor(2,1);
		LCD_send_string("Mois : ");
		if (Current_Moisture>=10)
		{
			LCD_send_char(Current_Moisture/10+48);
			LCD_send_char(Current_Moisture%10+48);
		}
		else if (Current_Moisture<10)
		{
			LCD_send_string(" ");
			LCD_send_char(Current_Moisture%10+48);
		}
		LCD_send_string("%");
		UART_Data_Tarnsmit(Mois_Changed);
		UART_Data_Tarnsmit(Current_Moisture);
		_delay_ms(200);
		
		//For Humidity 
		LCD_MOVE_cursor(3,1);
		LCD_send_string("Humid : ");
		if (Current_Humidity>=10)
		{
			LCD_send_char(Current_Humidity/10+48);
			LCD_send_char(Current_Humidity%10+48);
		}
		else if (Current_Humidity<10)
		{
			LCD_send_string(" ");
			LCD_send_char(Current_Humidity%10+48);
		}
		LCD_send_string("%");
		UART_Data_Tarnsmit(Humidity_Changed);
		UART_Data_Tarnsmit(Current_Humidity);
		_delay_ms(200);
		
		//For Water Tank Level 
		LCD_MOVE_cursor(4,1);
		LCD_send_string("Tank Level : ");
		if (Current_Water_Tank_Level>=10)
		{
			LCD_send_char(Current_Water_Tank_Level/10+48);
			LCD_send_char(Current_Water_Tank_Level%10+48);
		}
		else if (Current_Water_Tank_Level<10)
		{
			LCD_send_string(" ");
			LCD_send_char(Current_Water_Tank_Level%10+48);
		}
		LCD_send_string("cm");
		UART_Data_Tarnsmit(WATER_TANK_Level_Changed);
		UART_Data_Tarnsmit(Current_Water_Tank_Level);
		_delay_ms(200);
		

		
		
    }//end of while
}//end of main 

ISR(USART_RXC_vect)
{
	CMD = UDR,
	CMD_Received = 1;
	
	switch (CMD)
	{
		case TURN_AC_ON :
		LED_on('B',0);
		break;
		
		case TURN_AC_OFF :
		LED_off('B',0);
		break;
		
		case TURN_HEATER_ON :
		LED_on('B',1);
		break;
		
		case TURN_HEATER_OFF :
		LED_off('B',1);
		break;
		
		case TURN_FAN_ON :
		LED_on('B',2);
		break;
		
		case TURN_FAN_OFF :
		LED_off('B',2);
		break;
		
		case TURN_Humidifier_ON :
		LED_on('B',3);
		break;
		
		case TURN_Humidifier_OFF :
		LED_off('B',3);
		break;
		
		case TURN_WATER_PUMP_ON :
		LED_on('B',4);
		break;
		
		case TURN_WATER_PUMP_OFF :
		LED_off('B',4);
		break;
		
		case TURN_LED_ON :
		LED_on('B',5);
		break;
		
		case TURN_LED_OFF :
		LED_off('B',5);
		break;
		
		case NO_CHANGE :
		break;
	}
	CMD_Received = 0;
		
}