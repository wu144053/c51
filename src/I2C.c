#include"I2C.h"

/**
 * @param I2C_SCL 通信的时钟
 * @param I2C_SDA 通信要传输的数据
 */
sbit I2C_SCL = P2^1;
sbit I2C_SDA = P2^0;

/**
 * @brief I2C起始
 * @param 无
 * @return 无
 */
void I2C_start(){
    I2C_SDA = 1;
    I2C_SCL  = 1;
    I2C_SDA = 0;
    I2C_SCL = 0;  
}

/**
 * @brief I2C 的终止
 * @param 无
 * @return 无
 */
void I2C_stop(){
    I2C_SDA = 0;
    I2C_SCL = 1;
    I2C_SDA = 1;
}

/**
 * @brief 传输8bit的数据
 * @param Byte 将要传输的8位数据
 * @return 无
 */
void I2C_sendByte(unsigned char Byte){
    unsigned char i ;
    for(i = 0 ; i < 8 ; i++){
        I2C_SDA = Byte&(0X80>>i);
        I2C_SCL = 1;
        I2C_SCL = 0;
    }
}

/**
 * @brief 接收一字节的数据
 * @param Byte将接收到的数据存储在Byte中返回
 * @return Byte接收到的数据
 * 
 */
unsigned char I2C_reciveByte(void ){
    unsigned char i,Byte = 0X00;
    I2C_SDA = 1; 
    for( i = 0 ;i < 8 ; i++ ){
        I2C_SCL = 1;
        if(I2C_SDA){Byte |= (0X80>>i);}
        I2C_SCL = 0;
    }
    return Byte;
}

/**
 * @brief 发送应答
 * @param ack 发送的应答信号，应答0，非应答1
 * @return 无
 */
void I2C_sedAck(unsigned char ack){
    I2C_SDA = ack;
    I2C_SCL = 1;
    I2C_SCL = 0;
}

/**
 * @brief 接收应答
 * @param AckBit 接收到的应答数据，1代表非应答，0代表应答
 * @return AckBit 接受到的应答位
 */
unsigned char I2C_recive_Ack (void ){
    unsigned char AckBit;
    I2C_SDA = 1;
    I2C_SCL = 1;
    AckBit = I2C_SDA;
    I2C_SCL = 0;
    return AckBit;
}