/*
 * SPI.c
 *
 * Created: 5/17/2026 5:33:55 PM
 *  Author: Cascoo
 */ 


#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "DIO.h"
#include "Standard Macros.h"


void SPI_Master_init()
{
	
	
	//setting SPCR 
	SET_BIT(SPCR,SPE);		//enable SPI
	SET_BIT(SPCR,DORD);		//setting LSB transmitted first 
	SET_BIT(SPCR,MSTR);		//setting MCU to be master
	CLR_BIT(SPCR,CPOL);		//setting clock polarity to leading edge is the rising and trailing edge is falling (in idle state clock = 0)
	CLR_BIT(SPCR,CPHA);		//setting clock phase to sample (transmit) on leading edge (rising) and setup on trailing edge
	
	CLR_BIT(SPCR,SPR0);		//setting SPI clock by CPU clock/4 (2 bits in SPCR and 1 bit in SPSR)
	CLR_BIT(SPCR,SPR1);
	
	//setting SPSR
	CLR_BIT(SPSR,SPI2X);	//setting SPI clock by CPU clock/4
	//setting pins direction
	set_pin_direction('B',4,1);		//setting SS pin to be output pin (default in master mode)
	set_pin_direction('B',5,1);		//setting MOSI pin to be output pin (default in master mode)
	set_pin_direction('B',6,0);		//setting MISO pin to be input pin
	set_pin_direction('B',7,1);		//setting SCK pin to be output pin (default in master mode)
	
	/*set SS to high*/
	DIO_write_pin('B',4,1);
}

void SPI_Slave_init()
{
	//setting SPCR
	SET_BIT(SPCR,SPE);		//enable SPI
	SET_BIT(SPCR,DORD);		//setting LSB transmitted first
	CLR_BIT(SPCR,MSTR);		//setting MCU to be slave
	CLR_BIT(SPCR,CPOL);		//setting clock polarity to leading edge is the rising and trailing edge is falling (in idle state SCK = 0)
	CLR_BIT(SPCR,CPHA);		//setting clock phase to sample (transmit) on leading edge (rising) and setup on trailing edge
	
	//setting pins direction
	set_pin_direction('B',4,0);		//setting SS pin to be input pin
	set_pin_direction('B',5,0);		//setting MOSI pin to be input pin
	set_pin_direction('B',6,1);		//setting MISO pin to be output pin (default in slave mode)
	set_pin_direction('B',7,0);		//setting SCK pin to be input pin 
}


//the data is exchanged between master and slave every transmission cycle

unsigned char SPI_Master_Data_Transmit(unsigned char Data)
{
	DIO_write_pin('B',4,0);		//writing 0 on SS pin to select slave 
	
	SPDR= Data;	
	while(READ_BIT(SPSR,SPIF)==0); //SPIF will be 1 if transmission is completed and data exchanged between Master and Slave SPDR
	//SPIF will be cleared when we read SPSR while SPIF is 1 and then accessing the data register 
	//(we read SPSR while SPIF is 1 in this cycle and we will access the SPDR in next transmission which clearing the flag then start transmission)
	DIO_write_pin('B',4,1);
	return SPDR;	//no need to this data in most cases
}

unsigned char SPI_Slave_Data_Receive(unsigned char data)
{
	SPDR=data;		//putting data in SPDR maybe DUMMY in most cases put it is for the exchanging 
	//transmission will not be initialized till Master send clock so salve puts data in SPDR and wait
	while(READ_BIT(SPSR,SPIF)==0); //SPIF will be 1 if transmission is completed and data exchanged between Master and Slave SPDR
	//SPIF will be cleared when we read SPSR while SPIF is 1 and then accessing the data register
	//(we read SPSR while SPIF is 1 in this cycle and we will access the SPDR in next transmission which clearing the flag then start transmission)
	
	return SPDR;	//no need to this data in most cases
	
}

void SPI_Master_String_Transmit(unsigned char *string_ptr)
{
	while (*string_ptr!=0)
	{
		SPI_Master_Data_Transmit(*string_ptr);
		_delay_ms(200);
		string_ptr++;
	}
}