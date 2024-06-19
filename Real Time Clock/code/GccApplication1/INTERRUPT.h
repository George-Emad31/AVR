/*
 * INTERRUPT.h
 *
 * Created: 4/17/2024 7:17:09 PM
 *  Author: georg
 */ 


#ifndef INTERRUPT_H_
#define INTERRUPT_H_
#include <avr/interrupt.h>
#include "DIO.h"
/************************************************************************/
/*                      INTERRUPT REGISTERS  MACROS                     */
/************************************************************************/


 
 // MCU Control Register for  INT0  and INT1
 //#define MCUCR           (*(volatile u8*)0x55)

 // MCU Control and Status Register   INT2
 //#define MCUCSR          (*(volatile u8*)0x54)

 // General Interrupt Control Register
 //#define GICR            (*(volatile u8*)0x5B)

 // General Interrupt Flag Register
// #define GIFR            (*(volatile u8*)0x5A)

 /* GLOBAL INTERRUPT REGISTERS */
 // Status Register
 //#define SREG            (*(volatile u8*)0x5F)


/************************************************************************/
/*      How to set the I-bit? SREG = SREG | (1<<7); or    sei();
        How to clear the I-bit? SREG = SREG & (~(1<<7)) ; or cli();     */
/************************************************************************/

//void sei(void);
//void cli(void);






#endif /* INTERRUPT_H_ */