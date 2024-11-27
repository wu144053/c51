#include"Martrix_led.h"

void _74HC59_write(unsigned char DATA){
    unsigned char i ;
    for( i = 0 ; i<8;i++){
        SER = DATA&(0x80>>i);
        SCK = 1;
        SCK = 0;
    }
    RCK = 1;
    RCK = 0;
}

void Martix_led(unsigned char colounm ,unsigned DATA){
    _74HC59_write(DATA);
    Martrix_led_colounm = ~(0x80>>colounm);
    time(1);
    Martrix_led_colounm = 0xFF;
}
void Martix_led_xiaolian(){
    SCK = 0;
    RCK = 0;
    while(1){
        Martix_led(0,0x3C);
        Martix_led(1,0x42);
        Martix_led(2,0xA9);
        Martix_led(3,0x85);
        Martix_led(4,0x85);
        Martix_led(5,0xA9);
        Martix_led(6,0x42);
        Martix_led(7,0x3C);
    }
}
/*void Martrix_led_HELLO(){
    unsigned char i ,count, time = 0;
    unsigned char xiaolian[]={
        0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
        0xFF,0x10,0x10,0xFF,0x00,0xFF,0x89,0x89,
        0x89,0x00,0xFF,0x01,0x01,0x01,0x01,0x00,
        0xFF,0x01,0x01,0x01,0x01,0x00,0x7E,0x81,
        0x81,0x81,0x81,0x7E,0x00,0x00,0x00,0x00,
        0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    };
    while (1) {
        for (i = 0; i < 8;i++ ) {
            Martix_led(i, xiaolian[i + time]);
        }
        count ++;
        if(count ==10){
            count = 0;
            time++;
            if(time>40){
                time = 0;
            }
        }
    }
}*/
/*void Martrix_expression_fun(){
    unsigned char i ,count = 0, time = 0;
    unsigned char expression[]={
        0x3C,0x42,0xA5,0x83,0x83,0xA5,0x42,0x3C,
        0x7E,0xD1,0xA5,0x95,0x95,0xA5,0x91,0x7E,
        0x7E,0xC1,0xB9,0xA3,0x83,0xB9,0xA1,0x7E,
        0x7E,0xC1,0xA1,0xA5,0x89,0xA5,0xA1,0x7E,
    };
    while(1){
        for(i = 0;i<8;i++){
            Martix_led(i,expression[i+time]);
        }
        count ++;
        if(count == 30){
            count = 0;
            time+=8;
            if(time>24){
                time = 0;
            }
        }
    }
}*/