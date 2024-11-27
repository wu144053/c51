#include"time.h"

/**
 * @brief 延时一毫秒的整数倍
 * 
 * @param ms 延时几个毫秒 
 * 
 * @return 无
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


