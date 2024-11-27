#ifndef _KEY_H
#define _KEY_H
#include"time.h"    
#include<REGX52.H>
/**
 * @brief 鑾峰彇鐙珛鎸夐敭缂栫爜
 * 
 * @param 鏃? 
 * 
 * @return 鎸変笅鎸夐敭缂栫爜鐨勮寖鍥?1~4锛屾棤鎸夐敭鎸変笅鏃惰繑鍥炲�间负0
 */
unsigned char key_number();

/**
 * @brief 检测按键有没有被按下
 * @param temp 临时存储数据 
 * @param Key_key_number 检测按键有没有被按下
 * @return 返回temp如过被按下1则返回1按下2则返回2按下3则返回3按下4则返回4
 */

unsigned char key();

/**
 * @brief 按键定时器每二十毫秒就检测一次看按键是否被按下
 * @param last_key 存储上一次按键的数值，如果为零就代表按键没有被按下，如果非零就代表按键已经被按下
 * @param now_key 存储现在按键的数值，如果为零就代表没有被按下，当last_key为非零，now_key 为0时就代表按键被按下又松开
 * @return 无
 */
void key_loop(void);
#endif