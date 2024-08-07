/*
 * GccApplication1.c
 *
 * Created: 4/7/2024 7:37:14 PM
 * Author : george
 */
#define F_CPU 16000000UL
#include "DIO.h"
#include "led.h"
#include "Timer.h"
#include "LCD.h"
#include <avr/interrupt.h>
//void SW_PWM(void);

int main(void)
{  
	clk_64();
	timer_CTC_init_interrupt(250);
	// isr every 1msec
	// control intinsety of 3 led using SW_PWM 
	// 25% 50% 75%
	LED_vInit('D',3);
	LED_vInit('C',2);
	LED_vInit('C',7);
   sei();	
 
   while(1)
   {	
    	static u8 counter=0;
    	counter++;
    	switch(counter)
    	{
	    	case  5:LED_vTurnOff('D',3);break;
	    	case 10:LED_vTurnOff('C',2);break;
	    	case 15:LED_vTurnOff('C',7);break;
	    	case 20:
	    	LED_vTurnOn('D',3);
	    	LED_vTurnOn('C',2);
	    	LED_vTurnOn('C',7);
	    	counter=0;
	    	break;
	   
   }
}



}




