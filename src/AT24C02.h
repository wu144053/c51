#ifndef _AT24C02_H
#define _AT24C02_H

#include"I2C.h"
#include<REGX52.H>

/**
 * @brief 将数据Data写入到AT42C02存储芯片的Work_address地址中
 * @param Data 将要存储的数据
 * @param Work_address 将要写入数据的地址
 * @return 无
 */
void AT24C02_WriteByte(unsigned char Work_address,unsigned char Data);

/**
 * @brief 读取AT24C02中Work_address位置的数据 
 * @param Work_address 将要读取字节的地址
 * @return 返回读取到的数据
 *
 */
unsigned char AT24C02_ReadByte(unsigned char Work_address);
#endif