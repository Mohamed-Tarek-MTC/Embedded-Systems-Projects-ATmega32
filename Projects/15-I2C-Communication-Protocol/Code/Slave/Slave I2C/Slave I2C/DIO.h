/*
 * IncFile1.h
 *
 * Created: 4/12/2026 3:44:04 AM
 *  Author: Cascoo
 */ 


#ifndef DIO_H_
#define DIO_H_

void set_pin_direction(char port,char pin,char direction);
void DIO_write_pin(char port, char pin, char write_value);
char DIO_read_pin(char port, char pin);
void set_port_direction(char port, char direction);
char DIO_read_port(char port);
void DIO_write_port(char port, char value);
void DIO_togl_port(char port);
void DIO_write_high_nibble(char port, char data);
void DIO_write_low_nibble(char port, char data);


#endif /* INCFILE1_H_ */