#include<REGX52.H>
/**
 * @brief ��ʱ�����ܣ���ʼ����ʱ����Ĭ�϶�ʱ��û�д�
 * 
 * @param ��
 * 
 * @return ��
 */
void timer_ir_init(){
    TMOD &= 0Xf0;               //���ö�ʱ��ģʽ
    TMOD |= 0x01;               //���ö�ʱ��ģʽ
    TF0 = 0;                    //���TFO��־
    TR0 = 0 ;                   //��ʱ������ʼ��ʱ
    TH0 = 0x00;                 //���ö�ʱ����ֵ
    TL0 = 0x00;                 //���ö�ʱ����ֵ
}

/**
 * @brief ���ö�ʱ���ĳ�ʼֵ
 * 
 * @param value ��ʱ���ĳ�ʼֵ
 * 
 * @return ��
 */
void timer_setcounter(unsigned char value){
    TH0 = value /256;
    TL0 = value %256;
}

/**
 * @brief ���ؼ�ʱ����ʱ��
 * 
 * @param ��
 * 
 * @return ��ʱ����ʱ��
 */
unsigned int time_read_value(){
    return (TH0<<8) | TL0;
}

/**
 * @brief ��ʱ����ʼ
 * 
 * @param Flag ��1�����ʱ��ʼ 
 * 
 * @return ��
 */
void timer_rounting(unsigned char Flag){
    TR0 = Flag;
}