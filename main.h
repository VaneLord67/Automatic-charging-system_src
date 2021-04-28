#ifndef _MAIN_H_
#define _MAIN_H_

#include<graphics.h>
#include<stdio.h>
#include<malloc.h>

#include"page0.h"
#include"page1.h"
#include"page2.h"
#include"page4.h"
#include"page5.h"
#include"page6.h"
#include"page8.h"
#include"page9.h"
#include"page10.h"
#include"page11.h"
#include"map.h"
#include"page13.h"
#include"page14.h"
#include"page15.h"
#include"page16.h"
#include"page17.h"

#include"mouse.h"
#include"hz.h"
#include"myf.h"

/*
函数名：main
功能：主函数
入口参数：void
返回值：int
*/
int main(void);

/*
函数名：initCar
功能：初始化汽车参数
入口参数：汽车结构体指针pCar
返回值：void
*/
void initCar(PCAR pCar);

/*
函数名：carInfoWrite
功能：汽车剩余电量、位置写入文件carinfo.txt
入口参数：汽车结构体指针pCar
返回值：void
*/
void carInfoWrite(PCAR pCar);

#endif
