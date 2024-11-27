#ifndef _I2C_H
#define _I2C_H

#include<REGX52.H>
#include"LCD1602.h"
#include"time.h"

void I2C_start();
void I2C_stop();
void I2C_sendByte(unsigned char Byte);
unsigned char I2C_reciveByte(void );
void I2C_sedAck(unsigned char ack);
unsigned char I2C_recive_Ack( void);


#endif