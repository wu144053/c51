#include"I2C.h"

/**
 * @param I2C_SCL ͨ�ŵ�ʱ��
 * @param I2C_SDA ͨ��Ҫ���������
 */
sbit I2C_SCL = P2^1;
sbit I2C_SDA = P2^0;

/**
 * @brief I2C��ʼ
 * @param ��
 * @return ��
 */
void I2C_start(){
    I2C_SDA = 1;
    I2C_SCL  = 1;
    I2C_SDA = 0;
    I2C_SCL = 0;  
}

/**
 * @brief I2C ����ֹ
 * @param ��
 * @return ��
 */
void I2C_stop(){
    I2C_SDA = 0;
    I2C_SCL = 1;
    I2C_SDA = 1;
}

/**
 * @brief ����8bit������
 * @param Byte ��Ҫ�����8λ����
 * @return ��
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
 * @brief ����һ�ֽڵ�����
 * @param Byte�����յ������ݴ洢��Byte�з���
 * @return Byte���յ�������
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
 * @brief ����Ӧ��
 * @param ack ���͵�Ӧ���źţ�Ӧ��0����Ӧ��1
 * @return ��
 */
void I2C_sedAck(unsigned char ack){
    I2C_SDA = ack;
    I2C_SCL = 1;
    I2C_SCL = 0;
}

/**
 * @brief ����Ӧ��
 * @param AckBit ���յ���Ӧ�����ݣ�1�����Ӧ��0����Ӧ��
 * @return AckBit ���ܵ���Ӧ��λ
 */
unsigned char I2C_recive_Ack (void ){
    unsigned char AckBit;
    I2C_SDA = 1;
    I2C_SCL = 1;
    AckBit = I2C_SDA;
    I2C_SCL = 0;
    return AckBit;
}