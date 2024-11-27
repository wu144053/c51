#include"Uart.h"
void Uartinit(void){
    SCON = 0x50;
    PCON |=0x80;                //使能波特率的倍速翻倍
    TMOD &= 0X0F;                //将定时器一置零
    TMOD |= 0X20;                //设定时器为自动重装模式
    TL1 = 0xF4;                  //设置定时器初值
    TH1 = 0XF4;                  //设置定时器重装值
    ET1 = 0;                     //禁止中断器启动
    TR1 = 1;                     //将定时器设为1
    EA = 1;
    ES = 1;
}

void Uart_byte(unsigned char byte){
    SBUF = byte;
    while(TI == 0);
    TI = 0;
}