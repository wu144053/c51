#ifndef _AT24C02_H
#define _AT24C02_H

#include"I2C.h"
#include<REGX52.H>

/**
 * @brief ������Dataд�뵽AT42C02�洢оƬ��Work_address��ַ��
 * @param Data ��Ҫ�洢������
 * @param Work_address ��Ҫд�����ݵĵ�ַ
 * @return ��
 */
void AT24C02_WriteByte(unsigned char Work_address,unsigned char Data);

/**
 * @brief ��ȡAT24C02��Work_addressλ�õ����� 
 * @param Work_address ��Ҫ��ȡ�ֽڵĵ�ַ
 * @return ���ض�ȡ��������
 *
 */
unsigned char AT24C02_ReadByte(unsigned char Work_address);
#endif