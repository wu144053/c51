#include<REGX52.H>
#include"time.h"
#include "key.h"
#include"buzzer.h"


unsigned char key_result ;
unsigned int i ;
unsigned char frequen_select,music_select = 0;

void time_buzzer(unsigned char ms){
    for ( i = 0;i<(ms*2);i++){
        buzzer1 =!buzzer1;
        buzzer_Delay500us();
    }
}

unsigned int code freqTable[] = { 
    0,
    63628,63731,63835,63928,64021,64103,
    64185,64260,64331,64400,64463,64528,
    64580,64633,64684,64732,64777,64820,
    64860,64898,64934,64968,65000,65030,
    65058,65085,65110,65134,65157,65178,
    65198,65217,65235,65252,65268,65283,
} ;

void buzzer_Delay500us(void)	//@11.0592MHz
{
	unsigned char data i;

	_nop_();
	i = 227;
	while (--i);
}

unsigned char code music_sky []= {
    P_,	4,
	P_,	4,
	P_,	4,
	M6,	2,
	M7,	2,
	
	H1,	4+2,
	M7,	2,
	H1,	4,
	H3,	4,
	
	M7,	4+4+4,
	M3,	2,
	M3,	2,
	
	//2
	M6,	4+2,
	M5,	2,
	M6, 4,
	H1,	4,
	
	M5,	4+4+4,
	M3,	4,
	
	M4,	4+2,
	M3,	2,
	M4,	4,
	H1,	4,
	
	//3
	M3,	4+4,
	P_,	2,
	H1,	2,
	H1,	2,
	H1,	2,
	
	M7,	4+2,
	M4_,2,
	M4_,4,
	M7,	4,
	
	M7,	8,
	P_,	4,
	M6,	2,
	M7,	2,
	
	//4
	H1,	4+2,
	M7,	2,
	H1,	4,
	H3,	4,
	
	M7,	4+4+4,
	M3,	2,
	M3,	2,
	
	M6,	4+2,
	M5,	2,
	M6, 4,
	H1,	4,
	
	//5
	M5,	4+4+4,
	M2,	2,
	M3,	2,
	
	M4,	4,
	H1,	2,
	M7,	2+2,
	H1,	2+4,
	
	H2,	2,
	H2,	2,
	H3,	2,
	H1,	2+4+4,
	
	//6
	H1,	2,
	M7,	2,
	M6,	2,
	M6,	2,
	M7,	4,
	M5_,4,
	
	
	M6,	4+4+4,
	H1,	2,
	H2,	2,
	
	H3,	4+2,
	H2,	2,
	H3,	4,
	H5,	4,
	
	//7
	H2,	4+4+4,
	M5,	2,
	M5,	2,
	
	H1,	4+2,
	M7,	2,
	H1,	4,
	H3,	4,
	
	H3,	4+4+4+4,
	
	//8
	M6,	2,
	M7,	2,
	H1,	4,
	M7,	4,
	H2,	2,
	H2,	2,
	
	H1,	4+2,
	M5,	2+4+4,
	
	H4,	4,
	H3,	4,
	H3,	4,
	H1,	4,
	
	//9
	H3,	4+4+4,
	H3,	4,
	
	H6,	4+4,
	H5,	4,
	H5,	4,
	
	H3,	2,
	H2,	2,
	H1,	4+4,
	P_,	2,
	H1,	2,
	
	//10
	H2,	4,
	H1,	2,
	H2,	2,
	H2,	4,
	H5,	4,
	
	H3,	4+4+4,
	H3,	4,
	
	H6,	4+4,
	H5,	4+4,
	
	//11
	H3,	2,
	H2,	2,
	H1,	4+4,
	P_,	2,
	H1,	2,
	
	H2,	4,
	H1,	2,
	H2,	2+4,
	M7,	4,
	
	M6,	4+4+4,
	P_,	4,

	0xFF,
};

void rounting_music_sky(){
	time_init();
  while(1){
    if(music_sky[music_select]!=0xFF){
    frequen_select = music_sky[music_select];
    music_select++;
    time(SPEED/4*music_sky[music_select]);
    music_select++;
    TR0 = 0;
    time(5);
    TR0= 1;
    }else{
        TR0 = 0;
      while(1){ }
    }
  }
}
/*void buzzer_Delay500us(void)	//@12.000MHz
{
	unsigned char data i, j;

	i = 6;
	j = 211;
	do
	{
		while (--j);
	} while (--i);
}
*/
