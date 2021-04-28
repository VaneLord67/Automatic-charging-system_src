#ifndef _PAGE16_H_
#define _PAGE16_H_

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
函数名：page16_screen
功能：绘制换电金额计算界面
入口参数：void
返回值：void
*/
void page16_screen(void);

/*
函数名：p16
功能：换电金额计算界面
入口参数：汽车指针pCar
返回值：int类型，返回page的值
*/
int p16(PCAR pCar);


#endif