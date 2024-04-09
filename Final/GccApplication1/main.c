/*
 * StopWatchProject.c
 *
 */

#define F_CPU 1000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#define SET_BIT(reg,bit)    reg|=(1<<bit)
#define CLR_BIT(reg,bit)    reg&=(~(1<<bit))
#define TOG_BIT(reg,bit)    reg^=(1<<bit)

/*                                         GLOBAL VARIABLES                                          */
unsigned char seconds=0 , minutes=0 , hours=0;



/*                                         7 SEGMENT FUNCTION                                          */
void SevenSegment_init(void)
{
	SET_BIT(DDRC, 5);   
	CLR_BIT(DDRA, 6);   
    TOG_BIT(PORTC, 7);
}



/*                                         TIMER FUNCTION                                          */
void Timer1_init(void)
{
	TCNT1 = 0;  //INITIAL VALUE

	/* Description:
	 * For System Clock=1Mhz and timer prescaler is F_CPU/1024.
	 * Timer frequency will be around 1Khz, TICK TIME = 1024us
	 * WE WANT 1 SEC
	 * 1/1024 =976 , 976 IS COMP VALUE
	 */

	OCR1A = 976; // COMP VALUE

	/* Configure the timer control register
	 * 1. Non PWM mode FOC1A=1
	 * 2. CTC Mode WGM12=1
	 * 3. clock = F_CPU/1024 CS10=1 CS11=0 CS12=1
	 * 4. CTC INTERRUPT OCIE1A=1
	 */

SET_BIT(TCCR1A, FOC1A);
// Set CS10, CS12, and WGM12 bits in TCCR1B
	SET_BIT(TCCR1B, CS10);
	SET_BIT(TCCR1B, CS12);
	SET_BIT(TCCR1B, WGM12);
    SET_BIT(TIMSK, OCIE1A);

}



/*                                         RESET FUNCTION                                          */
void Reset (void)
{
	CLR_BIT(DDRD, PD2);
	SET_BIT(PORTD, PD2);
    SET_BIT(GICR, INT0);
SET_BIT(MCUCR, ISC01);

}




/*                                         PAUSE FUNCTION                                          */

void Pause(void)
{
	// Enable interrupt for INT1
	SET_BIT(GICR, INT1);

	// Set rising edge interrupt for INT1
	SET_BIT(MCUCR, ISC10);
	SET_BIT(MCUCR, ISC11);
}




/*                                         RESUME FUNCTION                                          */


void Resume (void)
{
	// Set PB2 as input pin
	CLR_BIT(DDRB, PB2);

	// Enable internal pull up for PB2
	SET_BIT(PORTB, PB2);

	// Enable interrupt for INT2
	SET_BIT(GICR, INT2);

	// Set falling edge interrupt for INT2
	CLR_BIT(MCUCSR, ISC2);
}




/*                                         DISPLAY FUNCTION                                          */

void SevenSegment_Display(void)
{
	// Display first digit in seconds
	SET_BIT(PORTA, PA0);
	PORTC = seconds % 10;
	_delay_ms(1);

	// Display second digit in seconds
	SET_BIT(PORTA, PA1);
	PORTC = seconds / 10;
	_delay_ms(1);

	// Display first digit in minutes
	SET_BIT(PORTA, PA2);
	PORTC = minutes % 10;
	_delay_ms(1);

	// Display second digit in minutes
	SET_BIT(PORTA, PA3);
	PORTC = minutes / 10;
	_delay_ms(1);

	// Display first digit in hours
	SET_BIT(PORTA, PA4);
	PORTC = hours % 10;
	_delay_ms(1);

	// Display second digit in hours
	SET_BIT(PORTA, PA5);
	PORTC = hours / 10;
	_delay_ms(1);
}




/*                                         TIMER1 INTERRUPT                                          */
ISR (TIMER1_COMPA_vect)  // STOP WATCH INCREAMENT
{
	seconds++;

	if (seconds == 60)
	{
		minutes++;
		seconds=0;
	}

	if (minutes == 60)
	{
		hours++;
		minutes=0;
	}
}



/*                                         INT0 INTERRUPT                                          */
ISR (INT0_vect)  // RESET BUTTOM
{
	hours = 0;
	minutes = 0;
	seconds = 0;
}




/*                                         INT1 INTERRUPT                                          */
ISR (INT1_vect)
{
	// Clear CS10, CS11, CS12 bits in TCCR1B to pause
	CLR_BIT(TCCR1B, CS10);
	CLR_BIT(TCCR1B, CS11);
	CLR_BIT(TCCR1B, CS12);
}





/*                                         INT2 INTERRUPT                                          */
ISR (INT2_vect)
{
	// Set CS10 and CS12 bits in TCCR1B to resume
	SET_BIT(TCCR1B, CS10);
	SET_BIT(TCCR1B, CS12);
}





/*                                         MAIN FUNCTION                                          */
int main ()
{
	SevenSegment_init(); //FUNCTION TO INITIALIZE 6-DIGIT SEVEN SEGMENT
	sei(); // SET I-BIT
	Reset (); //FUNCTION TO INITIALIZE RESET BUTTOM
	Pause();  //FUNCTION TO INITIALIZE PAUSE BUTTOM
	Resume ();  //FUNCTION TO INITIALIZE RESUME BUTTOM
	Timer1_init();  //FUNCTION TO INITIALIZE TIMER1 WITH COMP MODE

	while (1)
	{
		SevenSegment_Display();  //FUNCTION TO DISPLAY 7 SEGMENT
	}
}


