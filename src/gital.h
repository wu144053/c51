#include<REGX52.H>
#include"key.h"
#include"AT24C02.h"

extern unsigned char digital_num[];
extern unsigned char minute ,second ,min_second ;
/**
 * @param run_flag ��run_flagΪ0ʱ��ʼ��ʱ����Ϊ1ʱֹͣ��ʱ
 */
extern unsigned char run_flag;
/**
 * @brief �����������ʾ����
 * 
 * @param local_number ��Ҫ��ʾ���ֵ�λ��
 * @param num ��Ҫ��ʾ������
 * 
 * @return ��
 */
void digital_scan(unsigned char local_number ,unsigned char num);


/**
 * @brief �����������ʾ���֣����ն�ɨ��
 * 
 * @param �� ��Ҫ��ʾ��������ϵ�λ��
 * @param ��  ��Ҫ��ʾ��������ϵ�����
 * 
 * @return �� 
 */
void digital_loop(void);

/**
 * @brief ѡ����local_numberλ����ʲô����
 * 
 * @param local_number ��Ҫ��������ݵ�λ��
 * 
 * @param num ���������
 * 
 * @return ��
 */
void gital_num_set(unsigned char location ,unsigned char Number);

/**
 * @brief �����������ʾ5201314
 */
void run_520(unsigned char* num);

/**
 * @brief ���
 * @param minute ��
 * @param second ��
 * @param min_second �ٷ�֮һ��
 * 
 * @return ��
 */
void sec_loop();
void clock();