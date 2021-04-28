#ifndef _PAGE4_H_
#define _PAGE4_H_

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
#include"main.h"

extern void *buffer;
extern union REGS regs;

extern int mouseX;
extern int mouseY;
extern int press;
extern int flag;

/*
函数名：page4_screen
功能：绘制数据显示界面
入口参数：void
返回值：void
*/
void page4_screen(void);

/*
函数名：p4
功能：数据显示界面
入口参数：汽车指针pCar
返回值：int类型，返回page的值
*/
int p4(PCAR pCar);

/*
函数名：turnToState0
功能：转换成熄火状态的界面效果
入口参数：void
返回值：void
*/
void turnToState0(void);

/*
函数名：turnToState1
功能：转换成行驶状态的界面效果
入口参数：void
返回值：void
*/
void turnToState1(void);

/*
函数名：turnToState2
功能：转换成制动状态的界面效果
入口参数：void
返回值：void
*/
void turnToState2(void);

/*
函数名：turnOffCarFacility
功能：点击熄火后关闭汽车所有设备
入口参数：汽车指针pCar
返回值：void
*/
void turnOffCarFacility(PCAR pCar);

#endif