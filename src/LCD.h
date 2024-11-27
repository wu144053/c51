#ifndef _LCD_H
#define _LCD_H


void Lcd_Write_commend(unsigned char Commend);
void Lcd_Write_Data(unsigned char Data);
void Lcd_show_StringChar(unsigned char line,unsigned char Colum,unsigned char Char);
void Lcd_Init(void);
void Lcd_show_String(unsigned char line,unsigned char conlum,unsigned char* String);
int num_power(int x,int y );
void Lcd_show_number(unsigned char line,unsigned char Colum,unsigned int num ,unsigned char length);
void Lcd_set_cursor(unsigned char line ,unsigned char Colum);
void Lcd_showSignum(unsigned char line,unsigned char colum,int number,unsigned char length);
void LCD_ShowHexNum(unsigned char Line,unsigned char Column,unsigned int Number,unsigned char Length);
void Lcd_show_Binnumber(unsigned char line,unsigned char colum,unsigned int number,unsigned char length);
#endif