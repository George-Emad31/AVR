/*
 * INERRUPT.c
 *
 * Created: 4/17/2024 7:16:40 PM
 *  Author: georg
 */ 
#include "INTERRUPT.h"

void sei(void)
{
	// I-bit active
	SET_BIT(SREG,7);
};

void cli(void)
{
CLR_BIT(SREG,7);	
};

