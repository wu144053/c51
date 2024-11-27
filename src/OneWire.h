#ifndef _OneWire_H
#define _OneWire_H

unsigned char OneWire_Init();
void OneWire_send_bit (unsigned char Data);
unsigned char OneWire_read_bit();
void OneWire_send_Byte(unsigned char Byte);
unsigned char OneWire_read_Byte();

#endif