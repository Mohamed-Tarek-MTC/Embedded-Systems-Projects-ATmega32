/*
 * USART.c
 *
 * Created: 5/17/2026 4:18:30 PM
 *  Author: Cascoo
 */ 

#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "std_macros.h"

void UART_normal_init(unsigned short Baud_Rate)
{
	unsigned short UBRR ;
	
	UBRR = (F_CPU/(16*Baud_Rate))-1;
	
	//setting Baud Rate
	UBRRH = UBRR>>8;
	UBRRL = UBRR;
	
	//setting 1st control register UCSRA
	//left it in default bits values 
	
	//setting 2nd control register UCSRB
	//leave interrupt enable bits by 0 as default
	
	//enabling Tx and Rx 
	SET_BIT(UCSRB,TXEN);
	SET_BIT(UCSRB,RXEN);
	
	//setting 8 bits characters transmission
	CLR_BIT(UCSRB,UCSZ2);	// 1 bit in UCSRB
	// 2 bits in UCSRC

	
	//setting 3rd control register UCSRC 
	//must write 1 on URSEL bit to write on UCSRA if 0 we write on UBBRH
	
	//setting UCSRC with  Asynchronous Operation (UMSEL = 0),enabling parity with even parity (UPM0=0, UPM1=1), 1 stop bit (USBS=0)
	// and character size of 8 bit (UCSZ0=1, UCSZ1=1) 
	//(and clock polarity of Tx on rising edge and Rx on falling edge (UCPOL=0) but no need in Asynchronous Mode)
	UCSRC|= (1<<URSEL)|(1<<UPM1)|(1<<UCSZ0)|(1<<UCSZ1);
}

void UART_Data_Tarnsmit(unsigned char data)
{
	//check for UDR is empty with UDRE flag in UCSRA (if empty UDRE=1) 
	//when data is transmitted completely TXC flag will = 1 then data moves from UDR to Tx buffer so UDRE will = 1 
	while(READ_BIT(UCSRA,UDRE)==0);
	//put data to be transmit in UDR
	UDR=data;
}

unsigned char UART_Data_Recieve(void)
{
	unsigned char Received_data;
	//check if data received completely and it is in Rx UDR with RXC flag in UCSRA (if 1 means data Received completely and it is in UDR)
	//reading the data in UDR will clear the RXC flag (RXC will = 0)
	while (READ_BIT(UCSRA,RXC)==0);
	Received_data=UDR;
	
	return Received_data;
}

void UART_Send_String(char *String_Ptr)
{
	while (*String_Ptr!=0)
	{
		UART_Data_Tarnsmit(*String_Ptr);
		_delay_ms(200); //wait till the string transmitted to be displayed in receiver 
		String_Ptr++;
	}
}
