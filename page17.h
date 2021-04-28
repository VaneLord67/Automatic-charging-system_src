#ifndef _PAGE17_H_
#define _PAGE17_H_

#include"myf.h"

#define SIZE 2			//一页显示几条
#define MAX_RECORD 500	//最多几条记录

//声明记录结构体，包括索引、用户、花费、电量、时间 
typedef struct elec 
{
	char index[10];
	char user[20];
	char elec[60];
	char money[50];
	char time[60];
	char mode[20];
}ELEC,*pELEC;

/*
函数名：p17
功能：管理员电量查询界面 
入口参数：汽车指针pCar
返回值：int类型，返回page的值
*/
int p17(PCAR pCar);

/*
函数名：page17_screen
功能：绘制充电记录查询界面
入口参数：void
返回值：void
*/
void page17_screen(void);

/*
函数名：maxPageQueryForElec 
功能：返回充电记录文件（elec.txt）中最大页数(一页显示SIZE条)
入口参数：void
返回值：int最大页数
*/
int maxPageQueryForElec(int * getMax);

/*
函数名：findRecordForElec
功能：输出充电记录
入口参数：当前页面pageCurrent
返回值：void
*/
void findRecordForElec(int pageCurrent,int max);

#endif
