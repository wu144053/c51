#include<REGX52.H>
#include"key.h"
#include"AT24C02.h"

extern unsigned char digital_num[];
extern unsigned char minute ,second ,min_second ;
/**
 * @param run_flag 当run_flag为0时开始计时，当为1时停止计时
 */
extern unsigned char run_flag;
/**
 * @brief 在数码管上显示数字
 * 
 * @param local_number 将要显示数字的位置
 * @param num 将要显示的数字
 * 
 * @return 无
 */
void digital_scan(unsigned char local_number ,unsigned char num);


/**
 * @brief 在数码管上显示数字，用终端扫描
 * 
 * @param 无 将要显示在数码管上的位置
 * @param 无  将要显示在数码管上的数字
 * 
 * @return 无 
 */
void digital_loop(void);

/**
 * @brief 选择在local_number位填入什么数据
 * 
 * @param local_number 将要填入的数据的位置
 * 
 * @param num 填入的数据
 * 
 * @return 无
 */
void gital_num_set(unsigned char location ,unsigned char Number);

/**
 * @brief 在数码管上显示5201314
 */
void run_520(unsigned char* num);

/**
 * @brief 秒表
 * @param minute 分
 * @param second 秒
 * @param min_second 百分之一秒
 * 
 * @return 无
 */
void sec_loop();
void clock();