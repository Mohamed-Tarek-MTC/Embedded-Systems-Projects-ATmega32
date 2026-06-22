/*
 * ADC.h
 *
 * Created: 5/11/2026 3:41:24 PM
 *  Author: Cascoo
 */ 


#ifndef ADC_H_
#define ADC_H_

void ADC_init();
unsigned short ADC_READ();
void ADC_SELECT_channel(char channel_pin);




#endif /* ADC_H_ */