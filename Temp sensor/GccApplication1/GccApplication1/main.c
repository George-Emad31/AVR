/*
 * GccApplication1.c
 *
 * Created: 4/7/2024 7:37:14 PM
 * Author : george
 */
#define F_CPU 8000000UL
#include <util/delay.h>
#include "ADC.h"
 #include "App_config.h"
u8 temperature ;
int main(void)
{   LCD_vInit();
    ADC_init();
    LCD_vSend_string("Temperature=");
	
   
   while(1)
   {	
        
       
	temperature=(0.25*ADC_u16Read(0));
	if (temperature<10)
	{    
		LCD_movecursor(1,13);
		
		LCD_vSend_char(temperature%10+ASCII);
	    LCD_vSend_char(0xDF);// degree
		LCD_vSend_char('c');
        LCD_vSend_char(0x20);// space
	} 
	else if (temperature<100)
	{   LCD_movecursor(1,13);
		LCD_vSend_char(temperature/10 + ASCII );
		LCD_vSend_char(temperature%10 + ASCII );
		LCD_vSend_char(0xDF);// 0
		LCD_vSend_char('c');
	}
	   
   }
}
