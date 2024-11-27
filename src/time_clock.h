#ifndef _TIME_CLOCK_H
#define _TIME_CLOCK_H

#include<REGX52.H>
#include"LCD1602.h"
#include"key.h"
#include"timer_control.h"

sbit DS1302_SCLK = P3^6; 
sbit DS1302_IO = P3^4;
sbit Ds1302_CE = P3^5;

extern unsigned char time_clock[];

/**
 * @param key_number_result ѡ��ʱ�ӵ�ģʽ
 * @param time_select ��¼����ʱ�ӵ�λ��
 */
//extern unsigned char key_number_result ,time_select,time_count  ;

/**
 * @brief ��ʱ��ģ��д������
 * 
 * 
 * @param commend �Ե�Ƭ��������
 * @param data ��Ҫд�������
 * 
 * 
 */

void time_clock_wirte(unsigned char commend,unsigned char Data);
/**
 * @brief ��ʱ��ģ���ȡ����
 * 
 * @param Data ��ȡ�����ݴ����data������
 * 
 * @return ��������Ϊunsign char���� 
 */
unsigned char time_clock_rade(unsigned char commend);
/**
 * @brief ��ʱ��ģ����г�ʼ��
 */
void time_clock_init();

/**
 * @brief ��ʱ�ӽ��ж�ȡ
 * 
 * @param ��
 * 
 * @return ��
 */
void time_read();
/**
 * @brief ��ʱ��ģ�����д��
 * 
 * @param ��
 * 
 * @return ��
 */
void time_set();

/**
 * @brief ��ʾʱ�ӵ�ʱ��
 */
void time_show();
/**
 * @brief �ı�ʱ�ӵ�ʱ��
 */
void time_change();
#endif