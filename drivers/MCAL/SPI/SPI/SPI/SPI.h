/*
 * SPI.h
 *
 * Created: 5/17/2026 5:34:48 PM
 *  Author: Cascoo
 */ 


#ifndef SPI_H_
#define SPI_H_

void SPI_Master_init();
void SPI_Slave_init();	
unsigned char SPI_Master_Data_Transmit(unsigned char Data);
unsigned char SPI_Slave_Data_Receive(unsigned char data);
void SPI_Master_String_Transmit(unsigned char *string_ptr);

#endif /* SPI_H_ */