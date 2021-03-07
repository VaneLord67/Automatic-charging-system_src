#ifndef _PAGE9_H_
#define _PAGE9_H_

extern void *buffer;
extern union REGS regs;

extern int mouseX;
extern int mouseY;
extern int press;
extern int flag;

#define SIZE 2

//声明记录结构体，包括索引、用户、时间、里程
typedef struct record
{
	char index[10];
	char user[20];
	char time[60];
	char mileage[10];
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
入口参数：void
返回值：int类型，返回page的值
*/
int p9(void);

/*
函数名：maxPageQuery
功能：返回行驶记录文件（record.txt）中最大页数(一页显示3条)
入口参数：void
返回值：int最大页数
*/
int maxPageQuery(void);

/*
函数名：findRecord
功能：输出行驶记录
入口参数：当前页面pageCurrent
返回值：void
*/
void findRecord(int pageCurrent);

#endif