#include"time.h"

/**
 * @brief ��ʱһ�����������
 * 
 * @param ms ��ʱ�������� 
 * 
 * @return ��
 */
void time(unsigned int ms)	//@11.0592MHz
{
	unsigned char data i, j;
    unsigned int k;
    for (k = 0; k < ms; k++) {
        _nop_();
        i = 2;
        j = 199;
        do {
            while (--j);
        } while (--i);
    }
}


