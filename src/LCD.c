#include"time.h"
#include"REGX52.H"
#include<STRING.H>
#include"LCD.h"

sbit LCD_RS = P2^6;
sbit LCD_RW = P2^5;
sbit LCD_E =  P2^7;
#define LCD_Data_port P0

/**
 * @brief 选择lcd的命令 
 * 
 * @param Commend 
 * 
 * @return 无
 */
void Lcd_Write_commend(unsigned char Commend){
    LCD_RS = 0;
    LCD_RW = 0;
    LCD_Data_port = Commend ;
    LCD_E = 1;
    time(1);
    LCD_E =0;
    time(1);
}
void Lcd_Write_Data(unsigned char Data){
    LCD_RS = 1;
    LCD_RW = 0;
    LCD_Data_port = Data;
    LCD_E = 1;
    time(1);
    LCD_E =0;
    time(1);
}

/**
 * @brief 在lcd屏幕上显示一个字符
 * 
 * @param line 在lcd屏上的行
 * 
 * @param Colum 在lcd屏上的列
 * 
 * @return 无
 */
void Lcd_show_StringChar(unsigned char line,unsigned char Colum,unsigned char Char){
    Lcd_set_cursor(line,Colum);
    Lcd_Write_Data(Char);
}

/**
 * @brief 初始化函数
 */
void Lcd_Init1(void){
    Lcd_Write_commend(0x38);
    Lcd_Write_commend(0x0C);
    Lcd_Write_commend(0x06);
    Lcd_Write_commend(0x01);
}

void Lcd_show_String(unsigned char line,unsigned char Colum,unsigned char* String){
    unsigned char i;
    Lcd_set_cursor(line,Colum);
    for(i = 0;i<strlen(String);i++){
        Lcd_Write_Data(*(String+i));
    }
    
}

void Lcd_set_cursor(unsigned char line ,unsigned char Colum){
    if(line == 1){
        Lcd_Write_commend(0x80|Colum-1);
    }else{
        Lcd_Write_commend(0x80|Colum-1 +0x40);
    }
}

void Lcd_show_number(unsigned char line,unsigned char Colum,unsigned int num ,unsigned char length){
    unsigned char i;
    Lcd_set_cursor(line,Colum);
    for(i = length ;i>0;i--){
        Lcd_Write_Data((0x30+num/num_power(10,(int)(i-1))%10));
    }
}

int num_power(int x,int y){
   int result = 1;
   unsigned char i = 0;
   for(i = 0;i<y;i++){
    result *=x;
   }
   return result;
}

void Lcd_showSignum(unsigned char line,unsigned char colum,int number,unsigned char length){
    unsigned char i;
    int number1;
    Lcd_set_cursor(line,colum);
    if(number >= 0){
        Lcd_Write_Data('+');
        number1 = number;
    }else{
        Lcd_Write_Data('-');
        number1 = -number ;
    }
   for( i = length;i>0;i--){
    Lcd_Write_Data('0'+number1 / num_power(10,i-1)%10);
   }
}

void Lcd_show_HEXnumber(unsigned char line,unsigned char colum,unsigned int number,unsigned char length) {
    unsigned char i;
    unsigned int hexnumber;
    Lcd_set_cursor(line,colum);
    for(i =length;i>0;i--){
        hexnumber =number / num_power(16,i-1)%16;
        if(hexnumber < 10){
            Lcd_Write_Data(hexnumber+'0');
        }else{
            Lcd_Write_Data(hexnumber + 'A');
        }
    }
}

void Lcd_show_Binnumber(unsigned char line,unsigned char colum,unsigned int number ,unsigned char length){
    unsigned char i ;
    Lcd_set_cursor(line,colum);
    for( i =length ;i>0;i--){
        Lcd_Write_Data(number/num_power(2,i-1) %2 + '0');
    }
}