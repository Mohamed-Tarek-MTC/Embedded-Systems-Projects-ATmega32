/*
 * Timers.h
 *
 * Created: 5/12/2026 10:38:02 PM
 *  Author: Cascoo
 */ 


#ifndef TIMERS_H_
#define TIMERS_H_

void TIMER0_init(void);
void TIMER0_CTC_init_10ms(void);
void TIMER2_OVF_init_1s(void);
void TIMER0_PWM_init(float duity_cycle);
void TIMER0_phase_correct_PWM_init(float duity_cycle);

#endif /* TIMERS_H_ */