#include"IR.h"
#include"LCD1602.h"
#include"time.h"

unsigned int IR_time;
unsigned char IR_state;

unsigned char IR_Data[4];
unsigned char IR_Pdata;

unsigned char IR_data_flag;
unsigned char IR_repeatFlag;
unsigned char IR_address;
unsigned char IR_Commend;

/**
 * @brief ir初始化
 */
void IR_init(void ){
    timer_ir_init();
    int0_init();
}

/**
 *  @brief 检测数据是否读取成功
 */
unsigned  char IR_getFlag(){
    if(IR_data_flag){
        IR_data_flag = 0;
        return 1;
    }else{
        return 0;
    }
}

/**
 * @brief  检测是否重新发送
 */
unsigned char IR_getReaptFlag(){
    if(IR_repeatFlag){
        IR_repeatFlag = 0;
        return 1;
    }else{
        return 0;
    }
}

/**
 * @获取地址
 */
unsigned char IR_getaddress(){
    return IR_address;
}

/**
 * @brief 获取命令
 */
unsigned char IR_getCommend(){
    return IR_Commend;
}

/**
 * @brief  inter0下降沿中断检测遥控器信号
 */
void interrupt_rounting (void) interrupt 0{
    if(IR_state == 0){
        timer_setcounter(0);
        timer_rounting(1);
        IR_state = 1;
    }else if(IR_state == 1 ){
        IR_time = time_read_value();
        timer_setcounter(0);
        if(IR_time >12500 - 500 && IR_time < 12500 + 500 ){

            IR_state = 2;
        }else if(IR_time >10250 -500 && IR_time <10250 + 500){
            IR_repeatFlag = 1;
            timer_rounting(1);
            IR_state = 0;
        }
    }else if (IR_state == 2){
        IR_time = time_read_value();
        timer_setcounter(0);
        if(IR_time <1032+500 && IR_time > 1032 - 500){
            IR_Data[IR_Pdata /8] &= ~(0x01<<(IR_Pdata % 8));
            IR_Pdata ++;
        }else if(IR_time < 2073 + 500 && IR_time > 2073 - 500){
            IR_Data [IR_Pdata /8] |= (0x01 << (IR_Pdata % 8) );
            IR_Pdata ++;
        }else{
            IR_Pdata = 0;
            IR_state = 1;
        }if(IR_Pdata >= 32){
            IR_Pdata = 0;
            if(IR_Data[0]== ~IR_Data[1] && IR_Data[2] == ~IR_Data[3]){
                IR_data_flag = 1;
                IR_address = IR_Data[0];
                IR_Commend = IR_Data[2];
            } 
            timer_rounting (0);
            IR_state = 0;
        }
    }
}
