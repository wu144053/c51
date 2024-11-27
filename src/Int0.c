#include"Int0.h"

/**
 * @brief 外部中断初始化
 * 
 * @param 无
 * 
 * @return 无
 */
void int0_init(){
    IT0 = 1;                //设置为下降沿中断
    IE0 = 0;                //清除外部中断为零的中断位
    EX0 = 1;                //中断使能
    EA = 1;                 //全部中断使能
    PX0 = 1;                //设置外部中断为最高优先级
}