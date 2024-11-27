#include<REGX52.H>
#include"time.h"

sbit XPT2042_CS = P3^5;
sbit XPT2042_DCLK = P3^6;
sbit XPT2042_DIN = P3^4;
sbit XPT2042_DOUT = P3^7;

unsigned int xpt2042readAD(unsigned char commend){
    unsigned char i;
    unsigned int readvalue = 0;
    unsigned char j ;
    XPT2042_DCLK = 0;
    XPT2042_CS = 0;
    for( i = 0; i<8 ; i++){
        XPT2042_DIN = commend&(0x80>>i);
        XPT2042_DCLK = 1;
	    j = 64;
	    while (--j);
        XPT2042_DCLK = 0;
    }    
    for(i = 0; i<16;i++){
        XPT2042_DCLK = 1;
	    j = 64;
	    while (--j);
        XPT2042_DCLK = 0;
        if(XPT2042_DOUT){readvalue |= (0x8000>>i);}
    }
    XPT2042_CS = 1;
    return  readvalue>>8;
}