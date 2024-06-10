/*************************************************************/
/*      Author  : George Emad                                */
/*      Date    : 27-12-2022                                  */
/*      Version : 0.1                                        */
/*      File    : TIMER0_private.h                           */
/*************************************************************/


#ifndef __TIMER0_PRIVATE_H__
#define __TIMER0_PRIVATE_H__

// REGISTERS 
    // Common Regristers 
    #define SFIOR  *((volatile u8*)0x50)
    #define TIMSK  *((volatile u8*)0x59)
    #define TIFR   *((volatile u8*)0x58)
    
    // Timer 0
    #define OCR0   *((volatile u8*)0x5C)
    #define TCCR0  *((volatile u8*)0x53)
    #define TCNT0  *((volatile u8*)0x52)


// BITS 
    // Common Registers 
        // SFIOR

        //TIMSK
            #define OCIE2   7
            #define TOIE2   6
            #define TICIE1  5
            #define OCIE1A  4
            #define OCIE1B  3
            #define TOIE1   2
            #define OCIE0   1   // Timer 0: Timer Output Compare Interrupt Enable 
            #define TOIE0   0   // Timer 0: Timer overflow Interrupt Enable
        //TIFR
            #define OCF2    7
            #define TOV2    6
            #define ICF1    5
            #define OCF1A   4
            #define OCF1B   3
            #define TOV1    2
            #define OCF0    1   // Timer 0: Out Compare Flag  
            #define TOV0    0   // Timer 0: Timer overflow Flag 

    // Timer 0 
        // TCCR0
            #define FOC0    7   // Forced Compare Match 
            #define WGM00   6   // Waveform Generation Mode 
            #define COM01   5   // Compare Out Mode 
            #define COM00   4
            #define WGM01   3
            #define CS02    2   // CLock Select
            #define CS01    1
            #define CS00    0

// OPtions 
    // Timer Mode (Waver Form Generation Mode)
        #define TIMER0_NORMAL 		0
        #define TIMER0_PHASE_PWM 	1
        #define TIMER0_CTC 			2
        #define TIMER0_FAST_PWM     3

    // Prescaler
        #define TIMER_0_PRESCALER_0           0
        #define TIMER_0_PRESCALER_1			  1
        #define TIMER_0_PRESCALER_8			  2
        #define TIMER_0_PRESCALER_64		  3
        #define TIMER_0_PRESCALER_256	      4
        #define TIMER_0_PRESCALER_1024	      5
        #define TIMER_0_PRESCALER_ECS_FALL	  6
        #define TIMER_0_PRESCALER_ECS_RISE	  7

    // Timer Events (No Action, Toggle, Clear, Set)
        #define TIMER0_TE_NOEVENT 		0
        #define TIMER0_TE_TOGGLE	    1
        #define TIMER0_TE_CLEAR		    2
        #define TIMER0_TE_SET	        3

#endif