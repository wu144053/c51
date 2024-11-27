#include"REGX52.H"
#include"OneWire.h"
#include"time.h"
#include"AT24C02.h"
#include"timer_control.h"
#include"key.h"
#include"buzzer.h"

#define DS18B20_SKIP_ROM        0XCC
#define DS18B20_CONVENT_T       0X44
#define DS18B20_READ_SCRATCHPAD 0xBE

/**
 * @brief 通过oneWire总线发送两个字节的数据，包括跳过rom和实现温度转化功能
 * 
 * @param 无
 * 
 * @return 无
 */

void DS18B20_Covent_T(){
    OneWire_Init();
    OneWire_send_Byte(DS18B20_SKIP_ROM);
    OneWire_send_Byte(DS18B20_CONVENT_T);
}

/**
 * @brief 读取温度的数据
 * 
 * @param TLSB 存取温度的低位数据
 * 
 * @param TMSB 存取温度的高位字节的数据
 * 
 * @return tempareture 返回温度的完整数据
 */
float DS18B20_ReadT(){
    unsigned char TLSB,TMSB;
    int temp;
    float tempareture;
    OneWire_Init();
    OneWire_send_Byte(DS18B20_SKIP_ROM);
    OneWire_send_Byte(DS18B20_READ_SCRATCHPAD);
    TLSB = OneWire_read_Byte();
    TMSB = OneWire_read_Byte();
    temp = (TMSB<<8)|TLSB;
    tempareture = temp/16.0;
    return tempareture;
}
/**
 * @brief 实现温度的警告，超过限定的温度便会发出警告，并且将设定的温度阈值存储在at420c芯片里
 * @param T 存储的温度的值
 * 
 * @param Tshow 对温度的值进行转换方便温度的读取
 * 
 * @param THigh 设定的高温阈值
 * 
 * @param TLow 设定的低温阈值
 * 
 * @param key1 用来检测按键
 * 
 * @return 无
 */
void tempareture_warr(){
    float T,Tshow;
    char THigh,TLow;
    unsigned char key1;

    time_init();
    THigh = AT24C02_ReadByte(0);
    TLow = AT24C02_ReadByte(1); 
    LCD_Init();
    LCD_ShowString(1,1,"T:");
    DS18B20_Covent_T();
    //time();
    LCD_ShowString(2,1,"TH:");
    LCD_ShowString(2,6,"TL:");
    while(1){
        key1 = key_number();
        if(key1){
            if(key1 == 1){
                THigh++;
                if(THigh>125){THigh = 125;}
            }
            if(key1 == 2){
                THigh --;
                if(THigh<=TLow){
                    THigh++;
                }
            }
            if(key1 == 3){
                TLow++;
                if(TLow>=THigh){
                    TLow --;
                }
            }
            if(key1 == 4){
                TLow --;
                if(TLow <= -55){
                    TLow = -55;
                }
            }
        }
        LCD_ShowSignedNum(2,4,THigh,3);
        LCD_ShowSignedNum(2,12,TLow,3);
        DS18B20_Covent_T();
        T= DS18B20_ReadT();
        if(T<0){
            LCD_ShowString(1,3,"-");
            Tshow= -T;
        } else {
            Tshow = T;
            LCD_ShowString(1, 3, "+");
        }
        LCD_ShowNum(1, 4,Tshow, 4);
        LCD_ShowString(1, 8, ".");
        LCD_ShowNum(1, 9, (unsigned long)(Tshow* 10000) % 10000, 4);
        AT24C02_WriteByte(0,THigh);
        time(50);
        AT24C02_WriteByte(1,TLow);
        if(T>THigh){
            LCD_ShowString(1,13,"OVH");
        }else if(T<TLow){
            LCD_ShowString(1,13,"OVL");
        }else{
            LCD_ShowString(1,13,"    ");
        }
    }
}