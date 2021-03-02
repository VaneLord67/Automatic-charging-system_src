#ifndef _MY_F_H_
#define _MY_F_H_

extern void *buffer;
extern union REGS regs;

extern int mouseX;
extern int mouseY;
extern int press;
extern int flag;

extern int playIndex;
extern int isPlaySound;
extern clock_t start;
extern clock_t end;
extern double total;

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
//返回值：void
///////////////////////////////////
void popWindow_withoutFlush(void ** buf, int * isPopWindow, char *s);

///////////////////////////////////
//函数名：playSound
//功能：播放音乐
//入口参数：void
//返回值：void
///////////////////////////////////
void playSound(void);


#endif














