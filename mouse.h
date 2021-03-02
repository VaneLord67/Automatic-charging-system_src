#ifndef _MY_MOUSE_TEST_H_
#define _MY_MOUSE_TEST_H_

void initMouse(void);	//初始化鼠标
void save_bk_mou(int nx,int ny);	//保存鼠标背景
void mouse(int x,int y);		//画鼠标
void drawmous(int nx,int ny);	//鼠标的画法
void mread(int *nx,int *ny,int *nbuttons); //读鼠标信息
void newmouse(int *nx,int *ny,int *nbuttons);	//更新鼠标
void clrmous(int nx,int ny);	//清除鼠标
int mouse_press(int x1, int y1, int x2, int y2);	//监测鼠标点击

#endif