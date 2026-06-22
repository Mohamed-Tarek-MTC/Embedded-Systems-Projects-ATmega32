/*
 * USART.h
 *
 * Created: 5/17/2026 4:19:26 PM
 *  Author: Cascoo
 */ 


#ifndef USART_H_
#define USART_H_


void UART_normal_init(unsigned short Baud_Rate);
void UART_Data_Tarnsmit(unsigned char data);
unsigned char UART_Data_Recieve(void);
void UART_Send_String(char *String_Ptr);

#endif /* USART_H_ */