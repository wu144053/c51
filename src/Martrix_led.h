#ifndef _MARTRIX_LED_H
#define _MARTRIX_LED_H
#include<REGX52.H>
#include"time.h"
#include"REGX52.H"

/**
 * @brief 74HC95д��һ���ֽ�
 * @param byte��Ҫд����ֽ�
 * @param colounmд�����
 * @return 0
 */
sbit SER = P3^4;                        //SER
sbit RCK = P3^5;                        //RCLK
sbit SCK = P3^6;                        //SCLK
#define Martrix_led_colounm P0

void _74HC59_write(unsigned char DATA);
void Martix_led(unsigned char colounm ,unsigned DATA);
void Martix_led_xiaolian();
void Martrix_led_HELLO();
void Martrix_expression_fun();
#endif