/*
 * GccApplication1.c
 *
 * Created: 4/7/2024 7:37:14 PM
 * Author : george
 */
#include "App_config.h"
#define F_CPU 8000000UL
#include <util/delay.h>
#include <avr/interrupt.h>
volatile u8 seconds_counter=0; //ISR Check each 1 se
u8 hour_counter=0;
u8 minute_counter=0;
u8 First_Value;
u8 Second_Value;  
u8 value;
void App_init();

int main(void)
{  	
 LCD_vInit();
 keypad_vInit();
 seven_seg_vinit('B');
 // SEVEN SEGMENT CONTROL PINS ENABLE
 DIO_vsetPINDir('C',DIO_PIN0,DIO_PIN_OUTPUT);
 DIO_vsetPINDir('C',DIO_PIN1,DIO_PIN_OUTPUT);
 DIO_vsetPINDir('C',DIO_PIN2,DIO_PIN_OUTPUT);
 DIO_vsetPINDir('C',DIO_PIN3,DIO_PIN_OUTPUT);
 DIO_vsetPINDir('C',DIO_PIN4,DIO_PIN_OUTPUT);
 DIO_vsetPINDir('C',DIO_PIN5,DIO_PIN_OUTPUT);
 
LCD_vSend_string("PRESS 1 TO ");
LCD_movecursor(2,1);
LCD_vSend_string("SET CLOCK");
// ACTIVE TIMER 2 INTERRUPT
timer2_overflow_init_interrupt();
while(1)
 {	
value=keypad_u8check_press();
if (value!=NOTPRESSED)// pressed
    {
	if (value=='1')
	{
    LCD_clearscreen();
    LCD_vSend_string("Hours:--");
    LCD_movecursor(1,7);	
    _delay_ms(500);
	do 
    {   // need to check if key pressed
	First_Value=keypad_u8check_press();
    }
    while (First_Value==NOTPRESSED);
    // if pressed
    LCD_vSend_char(First_Value);
    _delay_ms(300);
    do 
    { 
		Second_Value=keypad_u8check_press();
    } 
	while (Second_Value==NOTPRESSED);
     LCD_vSend_char(Second_Value);
    _delay_ms(300);
	
	hour_counter=(Second_Value-ASCII)+10*(First_Value-ASCII);
	LCD_clearscreen();
	_delay_ms(300);
	LCD_vSend_string("minutes=--");
	LCD_movecursor(1,9);
	do 
	{ 
	  First_Value=keypad_u8check_press();	
	} 
	while (First_Value==NOTPRESSED);
	LCD_vSend_char(First_Value);
	_delay_ms(300);
	do 
	{
	 Second_Value=keypad_u8check_press()	;
	} while (Second_Value==NOTPRESSED);
	LCD_vSend_char(Second_Value);
	_delay_ms(300);
	minute_counter=(Second_Value-ASCII)+10*(First_Value-ASCII);
    _delay_ms(300);
	////
	LCD_clearscreen();
	LCD_vSend_string("seconds=--");
	LCD_movecursor(1,9);
	do
	{
		First_Value=keypad_u8check_press();
	}
	while (First_Value==NOTPRESSED);
	LCD_vSend_char(First_Value);
	_delay_ms(300);
	do
	{
		Second_Value=keypad_u8check_press();
	} while (Second_Value==NOTPRESSED);
	LCD_vSend_char(Second_Value);
	_delay_ms(300);
	seconds_counter=(Second_Value-ASCII)+10*(First_Value-ASCII);
	_delay_ms(300);
	LCD_clearscreen();
	LCD_vSend_string("press 1 to");
	LCD_movecursor(2,1);
	LCD_vSend_string("set clock");
  } 
else
{
	LCD_clearscreen();
	LCD_vSend_string("wrong choice");
	_delay_ms(1000);
	LCD_clearscreen();
	LCD_vSend_string("press 1 to");
	LCD_movecursor(2,1);
	LCD_vSend_string("set clock");
   }  
 }
 SET_BIT(PORTC,1);
 SET_BIT(PORTC,2);
 SET_BIT(PORTC,3);
 SET_BIT(PORTC,4);
 SET_BIT(PORTC,5);
 CLR_BIT(PORTC,0);
 seven_segment_write_Cathode('B',seconds_counter%10);
 _delay_ms(5);
 
 SET_BIT(PORTC,0);
 SET_BIT(PORTC,2);
 SET_BIT(PORTC,3);
 SET_BIT(PORTC,4);
 SET_BIT(PORTC,5);
 CLR_BIT(PORTC,1);
 seven_segment_write_Cathode('B',seconds_counter/10);
 _delay_ms(5);
 
 SET_BIT(PORTC,0);
 SET_BIT(PORTC,1);
 SET_BIT(PORTC,3);
 SET_BIT(PORTC,4);
 SET_BIT(PORTC,5);
 CLR_BIT(PORTC,2);
 seven_segment_write_Cathode('B',minute_counter%10);
 _delay_ms(5);
 
 SET_BIT(PORTC,0);
 SET_BIT(PORTC,1);
 SET_BIT(PORTC,2);
 SET_BIT(PORTC,4);
 SET_BIT(PORTC,5);
 CLR_BIT(PORTC,3);
 seven_segment_write_Cathode('B',minute_counter/10);
 _delay_ms(5);
 
 SET_BIT(PORTC,0);
 SET_BIT(PORTC,1);
 SET_BIT(PORTC,2);
 SET_BIT(PORTC,3);
 SET_BIT(PORTC,5);
 CLR_BIT(PORTC,4);
 seven_segment_write_Cathode('B',hour_counter%10);
 _delay_ms(5);
 
 SET_BIT(PORTC,0);
 SET_BIT(PORTC,1);
 SET_BIT(PORTC,2);
 SET_BIT(PORTC,3);
 SET_BIT(PORTC,4);
 CLR_BIT(PORTC,5);
 seven_segment_write_Cathode('B',hour_counter/10);
 _delay_ms(5);
 
 if (seconds_counter==60)
 {
	 seconds_counter=0;
	 minute_counter++;
 }
 if (minute_counter==60)
 {
	 minute_counter=0;
	 hour_counter++;
 }
 if (hour_counter==24)
 {
	 hour_counter=0;
 }
 }
 
 
}


ISR(TIMER2_OVF_vect)
{
seconds_counter++;
}


