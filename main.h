#ifndef _MAIN_H_
#define _MAIN_H_

#include"page0.h"
#include"page1.h"
#include"page2.h"
#include"page4.h"
#include"page5.h"
#include"page6.h"
#include"page7.h"
#include"page8.h"
#include"page9.h"
#include"logo.h"


int main(void);

/*
函数名：initCar
功能：初始化汽车参数
入口参数：汽车结构体指针pCar
返回值：void
*/
void initCar(PCAR pCar);

/*
函数名：electricityWrite
功能：剩余电量写入文件energy.txt
入口参数：汽车结构体指针pCar
返回值：void
*/
void electricityWrite(PCAR pCar);

#endif