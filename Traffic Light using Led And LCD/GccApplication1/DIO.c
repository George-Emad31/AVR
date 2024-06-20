


#include "DIO.h" 
void DIO_vsetPINDir(unsigned char portname,unsigned char pinnumber,unsigned char direction)
{
	switch(portname)
	{
		case 'A':
		if(DIO_PIN_OUTPUT==direction)
		{
			SET_BIT(DDRA,pinnumber);//Set the direction of the given pin in port A as output
		}
		else
		{
			CLR_BIT(DDRA,pinnumber);//Set the direction of the given pin in port A as input
		}
		break;
		case 'B':
		if(DIO_PIN_OUTPUT==direction)
		{
			SET_BIT(DDRB,pinnumber);//Set the direction of the given pin in port B as output
		}
		else
		{
			CLR_BIT(DDRB,pinnumber);//Set the direction of the given pin in port B as input
		}
		break;
		case 'C':
		if(DIO_PIN_OUTPUT==direction)
		{
			SET_BIT(DDRC,pinnumber);//Set the direction of the given pin in port C as output
		}
		else
		{
			CLR_BIT(DDRC,pinnumber);//Set the direction of the given pin in port C as input
		}
		break;
		case 'D':
		if(DIO_PIN_OUTPUT==direction)
		{
			SET_BIT(DDRD,pinnumber);//Set the direction of the given pin in port D as output
		}
		else
		{
			CLR_BIT(DDRD,pinnumber);//Set the direction of the given pin in port D as input
		}
		break;
		default: 
		break;
	}
}


void DIO_write(unsigned char portname,unsigned char pinnumber,unsigned char outputvalue)
{
	switch(portname)
	{
		case 'A' :
		
		if(DIO_PIN_HIGH==outputvalue)
		{
			SET_BIT(PORTA,pinnumber);//Set the value of the given pin in port A as High
		}
		else
		{
			CLR_BIT(PORTA,pinnumber);//Set the value of the given pin in port A as Low
		}
		break ;
		case 'B':
		
		if(DIO_PIN_HIGH==outputvalue)
		{
			SET_BIT(PORTB,pinnumber);//Set the value of the given pin in port B as High
		}
		else
		{
			CLR_BIT(PORTB,pinnumber);//Set the value of the given pin in port B as Low
		}
		break ;
		case 'C' :
		
		if(DIO_PIN_HIGH==outputvalue)
		{
			SET_BIT(PORTC,pinnumber);//Set the value of the given pin in port C as High
		}
		else
		{
			CLR_BIT(PORTC,pinnumber);//Set the value of the given pin in port C as Low
		}
		break ;
		case 'D':
		
		if(DIO_PIN_HIGH==outputvalue)
		{
			SET_BIT(PORTD,pinnumber);//Set the value of the given pin in port D as High
		}
		else
		{
			CLR_BIT(PORTD,pinnumber);//Set the value of the given pin in port D as Low
		}
		break ;
		default: break ;
	}
}


unsigned char DIO_u8read(unsigned char portname,unsigned char pinnumber)
{
	unsigned char return_value=0;
	switch(portname)
	{
		case 'A' :
		return_value=READ_BIT(PINA,pinnumber);//Read the value from the given pin in port A
		break;
		
		case 'B' :
		return_value=READ_BIT(PINB,pinnumber);//Read the value from the given pin in port B
		break;
		
		case 'C' :
		return_value=READ_BIT(PINC,pinnumber);//Read the value from the given pin in port C
		break;
		
		case 'D' :
		return_value=READ_BIT(PIND,pinnumber);//Read the value from the given pin in port D
		break;
		default: 
		break;
	}
	return return_value ;
}
void DIO_toggle(unsigned char portname,unsigned char pinnumber)
{
	switch(portname)
	{
		case 'A':
		TOG_BIT(PORTA,pinnumber);//Toggle the value of the given pin in port A
		break;
		case 'B':
		TOG_BIT(PORTB,pinnumber);//Toggle the value of the given pin in port B
		break;
		case 'C':
		TOG_BIT(PORTC,pinnumber);//Toggle the value of the given pin in port C
		break;
		case 'D':
		TOG_BIT(PORTD,pinnumber);//Toggle the value of the given pin in port D
		break;
		default: break;
	}
}

void DIO_vconnectpullup(char portname ,char pinnumber, char connect_pullup)
{
	switch(portname)
	{
		case 'A':
		if(connect_pullup==1)
		{
			SET_BIT(PORTA,pinnumber);
		}
		else
		{
			CLR_BIT(PORTA,pinnumber);
		}
		break;
		case 'B':
		if(connect_pullup==1)
		{
			SET_BIT(PORTB,pinnumber);
		}
		else
		{
			CLR_BIT(PORTB,pinnumber);
		}
		break;
		case 'C':
		if(connect_pullup==1)
		{
			SET_BIT(PORTC,pinnumber);
			
		}
		else
		{
			CLR_BIT(PORTC,pinnumber);
		}
		break;
		case 'D':
		if(connect_pullup==1)
		{
			SET_BIT(PORTD,pinnumber);
			
		}
		else
		{
			CLR_BIT(PORTD,pinnumber);
		}
		break;
		
	}
}





void DIO_set_port_direction(unsigned char portname,unsigned char direction)
{
	switch(portname)
	{
		case 'A' :
		DDRA=direction; //set the direction of port A
		break ;
		case 'B':
		DDRB=direction; //set the direction of port B
		break ;
		case 'C' :
		DDRC=direction; //set the direction of port C
		break ;
		case 'D':
		DDRD=direction; //set the direction of port D
		break ;
		default:
		break ;
	}
	
}
void DIO_write_port(unsigned char portname,unsigned char portvalue)
{
	switch(portname)
	{
		case 'A' :
		PORTA=portvalue; //Write the given value to the port A
		break ;
		case 'B':
		PORTB=portvalue; //Write the given value to the port B
		break ;
		case 'C' :
		PORTC=portvalue; //Write the given value to the port C
		break ;
		case 'D':
		PORTD=portvalue; //Write the given value to the port D
		break ;
		default:
		 break ;
	}
}

unsigned char DIO_read_port(unsigned char portname)
{
	unsigned char return_val=0;
	switch(portname)
	{
		case 'A' :
		return_val=PINA; // read the value of port A 
		break ;
		case 'B':
		return_val=PINB; // read the value of port B 
		break ;
		case 'C' :
		return_val=PINC; // read the value of port C 
		break ;
		case 'D':
		return_val=PIND; // read the value of port D 
		break ;
		default:
		break ;
	}
	return return_val;
}




void DIO_write_low_nibble(unsigned char portname,unsigned char numberValue)
{
	// macro read the var :number value like 3=0011 then it read bit 1 which is 1 
	DIO_write(portname,0,READ_BIT(numberValue,0));
	DIO_write(portname,1,READ_BIT(numberValue,1));
	DIO_write(portname,2,READ_BIT(numberValue,2));
	DIO_write(portname,3,READ_BIT(numberValue,3));
	
}

void DIO_write_high_nibble(unsigned char portname,unsigned char numberValue)
{
	DIO_write(portname,4,READ_BIT(numberValue,4));
	DIO_write(portname,5,READ_BIT(numberValue,5));
	DIO_write(portname,6,READ_BIT(numberValue,6));
	DIO_write(portname,7,READ_BIT(numberValue,7));
	
	
}
void write_high_nibble(unsigned char portname,unsigned char numberValue)
{
	numberValue<<=4;
	switch(portname)
	{
		case 'A':
		PORTA&=0x0f;
		PORTA|=numberValue;
		case 'B':
		PORTB&=0x0f;
		PORTB|=numberValue;
		case 'C':
		PORTC&=0x0f;
		PORTC|=numberValue;
		case 'D':
		PORTD&=0x0f;
		PORTD|=numberValue;
	}
	
	
	
}