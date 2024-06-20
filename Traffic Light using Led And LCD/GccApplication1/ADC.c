/*
 * ADC.c
 *
 * Created: 4/30/2024 11:42:44 AM
 *  Author: George
 */ 
#include "ADC.h"

void ADC_init(){
// by default REFS0 ,REFS1  SO WE NEED TO MAKE AVCC = VCC By setting REFS0 by 1
SET_BIT(ADMUX,REFS0);
SET_BIT(ADMUX,REFS1);  // vreff = 2.56
//SET_BIT(ADMUX,MUX0);
// Enable the ADC is ADC Statues and Control Register bit no 7
SET_BIT(ADCSRA,ADEN);
// Select Right Adjustment
//CLR_BIT(ADMUX,ADLAR);
// Single Conversation Mode
//CLR_BIT(ADCSRA,ADATE);
// Prescaler 128 For 16MHZ (125 KHZ== (16*10^3(TO KHZ)/128=125) FOR AMIT KIT MAKE ADPS0 ALSO =0
// Prescaler 64 For 8MHZ (125 KHZ)
SET_BIT(ADCSRA,ADPS2);
SET_BIT(ADCSRA,ADPS1);
CLR_BIT(ADCSRA,ADPS0);
}
unsigned short ADC_u16Read(u16 channelNum)
{    
	if((channelNum<32)&&(channelNum >=0))
	{
	//Clear ADMUX Channel Bits
    ADMUX &= 0b11100000;
	// Select Channel Number
	ADMUX |= channelNum;
	
	
	unsigned short read_val;
	// start of Conversion in ADC Statues and Control Register bit no 6 
	SET_BIT(ADCSRA,ADSC);
	// loop while the flag is 0 
	while(READ_BIT(ADCSRA,ADIF)==0); //stay in your position till ADIF become 1
	//while(READ_BIT(ADCSRA,ADSC)==1); WHEN EVER CONVERSION IN PROCESS  stay in your position -
	//**MUST REMOVESET_BIT(ADCSRA,ADIF); 
	SET_BIT(ADCSRA,ADIF); // clear ADIF
	read_val=(ADCL);
	read_val|=(ADCH<<8);
	return read_val ;
    } 
}


void ADC_interrupt_EN()
{
	SET_BIT(ADCSRA,ADIE);
}

void ADC_Start_Conversion()
{
	SET_BIT(ADCSRA,ADSC);
}
