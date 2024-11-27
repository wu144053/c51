#include"Uart.h"
void Uartinit(void){
    SCON = 0x50;
    PCON |=0x80;                //ʹ�ܲ����ʵı��ٷ���
    TMOD &= 0X0F;                //����ʱ��һ����
    TMOD |= 0X20;                //�趨ʱ��Ϊ�Զ���װģʽ
    TL1 = 0xF4;                  //���ö�ʱ����ֵ
    TH1 = 0XF4;                  //���ö�ʱ����װֵ
    ET1 = 0;                     //��ֹ�ж�������
    TR1 = 1;                     //����ʱ����Ϊ1
    EA = 1;
    ES = 1;
}

void Uart_byte(unsigned char byte){
    SBUF = byte;
    while(TI == 0);
    TI = 0;
}