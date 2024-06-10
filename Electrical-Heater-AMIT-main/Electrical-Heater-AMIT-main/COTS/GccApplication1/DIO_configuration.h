/*****************************************/
/*	Author : Khaled Mohsen				 */
/*	Date   : 6-11-2022   		   		 */
/*	Version: 0.1				         */
/*	File   : DIO_configuration.h		 */
/*****************************************/


/*
	for configuration
*/
#ifndef _DIO_CONFIGURATION_H_
#define _DIO_CONFIGURATION_H_

#define DIO_u8_DIR_PINA0	 DIO_u8_INPUT
#define DIO_u8_DIR_PINA1     DIO_u8_INPUT
#define DIO_u8_DIR_PINA2     DIO_u8_INPUT
#define DIO_u8_DIR_PINA3     DIO_u8_INPUT
#define DIO_u8_DIR_PINA4     DIO_u8_OUTPUT
#define DIO_u8_DIR_PINA5     DIO_u8_OUTPUT
#define DIO_u8_DIR_PINA6     DIO_u8_OUTPUT
#define DIO_u8_DIR_PINA7     DIO_u8_OUTPUT
									
									
#define DIO_u8_DIR_PINB0	 DIO_u8_INPUT
#define DIO_u8_DIR_PINB1     DIO_u8_OUTPUT
#define DIO_u8_DIR_PINB2     DIO_u8_OUTPUT
#define DIO_u8_DIR_PINB3     DIO_u8_OUTPUT
#define DIO_u8_DIR_PINB4     DIO_u8_INPUT
#define DIO_u8_DIR_PINB5     DIO_u8_INPUT
#define DIO_u8_DIR_PINB6     DIO_u8_INPUT
#define DIO_u8_DIR_PINB7     DIO_u8_INPUT
									
									
#define DIO_u8_DIR_PINC0	 DIO_u8_OUTPUT
#define DIO_u8_DIR_PINC1     DIO_u8_OUTPUT
#define DIO_u8_DIR_PINC2     DIO_u8_OUTPUT
#define DIO_u8_DIR_PINC3     DIO_u8_OUTPUT
#define DIO_u8_DIR_PINC4     DIO_u8_INPUT
#define DIO_u8_DIR_PINC5     DIO_u8_INPUT
#define DIO_u8_DIR_PINC6     DIO_u8_INPUT
#define DIO_u8_DIR_PINC7     DIO_u8_INPUT
									
#define DIO_u8_DIR_PIND0	 DIO_u8_INPUT
#define DIO_u8_DIR_PIND1     DIO_u8_INPUT
#define DIO_u8_DIR_PIND2     DIO_u8_INPUT
#define DIO_u8_DIR_PIND3     DIO_u8_INPUT
#define DIO_u8_DIR_PIND4     DIO_u8_INPUT
#define DIO_u8_DIR_PIND5     DIO_u8_INPUT
#define DIO_u8_DIR_PIND6     DIO_u8_INPUT
#define DIO_u8_DIR_PIND7     DIO_u8_INPUT

#define DIO_u8_PORTA_DIR     CONC_BIT(DIO_u8_DIR_PINA7,DIO_u8_DIR_PINA6,DIO_u8_DIR_PINA5,DIO_u8_DIR_PINA4,DIO_u8_DIR_PINA3,DIO_u8_DIR_PINA2,DIO_u8_DIR_PINA1,DIO_u8_DIR_PINA0)
#define DIO_u8_PORTB_DIR 	 CONC_BIT(DIO_u8_DIR_PINB7,DIO_u8_DIR_PINB6,DIO_u8_DIR_PINB5,DIO_u8_DIR_PINB4,DIO_u8_DIR_PINB3,DIO_u8_DIR_PINB2,DIO_u8_DIR_PINB1,DIO_u8_DIR_PINB0)
#define DIO_u8_PORTC_DIR     CONC_BIT(DIO_u8_DIR_PINC7,DIO_u8_DIR_PINC6,DIO_u8_DIR_PINC5,DIO_u8_DIR_PINC4,DIO_u8_DIR_PINC3,DIO_u8_DIR_PINC2,DIO_u8_DIR_PINC1,DIO_u8_DIR_PINC0)
#define DIO_u8_PORTD_DIR     CONC_BIT(DIO_u8_DIR_PIND7,DIO_u8_DIR_PIND6,DIO_u8_DIR_PIND5,DIO_u8_DIR_PIND4,DIO_u8_DIR_PIND3,DIO_u8_DIR_PIND2,DIO_u8_DIR_PIND1,DIO_u8_DIR_PIND0)

#endif