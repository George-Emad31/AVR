/*
 * I2C.h
 *
 * Created: 6/5/2024 11:58:40 AM
 *  Author: George
 */ 


#ifndef I2C_H_
#define I2C_H_
#include "DIO.h"
void I2C_Master_init(u32 SCL_CLOCK,u8 Prescaler);
void I2C_start(void);
void I2C_write_address(u8 address);
void I2C_write_data(u8 data);
void I2C_stop(void);
void I2C_set_address(u8 address);
u8 I2C_slave_read(void);
#endif /* I2C_H_ */