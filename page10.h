#ifndef _PAGE10_H_
#define _PAGE10_H_

#include"myf.h"

/*
函数名：updateBalance
功能：更新用户余额
入口参数：用户指针pCar
返回值：void
*/
void updateBalance(PCAR pCar);

/*
函数名：page10_screen
功能：绘制一键充电界面
入口参数：void
返回值：void
*/
void page10_screen(void);

/*
函数名：p10
功能：一键充电界面
入口参数：汽车结构体变量pCar
返回值：int类型，返回page的值
*/
int p10(PCAR pCar);

/*
函数名：CarElecWrite_charge
功能：将汽车电量变化写入文件elec.txt中
入口参数：id,汽车结构体指针pCar，汽车充电前电量p1
返回值：void
*/
void CarElecWrite_charge(char * p, PCAR pCar, double *p1);

/*
函数名：drawcircle;
功能:在指定位置画一个圆 
入口参数：圆心坐标
返回值：void
*/
void drawcircle(int x,int y);

#endif
