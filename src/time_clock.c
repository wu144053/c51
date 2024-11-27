#include"time_clock.h"

#define DS1302_SECOND  0X80
#define DS1302_MINTUE  0X82
#define DS1302_HOUR    0X84
#define DS1302_DATE    0X86
#define DS1302_MONTH   0X88
#define DS1302_DAY     0X8A
#define DS1302_YEAR    0X8C
#define DS1302_PROTECT 0X8E
unsigned char time_clock[] = {24,9,28,13,10,42,6};

unsigned char key_number_result ,time_select,time_count ;

void time_clock_init(void){
    DS1302_SCLK = 0;
    Ds1302_CE = 0;
    time_clock_wirte(0x8e,0x00);
}

unsigned char  permint_month(unsigned char month,unsigned char year){
    switch (month)
    {
    case 0 : break;
    case 1:  return 31;
    case 2:  if(year % 4 == 0) {return 29 ;}else{return 28;}
    case 3: return 31;
    case 4: return 30;
    case 5:return 31;
    case 6: return 30;
    case 7: return 31;
    case 8: return 30;
    case 9: return 30;
    case 10: return 30;
    case 11: return 30;
    case 12: return 31;   
    default:
        break;
    }
    return 0;
}

void time_clock_wirte(unsigned char commend,unsigned char Data){
    unsigned char i;
    Ds1302_CE = 1;
    for (i = 0; i < 8; i++) {
        DS1302_IO   = commend & (0x01 << i);
        DS1302_SCLK = 1;
        DS1302_SCLK = 0;
    }
    for (i = 0; i < 8; i++) {
        DS1302_IO   = Data & (0x01 << i);
        DS1302_SCLK = 1;
        DS1302_SCLK = 0;
    }
    Ds1302_CE = 0;
}

unsigned char time_clock_rade(unsigned char commend){
    unsigned char i,Data = 0x00;
    commend |=0x01;
    Ds1302_CE = 1;
    for (i = 0; i < 8; i++) {
        DS1302_IO   = commend &( 0x01 << i);
        DS1302_SCLK = 0;
        DS1302_SCLK = 1;
    }
    for (i = 0; i < 8; i++ ) {
        DS1302_SCLK = 1;
        DS1302_SCLK = 0;
        if (DS1302_IO) { Data |= (0x01 << i); }
    }
    Ds1302_CE = 0;
    DS1302_IO = 0;
    return Data;
}

void time_set(){
    time_clock_wirte(0x8e,0x00);
    time_clock_wirte(DS1302_YEAR, time_clock[0] / 10 * 16 + time_clock[0] % 10);
    time_clock_wirte(DS1302_MONTH, time_clock[1] / 10 * 16 + time_clock[1] % 10);
    time_clock_wirte(DS1302_DATE, time_clock[2] / 10 * 16 + time_clock[2] % 10);
    time_clock_wirte(DS1302_HOUR, time_clock[3] / 10 * 16 + time_clock[3] % 10);
    time_clock_wirte(DS1302_MINTUE, time_clock[4] / 10 * 16 + time_clock[4] % 10);
    time_clock_wirte(DS1302_SECOND, time_clock[5] / 10 * 16 + time_clock[5] % 10);
    time_clock_wirte(DS1302_DAY,time_clock[6] / 10 * 16 + time_clock[6] % 10);
    time_clock_wirte(DS1302_PROTECT, 0x80);
}
void time_read(){
    unsigned char temp ;
    temp =time_clock_rade(DS1302_YEAR);
    time_clock[0]= temp/16*10 +temp%16;
    temp =time_clock_rade(DS1302_MONTH);
   time_clock[1]= temp/16*10 +temp%16;
    temp =time_clock_rade(DS1302_DATE);
   time_clock[2]= temp/16*10 +temp%16;
    temp =time_clock_rade(DS1302_HOUR);
    time_clock[3]= temp/16*10 +temp%16;
    temp =time_clock_rade(DS1302_MINTUE);
    time_clock[4]= temp/16*10 +temp%16;
    temp =time_clock_rade(DS1302_SECOND);
    time_clock[5]= temp/16*10 +temp%16;
    temp =time_clock_rade(DS1302_DAY);
    time_clock[6]= temp/16*10 +temp%16;
}
void time_show(){
      time_read();
      LCD_ShowNum(1, 1,time_clock[0] ,2);
      LCD_ShowNum(1, 4,time_clock[1] ,2);
      LCD_ShowNum(1, 7,time_clock[2] ,2);
      LCD_ShowNum(2, 1,time_clock[3] ,2);
      LCD_ShowNum(2, 4,time_clock[4] ,2);
      LCD_ShowNum(2, 7,time_clock[5] ,2);
}
void time_change(){
    if(key_number_result==2){
        time_select++;
        time_select%=6;
    }
    if(key_number_result== 3){
        time_clock[time_select]++;
        if(time_clock[0]>99){time_clock[0] =0;}
        if(time_clock[1]>12){time_clock [1]= 1;}
        if(time_clock[2]>permint_month(time_clock[1],time_clock[0])){time_clock[2]=permint_month(time_clock[1],time_clock[0]);}
        if(time_clock[3]>23){time_clock[3]= 0;}
        if(time_clock[4]>60){time_clock[4]=0;}
        if(time_clock[5]>60){time_clock[5]=0;}
    }
    if(key_number_result==4){
        time_clock[time_select]--;
        if(time_clock[0]>99){time_clock[0] =0;}
        if(time_clock[1]>12){time_clock [1]= 1;}
        if(time_clock[2]>permint_month(time_clock[1],time_clock[0])){time_clock[2]=permint_month(time_clock[1],time_clock[0]);}
        if(time_clock[3]>23){time_clock[3]= 0;}
        if(time_clock[4]>60){time_clock[4]=0;}
        if(time_clock[5]>60){time_clock[5]=0;}
    }
    if(time_select==0&&time_count==1){
          LCD_ShowString(1,1,"  ");
    }else {
       LCD_ShowNum(1, 1,time_clock[0] ,2);
    }
    if (time_select ==1&& time_count ==1){
        LCD_ShowString(1,4,"  ");
    }else{
        LCD_ShowNum(1, 4,time_clock[1] ,2);
    }
    if(time_select == 2 &&time_count == 1){
        LCD_ShowString(1,7,"  ");
    }else{
        LCD_ShowNum(1, 7,time_clock[2] ,2);
    }
    if(time_select==3&&time_count == 1){
        LCD_ShowString(2,1,"  ");
    }else{
        LCD_ShowNum(2, 1,time_clock[3] ,2);
    }
    if(time_select==4&&time_count==1){
        LCD_ShowString(2,4,"  ");
    }else{
        LCD_ShowNum(2, 4,time_clock[4] ,2);
    }
    if(time_select==5&&time_count==1){
        LCD_ShowString(2,7,"  ");
    }else{
        LCD_ShowNum(2, 7,time_clock[5] ,2);
    }
    
}