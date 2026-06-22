/*
 * EEPROM.c
 *
 * Created: 4/20/2026 12:50:55 AM
 *  Author: Cascoo
 */ 


#include <avr/io.h>
#include "EEPROM.h"
#include "Standard_Macros.h"

void EEPROM_write(char data, const unsigned short address)
{
	EEARL= address;
	EEARH= address>>8;
	
	EEDR= data;
	
	SET_BIT(EECR,EEMWE);
	SET_BIT(EECR,EEWE);
	
	while(READ_BIT(EECR,EEWE));
}


char EEPROM_read(const unsigned short address)
{
	EEARL= address;
	EEARH= address>>8;
	
	SET_BIT(EECR,EERE);
	
	return EEDR;
}
