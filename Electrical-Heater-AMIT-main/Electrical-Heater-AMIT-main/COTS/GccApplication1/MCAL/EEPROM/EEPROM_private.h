/*****************************************/
/*	Author : George Emad				 */
/*	Date   : 26-12-2022   		   		 */
/*	Version: 0.1				         */
/*	File   :EEPROM_private.h	         */
/*****************************************/


#ifndef _EEPROM_PRIVATE_H_
#define _EEPROM_PRIVATE_H_

//#define EEARH *((volatile u8*)0x3F)
//#define EEARL *((volatile u8*)0x3E)
#define EEAR *((volatile unsigned short int*)0x3E)
#define EEDR *((volatile unsigned char*)0x3D)
#define EECR *((volatile unsigned char*)0x3C)

#endif