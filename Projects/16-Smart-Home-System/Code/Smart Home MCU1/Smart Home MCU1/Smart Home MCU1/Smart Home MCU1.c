/*
* Smart_Home_MCU1.c
*
* Created: 6/1/2026 12:49:55 AM
*  Author: Cascoo
*/

#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>

#include "KeyPad.h"
#include "EEPROM.h"
#include "LCD.h"
#include "LCDconfig.h"
#include "USART.h"
#include "LED.h"


#define AC_Temp_First_Digit_Location	0x0200
#define AC_Temp_Second_Digit_Location	0x0201


enum DATA
{
	//ROOM1 control
	READ_ROOM1_LED_State = 0x01,
	TURN_ROOM1_LED_ON = 0x02,
	TURN_ROOM1_LED_OFF = 0x03,
	READ_ROOM1_FAN_State = 0x04,
	TURN_ROOM1_FAN_ON = 0x05,
	TURN_ROOM1_FAN_OFF = 0x06,
	
	//ROOM2 control
	READ_ROOM2_LED_State = 0x07,
	TURN_ROOM2_LED_ON = 0x08,
	TURN_ROOM2_LED_OFF = 0x09,
	READ_ROOM2_AC_State = 0x0A,
	ROOM2_AC_SET_TEMP =	0x0B,
	TURN_ROOM2_AC_ON = 0x0C,
	TURN_ROOM2_AC_OFF = 0x0D,
	
	//KITCHEN control
	READ_KITCHEN_LED_State = 0x0E,
	TURN_KITCHEN_LED_ON = 0x0F,
	TURN_KITCHEN_LED_OFF = 0x10,
	
	//BATH control
	READ_BATH_LED_State = 0x11,
	TURN_BATH_LED_ON = 0x12,
	TURN_BATH_LED_OFF = 0x13,
	
	//SALON control
	READ_SALON_LED_State = 0x14,
	TURN_SALON_LED_ON = 0x15,
	TURN_SALON_LED_OFF = 0x16,
	READ_SALON_AC_State = 0x17,
	SALON_AC_SET_TEMP =	0x18,
	TURN_SALON_AC_ON = 0x19,
	TURN_SALON_AC_OFF = 0x1A,
	READ_SALON_TV_State = 0x1B,
	TURN_SALON_TV_ON = 0x1C,
	TURN_SALON_TV_OFF = 0x1D,
};
int main(void)
{
	unsigned char i,press;
	unsigned char room1_led_state,room1_fan_state, room2_led_state,room2_AC_state,room2_AC_temp;  
	unsigned char kitchen_led_state,  bath_led_state, salon_led_state,salon_AC_state,salon_AC_temp,salon_TV_state;
	LCD_init();
	keypad_init();
	UART_normal_init(9600);
	
	while(1)
	{
		press = NotPressed;
		//main menu
		do
		{
			LCD_MOVE_cursor(1,1);
			LCD_send_string("1-Room1  2-Room2");
			LCD_MOVE_cursor(2,1);
			LCD_send_string("3-kitch  4-bath");
			
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
			LCD_send_string("5-Salon");
			
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
		//end of main menu
		
		//controlling choosing part of house
		LCD_CLR_screen();
		switch (press)
		{
			case '1' :
				//controlling ROOM1
				UART_Data_Tarnsmit(READ_ROOM1_LED_State);
				room1_led_state = UART_Data_Recieve();
				UART_Data_Tarnsmit(READ_ROOM1_FAN_State);
				room1_fan_state = UART_Data_Recieve();
			
				do
				{
					if (room1_led_state==1)
					{
						LCD_send_string("LED State: ON");
					}
					else
					{
						LCD_send_string("LED State: OFF");
					}
					LCD_MOVE_cursor(2,1);
					if (room1_fan_state==1)
					{
						LCD_send_string("FAN State: ON");
					}
					else
					{
						LCD_send_string("FAN State: OFF");
					}
					
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
					LCD_send_string("LED: 1-ON 2-OFF");
					LCD_MOVE_cursor(2,1);
					LCD_send_string("FAN: 3-ON 4-OFF");
					
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
					LCD_send_string("for main menu");
					LCD_MOVE_cursor(2,1);
					LCD_send_string("press another");
					
					for(i=0;i<100;i++)
					{
						press=keypad_read();

						if(press!=NotPressed)
						{
							break;
						}

						_delay_ms(10);
					}
					LCD_CLR_screen();
				
				} while (press==NotPressed);
				while (keypad_read()!=NotPressed);
			
				if (press == '1')
				{
					UART_Data_Tarnsmit(TURN_ROOM1_LED_ON);
				}
				else if (press == '2')
				{
					UART_Data_Tarnsmit(TURN_ROOM1_LED_OFF);
				}
				else if (press == '3')
				{
					UART_Data_Tarnsmit(TURN_ROOM1_FAN_ON);
				}
				else if (press == '4')
				{
					UART_Data_Tarnsmit(TURN_ROOM1_FAN_OFF);
				}
				break;
			
			case '2' :
				//controlling ROOM2
				UART_Data_Tarnsmit(READ_ROOM2_LED_State);
				room2_led_state = UART_Data_Recieve();
				UART_Data_Tarnsmit(READ_ROOM2_AC_State);
				room2_AC_state = UART_Data_Recieve();
			
				do
				{
					if (room2_led_state==1)
					{
						LCD_send_string("LED State: ON");
					}
					else
					{
						LCD_send_string("LED State: OFF");
					}
					LCD_MOVE_cursor(2,1);
					if (room2_AC_state==1)
					{
						LCD_send_string("AC State: ON");
					}
					else
					{
						LCD_send_string("AC State: OFF");
					}
					
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
					LCD_send_string("LED: 1-ON 2-OFF");
					LCD_MOVE_cursor(2,1);
					LCD_send_string("AC: 3-ON 4-OFF");
					
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
					LCD_send_string("for main menu");
					LCD_MOVE_cursor(2,1);
					LCD_send_string("press another");
					
					for(i=0;i<100;i++)
					{
						press=keypad_read();

						if(press!=NotPressed)
						{
							break;
						}

						_delay_ms(10);
					}
					LCD_CLR_screen();
				
				} while (press==NotPressed);
				while (keypad_read()!=NotPressed);
			
				if (press == '1')
				{
					UART_Data_Tarnsmit(TURN_ROOM2_LED_ON);
				}
				else if (press == '2')
				{
					UART_Data_Tarnsmit(TURN_ROOM2_LED_OFF);
				}
				else if (press == '3')
				{
					UART_Data_Tarnsmit(TURN_ROOM2_AC_ON);
					LCD_CLR_screen();
					LCD_send_string("Set AC temp");
					LCD_MOVE_cursor(2,1);
					UART_Data_Tarnsmit(ROOM2_AC_SET_TEMP);
					for (i=0;i<2;i++)
					{
						do
						{
							press=keypad_read();
						} while (press==NotPressed);
						while (keypad_read()!=NotPressed);
						EEPROM_write((press-48),AC_Temp_First_Digit_Location+i);
						LCD_send_char(press);
					}
				
					room2_AC_temp = (EEPROM_read(AC_Temp_Second_Digit_Location))+((EEPROM_read(AC_Temp_First_Digit_Location))*10);
					UART_Data_Tarnsmit(room2_AC_temp);
					_delay_ms(500);
				}
				else if (press == '4')
				{
					UART_Data_Tarnsmit(TURN_ROOM2_AC_OFF);
				}
				break;
			
			case '3' :
				//controlling kitchen
				UART_Data_Tarnsmit(READ_KITCHEN_LED_State);
				kitchen_led_state = UART_Data_Recieve();
			
				do
				{
					if (kitchen_led_state==1)
					{
						LCD_send_string("LED State: ON");
					}
					else
					{
						LCD_send_string("LED State: OFF");
					}
				
					LCD_MOVE_cursor(2,1);
					LCD_send_string("LED: 1-ON 2-OFF");

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
					LCD_send_string("for main menu");
					LCD_MOVE_cursor(2,1);
					LCD_send_string("press another");
					
					for(i=0;i<100;i++)
					{
						press=keypad_read();

						if(press!=NotPressed)
						{
							break;
						}

						_delay_ms(10);
					}
					LCD_CLR_screen();
				
				} while (press==NotPressed);
				while (keypad_read()!=NotPressed);
			
				if (press == '1')
				{
					UART_Data_Tarnsmit(TURN_KITCHEN_LED_ON);
				}
				else if (press == '2')
				{
					UART_Data_Tarnsmit(TURN_KITCHEN_LED_OFF);
				}
				break;
			
			case '4' :
				//controlling bathroom
				UART_Data_Tarnsmit(READ_BATH_LED_State);
				bath_led_state = UART_Data_Recieve();
			
				do
				{
					if (bath_led_state==1)
					{
						LCD_send_string("LED State: ON");
					}
					else
					{
						LCD_send_string("LED State: OFF");
					}
				
					LCD_MOVE_cursor(2,1);
					LCD_send_string("LED: 1-ON 2-OFF");

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
					LCD_send_string("for main menu");
					LCD_MOVE_cursor(2,1);
					LCD_send_string("press another");
					for(i=0;i<100;i++)
					{
						press=keypad_read();

						if(press!=NotPressed)
						{
							break;
						}

						_delay_ms(10);
					}
					LCD_CLR_screen();
				
				} while (press==NotPressed);
				while (keypad_read()!=NotPressed);
			
				if (press == '1')
				{
					UART_Data_Tarnsmit(TURN_BATH_LED_ON);
				}
				else if (press == '2')
				{
					UART_Data_Tarnsmit(TURN_BATH_LED_OFF);
				}
				break;
			
			case '5' :
				//Controlling Salon
				UART_Data_Tarnsmit(READ_SALON_LED_State);
				salon_led_state = UART_Data_Recieve();
				UART_Data_Tarnsmit(READ_SALON_AC_State);
				salon_AC_state = UART_Data_Recieve();
				UART_Data_Tarnsmit(READ_SALON_TV_State);
				salon_TV_state = UART_Data_Recieve();
			
				do
				{
					LCD_CLR_screen();
					if (salon_led_state==1)
					{
						LCD_send_string("LED State: ON");
					}
					else
					{
						LCD_send_string("LED State: OFF");
					}
					LCD_MOVE_cursor(2,1);
					if (salon_AC_state==1)
					{
						LCD_send_string("AC State: ON");
					}
					else
					{
						LCD_send_string("AC State: OFF");
					}
				
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
				
					if (salon_TV_state==1)
					{
						LCD_send_string("TV State: ON");
					}
					else
					{
						LCD_send_string("TV State: OFF");
					}
				
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
					LCD_send_string("LED: 1-ON 2-OFF");
					LCD_MOVE_cursor(2,1);
					LCD_send_string("AC: 3-ON 4-OFF");
					
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
					LCD_send_string("TV: 5-ON 6-OFF");
					
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
					LCD_send_string("for main menu");
					LCD_MOVE_cursor(2,1);
					LCD_send_string("press another");
					for(i=0;i<100;i++)
					{
						press=keypad_read();

						if(press!=NotPressed)
						{
							break;
						}

						_delay_ms(10);
					}
					LCD_CLR_screen();

				} while (press==NotPressed);
				while (keypad_read()!=NotPressed);
			
				if (press == '1')
				{
					UART_Data_Tarnsmit(TURN_SALON_LED_ON);
				}
				else if (press == '2')
				{
					UART_Data_Tarnsmit(TURN_SALON_LED_OFF);
				}
				else if (press == '3')
				{
					UART_Data_Tarnsmit(TURN_SALON_AC_ON);
					LCD_CLR_screen();
					LCD_send_string("Set AC temp");
					LCD_MOVE_cursor(2,1);
					UART_Data_Tarnsmit(SALON_AC_SET_TEMP);
					for (i=0;i<2;i++)
					{
						do
						{
							press=keypad_read();
						} while (press==NotPressed);
						while (keypad_read()!=NotPressed);
						EEPROM_write((press-48),AC_Temp_First_Digit_Location+i);
						LCD_send_char(press);
					}
				
					salon_AC_temp = (EEPROM_read(AC_Temp_Second_Digit_Location))+((EEPROM_read(AC_Temp_First_Digit_Location))*10);
					UART_Data_Tarnsmit(salon_AC_temp);
					_delay_ms(500);
				}
				else if (press == '4')
				{
					UART_Data_Tarnsmit(TURN_SALON_AC_OFF);
				}
				else if (press == '5')
				{
					UART_Data_Tarnsmit(TURN_SALON_TV_ON);
				}
				else if (press == '6')
				{
					UART_Data_Tarnsmit(TURN_SALON_TV_OFF);
				}
				break;
		}
		_delay_ms(10);	//to prevent UDR over write in Reciever;
	}
}	