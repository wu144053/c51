#include"time.h"
#include"LCD.h"
#include"Int0.h"
#include"timer0_IR.h"
#include"IR.h"

unsigned char commend;
unsigned char address;
unsigned char num = 100;

void main(void){
  IR_init();
  Lcd_Init();
  while(1){
    if(IR_getFlag() || IR_getReaptFlag()){
      commend = IR_getCommend();
      address = IR_getaddress();
      if(commend == 0x46){
        P2 = ~P2;
      }
      LCD_ShowHexNum(2,1,commend,4);
      LCD_ShowHexNum(2,6,address,4);
      Lcd_show_number(1,1,num,3);
      if(commend == 0x15){
        num --;
      }else if(commend == 0x09){
        num ++;
      }
    }
  }
}
