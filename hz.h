#ifndef __HZ_H__
#define __HZ_H__

#include<graphics.h>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<dos.h>
#include<bios.h>

/*
函数名：puthz
功能：打印汉字
入口参数：汉字坐标x，y，字符串s，大小flag，间隔part，颜色color
返回值：int类型，返回page的值 
*/
void puthz(int x, int y,char *s,int flag,int part,int color);

#endif

