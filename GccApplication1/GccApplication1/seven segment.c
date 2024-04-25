/*
 * seven_segment.c
 *
 * Created: 4/8/2024 7:32:53 PM
 *  Author: georg
 */ 

#include "seven segment.h"

void seven_seg_vinit(unsigned char portname )
{
	DIO_set_port_direction(portname,0xff);
}

void seven_seg_vinit_BCD(unsigned char portname,unsigned char nibble )
{ 
	switch(nibble){
	  
	 case 'L':
	DIO_vsetPINDir(portname,0,1);
	DIO_vsetPINDir(portname,1,1);
	DIO_vsetPINDir(portname,2,1);
	DIO_vsetPINDir(portname,3,1);
	break;
	case 'l':
	DIO_vsetPINDir(portname,0,1);
	DIO_vsetPINDir(portname,1,1);
	DIO_vsetPINDir(portname,2,1);
	DIO_vsetPINDir(portname,3,1);
	break;
	
	case 'h':
	DIO_vsetPINDir(portname,4,1);
	DIO_vsetPINDir(portname,5,1);
	DIO_vsetPINDir(portname,6,1);
	DIO_vsetPINDir(portname,7,1);
	break;
	
	
	case 'H':
	DIO_vsetPINDir(portname,4,1);
	DIO_vsetPINDir(portname,5,1);
	DIO_vsetPINDir(portname,6,1);
	DIO_vsetPINDir(portname,7,1);
	break;
	
	}
}



void seven_segment_write_Cathode (unsigned char portname ,unsigned char Number)
{
	unsigned char arr[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};
	DIO_write_port(portname,arr[Number]);
}

void seven_segment_write_anode (unsigned char portname ,unsigned char Number1)
{
	unsigned char arr1[]={~0x3f,~0x06,~0x5b,~0x4f,~0x66,~0x6d,~0x7d,~0x47,~0x7f,~0x6f};
	DIO_write_port(portname,arr1[Number1]);
}



void seven_segment_write_Cathode_BCD(unsigned char portname,unsigned char nibbleVal ,unsigned char numberVal){
	
	if (nibbleVal==0)
	{
		DIO_write_low_nibble(portname,numberVal);
	} 
	else if (nibbleVal==1)
	{
		DIO_write_high_nibble(portname,numberVal);
	}
	
	else{
		// error
	}
}

//void seven_segment_write_anode_BCD();
