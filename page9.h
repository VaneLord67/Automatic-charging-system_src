#ifndef _PAGE9_H_
#define _PAGE9_H_

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

#define SIZE 2			//一页显示几条
#define MAX_RECORD 500	//最多几条记录

//声明记录结构体，包括索引、用户、时间、里程
typedef struct record
{
	char index[10];
	char user[20];
	char time[60];
	char mileage[50];
	//char electricityLeft[5];
}RECORD,*pRECORD;

/*
函数名：page9_screen
功能：绘制行驶记录查询界面
入口参数：void
返回值：void
*/
void page9_screen(void);

/*
函数名：p9
功能：行驶记录查询界面
入口参数：汽车指针pCar
返回值：int类型，返回page的值
*/
int p9(PCAR pCar);

/*
函数名：maxPageQuery
功能：返回行驶记录文件（record.txt）中最大页数(一页显示3条)
入口参数：void
返回值：int最大页数
*/
int maxPageQuery(int * getMax);

/*
函数名：maxPageQueryForUser
功能：返回行驶记录文件（record.txt）中用户对应的最大页数(一页显示3条)
入口参数：void
返回值：int最大页数
*/
int maxPageQueryForUser(PCAR pCar,int * skip);

/*
函数名：findRecord
功能：输出行驶记录
入口参数：当前页面pageCurrent
返回值：void
*/
//@Deprecated
//已被findRecordForAdmin和findRecordForUser取代
// void findRecord(int pageCurrent,PCAR pCar);

/*
函数名：findRecordForAdmin
功能：向管理员输出行驶记录
入口参数：当前页面pageCurrent
返回值：void
*/
void findRecordForAdmin(int pageCurrent,int max);

/*
函数名：findRecordForUser
功能：向用户输出行驶记录
入口参数：当前页面pageCurrent,用户对应的跳过数组skip
返回值：void
*/
void findRecordForUser(int pageCurrent,int * skip);

#endif