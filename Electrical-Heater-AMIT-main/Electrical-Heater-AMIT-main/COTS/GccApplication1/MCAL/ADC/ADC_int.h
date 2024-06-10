/*****************************************/
/*	Author : George Emad				 */
/*	Date   : 26-12-2022   		   		 */
/*	Version: 0.1				         */
/*	File   :ADC_int.h	                 */
/*****************************************/


#ifndef _ADC_INT_H_
#define _ADC_INT_H_

void ADC_init(void);
unsigned short int ADC_read(unsigned char channel);

#endif