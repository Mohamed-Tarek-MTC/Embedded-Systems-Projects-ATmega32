/*
 * Ultra_Sonic.h
 *
 * Created: 5/15/2026 2:24:29 AM
 *  Author: Cascoo
 */ 



#ifndef ULTRA SONIC_H_
#define ULTRA SONIC_H_

#define US_port 'D'
#define US_TRIG_pin 7		//must send logic 1 to the ultra sonic trig pin for at least 10uS to make ultra sonic send its Tx signal
#define sound_speed 34600	//sound speed in protues in cm/s

void Ultra_Sonic_init();
unsigned int Ultra_Sonic_read(void);



#endif /* ULTRA SONIC_H_ */