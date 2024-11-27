#ifndef _TIMER_IR_H
#define _TIMER_TR_H

void timer_ir_init();
void timer_setcounter(unsigned char value);
unsigned int time_read_value();
void timer_rounting(unsigned char Flag);

#endif