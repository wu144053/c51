#include"timer_control.h"

/**
 * @brief ��ʱ��100us��ÿ100΢���ж�һ��
 * @param ��
 * @return ��
 */
void time_init(){
    TMOD &= 0Xf0;
    TMOD |= 0x01;
    TF0 = 0;
    TR0 = 1 ;
    TH0 = 0xFF;
    TL0 = 0xA4;
    ET0 = 1;
    EA = 1;
    PT0 =0;
}

/*void T0_timeer_rounting()  interrupt 1{
    static unsigned int T0_count = 0;
    TH0 = 0xA4;
    TL0 = 0xFF;
    T0_count++;
    if(T0_count>=500){
        T0_count = 0;
    }
}
*/
