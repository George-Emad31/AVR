/*****************************************/
/*	Author : George Emad				 */
/*	Date   : 23-12-2022   		   		 */
/*	Version: 0.1				         */
/*	File   :ADC_prog.c                   */
/*****************************************/
#define  F_CPU 1000000UL
#include <util/delay.h>
#include "ADC_private.h"


void ADC_init()
{
	DDRA   = 0b11111110;			/* Make ADC0  as input                                  */
	ADMUX  = 0b01000000;	        /* Vref: Avcc,ADLR: right adjast result, ADC channel: 0 */
	ADCSRA = 0b10000111;			/* Enable ADC, fr/128                                   */
}
unsigned short int ADC_read(unsigned char channel)
{
	unsigned short int ADC_value,ADC_Low;
	
	ADMUX     = ADMUX|(channel & 0b00001111);	/* Set input channel to read                   */
	ADCSRA   |= (1<<6);		                    /* Start conversion                            */
	while((ADCSRA&(1<<4))==0);	                /* Monitor end of conversion interrupt         */
	_delay_us(10);
	ADC_Low   = (int)ADCL;		                /* Read lower byte                             */
	ADC_value = (int)ADCH*256;		            /* Read higher 2 bits and Multiply with weight */
	ADC_value = ADC_value + ADC_Low;				
	return(ADC_value);			                /* Return digital value                        */
}