#ifndef _BUZZER_H
#define _BUZZER_H
#define SPEED 500

#include<REGX52.H>
#include<INTRINS.H>
#include"time.h"
#include"timer_control.h"

extern unsigned char frequen_select,music_select ;
extern unsigned char key_result;
sbit buzzer1 = P2^5;

enum Fre{
  P_,
  L1,
  L1_,
  L2,
  L2_,
  L3,
  L4,
  L4_,
  L5,
  L5_,
  L6,
  L6_,
  L7,
  M1,
  M1_,
  M2,
  M2_,
  M3,
  M4,
  M4_,
  M5,
  M5_,
  M6,
  M6_,
  M7,
  H1,
  H1_,
  H2,
  H2_,
  H3,
  H4,
  H4_,
  H5,
  H5_,
  H6,
  H6_,
  H7,
};
/**
 * @brief freqTable将音乐的频率存储在数组中
 */
extern unsigned int code freqTable[] ;

/**
 * @brief 天空之城的音乐
 */
extern unsigned char code music_sky [];
/**
 * @brief 蜂鸣器私有延时函数
 * @param 无
 * @return 无
 */
void buzzer_Delay500us(void);

/**
 * @brief ，蜂鸣器发声的时间函数
 * @param ms 蜂鸣器发生的时间，单位是ms
 * @return 无
 */
void time_buzzer(unsigned char ms);

/**
 * @brief 播放天空之城
 * @param 无
 * @return 无
 */
void rounting_music_sky();

#endif
