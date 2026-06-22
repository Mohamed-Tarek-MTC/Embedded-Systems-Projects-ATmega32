/*
 * counter_form_0_to_F_using_7_Segments.c
 *
 * Created: 5/9/2026 11:42:46 PM
 *  Author: Cascoo
 */ 

#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "7_SEG.h"

int main(void)
{
	_7_SEG_init('D');
	
    while(1)
    {
	   for (int i=0;i<16;i++)
	   {
		   _7_SEG_write('D',i);
		   _delay_ms(1000);
	   }
    }
}