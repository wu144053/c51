#include"key.h"

unsigned char Key_key_number;

unsigned char key(){
    unsigned char temp;
    temp = Key_key_number;
    Key_key_number = 0;
    return temp;
}
unsigned char key_number(){
    unsigned char key_number = 0 ;
    if(P3_1 == 0 ){key_number = 1;}
    if(P3_0 == 0 ){key_number = 2;}
    if(P3_2 == 0 ){key_number = 3;}
    if(P3_3 == 0 ){key_number = 4;}
    return key_number;
}

void key_loop(void){
    static unsigned char last_key,now_key;
    last_key = now_key ;
    now_key = key_number();
    if (last_key == 1 && now_key == 0) {
        Key_key_number = 1;
    }
    if (last_key == 2 && now_key == 0) {
        Key_key_number = 2;
    }
    if (last_key == 3 && now_key == 0) {
        Key_key_number = 3;
    }
    if (last_key == 4 && now_key == 0) {
        Key_key_number = 4;
    }
}