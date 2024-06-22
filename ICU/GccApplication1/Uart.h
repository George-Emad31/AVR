/*
 * Uart.h
 * Created: 5/23/2024 5:06:38 PM
 *  Author: George
 */ 
#ifndef UART_H_
#define UART_H_
#include "DIO.h"
//#define F_CPU 8000000UL
#include<util/delay.h>
void UART_vInit(u32 baud);
void UART_vSendData(u8);
u8 UART_uReceiveData();
void UART_vSendstring(u8*ptr);



#endif /* UART_H_ */