#ifndef _PAGE5_H_
#define _PAGE5_H_

extern void *buffer;
extern union REGS regs;

extern int mouseX;
extern int mouseY;
extern int press;
extern int flag;

/*
函数名：page5_screen
功能：绘制中控模块界面
入口参数：void
返回值：void
*/
void page5_screen(void);

/*
函数名：p5
功能：中控模块
入口参数：void
返回值：int类型，返回page的值
*/
int p5(PCAR pCar);

/*
函数名：stateDraw
功能：根据状态绘制界面
入口参数：矩形框位置，标志地址
返回值：void
*/
void stateDraw(int x1,int y1,int x2,int y2,int * flag);

/*
函数名：changeToOn
功能：切换至开启状态
入口参数：矩形框位置，标志地址
返回值：void
*/
void changeToOn(int x1,int y1,int x2,int y2,int* flag);

/*
函数名：changeToOff
功能：切换至开启状态
入口参数：矩形框位置，标志地址
返回值：void
*/
void changeToOff(int x1,int y1,int x2,int y2,int* flag);


#endif