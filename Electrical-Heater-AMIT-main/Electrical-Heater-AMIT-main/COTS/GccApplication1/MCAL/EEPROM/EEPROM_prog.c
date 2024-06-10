/*****************************************/
/*	Author : George Emad				 */
/*	Date   : 26-12-2022   		   		 */
/*	Version: 0.1				         */
/*	File   :EEPROM_private.h	         */
/*****************************************/

#include "EEPROM_private.h"

void EEPROM_write(unsigned short int Address,unsigned char Data)
{
	//wait for completion of previous write
	while(EECR & (1<<1));
	//write address to address register and write data to data register
	EEAR = Address;
	EEDR = Data;
	//write logic one to EEMWE(EEPROM master write enable)
	EECR |= (1<<2);
	//start EEPROM write by setting EEWE(EEPROM write enable)
	EECR |= (1<<1);
}

unsigned char EEPROM_read(unsigned short int Address)
{
	//wait for completion of previous write
	while(EECR & (1<<1));
	//put address EEPROM address register
	EEAR = Address;
	//start EEPROM read by setting EERE(EEPROM read enable)
	EECR |= (1<<0);
	//return data from EEPROM data register
	return EEDR;
}