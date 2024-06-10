/*
 * ATMEGA32_REG.h
 *
 *  Created on: Jan 6, 2023
 *      Author: GEORGE EMAD
 */

#ifndef ATMEGA32_REG_H_
#define ATMEGA32_REG_H_

#define unsigned char       u8
								 /* DIO REGISTERS*/
								 
/* DATA DIRCTION REGISTERS */
#define DDRA           (*(volatile u8*)0x3A)
#define DDRB           (*(volatile u8*)0x37)
#define DDRC           (*(volatile u8*)0x34)
#define DDRD           (*(volatile u8*)0x31)

/* OUTPUT REGISTERS */
#define PORTA          (*(volatile u8*)0x3B)
#define PORTB          (*(volatile u8*)0x38)
#define PORTC          (*(volatile u8*)0x35)
#define PORTD          (*(volatile u8*)0x32)

/* INPUT REGISTERS */
#define PINA           (*(volatile u8*)0x39)
#define PINB           (*(volatile u8*)0x36)
#define PINC           (*(volatile u8*)0x33)
#define PIND           (*(volatile u8*)0x30)


                          /* EXTERNAL INTERRUPT REGISTERS */
						  
// MCU Control Register
#define MCUCR           (*(volatile u8*)0x55)

// MCU Control and Status Register
#define MCUCSR          (*(volatile u8*)0x54)

// General Interrupt Control Register
#define GICR            (*(volatile u8*)0x5B)

// General Interrupt Flag Register
#define GIFR            (*(volatile u8*)0x5A)

                          /* GLOBAL INTERRUPT REGISTERS */ 
// Status Register
#define SREG            (*(volatile u8*)0x5F)


                                 /* ADC REGISTERS*/
								 
// ADC Multiplexer Selection Register
#define ADMUX            (*(volatile u8*)0x27)

// ADC Control and Status Register A
#define ADCSRA           (*(volatile u8*)0x26)

// The ADC Data Register
#define ADC_u16          (*(volatile u16*)0x24)

// Special FunctionIO Register
#define SFIOR            (*(volatile u8*)0x50)


                                 /* TIMER0 REGISTERS*/
								 
// Timer/Counter Control Register
#define TCCR0            (*(volatile u8*)0x53)

// Timer/Counter Register
#define TCNT0            (*(volatile u8*)0x52)

// Output Compare Register
#define OCR0             (*(volatile u8*)0x5C)

// Timer/Counter Interrupt Mask Register
#define TIMSK            (*(volatile u8*)0x59)

// Timer/Counter Interrupt Flag Register
#define TIFR             (*(volatile u8*)0x58)
                                 /* EEPROM REGISTERS*/

// EEPROME

#endif /* ATMEGA32_REG_H_ */
