/*
 * Green_House_Control.c
 *
 * Created: 6/4/2026 2:23:28 AM
 *  Author: Cascoo
 */ 
#define F_CPU 8000000UL
#include <util/delay.h>
#include "Green_House_Control.h"
#include "Plant_Config.h"

unsigned char one_hour_flag=0;

void TEMP_Control(unsigned char TEMP)
{
	if (TEMP>(EEPROM_read(PLANT_Max_temp_Compare_Location)))
	{
		UART_Data_Tarnsmit(TURN_AC_ON);
		_delay_ms(10),
		UART_Data_Tarnsmit(TURN_HEATER_OFF);
	}
	else if (TEMP<(EEPROM_read(PLANT_Least_temp_Compare_Location)))
	{
		UART_Data_Tarnsmit(TURN_AC_OFF);
		_delay_ms(10),
		UART_Data_Tarnsmit(TURN_HEATER_ON);
	}
	else if ( (TEMP>(EEPROM_read(PLANT_Least_temp_Compare_Location))) && (TEMP<(EEPROM_read(PLANT_Max_temp_Compare_Location))) )
	{
		UART_Data_Tarnsmit(TURN_AC_OFF);
		_delay_ms(10),
		UART_Data_Tarnsmit(TURN_HEATER_OFF);
	}
}

void Mois_Control(unsigned char Mois)
{
	if (Mois<(EEPROM_read(PLANT_Least_Soil_Mois_Compare_Location)))
	{
		UART_Data_Tarnsmit(TURN_WATER_PUMP_ON);
	}
	else if (Mois>(EEPROM_read(PLANT_Max_Soil_Mois_Compare_Location)))
	{
		UART_Data_Tarnsmit(TURN_WATER_PUMP_OFF);
	}
	else
	{
		UART_Data_Tarnsmit(NO_CHANGE);
	}
}

void Humidity_Control(unsigned char Humidity)
{
	if (Humidity<(EEPROM_read(PLANT_Least_Air_Humidity_Compare_Location)))
	{
		
		UART_Data_Tarnsmit(TURN_Humidifier_ON);
	}
	else if (Humidity>(EEPROM_read(PLANT_Max_Air_Humidity_Compare_Location)))
	{

		UART_Data_Tarnsmit(TURN_Humidifier_OFF);
	}
	else
	{
		UART_Data_Tarnsmit(NO_CHANGE);
	}
}

void WATER_TANK_Control(unsigned char Water_Tank_Level)
{
	if (Water_Tank_Level>(EEPROM_read(WATER_TANK_Least_Level_Location)))
	{
		UART_Data_Tarnsmit(TURN_LED_OFF);
	}
	else if (Water_Tank_Level<(EEPROM_read(WATER_TANK_Least_Level_Location)))
	{
		UART_Data_Tarnsmit(TURN_LED_ON);
	}
}

//change air every 12 hours for 1 hour
unsigned char Change_air(unsigned int timer)
{
	unsigned char reset_counter=0;
	if ( ((timer/(12*60*60))!=0) && (one_hour_flag==0) )
	{
		UART_Data_Tarnsmit(TURN_FAN_ON);
		one_hour_flag = 1;
		reset_counter = 1;
	}
	if ( ((timer/(1*60*60))!=0) && (one_hour_flag==1) )
	{
		UART_Data_Tarnsmit(TURN_FAN_OFF);
		one_hour_flag = 0;
		reset_counter = 1;
	}
	return reset_counter;
	
}