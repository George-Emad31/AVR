/*
 * GccApplication1.c
 *
 * Created: 4/7/2024 7:37:14 PM
 * Author : georg
 */
#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>
#include "Keypad_driver.h"
#include "LCD.h"
int main(void)
{
   LCD_vInit();
   keypad_vInit();
   char x;
   while(1)
   {
	   x=keypad_u8check_press();
	   if (x!=NOTPRESSED)
	   {
		   LCD_vSend_char(x);
	   }
	   else
	   {
		   
	   }
	   _delay_ms(250);
   }
}



