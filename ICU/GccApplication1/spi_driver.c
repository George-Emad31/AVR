/*
 * spi_driver.c
 *
 * Created: 6/7/2024 12:13:51 PM
 *  Author: George
 */ 
#include "spi_driver.h"
#define F_CPU 8000000UL
#include "util/delay.h"

void SPI_MasterInit(void)
{
// 1- set Spi pins as output /MOSI , SS SCK for master	
DIO_vsetPINDir('B',DIO_PIN4,DIO_PIN_OUTPUT);//SS
DIO_vsetPINDir('B',DIO_PIN5,DIO_PIN_OUTPUT);//MOSI
DIO_vsetPINDir('B',DIO_PIN6,DIO_PIN_INPUT);//MISO
DIO_vsetPINDir('B',DIO_PIN7,DIO_PIN_OUTPUT);//SCK

// ENABLE SPI AS MASTER 
SET_BIT(SPCR,MSTR);
// ENABLE SPI
SET_BIT(SPCR,SPE); 
// SET CLK OF SPI FOSC/16
SET_BIT(SPCR,SPR0);
// SLAVE SELECT AS HIGH LOGIC 
DIO_write('B',DIO_PIN4,DIO_PIN_HIGH); 
}

void SPI_SlaveInit(void)
{
	// SLAVE MODE ENABLE
	CLR_BIT(SPCR,MSTR);
	// SPI ENABLE
	SET_BIT(SPCR,SPE);
	// MISO AS OUTPUT
   DIO_vsetPINDir('B',DIO_PIN6,DIO_PIN_OUTPUT);
}

u8 SPI_MasterTransmitchar(u8 Data)
{
// CLEAR SS (LOW) TO SELECT SLAVE 
DIO_write('B',DIO_PIN4,DIO_PIN_LOW);
// STORE DATA IN DATA Register
	SPDR=Data;
//wait until transmition complete
// WHEN IT IS COMPLETE IT IS SET TO 1 -> EXIT THE LOOP 
while(READ_BIT(SPSR,SPIF)==0); 
// READ THE RECEIVED DATA
return SPDR	;
}
u8 SPI_SlaveReceivechar(u8 Data)
{
// STORE DATA IN SPDR REGISTER 	
SPDR=Data;	
//wait until RECIEVE complete
// WHEN IT IS COMPLETE IT IS SET TO 1 -> EXIT THE LOOP
while(READ_BIT(SPSR,SPIF)==0);
// READ THE RECEIVED DATA
return SPDR;
}
void SPI_MasterTransmitstring(u8*ptr)
{
	while((*ptr)!=0)
	{
	SPI_MasterTransmitchar(*ptr);
	_delay_ms(300);
	ptr++;
	}
}