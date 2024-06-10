/*************************************************************/
/*      Author  : George Emad                                */
/*      Date    : 27-12-2022                                  */
/*      Version : 0.1                                        */
/*      File    : TIMER0_interface.h                               */
/*************************************************************/


#ifndef __TIMER0_INTERFACE_H__
#define __TIMER0_INTERFACE_H__

#include "../../Services/STD_TYPES.h"
#define F_CPU 1000000UL

void TIMER0_init();
void TIMER0_setMode(u8 mode);
void TIMER0_setTE(u8 timerEvent);
void TIMER0_setPrescaler(u8 prescaler);
void TIMER0_OV_enable();
void TIMER0_OV_disable();

void TIMER0_CTC_enable();
void TIMER0_CTC_disable();

void TIMER0_SetTimerCounter(u8 preload);
void TIMER0_SetCompare(u8 compare);

void TIMER0_SetOV_CallBack( void (*fun_ptr) (void));
void TIMER0_SetCTC_CallBack( void (*fun_ptr) (void));


#endif