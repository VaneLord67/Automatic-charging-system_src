#ifndef _PAGE11_H_
#define _PAGE11_H_



extern void *buffer;
extern union REGS regs;

extern int mouseX;
extern int mouseY;
extern int press;
extern int flag;

/*
函数名：page11_screen
功能：绘制一键换电界面
入口参数：void
返回值：void
*/
void page11_screen(void);

/*
函数名：p11
功能：一键换电界面
入口参数：汽车结构体变量pCar
返回值：int类型，返回page的值
*/
int p11(PCAR pCar);

#endif