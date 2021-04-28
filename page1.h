#ifndef _PAGE1_H_
#define _PAGE1_H_

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

/*
函数名：page1_screen
功能：绘制注册界面
入口参数：void
返回值：void
*/
void page1_screen(void);

/*
函数名：p1
功能：注册界面控制函数
入口参数：汽车指针
返回值：page
*/
int p1(PCAR pCar);

/*
函数名：Register
功能：注册
入口参数：用户名文本userText,密码文本passwordText，管理员标志位adminMode
返回值：int类型，1为成功，0为不成功
*/
int Register(char * userText, char * passwordText,int adminMode);

/*
函数名：check
功能：检查账号密码格式
入口参数：用户名文本userText,密码文本passwordText
返回值：int类型，1为格式合格，0为不合格 
*/
int check(char * userText, char * passwordText);


#endif
