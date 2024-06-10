/*
 * GccApplication1.c
 *
 * Created: 4/7/2024 7:37:14 PM
 * Author : george
 */
#define F_CPU 8000000UL
#include "Timer.h"
#include "DIO.h"
#include "seven segment.h"
#include <avr/interrupt.h>
volatile u8  counter1=0; // first 7 seg
volatile u8  counter2=0;  // for 7 segment 
volatile u8  counter3=0; // second 7 seg
int main(void)
{  
	clk_1024();
	seven_seg_vinit('D');
   timer_CTC_init_interrupt(78);
   // seven segment control  as Output pin
   DIO_vsetPINDir('A',1,DIO_PIN_OUTPUT);
   DIO_vsetPINDir('A',0,DIO_PIN_OUTPUT);
   
   
   while(1)
    { 
	  // 2nd seven segment
	 DIO_write('A',1,DIO_PIN_HIGH);// SET 7 SEG (2) ACTIVE
	 DIO_write('A',0,DIO_PIN_LOW);// CLR 7 SEG (1) DISABLE
	// WRITE ON 7 SEGMENT 
    seven_segment_write_Cathode('D',counter2%10);	   
	 // 1st seven segment 
    while(counter3==0);// means it reach ISR each 10 ms // waiting station until 0cr reaches the value (ex 80) means it goes to isr each 10ms then increment counter3 =1 then pass from while loop ,
	counter3=0;
	 DIO_write('A',0,DIO_PIN_HIGH);// SET 7 SEG (1) ACTIVE
	 DIO_write('A',1,DIO_PIN_LOW);// CLR 7 SEG (2) DISABLE
	 // WRITE ON 7 SEGMENT
	 seven_segment_write_Cathode('D',counter2/10);
	//  1 second  check 
	/while (counter3==0);
		counter3=0;
		if(counter1>=100) // 1 second pass
		{
			counter1=0; // 1 second counter =0 for new second
		    counter2++;
		    if(counter2==21)  // check 7 segment  count limit 
		    {
			counter2=0; 
		    }
	   }
  }
}


ISR(TIMER0_COMP_vect)
{
counter1++;
counter3=1;


}