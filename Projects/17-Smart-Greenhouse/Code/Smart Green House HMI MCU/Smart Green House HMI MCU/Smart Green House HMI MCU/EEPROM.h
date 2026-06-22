/*
 * IncFile1.h
 *
 * Created: 4/20/2026 12:55:22 AM
 *  Author: Cascoo
 */ 


#ifndef INCFILE1_H_
#define INCFILE1_H_

void EEPROM_write(char data, const unsigned short address);
char EEPROM_read(const unsigned short address);


#endif /* INCFILE1_H_ */