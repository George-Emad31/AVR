/*
 * ADC.h
 *
 * Created: 4/30/2024 11:42:58 AM
 *  Author: George
 */ 


#ifndef ADC_H_
#define ADC_H_
#include "DIO.h"


void ADC_init();
void ADC_interrupt_EN();
void ADC_Start_Conversion();
unsigned short ADC_u16Read(u8 channelNum);



#endif /* ADC_H_ */