
/*
 * Keypad_driver.h
 *
 * Created: 4/25/2024 11:08:01 AM
 *  Author: George
 */ 


#ifndef KEYPAD_DRIVER_H_
#define KEYPAD_DRIVER_H_
#include "DIO.h"
#include "Keypad_driver_CONFIG.h"
/************************************************************************/
/************************** APIS PROTO TYPES ****************************/
/************************************************************************/

 void keypad_vInit();

 u16 keypad_u8check_press();
 

#endif /* KEYPAD_DRIVER_H_ */