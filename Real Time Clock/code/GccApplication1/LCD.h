/*
 * LCD.h
 *
 */ 

#ifndef LCD_H_
#define LCD_H_
#include "LCD_CONFIG.h"
#include "DIO.h"
#define CLR_SCREEN 0x01
#define CURSOR_ON_DISPLAY_ON 0x0e
#define RETURN_HOME 0x02
#define ENTRY_MODE 0x06
#if defined four_bits_mode
#define EN DIO_PIN0     // SUPPORTS AMIT KIT   IF =3
#define RS DIO_PIN2
#define RW DIO_PIN1
#define FOUR_BITS 0x28
#elif defined eight_bits_mode
#define EN DIO_PIN0
#define RS DIO_PIN1
#define RW DIO_PIN2
#define EIGHT_BITS 0x38
#endif


#define Rs_Cmd     0
#define Rs_Data    1
#define RW_WRITE   0
#define RW_READ    1
#define FIRST_ROW  0x80
#define SECOND_ROW 0xc0

void LCD_vInit(void);
static void send_falling_edge(void);
void LCD_vSend_cmd(char cmd);
void LCD_vSend_char(char data);
void LCD_vSend_string(char *data);
void LCD_clearscreen();
void LCD_movecursor(char row,char coloumn);

#endif /* LCD_H_ */