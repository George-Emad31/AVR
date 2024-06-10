/*
 * DIO_CONFIG.h
 *
 * Created: 4/22/2024 6:37:58 PM
 *  Author: George
 */ 


#ifndef DIO_CONFIG_H_
#define DIO_CONFIG_H_
/************************************************************************/
/*                           MACROS                                     */
/************************************************************************/
 /* STD_TYPES*/
 typedef unsigned char            u8;
 typedef signed char              s8;

 typedef unsigned short int       u16;
 typedef signed short int         s16;

 typedef unsigned long int        u32;
 typedef signed long int          s32;

 #define NULL                     0


			 /*************** MACROS FOR PIN ***************/
/* Macros For Pin Id */
 #define DIO_PIN0           0
 #define DIO_PIN1           1
 #define DIO_PIN2           2
 #define DIO_PIN3           3
 #define DIO_PIN4           4
 #define DIO_PIN5           5
 #define DIO_PIN6           6
 #define DIO_PIN7           7

 /* Macros For Pin Direction */
 #define DIO_PIN_INPUT      0
 #define DIO_PIN_OUTPUT     1

 /* Macros For Pin state */
 #define DIO_PIN_LOW        0
 #define DIO_PIN_HIGH       1


 /*************** MACROS FOR PORT ***************/

 /* Macros For Port Id */
 #define DIO_PORTA    0
 #define DIO_PORTB    1
 #define DIO_PORTC    2
 #define DIO_PORTD    3

 /* Macros For Port Direction */
 #define DIO_PORT_INPUT      0x00
 #define DIO_PORT_OUTPUT     0xff

 /* Macros For Port state */
 #define DIO_PORT_LOW        0x00
 #define DIO_PORT_HIGH       0xff






#endif /* DIO_CONFIG_H_ */