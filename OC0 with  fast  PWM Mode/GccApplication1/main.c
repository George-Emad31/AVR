/*
 * GccApplication1.c
 *
 * Created: 4/7/2024 7:37:14 PM
 * Author : george
 */
#define F_CPU 8000000UL
#include "DIO.h"
#include "Timer.h"
#include "LCD.h"
#include "Keypad_driver.h"
#include "App_config.h"
 u16 x= 128;
 u8 z=0;
int main(void)
{  		
clk_1024();
timer_wave_fastPWM(x);
LCD_vInit();
x=(x*100);
u8 y;
y=((u8)(x/(255)));

if ((y!=100))
{
	LCD_vSend_string("Duty cycle=  %");
	LCD_movecursor(1,12);
	LCD_vSend_char((y/10)+ASCII);
	LCD_vSend_char((y%10)+ASCII);
}
else
{
	LCD_vSend_string("Duty cycle=100%");
	LCD_movecursor(1,12);
}


   while(1)
   {	
     
   }
}


