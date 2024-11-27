#include"gital.h"
#include"time.h"
unsigned char minute = 0,second = 0,min_second = 0;
unsigned char run_flag = 0;
unsigned char digital_num [] = {0,10,10,10,10,10,10,10,10,10,10};
char num_led[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f,0x00,0x40};

void gital_num_set(unsigned char location ,unsigned char Number){
    digital_num[location] = Number;
}

void digital_scan(unsigned char local_number ,unsigned char num){
    P0 = 0x00;
    switch (local_number)
    {
    case 1: P2_4 = 1 ;P2_3 = 1 ;P2_2 = 1;break;
    case 2: P2_4 = 1 ;P2_3 = 1 ;P2_2 = 0;break;
    case 3: P2_4 = 1 ;P2_3 = 0 ;P2_2 = 1;break;
    case 4: P2_4 = 1 ;P2_3 = 0 ;P2_2 = 0;break;
    case 5: P2_4 = 0 ;P2_3 = 1 ;P2_2 = 1;break;
    case 6: P2_4 = 0 ;P2_3 = 1 ;P2_2 = 0;break;
    case 7: P2_4 = 0;P2_3 = 0 ;P2_2 = 1;break;
    case 8: P2_4 = 0 ;P2_3 = 0 ;P2_2 = 0;break;
    default:
        break;
    }
    P0 = num_led[num];
}

void digital_loop(void){
    unsigned char i;
    digital_scan(i,digital_num[i]);
    i++;
    if(i>9){i = 1;}
}

void run_520(unsigned char *num)
{
 num[1] = 5;
 num[2] = 2;
 num[3] = 0;
 num[4] = 1;
 num[5] = 3;
 num [6] = 1;
 num[7] = 4; 
}

void sec_loop()
{
    if(run_flag == 0) {
        min_second++;
        if (min_second >= 100) {
            min_second = 0;
            second++;
            if (second >= 60) {
                second = 0;
                minute++;
                {
                    if (minute >= 60) {
                        minute = 0;
                    }
                }
            }
        }
    }
}

/**
 * @brief 秒表的功能，当按下一时秒表开始计时，当按下2时秒表暂停，当按下3时秒表写入数据，当按下4时秒表读取数据
 * 
 * @param key_number_result 用来判定按键的选择
 * 
 * @return 无
 * 
 */
void clock(){
        unsigned char key_number_result_;
        key_number_result_ = key();
        if(key_number_result_ == 1){run_flag = !run_flag;}
        if(key_number_result_ == 2){min_second = 0;second = 0;minute = 0;}
        if(key_number_result_==3){
            AT24C02_WriteByte(0,minute);
            time(5);
            AT24C02_WriteByte(1,second);
            time(5);
            AT24C02_WriteByte(2,min_second);
            time(5);
        }
        if(key_number_result_==4){
            minute = AT24C02_ReadByte(0);
            second = AT24C02_ReadByte(1);
            min_second = AT24C02_ReadByte(2);
        }
        gital_num_set(1,minute/10);
        gital_num_set(2,minute%10);
        gital_num_set(3,11);
        gital_num_set(4,second/10);
        gital_num_set(5,second%10);
        gital_num_set(6,11);
        gital_num_set(7,min_second/10);
        gital_num_set(8,min_second%10);
}