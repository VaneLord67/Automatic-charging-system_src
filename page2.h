#ifndef _PAGE2_H_
#define _PAGE2_H_

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
函数名：page2_screen
功能：登录界面绘制
入口参数：void
返回值：void
*/
void page2_screen(void);

/*
函数名：p2
功能：登录界面的功能
入口参数：汽车结构体指针pCar
返回值：int类型，返回page的值
*/
int p2(PCAR pCar);

/*
函数名：Login
功能：登录
入口参数：用户名文本userText，密码文本passwordText,管理员模式标志位adminMode,汽车指针pCar
返回值：int类型，1为登录成功，0为登录失败
*/
int Login(char * userText, char * passwordText,int adminMode,PCAR pCar);



#endif