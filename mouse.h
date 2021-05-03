#ifndef _MY_MOUSE_H_
#define _MY_MOUSE_H_

#include"myf.h"

/*
函数名：initMouse
功能:初始化鼠标
入口参数：void
返回值：void
*/
void initMouse(void);	

/*
函数名：save_bk_mou
功能:保存鼠标背景
入口参数：鼠标坐标nx,ny
返回值：void
*/
void save_bk_mou(int nx,int ny);	

/*
函数名：mouse
功能:画鼠标
入口参数：鼠标坐标x,y
返回值：void
*/
void mouse(int x,int y);	

/*
函数名：drawmous
功能:鼠标的画法
入口参数：鼠标坐标nx,ny
返回值：void
*/
void drawmous(int nx,int ny);	

/*
函数名：mread
功能:读鼠标信息
入口参数：鼠标坐标nx,ny的地址，鼠标按下地址
返回值：void
*/
void mread(int *nx,int *ny,int *nbuttons); 

/*
函数名：newmouse
功能:更新鼠标
入口参数：鼠标坐标nx,ny的地址，鼠标按下地址
返回值：void
*/
void newmouse(int *nx,int *ny,int *nbuttons);	

/*
函数名：clrmous
功能:清除鼠标
入口参数：鼠标坐标nx,ny
返回值：void
*/
void clrmous(int nx,int ny);	

/*
函数名：mouse_press
功能:监测鼠标点击
入口参数：矩形框x1,y1,x2,y2
返回值：int，按下为1，在框里为2，右键为3
*/
int mouse_press(int x1, int y1, int x2, int y2);	

/*
函数名：mouse_pressCenter
功能:用中心坐标和大小调用鼠标点击
入口参数：中心坐标x,y，大小size
返回值：int，按下为1，在框里为2，右键为3
*/
int mouse_pressCenter(int centerX,int centerY,int size); 

#endif