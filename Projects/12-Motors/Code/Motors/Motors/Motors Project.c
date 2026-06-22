/*
 * Motors.c
 *
 * Created: 5/15/2026 1:28:21 AM
 *  Author: Cascoo
 */ 

#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "motors.h"
#include "Standard_Macros.h"
#include "DIO.h"

int main(void)
{
	//setting pins for Dc motor to control rotation direction clockwise
	set_pin_direction('D',6,0);
	set_pin_direction('D',7,1);
	
    while(1)
    {
		//generating wave on OC0 pin with duty cycle = 50%
        DC_motor_duty_cycle_timer0(40);
		
		//generating wave on OC1A pin to control servo motor angles
		Servo_motor_angle_timer1(90);
		_delay_ms(1000);
		
		Servo_motor_angle_timer1(0);
		_delay_ms(1000);
		
		Servo_motor_angle_timer1(-90);
		_delay_ms(1000);
		
		Servo_motor_angle_timer1(-33);
		_delay_ms(1000);
		
		Servo_motor_angle_timer1(45);
		_delay_ms(1000);
		
		Servo_motor_angle_timer1(-45);
		_delay_ms(1000);
		
		Servo_motor_angle_timer1(-50);
		_delay_ms(1000);
		
		Servo_motor_angle_timer1(77);
		_delay_ms(1000);
		
    }
}