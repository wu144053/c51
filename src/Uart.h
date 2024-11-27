#ifndef _UART_H
#define _UART_H
#include"time.h"
#include<REGX52.H>
#include"timer_control.h"

void Uartinit(void);
void Uart_byte(unsigned char byte);
#endif
