
#include <avr/io.h>
#include "LCD.h"
#include "timer.h"
#define F_CPU 8000000UL
#include <util/delay.h>
#include "LED.h"
#include <avr/interrupt.h>
volatile unsigned char counter1=0;
volatile unsigned char counter_green=10;
volatile unsigned char counter_yellow=5;
volatile unsigned char counter_red=7;
int main(void)
{
	LED_vInit('D',0);
	LED_vInit('D',1);
	LED_vInit('D',2);
	LCD_vInit();
	timer_CTC_init_interrupt();
	
    while(1)
    {
		counter_green=10;
		counter_yellow=5;
		counter_red=7;
		LCD_clearscreen();
		LCD_vSend_string("remaining 10 sec");
		LED_vTurnOn('D',0);
		while(counter_green>0)
		{
			if(counter1>=100)
			{
				counter1=0;
				counter_green--;
				LCD_movecursor(1,11);
				LCD_vSend_char(' ');
				LCD_vSend_char((counter_green%10)+48);
			}
		}
		_delay_ms(500);
		LED_vTurnOn('D',1);
		LED_vTurnOff('D',0);
		LCD_clearscreen();
		LCD_vSend_string("remaining  5 sec");
		while(counter_yellow>0)
		{
			if(counter1>=100)
			{
				counter1=0;
				counter_yellow--;
				LCD_movecursor(1,11);
				LCD_vSend_char(' ');
				LCD_vSend_char((counter_yellow%10)+48);
			}
		}
		_delay_ms(500);
		LED_vTurnOn('D',2);
		LED_vTurnOff('D',1);
		LCD_clearscreen();
		LCD_vSend_string("remaining  7 sec");
		while(counter_red>0)
		{
			if(counter1>=100)
			{
				counter1=0;
				counter_red--;
				LCD_movecursor(1,11);
				LCD_vSend_char(' ');
				LCD_vSend_char((counter_red%10)+48);
			}
		}
		_delay_ms(500);
		LED_vTurnOff('D',2);
	}
         
 }


ISR(TIMER0_COMP_vect)
{
	counter1++;
}