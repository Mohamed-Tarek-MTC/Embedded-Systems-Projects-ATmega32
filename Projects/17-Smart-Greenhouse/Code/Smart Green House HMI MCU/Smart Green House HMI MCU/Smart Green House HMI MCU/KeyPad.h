/*
 * KeyPad.h
 *
 * Created: 4/23/2026 1:30:25 AM
 *  Author: Cascoo
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_


//#define keypad_4x4
#define keypad_4x3


#define KeyPad_port 'A'
#define NotPressed 0xFF

void keypad_init();
unsigned char keypad_read();


#endif /* KEYPAD_H_ */