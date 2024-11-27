#include"AT24C02.h"
#define AT42C02_ADDRESS 0XA0
void AT24C02_WriteByte(unsigned char Work_address,unsigned char Data){
    I2C_start();
    I2C_sendByte(AT42C02_ADDRESS);
    I2C_recive_Ack();
    I2C_sendByte(Work_address);
    I2C_recive_Ack();
    I2C_sendByte(Data);
    I2C_recive_Ack();
    I2C_stop();
}

unsigned char AT24C02_ReadByte(unsigned char Work_address){
    unsigned char Data;
    I2C_start();
    I2C_sendByte(AT42C02_ADDRESS);
    I2C_recive_Ack();
    I2C_sendByte(Work_address);
    I2C_recive_Ack();
    I2C_start();
    I2C_sendByte(AT42C02_ADDRESS|0x01);
    I2C_recive_Ack();
    Data = I2C_reciveByte();
    I2C_sedAck(1);
    return Data;
}