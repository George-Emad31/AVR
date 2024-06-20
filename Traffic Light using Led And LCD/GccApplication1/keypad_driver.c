/*
 * keypad_driver.c
 *
 * Created: 2/24/2024 4:06:22 PM
 *  Author: GEORGE EMAD
 */ 


 #include "keypad_driver.h"
 #define KPD_ROWS_PORT 'D'
 #define KPD_COLS_PORT 'D'
 void keypad_vInit()
 {    // ROWS  -> OUTPUT 
	 DIO_vsetPINDir(KPD_ROWS_PORT,KPD_ROW0_PIN,DIO_PIN_OUTPUT);
	 DIO_vsetPINDir(KPD_ROWS_PORT,KPD_ROW1_PIN,DIO_PIN_OUTPUT);
	 DIO_vsetPINDir(KPD_ROWS_PORT,KPD_ROW2_PIN,DIO_PIN_OUTPUT);
	 DIO_vsetPINDir(KPD_ROWS_PORT,KPD_ROW3_PIN,DIO_PIN_OUTPUT);
	 // COL -> INPUT
	 DIO_vsetPINDir(KPD_COLS_PORT,KPD_COL0_PIN,DIO_PIN_INPUT);
	 DIO_vsetPINDir(KPD_COLS_PORT,KPD_COL1_PIN,DIO_PIN_INPUT);
	 DIO_vsetPINDir(KPD_COLS_PORT,KPD_COL2_PIN,DIO_PIN_INPUT);
	 DIO_vsetPINDir(KPD_COLS_PORT,KPD_COL3_PIN,DIO_PIN_INPUT);
	 // COL -> INPUT + ACTIVE INTERNAL PULLUP
	 DIO_vconnectpullup(KPD_COLS_PORT,KPD_COL0_PIN,DIO_PIN_HIGH);
	 DIO_vconnectpullup(KPD_COLS_PORT,KPD_COL1_PIN,DIO_PIN_HIGH);
	 DIO_vconnectpullup(KPD_COLS_PORT,KPD_COL2_PIN,DIO_PIN_HIGH);
	 DIO_vconnectpullup(KPD_COLS_PORT,KPD_COL3_PIN,DIO_PIN_HIGH);
	  
 }
 u16 keypad_u8check_press()
{
	 u16 arr[4][4]={{'7','8','9','/'},{'4','5','6','*'},{'1','2','3','-'},{'A','0','=','+'}};
	 u16 row,coloumn;
	// u8 x;
	 u16 returnval=NOTPRESSED;
	 for(row=0;row<=3;row++)
	 {   // ROWS  -> OUTPUT WITH LOGIC 1
		DIO_write(KPD_ROWS_PORT,KPD_ROW0_PIN,DIO_PIN_HIGH);
		DIO_write(KPD_ROWS_PORT,KPD_ROW1_PIN,DIO_PIN_HIGH);
		DIO_write(KPD_ROWS_PORT,KPD_ROW2_PIN,DIO_PIN_HIGH);
		DIO_write(KPD_ROWS_PORT,KPD_ROW3_PIN,DIO_PIN_HIGH);
		// INTIRATION FOR ROW CHECK
		DIO_write(KPD_ROWS_PORT,row,DIO_PIN_LOW);
	
		for(coloumn=0;coloumn<=3;coloumn++)
		{
			//x=DIO_u8read('D',(coloumn+KPD_COL0_PIN)); 
			// IF THE PIN OF FIRST COL IS CONNECTED FROM PIN 4 IF NOT IT WILL + 0
			if(DIO_u8read(KPD_COLS_PORT,(coloumn+KPD_COL0_PIN))==PRESSED)
			 {
				 returnval=arr[row][coloumn];
				 break;
			 }  
		}	
     		if(returnval==PRESSED)
	     	 {  // BREAK ROM MAIN FOR LOOP
			break;
		     }
	}	 
	 return returnval ;	 
}