#ifndef _KEY_H
#define _KEY_H
#include"time.h"    
#include<REGX52.H>
/**
 * @brief 获取独立按键编码
 * 
 * @param �? 
 * 
 * @return 按下按键编码的范�?1~4，无按键按下时返回值为0
 */
unsigned char key_number();

/**
 * @brief ��ⰴ����û�б�����
 * @param temp ��ʱ�洢���� 
 * @param Key_key_number ��ⰴ����û�б�����
 * @return ����temp���������1�򷵻�1����2�򷵻�2����3�򷵻�3����4�򷵻�4
 */

unsigned char key();

/**
 * @brief ������ʱ��ÿ��ʮ����ͼ��һ�ο������Ƿ񱻰���
 * @param last_key �洢��һ�ΰ�������ֵ�����Ϊ��ʹ�����û�б����£��������ʹ������Ѿ�������
 * @param now_key �洢���ڰ�������ֵ�����Ϊ��ʹ���û�б����£���last_keyΪ���㣬now_key Ϊ0ʱ�ʹ��������������ɿ�
 * @return ��
 */
void key_loop(void);
#endif