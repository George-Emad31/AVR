/*
 * Keypad_driver_CONFIG.h
 *
 * Created: 4/25/2024 11:33:34 AM
 *  Author: George
 */ 


#ifndef KEYPAD_DRIVER_CONFIG_H_
#define KEYPAD_DRIVER_CONFIG_H_

#define NOTPRESSED 0xff 
#define PRESSED    0
 /* MACROS FOR KPD COLUMNS PORTS & PINS CONFIGURATION */

 //input + PULL UP
 //#define KPD_COLS_PORT        DIO_PORT D
 #define KPD_COL0_PIN           DIO_PIN4
 #define KPD_COL1_PIN           DIO_PIN5
 #define KPD_COL2_PIN           DIO_PIN6
 #define KPD_COL3_PIN           DIO_PIN7

 /* MACROS FOR KPD ROWS PORTS & PINS CONFIGURATION */
 
 //output  
 //#define KPD_ROWS_PORT        DIO_PORT D
 #define KPD_ROW0_PIN           DIO_PIN0
 #define KPD_ROW1_PIN           DIO_PIN1
 #define KPD_ROW2_PIN           DIO_PIN2
 #define KPD_ROW3_PIN           DIO_PIN3



#endif /* KEYPAD_DRIVER_CONFIG_H_ */