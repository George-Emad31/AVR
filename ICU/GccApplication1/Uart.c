/*
 * Uart.c
 *
 * Created: 5/23/2024 5:06:04 PM
 *  Author: George
 */ 
#include "Uart.h"


void UART_vInit(u32 baud)
{
/*1 - Choose baud rate that will be used by
 sender and receiver by writing to UBRRL/UBRRH*/
u16 UBRR;
UBRR=(F_CPU/(16*baud))-1;
// Data must be writen in high then low
UBRRH=(u8)(UBRR>>8);
UBRRL=(u8)(UBRR);
/*2 - Enable USART Sender & Receiver*/
SET_BIT(UCSRB,TXEN);
SET_BIT(UCSRB,RXEN);
/*3 - Choose number of data bits to be sent,parity and stop bits from UCSRC
	, We will work with  frame formate :  8 bits data,1 stop bit and no parity bits*/
UCSRC=(1<<URSEL)|(1<<UCSZ0)|(1<<UCSZ1);	
}

void UART_vSendData(u8 data) // Transmit
{
	/*Wait for UDR transmit buffer to be empty*/
	while(READ_BIT(UCSRA,UDRE)==0);
	/*Put data to UDR transmit buffer transmit*/
	UDR=data ;
}
u8 UART_uReceiveData()
{
/*Wait for UDR receive buffer to be filled with data*/

while(READ_BIT(UCSRA,RXC)==0);

/*Receive data from UDR receive buffer*/
return UDR;
}

void UART_vSendstring(u8*ptr)
{
	while(*ptr!=0)
	{
	UART_vSendData(*ptr);	
	ptr++;
	_delay_ms(100);
	}
	
}