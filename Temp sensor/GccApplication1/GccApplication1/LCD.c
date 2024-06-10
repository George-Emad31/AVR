/*
 * LCD.c
 *
 * Created: 4/23/2024 1:38:26 PM
 *  Author: GEORGE EMAD
 */ 
#include "LCD.h"
#define  F_CPU 8000000UL 
#include <util/delay.h>
/************************************************************************/
/*                                Macros                                */
/************************************************************************/




void LCD_vInit(void)
{
	_delay_ms(200);
	#if defined eight_bits_mode
	DIO_vsetPINDir(Data_port,DIO_PIN0,DIO_PIN_OUTPUT);
	DIO_vsetPINDir(Data_port,DIO_PIN1,DIO_PIN_OUTPUT);
	DIO_vsetPINDir(Data_port,DIO_PIN2,DIO_PIN_OUTPUT);
	DIO_vsetPINDir(Data_port,DIO_PIN3,DIO_PIN_OUTPUT);
	DIO_vsetPINDir(Data_port,DIO_PIN4,DIO_PIN_OUTPUT);
	DIO_vsetPINDir(Data_port,DIO_PIN5,DIO_PIN_OUTPUT);
	DIO_vsetPINDir(Data_port,DIO_PIN6,DIO_PIN_OUTPUT);
	DIO_vsetPINDir(Data_port,DIO_PIN7,DIO_PIN_OUTPUT);
	DIO_vsetPINDir(Cmd_port,EN,DIO_PIN_OUTPUT);
	DIO_vsetPINDir(Cmd_port,RW,DIO_PIN_OUTPUT);
	DIO_vsetPINDir(Cmd_port,RS,DIO_PIN_OUTPUT);
	DIO_write(Cmd_port,RW,DIO_PIN_INPUT);
	LCD_vSend_cmd(EIGHT_BITS); //8 bit mode
	_delay_ms(1);
	LCD_vSend_cmd(CURSOR_ON_DISPLAY_ON);//display on cursor on
	_delay_ms(1);
	//LCD_vSend_cmd(CLR_SCREEN);//clear the screen
	_delay_ms(10);
	LCD_vSend_cmd(ENTRY_MODE); //entry mode
	_delay_ms(1); 
	
	#elif defined four_bits_mode
	DIO_vsetPINDir(Data_port,DIO_PIN4,DIO_PIN_OUTPUT);
	DIO_vsetPINDir(Data_port,DIO_PIN5,DIO_PIN_OUTPUT);
	DIO_vsetPINDir(Data_port,DIO_PIN6,DIO_PIN_OUTPUT);
	DIO_vsetPINDir(Data_port,DIO_PIN7,DIO_PIN_OUTPUT);
	DIO_vsetPINDir(Cmd_port,EN,DIO_PIN_OUTPUT);
	DIO_vsetPINDir(Cmd_port,RW,DIO_PIN_OUTPUT);
	DIO_vsetPINDir(Cmd_port,RS,DIO_PIN_OUTPUT);
   	DIO_write(Cmd_port,RW,DIO_PIN_LOW);
	LCD_vSend_cmd(RETURN_HOME); //return home
	_delay_ms(10);
	LCD_vSend_cmd(FOUR_BITS); //4bit mode
	_delay_ms(1);
	LCD_vSend_cmd(CURSOR_ON_DISPLAY_ON);//display on cursor on
	_delay_ms(1);
	LCD_vSend_cmd(CLR_SCREEN);//clear the screen
	_delay_ms(10);
	LCD_vSend_cmd(ENTRY_MODE); //entry mode
	_delay_ms(1);
	#endif
}


static void send_falling_edge(void)
{
	DIO_write(Cmd_port,EN,DIO_PIN_HIGH);
	_delay_ms(2);
	DIO_write(Cmd_port,EN,DIO_PIN_LOW);
	_delay_ms(2);
}
void LCD_vSend_cmd(char cmd)
{
	#if defined eight_bits_mode
	DIO_write_port(Data_port,cmd);
	DIO_write(Cmd_port,RS,Rs_Cmd);
	send_falling_edge();
	
	#elif defined four_bits_mode
	write_high_nibble(Data_port,cmd>>4);
	DIO_write(Cmd_port,RS,Rs_Cmd);
	send_falling_edge();
	write_high_nibble(Data_port,cmd);
	DIO_write(Cmd_port,RS,Rs_Cmd);
	send_falling_edge();
	#endif
	_delay_ms(1);
}

void LCD_vSend_char(char data)
{
	#if defined eight_bits_mode
	DIO_write_port(Data_port,data);
	DIO_write(Cmd_port,RS,Rs_Data);
	send_falling_edge();
	
	#elif defined four_bits_mode
	write_high_nibble(Data_port,data>>4);
	DIO_write(Cmd_port,RS,Rs_Data);
	send_falling_edge();
	write_high_nibble(Data_port,data);
	DIO_write(Cmd_port,RS,Rs_Data);
	send_falling_edge();
	#endif
	_delay_ms(1);
}


void LCD_vSend_string(char *data)
{
	while((*data)!='\0')
	{
		LCD_vSend_char(*data);
		data++;
	}
}
void LCD_clearscreen()
{
	LCD_vSend_cmd(CLR_SCREEN);
	_delay_ms(10);
}
void LCD_movecursor(char row,char coloumn)
{
	char data ;
	if(row>2||row<1||coloumn>16||coloumn<1)
	{
		data=FIRST_ROW;
	}
	else if(row==1)
	{
		data=FIRST_ROW+coloumn-1 ;
	}
	else if (row==2)
	{
		data=SECOND_ROW+coloumn-1;
	}
	LCD_vSend_cmd(data);
	_delay_ms(1);
}
