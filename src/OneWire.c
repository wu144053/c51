#include<REGX52.H>

sbit OneWire_DQ = P3^7;
/**
 * @brief 对OneWir通信协议进行初始化
 * 
 * @param OneWire_DQ 通信的数据总线
 * 
 * @param AckBit 检测是否应答
 * 
 * @return 无
 */

unsigned char OneWire_Init(){
    unsigned char AckBit,i;
    EA = 0;
    OneWire_DQ = 1;
    OneWire_DQ = 0;
    i = 227;while (--i);            //延时500毫秒
    OneWire_DQ = 1;
    i = 29;while (--i);             //等待15—60毫秒等待从机响应
    AckBit = OneWire_DQ ;
    i = 227;while (--i);            //延时500毫秒
    EA = 1;
    return AckBit;
}

/**
 * @brief 主机给从机发送1bit的数据
 * 
 * @param 无
 * 
 * @return 无
 */
void OneWire_send_bit (unsigned char Data){
    unsigned char i ;
    EA = 0;
    OneWire_DQ = 0;
    i = 3;while (--i);                  //在
    OneWire_DQ = Data ;
    i = 22;while (--i);
    OneWire_DQ = 1;
    EA = 1;
}
/**
 * @brief 主机读取1bit的数据
 * 
 * @param OneWire_DQ 通信总线
 * 
 * @return 无
 */

unsigned char OneWire_read_bit(){
    unsigned char Data,i;
    EA = 0;
    OneWire_DQ = 0;
    i= 2;while(--i);
    OneWire_DQ = 1;
    i = 2;while(--i);
    Data = OneWire_DQ;
    i = 29;while (i--);
    EA = 1;
    return Data;
} 

/**
 * @brief 发送一个字节的数据
 * 
 * @param Byte 将要发送的数据
 * 
 * @return 无
 * 
 */
void OneWire_send_Byte(unsigned char Byte){
    unsigned char i ;
    for (i = 0; i<8;i++){
        OneWire_send_bit(Byte & (0x01<<i));
    }
}
/**
 * @brief 读取一个字节的数据
 * 
 * @param  Byte 接收数据，返回。
 * 
 * @return Byte 返回的是读取到的数据
 */

unsigned char OneWire_read_Byte(){
    unsigned char i ,Byte = 0x00;
    for (i = 0; i<8;i++){
        if(OneWire_read_bit()){Byte |= (0x01<<i);}
    }
    return Byte;
}