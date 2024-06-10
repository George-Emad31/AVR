/*************************************************************/
/*      Author  : George Emad                                */
/*      Date    : 27-12-2022                                 */
/*      Version : 0.1                                        */
/*      File    : TIMER0_program.h                           */
/*************************************************************/


#include "../../Services/STD_TYPES.h"
#include "../../Services/BIT_MATH.h"
#include "TIMER0_private.h"
#include "TIMER0_config.h"
#include "TIMER0_int.h"

void (*TIMER_0_OV_CallBack) (void) ;
void (*TIMER_0_CTC_CallBack) (void) ;

void TIMER0_init(void){
    // Select Opreation Mode 
        TIMER0_setMode(TIMER0_OP_MODE);
    // Select Prescaler 
        TIMER0_setPrescaler(TIMER0_PRESCALER);
    // Timer Events (No Action, Toggle, Clear, Set)
        TIMER0_setTE(TIMER0_TE);
    // Interrupts 
        CLEAR_BIT(TIMSK, OCIE0);
        CLEAR_BIT(TIMSK, TOIE0);
    // Clearing Flags
        CLEAR_BIT(TIFR, OCF0); 
        CLEAR_BIT(TIFR, TOV0); 
    // Clear Registers 
        TCNT0 = 0; 
        OCR0 = 0;
}


void TIMER0_setMode(u8 mode){
   
    switch (mode){
    case TIMER0_NORMAL:
        CLEAR_BIT(TCCR0 , WGM00);
        CLEAR_BIT(TCCR0 , WGM01);
        break;
    case TIMER0_PHASE_PWM:
        SET_BIT  (TCCR0 , WGM00);
        CLEAR_BIT(TCCR0 , WGM01);
        break;
    case TIMER0_CTC:
        CLEAR_BIT(TCCR0 , WGM00);
        SET_BIT  (TCCR0 , WGM01);
        break;
    case TIMER0_FAST_PWM:
        SET_BIT  (TCCR0 , WGM00);
        SET_BIT  (TCCR0 , WGM01);
        break;
    default: break;
    }     
}

void TIMER0_setTE(u8 timerEvent){
   
    switch (timerEvent){
    case TIMER0_TE_NOEVENT:
        CLEAR_BIT(TCCR0 , COM00);
        CLEAR_BIT(TCCR0 , COM01);
        break;
    case TIMER0_TE_TOGGLE:
        SET_BIT  (TCCR0 , COM00);
        CLEAR_BIT(TCCR0 , COM01);
        break;
    case TIMER0_TE_CLEAR:
        CLEAR_BIT(TCCR0 , COM00);
        SET_BIT  (TCCR0 , COM01);
        break;
    case TIMER0_TE_SET:
        SET_BIT  (TCCR0 , COM00);
        SET_BIT  (TCCR0 , COM01);
        break;
    default: break;
    }     
}

void TIMER0_setPrescaler(u8 prescaler){
    TCCR0 &= 0b11111000;    // Clear Required Bits 
    TCCR0 |= prescaler;     // Set the new value 
       
}

void TIMER0_OV_enable(){ 
    SET_BIT(TIMSK,TOIE0);

}
void TIMER0_OV_disable(){
    CLEAR_BIT(TIMSK,TOIE0);
}

void TIMER0_CTC_enable(){
    SET_BIT(TIMSK,OCIE0);
}
void TIMER0_CTC_disable(){
     CLEAR_BIT(TIMSK,OCIE0);
}

void TIMER0_SetTimerCounter(u8 preload){
    TCNT0 = preload;
}


void TIMER0_SetCompare(u8 compare){
    OCR0 = compare;
}

void TIMER0_SetOV_CallBack(void (*fun_ptr) (void)){
    TIMER_0_OV_CallBack = fun_ptr;
}

void TIMER0_SetCTC_CallBack(void (*fun_ptr) (void)){
   
    TIMER_0_CTC_CallBack = fun_ptr;
}


void __vector_11(void) __attribute__((signal , used));
void __vector_11(void)
{
	TIMER_0_OV_CallBack();
}

void __vector_10(void) __attribute__((signal , used));
void __vector_10(void)
{
	TIMER_0_CTC_CallBack();
}




