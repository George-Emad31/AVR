/*
 * spi_driver.h
 *
 * Created: 6/7/2024 12:14:16 PM
 *  Author: George
 */ 


#ifndef SPI_DRIVER_H_
#define SPI_DRIVER_H_
#include "DIO.h"

void SPI_MasterInit(void);
void SPI_SlaveInit(void);
u8 SPI_MasterTransmitchar(u8 Data);
u8 SPI_SlaveReceivechar(u8 Data);
void SPI_MasterTransmitstring(u8*ptr);

#endif /* SPI_DRIVER_H_ */