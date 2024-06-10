/*****************************************/
/*	Author : George Emad				 */
/*	Date   : 25-12-2022   		   		 */
/*	Version: 0.1				         */
/*	File   :ADC_private.h	             */
/*****************************************/


#ifndef _ADC_PRIVATE_H_
#define _ADC_PRIVATE_H_

#define ADMUX   *((volatile unsigned char*)0x27)
#define ADCSRA  *((volatile unsigned char*)0x26)
#define ADCH    *((volatile unsigned char*)0x25)
#define ADCL    *((volatile unsigned char*)0x24)
#define SFIOR   *((volatile unsigned char*)0x50)
#define PORTA   *((volatile unsigned char*)0x3B)
#define DDRA    *((volatile unsigned char*)0x3A)
#define PINA    *((volatile unsigned char*)0x39)

#endif