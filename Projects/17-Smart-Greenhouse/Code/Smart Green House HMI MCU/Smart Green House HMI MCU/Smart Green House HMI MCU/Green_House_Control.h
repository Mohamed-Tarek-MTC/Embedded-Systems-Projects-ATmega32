/*
 * Green_House_Control.h
 *
 * Created: 6/4/2026 2:23:40 AM
 *  Author: Cascoo
 */ 


#ifndef GREEN_HOUSE_CONTROL_H_
#define GREEN_HOUSE_CONTROL_H_

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

void TEMP_Control(unsigned char TEMP);
void Mois_Control(unsigned char Mois);
void Humidity_Control(unsigned char Humidity);
void WATER_TANK_Control(unsigned char Water_Tank_Level);
unsigned char Change_air(unsigned int timer);


#endif /* GREEN_HOUSE_CONTROL_H_ */