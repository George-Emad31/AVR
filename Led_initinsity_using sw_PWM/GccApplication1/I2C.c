/*
 * I2C.c
 *
 * Created: 6/5/2024 11:57:45 AM
 *  Author: George
 */ 
#include "I2C.h"

void I2C_Master_init(u32 SCL_CLOCK,u8 Prescaler)
{ //TWBR IS 8-BIT REGISTER MUST BE CASTED TO U8 
TWBR=(u8)((F_CPU/SCL_CLOCK)-16)/(2*Prescaler);	
if(Prescaler==1)
{
TWSR=0;
}
else if (Prescaler==4)
{
	TWSR=1;
}
else if(Prescaler==16)
{
	TWSR=2;
}
else if(Prescaler==64)
{
	TWSR=3;
}
}

void I2C_start(void)
{
// 1. application writees to TWCR to initiate transmission of start
// ENABLE I2C INTERRUPT FLAG ->  TWINT  BY CLEAR FLAG BY WRITING 1  
SET_BIT(TWCR,TWINT);
// ENABLE I2C ->TWEN 
SET_BIT(TWCR,TWEN);
// ENABLE I2C START CONDITION ->  TWSTA 
SET_BIT(TWCR,TWSTA);
// WAIT UNTIL THE FLAG IS CLEARD ?? TAKE TIME
while(READ_BIT(TWCR,TWINT)==0); // if it is cleared by setting 1 to flag then waiting time = finish
// ack of start condition has been transmitted 
while((TWSR&0xF8)!=0X08);
}

void I2C_write_address(u8 address)
{
// LOAD THE DATA IN Address reg	
	TWDR=address;
// ENABLE I2C INTERRUPT FLAG ->  TWINT  BY CLEAR FLAG BY WRITING 1
    SET_BIT(TWCR,TWINT);
// ENABLE I2C ->TWEN
   SET_BIT(TWCR,TWEN);
   while(READ_BIT(TWCR,TWINT)==0); // if it is cleared by setting 1 to flag then waiting time = finish
   //  SLA+WRITE ADDRESS has been transmitted AND ACK RECEIVED
   while((TWSR&0xF8)!=0X18);
}
void I2C_write_data(u8 data)
{
	// LOAD THE DATA IN Address reg
	TWDR=data;
	// ENABLE I2C INTERRUPT FLAG ->  TWINT  BY CLEAR FLAG BY WRITING 1
	SET_BIT(TWCR,TWINT);
	// ENABLE I2C ->TWEN
	SET_BIT(TWCR,TWEN);
	while(READ_BIT(TWCR,TWINT)==0); //wait to finish
	while ((TWSR & 0XF8) != 0x28); // data has been transmitted and ACK has been received
}
void I2C_stop(void)
{
	// 1. application writees to TWCR to initiate transmission of STOP
	// ENABLE I2C INTERRUPT FLAG ->  TWINT  BY CLEAR FLAG BY WRITING 1
	SET_BIT(TWCR,TWINT);
	// ENABLE I2C ->TWEN
	SET_BIT(TWCR,TWEN);
	// ENABLE I2C START CONDITION ->  TWSTA
	SET_BIT(TWCR,TWSTO);
	
}

void I2C_set_address(u8 address)
{
	TWAR=address;
}
u8 I2C_slave_read(void)
{
	TWCR=(1<<TWINT)|(1<<TWEN)|(1<<TWEA);
	while(READ_BIT(TWCR,TWINT)==0);
	while ((TWSR & 0XF8) != 0x60); // own SLA+W has been received and ACK has been returned
	TWCR=(1<<TWINT)|(1<<TWEN)|(1<<TWEA);
	while(READ_BIT(TWCR,TWINT)==0);
	while ((TWSR & 0XF8) != 0x80); // previously addressed with own SLA+W : data has been received : ACK has been returned
	return TWDR ;
}