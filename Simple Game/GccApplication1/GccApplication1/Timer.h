/*
 * Timer.h
 *
 * Created: 5/12/2024 9:09:29 PM
 *  Author: George
 */ 


#ifndef TIMER_H_
#define TIMER_H
#include "Timer_config.h"
#include <avr/interrupt.h>

//clock
int TIMER_STOP();
int clk_0 ();
int clk_8 ();
int clk_64 ();
int clk_256 ();
int clk_1024 ();
int T0_FALLING ();
int T0_RISING ();
// Mode
void timer_CTC_init_interrupt(u16 Load_Value);
void timer_wave_phasecorrectPWM(u16 Load_Value);
void timer_wave_fastPWM(u16 Load_Value);
void timer_wave_nonPWM(u16 Load_Value);

#endif /* TIMER_H_ */