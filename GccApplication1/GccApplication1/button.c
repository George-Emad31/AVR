/*
 * button.c
 *
 */ 
#include "DIO.h"
void button_vInit(unsigned char portname,unsigned char pinnumber)
{
	DIO_vsetPINDir(portname,pinnumber,0);
}
unsigned char button_u8read(unsigned char portname,unsigned char pinnumber)
{
	unsigned char x;
	x=DIO_u8read(portname,pinnumber);
	return x ;
}

