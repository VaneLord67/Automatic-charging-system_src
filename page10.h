#ifndef _PAGE10_H_
#define _PAGE10_H_



extern void *buffer;
extern union REGS regs;

extern int mouseX;
extern int mouseY;
extern int press;
extern int flag;

/*
函数名：page10_screen
功能：绘制电量模块
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

#endif