/*
 * I2C.c
 *
 * Created: 5/23/2026 2:32:27 PM
 *  Author: Cascoo
 */ 


#define F_CPU 8000000UL
#include <avr/io.h>

#include "Standard Macros.h"

#define prescaler 4		//(1/4/16/64)


void I2C_master_init(unsigned long SCL_clock)
{
	TWBR = ((F_CPU/SCL_clock)-16)/(2*prescaler);
	if (prescaler==1)
	{
		TWSR=0;
	}
	else if (prescaler==4)
	{
		TWSR=1;
	}
	else if (prescaler==16)
	{
		TWSR=2;
	}
	else if (prescaler==64)
	{
		TWSR=3;
	}
}

void OWN_Address_Sett(unsigned char OWN_Address)
{
	TWAR=OWN_Address;
}

void Start_Con(void)
{
	TWCR=(1<<TWINT)|(1<<TWEN)|(1<<TWSTA);
	while (READ_BIT(TWCR,TWINT)==0);
	if ((TWSR&0xF8)!=0x08)	//start con transmitted
	{
		START_ERROR();
	}
}

void Repeated_Start_Con(void)
{
	TWCR=(1<<TWINT)|(1<<TWEN)|(1<<TWSTA);
	while (READ_BIT(TWCR,TWINT)==0);
	if ((TWSR&0xF8)!=0x10)	//Repeated Start con transmitted
	{
		START_ERROR();
	}
}

void STOP_Con(void)
{
	TWCR=(1<<TWINT)|(1<<TWEN)|(1<<TWSTO);
}

//Master Transmitter Mode

void I2C_Transmit_Slave_AddressW(unsigned char AddressW)
{
	TWDR = AddressW;
	TWCR = (1<<TWINT)|(1<<TWEN);
	while (READ_BIT(TWCR,TWINT)==0);
	if ((TWSR&0xF8)!=0x18)		// SLA+W has been transmitted + ACK has been received  
	{
		WRITE_ADDRESS_ERROR();
	}
}

void I2C_Master_Transmit_Data(unsigned char data)
{
	TWDR= data;
	TWCR = (1<<TWINT)|(1<<TWEN);
	while (READ_BIT(TWCR,TWINT)==0);
	if ((TWSR&0xF8)!=0x28)		//Data byte has been transmitted + ACK has been received
	{
		DATA_Transmit_ERROR();
	}
}





//Master Receiver Mode
void I2C_Transmit_Slave_AddressR(unsigned char AddressR)
{
	TWDR = AddressR;
	TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWEA);
	while (READ_BIT(TWCR,TWINT)==0);
	if ((TWSR&0xF8)!=0x40)		 //SLA+R has been transmitted + ACK has been received
	{
		WRITE_ADDRESS_ERROR();
	}
}

unsigned char I2C_Master_Receive_Data(void)
{
	TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWEA);
	while (READ_BIT(TWCR,TWINT)==0);
	if ((TWSR&0xF8)!=0x50)		// Data byte has been received + ACK has been returned
	{
		DATA_RECEIVE_ERROR();
	}
	else
	{
		return TWDR;
	}
}



//Slave Receiver Mode
void I2C_Slave_Receive_owm_AddressW(void)
{
	TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWEA);
	while (READ_BIT(TWCR,TWINT)==0);
	while ((TWSR&0xF8)!=0x60);		//wait till Own SLA+W has been received + ACK has been returned
}

unsigned char I2C_Slave_Receive_Data(void)
{
	TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWEA);
	while (READ_BIT(TWCR,TWINT)==0);
	if ((TWSR&0xF8)!=0x80)		// Previously addressed with own SLA+W + data has been received + ACK has been returned
	{
		DATA_RECEIVE_ERROR();
	}
	else
	{
		return TWDR;
	}	
}



//Slave Transmitter Mode
void I2C_Slave_Receive_owm_AddressR(void)
{
	TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWEA);
	while (READ_BIT(TWCR,TWINT)==0);
	while ((TWSR&0xF8)!=0xA8);		//wait till Own SLA+R has been received + ACK has been returned
}

void I2C_Slave_Transmit_Data(unsigned char data)
{
	TWDR = data;
	TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWEA);
	while (READ_BIT(TWCR,TWINT)==0);
	if ((TWSR&0xF8)!=0xB8)		//  Data byte in TWDR has been transmitted; ACK has been received
	{
		DATA_Transmit_ERROR();
	}
}


//ERROR Functions

void START_ERROR()
{
	//to be determined like LCD message
}


void WRITE_ADDRESS_ERROR()
{
	//to be determined like LCD message
}

void DATA_Transmit_ERROR()
{
	//to be determined like LCD message
}
void DATA_RECEIVE_ERROR()
{
	//to be determined like LCD message
}