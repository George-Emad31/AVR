/*****************************************/
/*	Author : George Emad				 */
/*	Date   : 23-12-2022   		   		 */
/*	Version: 0.1				         */
/*	File   :EEPROM_private.h	         */
/*****************************************/


#ifndef _EEPROM_INT_H_
#define _EEPROM_INT_H_

void EEPROM_write(unsigned short int Address,unsigned char Data);
unsigned char EEPROM_read(unsigned short int Address);

#endif