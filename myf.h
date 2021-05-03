#ifndef _MY_F_H_
#define _MY_F_H_

#include<graphics.h>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<dos.h>
#include<string.h>
#include<time.h>
#include<malloc.h>
#include<math.h>
#include"mouse.h"
#include"hz.h"

#define MAX_ELECTRICITY 70.0			//最大电量
#define WARNING_ELECTRICITY 15.0		//警告电量
#define PRICE_PER_KWH 0.5       //一度电的价钱
// #define SHOWMOUSE					//若define了则显示鼠标坐标
#define DEBUGMODE					//若define了则进入DEBUG模式。

//汽车结构声明
typedef struct car
{
	double electricityLeft;	//剩余电量
	double destElec;		//充电时目标电量
	double hasMileage; //已行驶里程
	
	//下列四种状态0为关闭，1为开启
	int airConditioningFlag; //空调状态
	int lightFlag;			//车灯状态
	int windowFlag;			//车窗状态
	int musicFlag; 			//音乐播放器状态
	
	int runState;			//行驶状态（熄火0、行驶1、制动2）
	int temperature;		//汽车温度
	int speed;				//汽车速度(60km/h)
	int k;					//数学模型k值
	int kEquipment;			//数学模型中设备对应的k
	int b;					//数学模型b值
	int loginFlag;			//登录状态，0未登录，1已登录
	
	//通过时间用来计算行驶里程的变量
	int start;				//起始时间
	int temp;				//临时时间
	
	tm info;				//行驶记录起始时间
	char id[20];			//汽车的id（即登录时的用户名）
	
	//车在地图上的坐标
	int x;
	int y;

	int isAdmin;		//是否为管理员
	double balance;		//用户余额
}CAR,*PCAR;

extern void *buffer;
extern union REGS regs;

extern int mouseX;
extern int mouseY;
extern int press;
extern int flag;

///////////////////////////////////
//函数名：printHZ
//功能：在x,y处打印s指向的汉字字符串(带矩形框)
//入口参数【第一个汉字的坐标：x,y】
//        【汉字字符串：s】
//        【大小：flag】
//        【颜色：color】
//返回值：void
///////////////////////////////////
void printHZ(int x, int y,char *s,int flag,int color);

///////////////////////////////////
//函数名：printHZ_withoutRec
//功能：在x,y处打印s指向的汉字字符串(不带矩形框)
//入口参数【第一个汉字的坐标：x,y】
//        【汉字字符串：s】
//        【大小：flag】
//        【颜色：color】
//返回值：void
///////////////////////////////////
void printHZ_withoutRec(int x, int y,char *s,int flag,int color);

///////////////////////////////////
//函数名：printText
//功能：在x,y处打印s指向的英文字符串(带矩形框)
//入口参数【第一个字符的坐标：x,y】
//        【字符串：s】
//        【大小：flag (0-10)】
//        【颜色：color】
//返回值：void
///////////////////////////////////
void printText(int x, int y,char *s,int flag,int color);


///////////////////////////////////
//函数名：printText_withoutRec
//功能：在x,y处打印s指向的英文字符串(不带矩形框)
//入口参数【第一个字符的坐标：x,y】
//        【字符串：s】
//        【大小：flag (0-10)】
//        【颜色：color】
//返回值：void
///////////////////////////////////
void printText_withoutRec(int x, int y,char *s,int flag,int color);

///////////////////////////////////
//函数名：change_page
//功能：页面切换
//入口参数：画页面的函数的地址
//返回值：void
///////////////////////////////////
void change_page(void(*draw_screen)(void));

///////////////////////////////////
//函数名：showMousePos
//功能：左上角显示鼠标坐标
//入口参数：画页面的函数的地址
//返回值：void
///////////////////////////////////
void showMousePos(void);

///////////////////////////////////
//函数名：inputText
//功能：输入法【所用字体为（DEFAULT_FONT,HORIZ_DIR,3）//（3号默认字体）】
//入口参数：起始位置的x,y坐标的地址，是否在输入法文本框内的标志，文本长度的地址，指向文本的字符串(这些变量都要在调用该函数的函数处定义好，把地址传进来)
//返回值：void
///////////////////////////////////
void inputText(int * x_input, int * y_input,int * inputFlag,int * inputLength, char * text, int color);

///////////////////////////////////
//函数名：inputTextWithLength
//功能：输入法【所用字体为（DEFAULT_FONT,HORIZ_DIR,3）//（3号默认字体）】【限制长度版本】
//入口参数：起始位置的x,y坐标的地址，是否在输入法文本框内的标志，文本长度的地址，指向文本的字符串(这些变量都要在调用该函数的函数处定义好，把地址传进来),颜色,文本最大长度
//返回值：void
///////////////////////////////////
void inputTextWithLength(int * x_input, int * y_input,int * inputFlag,int * inputLength, char * text, int color,int maxLength);

///////////////////////////////////
//函数名：inputPassword
//功能：输入法【所用字体为（DEFAULT_FONT,HORIZ_DIR,3）//（3号默认字体）】
//入口参数：起始位置的x,y坐标的地址，是否在输入法文本框内的标志，文本长度的地址，指向文本的字符串(这些变量都要在调用该函数的函数处定义好，把地址传进来),颜色
//返回值：void
///////////////////////////////////
void inputPassword(int * x_input, int * y_input,int * inputFlag,int * inputLength, char * text, int color);

///////////////////////////////////
//函数名：DiscardInput
//功能：丢弃非输入法状态下的键盘输入
//入口参数：void
//返回值：void
///////////////////////////////////
void DiscardInput(void);

///////////////////////////////////
//函数名：popWindow
//功能：在屏幕中央弹窗（含提示文字和一个用于点击的OK框）
//入口参数：画界面的函数名，弹窗状态变量的地址，汉字字符串的地址
//返回值：void
///////////////////////////////////
void popWindow(void(*draw_screen)(void), int * isPopWindow, char *s);

///////////////////////////////////
//函数名：popWindow_withoutFlush
//功能：在屏幕中央弹窗（点OK后不重画界面，而是使用putimage恢复弹窗前界面）（含提示文字和一个用于点击的OK框）
//入口参数：存储图像的指针的地址，弹窗状态变量的地址，汉字字符串的地址弹窗状态变量的地址，汉字字符串的地址
//返回值：int。点击确定返回1，没点击返回0
///////////////////////////////////
int popWindow_withoutFlush(void ** buf, int * isPopWindow, char *s);

///////////////////////////////////
//函数名：recordOut
//功能：回到初始界面/退出程序 后写入时间到record.txt
//入口参数：void
//返回值：void
///////////////////////////////////
void recordOut(void);

///////////////////////////////////
//函数名：recordWrite
//功能：写行驶记录到record.txt
//入口参数：id,汽车结构体变量pCar
//返回值：void
///////////////////////////////////
void recordWrite(char * p,PCAR pCar);

///////////////////////////////////
//函数名：barRecWithCenter
//功能：用中心点x,y和大小size绘制有颜色的矩形（车）
//入口参数：中心点x,y，大小size
//返回值：void
///////////////////////////////////
void barRecWithCenter(int centerX,int centerY,int size);

///////////////////////////////////
//函数名：exitFunc
//功能：程序出错时输出错误信息并退出程序
//入口参数：错误信息errorMessage
//返回值：void
///////////////////////////////////
void exitFunc(char * errorMessage);

/*
函数名：testStringIsAllNumbers
功能：测试字符串是否全为数字
入口参数：字符串
返回值：若全是数字返回1，不是返回0
*/
int testStringIsAllNumbers(char * str);

/*
函数名：testStringIsFloat
功能：测试字符串是否对应浮点数
入口参数：字符串
返回值：若是浮点数返回1，不是返回0
*/
int testStringIsFloat(char * str);

/*
函数名：button
功能：按钮阴影效果
入口参数：鼠标坐标，颜色
返回值：void
*/
void button(int x1, int y1, int x2, int y2, int color1, int color2);

#endif














