#ifndef _IR_H_
#define _IR_H_
#include<REGX52.H>
#include"timer0_IR.h"
#include"Int0.h"

void IR_init(void );
unsigned  char IR_getFlag();
unsigned char IR_getReaptFlag();
unsigned char IR_getaddress();
unsigned char IR_getCommend();

#endif