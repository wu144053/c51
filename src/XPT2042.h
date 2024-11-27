#ifndef _XPT2042_H
#define _XPT2042_H

#define XPT2042_XP 0x9c
#define XPT2042_YP 0xdc
#define XPT2042_VBAT 0xac
#define XPT2042_AUX 0xEC

unsigned int xpt2042readAD(unsigned char commend);

#endif 