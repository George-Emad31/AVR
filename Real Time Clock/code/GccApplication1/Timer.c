/*
 * Timer.c
 *
 * Created: 5/12/2024 9:08:54 PM
 *  Author: George
 */ 
#include"DIO.h"
#include "Timer.h"



void timer0_init(uint16_t delay_ms)
{
	  CLR_BIT(TCCR0,WGM00);
	  SET_BIT(TCCR0,WGM01);
	  /* load a value in OCR0 */
	  OCR0=(8000000/ 1024 / 1000) * delay_ms - 1;;
	  /* enable interrupt*/
	  sei();
	  SET_BIT(TIMSK,OCIE0);
}
void timer_CTC_init_interrupt(u16 Load_Value)
{    //Load_Value=80;
	/* select CTC mode*/
    CLR_BIT(TCCR0,WGM00);
    SET_BIT(TCCR0,WGM01);
    /* load a value in OCR0 */
  	OCR0=Load_Value;
   /* enable interrupt*/
    sei();
   	SET_BIT(TIMSK,OCIE0);

}

void timer_wave_nonPWM(u16 Load_Value)
{  // Load_Value=64;
	/* set OC0 as output pin */
	SET_BIT(DDRB,3);
	/* select CTC mode*/
    CLR_BIT(TCCR0,WGM00);
    CLR_BIT(TCCR0,WGM01);
	/* load a value in OCR0 */
	OCR0=Load_Value;
	/* select timer clock */
	//SET_BIT(TCCR0,CS00);
	//SET_BIT(TCCR0,CS02);
	/* toggle OC0 on compare match*/
	SET_BIT(TCCR0,COM00);
}

void timer_wave_fastPWM(u16 Load_Value)
{    //Load_Value=64;
	/* set OC0 as output pin */
	SET_BIT(DDRB,3);
	/* select fast PWM mode*/
	SET_BIT(TCCR0,WGM00);
	SET_BIT(TCCR0,WGM01);
	/* load a value in OCR0 */
	OCR0=Load_Value;
	/* select timer clock */
	//SET_BIT(TCCR0,CS00);
	//SET_BIT(TCCR0,CS02);
	/* Set OC0 on compare match, clear OC0 at BOTTOM,(inverting mode)*/
	SET_BIT(TCCR0,COM00);
	SET_BIT(TCCR0,COM01);
}


void timer_wave_phasecorrectPWM(u16 Load_Value)
{   //Load_Value=64;
	/* set OC0 as output pin */
	SET_BIT(DDRB,3);
	/* select phase correct PWM mode*/
	SET_BIT(TCCR0,WGM00);
	/* load a value in OCR0 */
	OCR0=Load_Value;
	/* select timer clock */
	//SET_BIT(TCCR0,CS00);
	//SET_BIT(TCCR0,CS02);
	/* Set OC0 on compare match when up-counting. Clear OC0 on compare match when down counting.*/
	SET_BIT(TCCR0,COM00);
	SET_BIT(TCCR0,COM01);
}

void timer2_overflow_init_interrupt(void)
{
	/* select timer clock */
	SET_BIT(ASSR,AS2);
	/* select timer pre scalar */
	SET_BIT(TCCR2,CS20);
	SET_BIT(TCCR2,CS22);
	/* enable interrupt*/
	sei();
	SET_BIT(TIMSK,TOIE2);
}


int TIMER_STOP()
{
	CLR_BIT(TCCR0,CS00);//0
	CLR_BIT(TCCR0,CS01);//0
	CLR_BIT(TCCR0,CS02);//0
	return 0;
}
int clk_0 ()
{
	SET_BIT(TCCR0,CS00);//1
	CLR_BIT(TCCR0,CS01);//0
	CLR_BIT(TCCR0,CS02);//0
	return 0;
}
int clk_8 ()
{
	CLR_BIT(TCCR0,CS00);//0
	SET_BIT(TCCR0,CS01);//1
	CLR_BIT(TCCR0,CS02);//0
	return 0;
}
int clk_64 ()
{
	SET_BIT(TCCR0,CS00);//1
	SET_BIT(TCCR0,CS01);//1
	CLR_BIT(TCCR0,CS02);//0
	return 0;
}
int clk_256 ()
{
	CLR_BIT(TCCR0,CS00);//0
	CLR_BIT(TCCR0,CS01);//0
	SET_BIT(TCCR0,CS02);//1
	return 0;
}
int clk_1024 ()
{
	SET_BIT(TCCR0,CS00);//1
	CLR_BIT(TCCR0,CS01);//0
	SET_BIT(TCCR0,CS02);//1
	return 0;
}
int T0_FALLING ()
{
	CLR_BIT(TCCR0,CS00);//0
	SET_BIT(TCCR0,CS01);//1
	SET_BIT(TCCR0,CS02);//1
	return 0;
}
int T0_RISING ()
{
	SET_BIT(TCCR0,CS00);//1
	SET_BIT(TCCR0,CS01);//1
	SET_BIT(TCCR0,CS02);//1
	return 0;
}