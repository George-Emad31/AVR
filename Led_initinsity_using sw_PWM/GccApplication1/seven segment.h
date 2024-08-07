/*
 * seven_segment.h
 *
 * Created: 4/8/2024 7:33:20 PM
 *  Author: georg
 */ 


#ifndef SEVEN SEGMENT_H_
#define SEVEN SEGMENT_H_

#include "DIO.h" 

void seven_seg_vinit(unsigned char portname );
void seven_seg_vinit_BCD(unsigned char portname ,unsigned char nibble);


void seven_segment_write_Cathode (unsigned char portname ,unsigned char Number);
void seven_segment_write_anode (unsigned char portname ,unsigned char Number);

void seven_segment_write_Cathode_BCD(unsigned char portname,unsigned char nibbleVal ,unsigned char numberVal);
void seven_segment_write_anode_BCD(unsigned char portname,unsigned char nibbleVal ,unsigned char numberVal);

#endif /* SEVEN SEGMENT_H_ */