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
 * @param key_number_result 选择时钟的模式
 * @param time_select 记录更改时钟的位置
 */
//extern unsigned char key_number_result ,time_select,time_count  ;

/**
 * @brief 向时钟模块写入数据
 * 
 * 
 * @param commend 对单片机的命令
 * @param data 将要写入的数据
 * 
 * 
 */

void time_clock_wirte(unsigned char commend,unsigned char Data);
/**
 * @brief 向时钟模块读取数据
 * 
 * @param Data 读取的数据存放在data变量中
 * 
 * @return 返回类型为unsign char类型 
 */
unsigned char time_clock_rade(unsigned char commend);
/**
 * @brief 对时钟模块进行初始化
 */
void time_clock_init();

/**
 * @brief 对时钟进行读取
 * 
 * @param 无
 * 
 * @return 无
 */
void time_read();
/**
 * @brief 对时钟模块进行写入
 * 
 * @param 无
 * 
 * @return 空
 */
void time_set();

/**
 * @brief 显示时钟的时间
 */
void time_show();
/**
 * @brief 改变时钟的时间
 */
void time_change();
#endif