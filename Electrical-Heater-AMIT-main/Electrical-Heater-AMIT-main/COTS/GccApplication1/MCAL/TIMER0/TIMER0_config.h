/*************************************************************/
/*      Author  : George Emad                                */
/*      Date    : 28-12-2022                                  */
/*      Version : 0.1                                        */
/*      File    : TIMER0_config.h                           */
/*************************************************************/


#ifndef __TIMER0_CONFIG_H__
#define __TIMER0_CONFIG_H__

// Options 

    // Select Timer Mode 
        /*Range
        TIMER0_NORMAL
        TIMER0_PHASE_PWM
        TIMER0_CTC
        TIMER0_FAST_PWM	
        */
       #define TIMER0_OP_MODE   TIMER0_NORMAL

    // Select Prescaler
        /*Range
        TIMER_0_PRESCALER_0       
        TIMER_0_PRESCALER_1			  
        TIMER_0_PRESCALER_8
        TIMER_0_PRESCALER_64 
        TIMER_0_PRESCALER_256	    
        TIMER_0_PRESCALER_1024	   
        TIMER_0_PRESCALER_ECS_FALL
        TIMER_0_PRESCALER_ECS_RISE
        */
       #define TIMER0_PRESCALER   TIMER_0_PRESCALER_1024

    // Timer Events (No Action, Toggle, Clear, Set)
        /*Range
        TIMER0_TE_NOEVENT
        TIMER0_TE_TOGGLE	
        TIMER0_TE_CLEAR		
        TIMER0_TE_SET	   
        */
       #define TIMER0_TE   TIMER0_TE_NOEVENT
    
#endif