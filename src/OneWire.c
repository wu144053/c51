#include<REGX52.H>

sbit OneWire_DQ = P3^7;
/**
 * @brief ��OneWirͨ��Э����г�ʼ��
 * 
 * @param OneWire_DQ ͨ�ŵ���������
 * 
 * @param AckBit ����Ƿ�Ӧ��
 * 
 * @return ��
 */

unsigned char OneWire_Init(){
    unsigned char AckBit,i;
    EA = 0;
    OneWire_DQ = 1;
    OneWire_DQ = 0;
    i = 227;while (--i);            //��ʱ500����
    OneWire_DQ = 1;
    i = 29;while (--i);             //�ȴ�15��60����ȴ��ӻ���Ӧ
    AckBit = OneWire_DQ ;
    i = 227;while (--i);            //��ʱ500����
    EA = 1;
    return AckBit;
}

/**
 * @brief �������ӻ�����1bit������
 * 
 * @param ��
 * 
 * @return ��
 */
void OneWire_send_bit (unsigned char Data){
    unsigned char i ;
    EA = 0;
    OneWire_DQ = 0;
    i = 3;while (--i);                  //��
    OneWire_DQ = Data ;
    i = 22;while (--i);
    OneWire_DQ = 1;
    EA = 1;
}
/**
 * @brief ������ȡ1bit������
 * 
 * @param OneWire_DQ ͨ������
 * 
 * @return ��
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
 * @brief ����һ���ֽڵ�����
 * 
 * @param Byte ��Ҫ���͵�����
 * 
 * @return ��
 * 
 */
void OneWire_send_Byte(unsigned char Byte){
    unsigned char i ;
    for (i = 0; i<8;i++){
        OneWire_send_bit(Byte & (0x01<<i));
    }
}
/**
 * @brief ��ȡһ���ֽڵ�����
 * 
 * @param  Byte �������ݣ����ء�
 * 
 * @return Byte ���ص��Ƕ�ȡ��������
 */

unsigned char OneWire_read_Byte(){
    unsigned char i ,Byte = 0x00;
    for (i = 0; i<8;i++){
        if(OneWire_read_bit()){Byte |= (0x01<<i);}
    }
    return Byte;
}