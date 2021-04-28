#ifndef _PAGE15_H_
#define _PAGE15_H_

#include<graphics.h>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<dos.h>
#include<bios.h>
#include<string.h>
#include<time.h>
#include<malloc.h>
#include<math.h>
#include"mouse.h"
#include"hz.h"
#include"myf.h"

extern void *buffer;
extern union REGS regs;

extern int mouseX;
extern int mouseY;
extern int press;
extern int flag;


/*
函数名：page15_screen
功能：绘制充电金额计算界面
入口参数：void
返回值：void
*/
void page15_screen(void);

/*
函数名：p15
功能：充电金额计算界面
入口参数：汽车指针pCar
返回值：int类型，返回page的值
*/
int p15(PCAR pCar);


#endif