#ifndef _PAGE14_H_
#define _PAGE14_H_

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
函数名：page14_screen
功能：绘制充值界面
入口参数：void
返回值：void
*/
void page14_screen(void);

/*
函数名：p14
功能：充值界面
入口参数：汽车指针pCar
返回值：int类型，返回page的值
*/
int p14(PCAR pCar);

/*
函数名：updateBalance
功能：更新用户余额
入口参数：用户指针pCar
返回值：void
*/
void updateBalance(PCAR pCar);

/*
函数名：card_check
功能：检查银行卡账号密码
入口参数：卡号文本cardText,卡密文本cardpasText
返回值：int类型，1为检查通过，0为检查不通过
*/
int card_check(char * cardIDText,char * passwordText);

#endif
