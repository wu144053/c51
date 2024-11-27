#include<REGX52.H>
/**
 * @brief 定时器功能，初始化定时器，默认定时器没有打开
 * 
 * @param 无
 * 
 * @return 无
 */
void timer_ir_init(){
    TMOD &= 0Xf0;               //设置定时器模式
    TMOD |= 0x01;               //设置定时器模式
    TF0 = 0;                    //清除TFO标志
    TR0 = 0 ;                   //定时器不开始计时
    TH0 = 0x00;                 //设置定时器初值
    TL0 = 0x00;                 //设置定时器初值
}

/**
 * @brief 设置定时器的初始值
 * 
 * @param value 定时器的初始值
 * 
 * @return 无
 */
void timer_setcounter(unsigned char value){
    TH0 = value /256;
    TL0 = value %256;
}

/**
 * @brief 返回计时器的时间
 * 
 * @param 无
 * 
 * @return 计时器的时间
 */
unsigned int time_read_value(){
    return (TH0<<8) | TL0;
}

/**
 * @brief 计时器开始
 * 
 * @param Flag 给1代表计时开始 
 * 
 * @return 无
 */
void timer_rounting(unsigned char Flag){
    TR0 = Flag;
}