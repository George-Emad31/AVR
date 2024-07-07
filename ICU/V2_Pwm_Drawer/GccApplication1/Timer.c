/*
 * Timer.c
 *
 * Created: 5/12/2024 9:08:54 PM
 *  Author: George
 */ 
#include"DIO.h"
#include "Timer.h"


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


//// Timer 2

void PWM_Init(void)
{
	// Define direction of 0C2
	SET_BIT(DDRD, PD7);
	// Choose timer mode as FPWM
	SET_BIT(TCCR2, WGM00);
	SET_BIT(TCCR2, WGM01);
}

void PWM_Start(PWM_PRESCALER prescaler)
{
	switch(prescaler)
	{
		case PWM_No_Prescaling:
		SET_BIT(TCCR2, CS00);
		CLR_BIT(TCCR2, CS01);
		CLR_BIT(TCCR2, CS02);
		break;
		case PWM_8:
		CLR_BIT(TCCR2, CS00);
		SET_BIT(TCCR2, CS01);
		CLR_BIT(TCCR2, CS02);
		break;
		case PWM_64:
		SET_BIT(TCCR2, CS00);
		SET_BIT(TCCR2, CS01);
		CLR_BIT(TCCR2, CS02);
		break;
		case PWM_256:
		CLR_BIT(TCCR2, CS00);
		CLR_BIT(TCCR2, CS01);
		SET_BIT(TCCR2, CS02);
		break;
		case PWM_1024:
		SET_BIT(TCCR2, CS00);
		CLR_BIT(TCCR2, CS01);
		SET_BIT(TCCR2, CS02);
	}
}

void PWM_Stop(void)
{
	// Choose prescaler 0
	CLR_BIT(TCCR2, CS00);
	CLR_BIT(TCCR2, CS01);
	CLR_BIT(TCCR2, CS02);
}

void PWM_SetDuty(PWM_MODE mode, u8 dutyCycle)
{
	
	switch(mode)
	{
		case Disconnected:
		CLR_BIT(TCCR2, COM00);
		CLR_BIT(TCCR2, COM01);
		OCR2 = 0;
		break;
		case Inverting:
		SET_BIT(TCCR2, COM00);
		SET_BIT(TCCR2, COM01);
		OCR2 = (BITS - 1) - ((BITS * dutyCycle) / 100) - 1;
		break;
		case Non_Inverting:
		CLR_BIT(TCCR2, COM00);
		SET_BIT(TCCR2, COM01);
	    OCR2 = ((BITS * dutyCycle) / 100) - 1;
	}
	
}




