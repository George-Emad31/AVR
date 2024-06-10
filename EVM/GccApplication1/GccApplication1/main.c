/*
 * GccApplication1.c
 *
 * Created: 4/7/2024 7:37:14 PM
 * Author : george
 */
#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>
#include "App_config.h"
#include "button.h"
#include "LCD.h"

void App_vinit();

 u8 counter_0=0;
 u8 counter_1=0;
 u8 counter_2=0;
 u8 counter_3=0;
 u8 counter_4=0;
 
int main(void)
{
    App_vinit();
   LCD_vSend_string("A=00");
   LCD_movecursor(1,12);
   LCD_vSend_string("B=00");
   LCD_movecursor(2,1);
   LCD_vSend_string("C=00");
   LCD_movecursor(2,12);
   LCD_vSend_string("D=00");
  
   while(1)
   {
	//LCD_vSend_char(counter_0 + ASCII);
	//LCD_movecursor(1,3);
	//LCD_vSend_char(counter_1 + ASCII);
	//LCD_movecursor(1,14);
	//LCD_vSend_char(counter_2 + ASCII);
	//LCD_movecursor(2,3);
	//LCD_vSend_char(counter_3 + ASCII);
	//LCD_movecursor(2,14);
		
	   if (button_u8read(Button0_Port,button_0)==VOTE)
	   {
		   counter_0++;
		   LCD_movecursor(1,3);
		   LCD_vSend_char(counter_0/10 + ASCII);
		   LCD_vSend_char(counter_0%10 + ASCII);
		while(button_u8read(Button0_Port,button_0)==VOTE);

	   } 
///////////////////////////////////////////////////////////////	   
	   else if (button_u8read(Button1_Port,button_1)==VOTE)
	   {
		 counter_1++;
		 LCD_movecursor(1,14);
		 LCD_vSend_char(counter_1/10 + ASCII);
	     LCD_vSend_char(counter_1%10 + ASCII);
		 while(button_u8read(Button1_Port,button_1)==VOTE);
	   }
////////////////////////////////////////////////////////////	   
	   else if (button_u8read(Button2_Port,button_2)==VOTE)
	   {
		   counter_2++;
		   LCD_movecursor(2,3);
		   LCD_vSend_char(counter_2/10 + ASCII);
		  LCD_vSend_char(counter_2%10 + ASCII);
		while(button_u8read(Button2_Port,button_2)==VOTE);
	   }
////////////////////////////////////////////////////////////	   
	   else if (button_u8read(Button3_Port,button_3)==VOTE)
	   {
		   counter_3++;	
     	   LCD_movecursor(2,14);
		  LCD_vSend_char(counter_3/10 + ASCII);
          LCD_vSend_char(counter_3%10 + ASCII);
		  while(button_u8read(Button3_Port,button_3)==VOTE);
	   }
/////////////////////////////////////////////////////////////	   
	   else if (button_u8read(Button4_Port,button_4)==RESET)
	   {	
		   counter_0=counter_1=counter_2=counter_3=0;
		   LCD_movecursor(1,1);
		   LCD_vSend_string("A=00");
		   LCD_movecursor(1,12);
		   LCD_vSend_string("B=00");
		   LCD_movecursor(2,1);
		   LCD_vSend_string("C=00");
		   LCD_movecursor(2,12);
		   LCD_vSend_string("D=00");
		   LCD_movecursor(1,1);
	   }
		
		//_delay_ms(150);   
	    _delay_ms(250);

   }
    
}

void App_vinit()
{
	button_vInit(Button0_Port,button_0);
	button_vInit(Button1_Port,button_1);
	button_vInit(Button2_Port,button_2);
	button_vInit(Button3_Port,button_3);
	button_vInit(Button4_Port,button_4);
	LCD_vInit();
}

