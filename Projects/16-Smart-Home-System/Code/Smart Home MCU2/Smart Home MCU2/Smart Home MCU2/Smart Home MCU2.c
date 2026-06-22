/*
 * Smart_Home_MCU2.c
 *
 * Created: 6/2/2026 2:01:37 AM
 *  Author: Cascoo
 */ 

#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#include "ADC.h"
#include "motors.h"
#include "LED.h"
#include "USART.h"
#include "DIO.h"

#define AVCC 2.0	//ADC Ref Volt


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

volatile unsigned char Recieved_flag=0;
volatile unsigned char CMD_Recieved = 0;
int main(void)
{
	ADC_init();
	UART_normal_init(9600);
	
	LED_init('C',0);	//Room 1
	LED_init('C',2);	//Room 2
	LED_init('C',4);	//Kitchen
	LED_init('C',5);	//Bathroom
	
	LED_init('B',0);	//Salon LED
	
	
	//we will LED_init('C',0);/treat ACs control pins, TV pin and FAN Control pin as LEDs to avoid using DIO driver (MCAL) in this application 
	LED_init('C',1);	//Room1 FAN
	LED_init('C',3);	//Room2 AC
	LED_init('C',6);	//Room2 AC Temp Control
	
	LED_init('B',1);	//Salon TV
	LED_init('B',2);	//Salon AC
	LED_init('B',3);	//Salon AC Temp Control
	
	//we turn all of initially 
	LED_off('C',0);	//Room 1
	LED_off('C',1);	//Room1 FAN
	LED_off('C',2);	//Room 2
	LED_off('C',3);	//Room2 AC
	LED_off('C',4);	//Kitchen
	LED_off('C',5);	//Bathroom
	LED_off('C',6);	//Room2 AC Temp Control
	LED_off('B',0);	//Salon LED
	LED_off('B',1);	//Salon TV
	LED_off('B',2);	//Salon AC
	LED_off('B',3);	//Salon AC Temp Control
	LED_init('C',7);
	
	float step = AVCC/1023; //ADC Step
	unsigned char room1_led_state,room1_fan_state, room2_led_state,room2_AC_state,room2_AC_temp;
	unsigned char kitchen_led_state,  bath_led_state, salon_led_state,salon_AC_state,salon_AC_temp,salon_TV_state;
	unsigned char Room2_temp = 0, Salon_temp = 0;
	sei();
	
    while(1)
    {
		
		LED_tog('c',7);
		_delay_ms(100);
		//setting temp for ACs using ADC 
		ADC_SELECT_channel(0);
		Room2_temp = ADC_READ()*step*100;	//(ADC_READ()*step)*1000 = value in mV, /senstivity (10mV) = temp 
		
		ADC_SELECT_channel(1);
		Salon_temp = ADC_READ()*step*100;
		
		if (Room2_temp>room2_AC_temp)
		{
			LED_on('C',6);
		}
		else
		{
			LED_off('C',6);
		}
		
		if (Salon_temp>salon_AC_temp)
		{
			LED_on('B',3);
		}
		else
		{
			LED_off('B',3);
		}
		
		
		
		//receiving commands from MCU1 and executing them
		if(Recieved_flag==1)
		{
			
			switch (CMD_Recieved)
			{
				//ROOM1 control
				case READ_ROOM1_LED_State : 
					room1_led_state = LED_state('C',0);
					UART_Data_Tarnsmit(room1_led_state);
					break;
					
				case TURN_ROOM1_LED_ON : 
					LED_on('C',0);
					break;
				
				case TURN_ROOM1_LED_OFF :
					LED_off('C',0);
					break;
				
				case READ_ROOM1_FAN_State :
					room1_fan_state = LED_state('C',1);
					UART_Data_Tarnsmit(room1_fan_state);
					break;
					
				case TURN_ROOM1_FAN_ON : 
					LED_on('C',1);					
					break;
				
				case TURN_ROOM1_FAN_OFF :
					LED_off('C',1);
					break;
				
				//ROOM2 control
				case READ_ROOM2_LED_State :
					room2_led_state = LED_state('C',2);
					UART_Data_Tarnsmit(room2_led_state);
					break;
				
				case TURN_ROOM2_LED_ON :
					LED_on('C',2);
					break;
					
				case TURN_ROOM2_LED_OFF :
					LED_off('C',2);
					break;
					
				case READ_ROOM2_AC_State :
					room2_AC_state = LED_state('C',3);
					UART_Data_Tarnsmit(room2_AC_state);
					break;
				
				case ROOM2_AC_SET_TEMP :
					cli();	//to make room2_AC_temp reads from UART_Data_Recieve not from ISR
					room2_AC_temp = UART_Data_Recieve();
					sei();
					break;
				
				case TURN_ROOM2_AC_ON :
					LED_on('C',3);
					break;
					
				case TURN_ROOM2_AC_OFF :
					LED_off('C',3);
					break;
					
				//KITCHEN control
				case READ_KITCHEN_LED_State :
					kitchen_led_state = LED_state('C',4);
					UART_Data_Tarnsmit(kitchen_led_state);
					break;
				
				case TURN_KITCHEN_LED_ON :
					LED_on('C',4);
					break;
					
				case TURN_KITCHEN_LED_OFF :
					LED_off('C',4);				
					break;
				 
				//BATH control
				case READ_BATH_LED_State :
					bath_led_state = LED_state('C',5);
					UART_Data_Tarnsmit(bath_led_state);
					break;
				
				case TURN_BATH_LED_ON : 
					LED_on('C',5);
					break;
					
				case TURN_BATH_LED_OFF :
					LED_off('C',5);
					break;
				
				//SALON control
				case READ_SALON_LED_State :
					salon_led_state = LED_state('B',0);
					UART_Data_Tarnsmit(salon_led_state);
					break;
				
				case TURN_SALON_LED_ON :
					LED_on('B',0);
					break;
				
				case TURN_SALON_LED_OFF :
					LED_off('B',0);
					break;
				
				case READ_SALON_AC_State :
					salon_AC_state = LED_state('B',2);
					UART_Data_Tarnsmit(salon_AC_state);
					break;
				
				case SALON_AC_SET_TEMP :
					cli();
					salon_AC_temp = UART_Data_Recieve();
					sei();
					break;
				
				case TURN_SALON_AC_ON :
					LED_on('B',2);
					break;
				
				case TURN_SALON_AC_OFF :
					LED_off('B',2);
					break;
				
				case READ_SALON_TV_State :
					salon_TV_state = LED_state('B',1);
					UART_Data_Tarnsmit(salon_TV_state);
					break;
				
				case TURN_SALON_TV_ON :
					LED_on('B',1);
					break;
				
				case TURN_SALON_TV_OFF :
					LED_off('B',1);
					break;
			}
			Recieved_flag = 0;
			
		} // if
		
         
    } //while
} //main


ISR(USART_RXC_vect)
{
	CMD_Recieved = UDR;
	Recieved_flag = 1;
}