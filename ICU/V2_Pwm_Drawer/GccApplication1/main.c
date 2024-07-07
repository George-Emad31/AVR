/*
 * GccApplication1.c
 *
 * Created: 4/7/2024 7:37:14 PM
 * Author : george
 */
#define F_CPU 16000000UL
#include "util/delay.h"
#include "DIO.h"
#include "LCD.h"
#include "Timer.h"
#define FREQ_MODE 1	

void DrawSignal(u16 frequency, u16 duty_cycle);
int main(void)
{  
	// PWM
	PWM_Init();
	PWM_Start(PWM_No_Prescaling);	// No prescaling
	PWM_SetDuty(Non_Inverting, 50);
	
	// ICU
	u16 a,b,c,high,period,duty_cycle,frequency;
	// LCD
	LCD_vInit();	
	LCD_vSend_string("READING");
   while(1)
   {	
	TCCR1A = 0; // NO NEED FOR ANY MODE
	SET_BIT(TIFR,ICF1);                /* Clear ICF (Input Capture flag)  */
	//TIFR| = (1<<ICF1);  	

	TCCR1B = 0x41; // 0xc1  	               /* Rising edge, no prescaler , noise canceler*/
	while (READ_BIT(TIFR,ICF1) == 0);
	a = ICR1;  		                  /* Take value of capture register */
    SET_BIT(TIFR,ICF1);               /* Clear ICF (Input Capture flag)  */ 	/* Clear ICF flag */
		
	TCCR1B =0x01;    //0x81;  	              /* Falling edge, no prescaler ,noise canceler*/
	while (READ_BIT(TIFR,ICF1) == 0);
	b = ICR1;  		                  /* Take value of capture register */
	SET_BIT(TIFR,ICF1);               /* Clear ICF (Input Capture flag)  */  	/* Clear ICF flag */
		 
	TCCR1B = 0x41; //0xc1;  	              /* Rising edge, no prescaler ,noise canceler*/
	while (READ_BIT(TIFR,ICF1) == 0);
	c = ICR1;  		                  /* Take value of capture register */
	
	SET_BIT(TIFR,ICF1);               /* Clear ICF (Input Capture flag)  */  	/* Clear ICF flag */

	TCCR1B = 0;  	                  /* Stop the timer */
		
	if(a<b && b<c)                   /* Check for valid condition, 
					                 to avoid timer overflow reading */
		{
			high=b-a;
			 period=c-a;
			 duty_cycle=((float)high/period)*100;
			 frequency=F_CPU/(period);
			 DrawSignal(frequency, duty_cycle);
			_delay_ms(50);
		}
		
		else 
		{
			LCD_clearscreen();
			LCD_vSend_string("out of range");
		
		}			
	
   }
}


/////// 

void DrawSignal(u16 frequency, u16 duty_cycle)
{
	LCD_vSend_cmd(0x80);
	#if FREQ_MODE
	LCD_vSend_string("F=");
	LCD_Write_Number(frequency / 1000);
	LCD_vSend_string("kHz ");
	#else
	u16 period = 1000000 / frequency;
	LCD_vSend_string("T=");
	LCD_Write_Number(period);
	LCD_vSend_string("us ");
	#endif
	LCD_vSend_string("D=");
	LCD_Write_Number(duty_cycle);
	LCD_vSend_string("%     ");

	// Draw signal
	LCD_vSend_cmd(0xC0);
	LCD_vSend_string("__");
	for (u8 i = 0; i < 3; i++)
	{
		u16 temp = duty_cycle;
		for (u8 p = 0; p < 4; p++)
		{
			if (temp > 25)
			{
				LCD_vSend_char('-');
				temp -= 25;
			}
			else if (temp > 0)
			{
				LCD_vSend_char('-');
				temp = 0;
			}
			else
			{
				LCD_vSend_char('_');
				temp = 0;
			}
		}
	}
	LCD_vSend_string("__");
}
