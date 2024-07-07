/*
 * Timer.h
 *
 * Created: 5/12/2024 9:09:29 PM
 *  Author: George
 */ 


#ifndef TIMER_H_
#define TIMER_H

#include <avr/interrupt.h>
#include "Timer_config.h"
#define BITS  256
//clock
int TIMER_STOP();
int clk_0 ();
int clk_8 ();
int clk_64 ();
int clk_256 ();
int clk_1024 ();
int T0_FALLING ();
int T0_RISING ();
// Mode timer 0
void timer_CTC_init_interrupt(u16 Load_Value);
void timer_wave_phasecorrectPWM(u16 Load_Value);
void timer_wave_fastPWM(u16 Load_Value);
void timer_wave_nonPWM(u16 Load_Value);

// timer 2
// PWM

void PWM_Init(void);
void PWM_Start(PWM_PRESCALER prescaler);
void PWM_Stop(void);
void PWM_SetDuty(PWM_MODE mode, u8 dutyCycle);

// Timer 0
//// PWM 

#endif /* TIMER_H_ */