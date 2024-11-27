#include "martrixkey.h"
#include "time.h"
unsigned char   key_martrix(){
    unsigned char key_number = 0;
    P1 = 0xFF;
    P1_3 =0;
    //time(2);
    if(P1_7== 0) {time(20);while(P1_7 == 0); time(20) ; key_number = 1;}
    if(P1_6== 0) {time(20);while(P1_6 == 0); time(20) ; key_number = 5;}
    if(P1_5== 0) {time(20);while(P1_5 == 0); time(20) ; key_number = 9;}
    if(P1_4== 0) {time(2);while(P1_4 == 0); time(2) ; key_number = 13;}

    P1 = 0xFF;
    P1_2 = 0;
   // if(P1_7== 0) {time(20);while(P1_7 == 0); time(20) ; key_number = 2;}
    if(P1_6== 0) {time(20);while(P1_6 == 0); time(20) ; key_number = 6;}
    if(P1_5== 0) {time(20);while(P1_5 == 0); time(20) ; key_number = 10;}
    if(P1_4== 0) {time(20);while(P1_4 == 0); time(20) ; key_number = 14;}
    
    P1 = 0xFF;
    P1_1 = 0;
    //if(P1_7== 0) {time(20);while(P1_7 == 0); time(20) ; key_number = 3;}
    if(P1_6== 0) {time(20);while(P1_6 == 0); time(20) ; key_number = 7;}
    if(P1_5== 0) {time(20);while(P1_5 == 0); time(20) ; key_number = 11;}
    if(P1_4== 0) {time(20);while(P1_4 == 0); time(20) ; key_number = 15;}
    

    P1 = 0xFF; 
    P1_0 = 0;
   // if(P1_7== 0) {time(20);while(P1_7 == 0); time(20) ; key_number = 4;}
    if(P1_6== 0) {time(20);while(P1_6 == 0); time(20) ; key_number = 8;}
    if(P1_5== 0) {time(20);while(P1_5 == 0); time(20) ; key_number = 12;}
    if(P1_4== 0) {time(20);while(P1_4 == 0); time(20) ; key_number = 16;}
    return key_number;
}