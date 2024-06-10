/*****************************************/
/*	Author : Khaled Mohsen				 */
/*	Date   : 6-18-2022   		   		 */
/*	Version: 0.2				         */
/*	File   : DIO_program.c	   	         */
/*****************************************/

#include "STD_types.h"
#include "BIT_MATH.h"
#include "DIO_private.h"
#include "DIO_configuration.h"
#include "DIO_interface.h"

/*
	functions definition
*/

void DIO_VoidInit(void)
{
	DDRA = DIO_u8_PORTA_DIR;
	DDRB = DIO_u8_PORTB_DIR;
	DDRC = DIO_u8_PORTC_DIR;
	DDRD = DIO_u8_PORTD_DIR;
}

void DIO_VoidSetPinValue(u8 DIO_u8Port , u8 DIO_u8Pin , u8 DIO_u8Val)
{
	switch(DIO_u8Port)
	{
		case DIO_u8_PORTA:
		
			if(DIO_u8Val == DIO_u8_HIGH)
			{
				SET_BIT(PORTA , DIO_u8Pin);
			}
			else if(DIO_u8Val == DIO_u8_LOW)
			{
				CLEAR_BIT(PORTA , DIO_u8Pin);
			}
			else
			{
				// error
			}
			break;
			
		case DIO_u8_PORTB:
		
			if(DIO_u8Val == DIO_u8_HIGH)
			{
				SET_BIT(PORTB , DIO_u8Pin);
			}
			else if(DIO_u8Val == DIO_u8_LOW)
			{
				CLEAR_BIT(PORTB , DIO_u8Pin);
			}
			else
			{
				// error
			}
		break;
		
		case DIO_u8_PORTC:
		
			if(DIO_u8Val == DIO_u8_HIGH)
			{
				SET_BIT(PORTC , DIO_u8Pin);
			}
			else if(DIO_u8Val == DIO_u8_LOW)
			{
				CLEAR_BIT(PORTC , DIO_u8Pin);
			}
			else
			{
				// error
			}
			break;
			
		case DIO_u8_PORTD:
		
			if(DIO_u8Val == DIO_u8_HIGH)
			{
				SET_BIT(PORTD , DIO_u8Pin);
			}
			else if(DIO_u8Val == DIO_u8_LOW)
			{
				CLEAR_BIT(PORTD , DIO_u8Pin);
			}
			else
			{
				// error
			}
			break;
		default:
				// error
				return;
	}
}

u8 DIO_u8GetPinValue(u8 DIO_u8Port , u8 DIO_u8Pin)
{
	switch(DIO_u8Port)
	{
		case DIO_u8_PORTA:
				return GET_BIT(PINA , DIO_u8Pin);
		
		case DIO_u8_PORTB:
				return GET_BIT(PINB , DIO_u8Pin);
				
		case DIO_u8_PORTC:
				return GET_BIT(PINC , DIO_u8Pin);
				
		case DIO_u8_PORTD:
				return GET_BIT(PIND , DIO_u8Pin);
				
		default:
				// error
				return DIO_u8_ERROR;
	}
}


void DIO_VoidSetPortValue(u8 DIO_u8Port , u8 DIO_u8Val)
{
	switch(DIO_u8Port)
	{
		case DIO_u8_PORTA:
				ASSIGN_PORT(PORTA , DIO_u8Val);
				break;
		case DIO_u8_PORTB:
				ASSIGN_PORT(PORTB , DIO_u8Val);
				break;
		case DIO_u8_PORTC:
				ASSIGN_PORT(PORTC , DIO_u8Val);
				break;
		case DIO_u8_PORTD:
				ASSIGN_PORT(PORTD , DIO_u8Val);
				break;
		default:
				// error
				return;
	}
}