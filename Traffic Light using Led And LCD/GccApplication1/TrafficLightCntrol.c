/*
 * GccApplication1.c
 *
 * Created: 4/7/2024 7:37:14 PM
 * Author : george
 *  Version:1
 */
#define F_CPU 8000000UL
#include <util/delay.h>
#include "Timer.h"
#include "DIO.h"
#include "LCD.h"
#include "avr/interrupt.h"
#include "LED.h"
#include "App_config.h"
#include "seven segment.h"
 u16 Red=12; 
 u16  Yellow=8;  
 u16 Green=13;  
volatile u8 counter1=0;
volatile u8 flag1=0,flag2=0; 

int main(void)
{  clk_1024();
   timer_CTC_init_interrupt(78);
   LCD_vInit();
   LED_vInit('D',2);//red
   LED_vInit('D',1);//yellow
   LED_vInit('D',0);//green
 
   while(1)
{  
 u16 Green=13;
 u16 Yellow=8;
 u16 Red=12;
 LCD_clearscreen();
 LCD_vSend_string("Remaining 13 sec");
	  LED_vTurnOn('D',0);//green   
while(Green>0)
{
  if (counter1>=100)// pass 1s)
  {
	  counter1=0;
	  Green--;
	  LCD_movecursor(1,11);
	  LCD_vSend_char((Green/10)+ASCII);
	  LCD_vSend_char((Green%10)+ASCII);
	    LCD_movecursor(2,1);
	    LCD_vSend_string("Go...........");
  }
}	   	
_delay_ms(500); 
  LED_vTurnOff('D',0);
  LED_vTurnOn('D',1);
  LCD_clearscreen();
  LCD_vSend_string("Remaining 08 sec");
  while(Yellow>0)
  {
	  if (counter1>=100)
	  {   
		  counter1=0;  
		  Yellow--;
		  LCD_movecursor(1,11);
		  LCD_vSend_char((Yellow/10)+ASCII);
		  LCD_vSend_char((Yellow%10)+ASCII);
	  }
  }
  do{
  if(flag1>=50)
  {
	  flag2=1;
	  counter1=0;
  }
  }while(flag2==0 );
 // _delay_ms(500);
   LED_vTurnOff('D',1);
   LED_vTurnOn('D',2);  
   LCD_clearscreen();
   LCD_vSend_string("Remaining 12 sec");
   while(Red>0)
   {
	   if (counter1>=100)
	   {
		   counter1=0;
		   Red--;
		   LCD_movecursor(1,11);
		   LCD_vSend_char((Red/10)+ASCII);
		   LCD_vSend_char((Red%10)+ASCII);
		   LCD_movecursor(2,1);
		   LCD_vSend_string("Stop !!!!!!!!"); 
	   }
   }
  do{
	  if(flag1>=50)
	  {
		  flag2=1;
	  }
	   counter1=0;
  }while(flag2==0 );
   //_delay_ms(500);
   LED_vTurnOff('D',2);
  
   } 
}

ISR(TIMER0_COMP_vect)
{
counter1++;	
flag1++;
}