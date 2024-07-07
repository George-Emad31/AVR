/*
 * Timer_config.h
 *
 * Created: 5/12/2024 9:09:46 PM
 *  Author: George
 */ 


#ifndef TIMER_CONFIG_H_
#define TIMER_CONFIG_H_
#include "DIO.h"
typedef enum
{
	Disconnected = 0,
	Inverting = 1,
	Non_Inverting = 2
}PWM_MODE;

// Table 42
typedef enum
{
	PWM_No_Prescaling = 0,
	PWM_8 = 1,
	PWM_64 = 2,
	PWM_256 = 3,
	PWM_1024 = 4
}PWM_PRESCALER;



#endif /* TIMER_CONFIG_H_ */