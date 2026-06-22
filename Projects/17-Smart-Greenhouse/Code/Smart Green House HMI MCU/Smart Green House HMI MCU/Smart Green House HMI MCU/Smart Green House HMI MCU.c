	/*
	 * Smart_Green_House_HMI_MCU.c
	 *
	 * Created: 6/3/2026 8:09:50 AM
	 *  Author: Cascoo
	 */ 

	#define F_CPU 8000000UL
	#include <avr/io.h>
	#include <util/delay.h>
	#include <avr/interrupt.h>

	#include "EEPROM.h"
	#include "LCD20x4.h"
	#include "LCDconfig.h"
	#include "KeyPad.h"
	#include "USART.h"
	#include "Timers.h"
	#include "Plant_Config.h"
	#include "Green_House_Control.h"

	volatile unsigned int Days_in_sec_counter=0;
	volatile unsigned int sec_counter = 0;
	
	volatile unsigned char CMD_Received = 0;
	volatile unsigned char CMD = 0;
	volatile unsigned char value = 0;
	volatile unsigned char index = 0;
	volatile unsigned char Recieved[2]={0,0};

	int main(void)
	{
		Plants_init();
		UART_normal_init(9600);
		LCD_init();
		keypad_init();
		TIMER2_OVF_init_1s();
		sei();
	
		unsigned char Current_stage;
		unsigned char press = NotPressed;
		unsigned char Current_Temp, Current_Mois, Current_Humidity, Current_Water_Level;
		unsigned char i, reset_sec_counter=0, days_to_harvest;
		unsigned short days=0;
	
		days_to_harvest = EEPROM_read(PLANT_Harvest_Days_Location);
		if ((EEPROM_read(Current_Days_Counter_Location))!=0xFF)			//to prevent power cut down before first day is gone so days location would be 0xFF
		{																//and 0xFF is greater than days to harvest so will display harvest rdy
			days = EEPROM_read(Current_Days_Counter_Location);
		}
		

		while(1)
		{
			Current_stage = EEPROM_read(Current_Stage_Location);
			if (Current_stage == 0)
			{
				do 
				{
					LCD_CLR_screen();
					LCD_MOVE_cursor(1,1);
					LCD_send_string("    Select Plant    ");
					LCD_MOVE_cursor(2,1);
					LCD_send_string("1-Tomato  2-Potato  ");
					LCD_MOVE_cursor(3,1);
					LCD_send_string("3-Wheat   4-Onions  ");
					LCD_MOVE_cursor(4,1);
					LCD_send_string("5-Garlic  6-Cucumber");
					//delay for 1 sec and taking read from keypad every 10Ms
					for(i=0;i<100;i++)
					{
						press=keypad_read();

						if(press!=NotPressed)
						{
							break;
						}

						_delay_ms(10);
					}
					if(press!=NotPressed)
					{
						break;
					}
				
					LCD_CLR_screen();
					LCD_MOVE_cursor(1,1);
					LCD_send_string("    Select Plant    ");
					LCD_MOVE_cursor(2,1);
					LCD_send_string("7-Pepper  8-Corn    ");
					LCD_MOVE_cursor(3,1);
					LCD_send_string("9-Lettuce           ");
					//delay for 1 sec and taking read from keypad every 10Ms
					for(i=0;i<100;i++)
					{
						press=keypad_read();

						if(press!=NotPressed)
						{
							break;
						}

						_delay_ms(10);
					}
				} while (press==NotPressed);
				while (keypad_read()!=NotPressed);
				Current_stage = 1;
				EEPROM_write(Current_stage,Current_Stage_Location);
			
			}
		
			if (Current_stage == 1)
			{
				switch (press)
				{
					case '1' :
						Tomatoes();
						break;
				
					case '2' :
						Potatoes();
						break;
					
					case '3' :
						Wheat();
						break;
					
					case '4' :
						Onions();
						break;
					
					case '5' :
						Garlic();
						break;
				
					case '6' :
						Cucumber();
						break;
			
					case '7' :
						Peppers();
						break;
					
					case '8' :
						Corn();
						break;
					
					case '9' :
						Lettuce();
						break;	
				}
				days=0;
				Current_stage = 2;
				days_to_harvest = EEPROM_read(PLANT_Harvest_Days_Location);
				EEPROM_write(Current_stage,Current_Stage_Location);
				EEPROM_write(0,Current_Days_Counter_Location);
				LCD_CLR_screen();
			}
		
			if (Current_stage == 2)
			{
				LCD_MOVE_cursor(1,1);
				LCD_send_string("   Current States   ");
				LCD_MOVE_cursor(2,1);
				LCD_send_string("Temp:");
				LCD_MOVE_cursor(2,10);
				LCD_send_string("  Mois:");
				LCD_MOVE_cursor(3,1);
				LCD_send_string("Hum:");
				LCD_MOVE_cursor(3,9);
				if (days<days_to_harvest)
				{
					LCD_send_string(" Day:");
					LCD_MOVE_cursor(3,14);
					if (days<10)
					{
						LCD_send_string("  ");
						LCD_send_char(days+48);
					}
					else if (days<100)
					{
						LCD_send_string(" ");
						LCD_send_char((days/10)+48);
						LCD_send_char((days%10)+48);
					}
					else if (days<1000)
					{
						LCD_send_char((days/100)+48);
						LCD_send_char(((days%100)/10)+48);
						LCD_send_char((days%10)+48);
					}
					else
					{
						days=0;
					}
					LCD_send_char('/');
					if (days_to_harvest<10)
					{
					
						LCD_send_char(days_to_harvest+48);
						LCD_send_string("  ");
					}
					else if (days_to_harvest<100)
					{
						LCD_send_char((days_to_harvest/10)+48);
						LCD_send_char((days_to_harvest%10)+48);
						LCD_send_string(" ");
					}
					else if (days_to_harvest<1000)
					{
						LCD_send_char((days_to_harvest/100)+48);
						LCD_send_char(((days_to_harvest%100)/10)+48);
						LCD_send_char((days_to_harvest%10)+48);
					}
				}
				else
				{
					LCD_send_string("Harvest Rdy");
				}
				LCD_MOVE_cursor(4,1);
				LCD_send_string("Change Plant hold 0 ");
				
				press=keypad_read();

				if(press=='0')
				{
					Current_stage=0;
					EEPROM_write(Current_stage,Current_Stage_Location);
				}
			}
		
			if (CMD_Received == 1)
			{
				switch (CMD)
				{
					case TEMP_Changed :
						Current_Temp = value;
						LCD_MOVE_cursor(2,6);
						if (Current_Temp<10)
						{
							LCD_send_string(" ");
							LCD_send_char(Current_Temp+48);
							LCD_send_char(0xDF);
							LCD_send_char('C');
						}
						else if (Current_Temp<100)
						{
							LCD_send_char((Current_Temp/10)+48);
							LCD_send_char((Current_Temp%10)+48);
							LCD_send_char(0xDF);
							LCD_send_char('C');
						}
						TEMP_Control(Current_Temp);
						break;
				
					case Mois_Changed :
						Current_Mois = value;
						Mois_Control(Current_Mois);
						LCD_MOVE_cursor(2,17);
						if (Current_Mois<10)
						{
							LCD_send_string(" ");
							LCD_send_char(Current_Mois+48);
							LCD_send_char('%');
						}
						else if (Current_Mois<100)
						{
							LCD_send_char((Current_Mois/10)+48);
							LCD_send_char((Current_Mois%10)+48);
							LCD_send_char('%');
						};
						break;
					
					case Humidity_Changed :
						Current_Humidity = value;
						Humidity_Control(Current_Humidity);
						LCD_MOVE_cursor(3,5);
						if (Current_Humidity<10)
						{
							LCD_send_string(" ");
							LCD_send_char(Current_Humidity+48);
							LCD_send_char('%');
						}
						else if (Current_Humidity<100)
						{
							LCD_send_char((Current_Humidity/10)+48);
							LCD_send_char((Current_Humidity%10)+48);
							LCD_send_char('%');
						}
						break;
				
					case WATER_TANK_Level_Changed :
						Current_Water_Level = value;
						WATER_TANK_Control(Current_Water_Level);
						break; 
				}
				CMD_Received = 0;
			}
		
			if ((sec_counter/(1*60*60))!=0)	//every one hour we call the fan function to take action
			{
				reset_sec_counter = Change_air(sec_counter);
				if (reset_sec_counter == 1)
				{
					sec_counter = 0;
				}
			}
		
			if ((Days_in_sec_counter/(24*60*60))!=0)	//1 Day gone
			{
				days++;
				EEPROM_write(days,Current_Days_Counter_Location);
				Days_in_sec_counter=0;
			}
				
		}//end of while
	}//end of main	

	ISR(USART_RXC_vect)
	{
		Recieved[index++] = UDR;
		if (index>=2)
		{
			CMD = Recieved[0];
			value = Recieved[1];
			index = 0;
			CMD_Received = 1;
		}
		
	}

	ISR(TIMER2_OVF_vect)
	{
		Days_in_sec_counter++;
		sec_counter++;
	}

