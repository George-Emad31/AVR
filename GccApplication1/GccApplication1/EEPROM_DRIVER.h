/*
 * EEPROM_DRIVER.h
 *
 * Created: 4/14/2024 7:07:14 PM
 *  Author: georg
 */ 


#ifndef EEPROM_DRIVER_H_
#define EEPROM_DRIVER_H_

#include "DIO.h"
/*
Function Name        : EEPROM_write
Function Returns     : void
Function Arguments   : unsigned short address, unsigned char data
Function Description :  write one byte to the given  address.
*/
void EEPROM_WRITE(unsigned short address , unsigned char data);


/*
Function Name        : EEPROM_read
Function Returns     : unsigned char
Function Arguments   :  unsigned short address
Function Description :  read one byte from the given  address.
*/


unsigned char EEPROM_READ(const unsigned short address);





#endif /* EEPROM_DRIVER_H_ */