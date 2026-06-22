/*
 * LED.h
 *
 * Created: 4/18/2026 8:17:48 PM
 *  Author: Cascoo
 */ 


#ifndef LED_H_
#define LED_H_

void LED_init(char port, char pin);
void LED_on(char port, char pin);
void LED_off(char port, char pin);
void LED_tog(char port, char pin);
char LED_state(char port, char pin);

#endif /* LED_H_ */