/*
 * GccApplication1.c
 *
 * Created: 4/7/2024 7:37:14 PM
 * Author : george
 */
#define F_CPU 8000000UL
#include <avr/interrupt.h>
#include "Timer.h"
#include "DIO.h"
#include "Keypad_driver.h"
#include "LCD.h"

u8 x;
volatile int flag_1=0,flag_2=0;
volatile int flag=0,flag_3=0;

int main(void)
{     
   clk_1024();
   LCD_vInit();
   timer_CTC_init_interrupt(78);
   keypad_vInit();
   LCD_movecursor(1,4);
   LCD_vSend_string("WELCOME TO");
   LCD_movecursor(2,4);
LCD_vSend_string("THE GAME");
do
{
	if(flag>=250) // 10000*10->80 means each 10 ms it goes to ISR
	{
      LCD_clearscreen();
	  flag_3=1;
	}
}
while (flag_3==0);
   LCD_vSend_string("3+?=8");
do  
{  
	if(flag_1>=1000) // 10000*10->80 means each 10 ms it goes to ISR 
	{
	flag_2=1; // if passed 10 second flag is up
	}
	x=keypad_u8check_press();
}
 while (x==NOTPRESSED && flag_2==0); // while NOTPRESSED and not reach to 10 second
 
	 if (x=='5')
	 {
	  LCD_clearscreen();
	  LCD_movecursor(2,4);
	  LCD_vSend_string("Well Done");
	 } 
	 else if (x==NOTPRESSED)
	 {
		   LCD_clearscreen();
		   LCD_movecursor(2,4);
		   LCD_vSend_string("Time over");
		
	 }
 	 else 
	  {
		 LCD_clearscreen();
		 LCD_movecursor(1,4);
		 LCD_vSend_string("WRONG ANSWER");
		 LCD_movecursor(2,4);
		 LCD_vSend_string("GAME OVER");
	  }
}
  
ISR(TIMER0_COMP_vect)
{   
	flag++;
	flag_1++;
}

