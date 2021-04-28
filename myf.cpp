///////////////////////////////////
//myf.cpp
//各种功能函数的实现
///////////////////////////////////
// #include"common.h"
#include<graphics.h>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<dos.h>
#include<bios.h>
#include<string.h>
#include<time.h>
#include<malloc.h>
#include"mouse.h"
#include"hz.h"
#include"myf.h"

#define HZ_OFFSET 4 		//汉字的偏移量

///////////////////////////////////
//函数名：printHZ
//功能：在x,y处打印s指向的汉字字符串(带矩形框)
//入口参数【第一个汉字的坐标：x,y】
//        【汉字字符串：s】
//        【大小：flag】
//        【颜色：color】
//返回值：void
///////////////////////////////////
void printHZ(int x, int y,char *s,int flag,int color)
{
	//判断s是否全为汉字，非严格判断，因为该if下s如果有偶数个英文字符混在里面也会被判断为false
	if( strlen(s) % 2 != 0)
	{
		settextjustify(LEFT_TEXT,TOP_TEXT);          
		settextstyle(GOTHIC_FONT,HORIZ_DIR,1);					
		outtextxy(10,10,"String cannot include english char!Press any key to quit...");
		getch();
		exit(1);
	}
	int length = strlen(s) / 2;
	int part = flag + HZ_OFFSET;
	
	setcolor(DARKGRAY);
	setlinestyle(SOLID_LINE,0,NORM_WIDTH);

	rectangle(x,y,x+flag*length*1.1+2,y+flag);
	puthz(x,y,s,flag,part,color);
	
	return;
}

///////////////////////////////////
//函数名：printHZ_withoutRec
//功能：在x,y处打印s指向的汉字字符串(不带矩形框)
//入口参数【第一个汉字的坐标：x,y】
//        【汉字字符串：s】
//        【大小：flag】
//        【颜色：color】
//返回值：void
///////////////////////////////////
void printHZ_withoutRec(int x, int y,char *s,int flag,int color)
{
	int part = flag + HZ_OFFSET;
	
	puthz(x,y,s,flag,part,color);
	
	return;
}

///////////////////////////////////
//函数名：printText
//功能：在x,y处打印s指向的英文字符串(带矩形框)
//入口参数【第一个字符的坐标：x,y】
//        【字符串：s】
//        【大小：flag (0-10)】
//        【颜色：color】
//返回值：void
///////////////////////////////////
void printText(int x, int y,char *s,int flag,int color)
{
	setcolor(color);
	settextstyle(DEFAULT_FONT,HORIZ_DIR,flag);
	setlinestyle(SOLID_LINE,0,NORM_WIDTH);
	rectangle(x-5,y-5,x+flag*8*strlen(s)+2,y+flag*8);
	outtextxy(x,y,s);
	
	return;
}


///////////////////////////////////
//函数名：printText_withoutRec
//功能：在x,y处打印s指向的英文字符串(不带矩形框)
//入口参数【第一个字符的坐标：x,y】
//        【字符串：s】
//        【大小：flag (0-10)】
//        【颜色：color】
//返回值：void
///////////////////////////////////
void printText_withoutRec(int x, int y,char *s,int flag,int color)
{
	setcolor(color);
	settextstyle(DEFAULT_FONT,HORIZ_DIR,flag);
	setlinestyle(SOLID_LINE,0,NORM_WIDTH);
	outtextxy(x,y,s);
	
	return;
}

///////////////////////////////////
//函数名：change_page
//功能：页面切换
//入口参数：画页面的函数的地址
//返回值：void
///////////////////////////////////
void change_page(void(*draw_screen)(void))
{
	clrmous(mouseX,mouseY);
	delay(100);
	draw_screen();
	save_bk_mou(mouseX,mouseY);
	drawmous(mouseX,mouseY);
	
	return;
}

///////////////////////////////////
//函数名：showMousePos
//功能：左上角显示鼠标坐标
//入口参数：画页面的函数的地址
//返回值：void
///////////////////////////////////
void showMousePos(void)
{
	int xn,yn,buttonsn;
	char x[5] = {'\0'};
	char y[5] = {'\0'};
	mread(&xn,&yn,&buttonsn);   
	if(!(xn == mouseX && yn == mouseY))
	{
		setfillstyle(SOLID_FILL,BLACK);
		bar(0,0,80,46);     //清除原有的数字
		sprintf(x,"%d",mouseX);
		sprintf(y,"%d",mouseY);
		settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
		outtextxy(0,13,x);
		outtextxy(0,30,y);
	}
		
	return;
}

///////////////////////////////////
//函数名：inputText
//功能：输入法【所用字体为（DEFAULT_FONT,HORIZ_DIR,3）//（3号默认字体）】
//入口参数：起始位置的x,y坐标的地址，是否在输入法文本框内的标志，文本长度的地址，指向文本的字符串(这些变量都要在调用该函数的函数处定义好，把地址传进来),颜色
//返回值：void
///////////////////////////////////
void inputText(int * x_input, int * y_input,int * inputFlag,int * inputLength, char * text, int color)
{
	int maxLength = 12; //文本输入最大长度12
	if(kbhit() != 0)
	{
		int ch = 0;			
		char textTemp[1] = {'\0'};	
		ch = getch();
		switch(ch)
		{
			case 8:  						//退格键
				if( (*inputLength) > 0)
				{
					text[(*inputLength) - 1] = '\0';
					(*inputLength) -- ;
					(*x_input) -= 25;
					clrmous(mouseX,mouseY);
					setfillstyle(SOLID_FILL,BLACK);
					bar((*x_input),(*y_input),(*x_input)+20,(*y_input)+24);
					save_bk_mou(mouseX,mouseY);
					drawmous(mouseX,mouseY);
					if((*x_input) <= 5)
					{
						(*x_input) = 600;
						if((*y_input) - 30 >= 240)
						{
							(*y_input) -= 30;
						}
					}
					
				}
				break;
			case 13:						//回车
			case 27:						//ESC
				(*inputFlag) = 0;
				break;
			default:
				if((*inputLength) < maxLength)
				{
					text[(*inputLength)] = ch;
					(*inputLength)++;
					memset(textTemp,'\0',sizeof(textTemp));
					sprintf(textTemp,"%c",ch);
					if((*x_input) < 550)
					{
						clrmous(mouseX,mouseY);
						settextstyle(DEFAULT_FONT,HORIZ_DIR,3);
						setcolor(color);
						outtextxy((*x_input),(*y_input),textTemp);

						save_bk_mou(mouseX,mouseY);
						drawmous(mouseX,mouseY);

						(*x_input) += 25;
					}					
				}
				break;
		}
	}
	return;
}

///////////////////////////////////
//函数名：inputTextWithLength
//功能：输入法【所用字体为（DEFAULT_FONT,HORIZ_DIR,3）//（3号默认字体）】【限制长度版本】
//入口参数：起始位置的x,y坐标的地址，是否在输入法文本框内的标志，文本长度的地址，指向文本的字符串(这些变量都要在调用该函数的函数处定义好，把地址传进来),颜色,文本最大长度
//返回值：void
///////////////////////////////////
void inputTextWithLength(int * x_input, int * y_input,int * inputFlag,int * inputLength, char * text, int color,int maxLength)
{
	//int maxLength = 12; //文本输入最大长度12
	if(kbhit() != 0)
	{
		int ch = 0;			
		char textTemp[1] = {'\0'};	
		ch = getch();
		switch(ch)
		{
			case 8:  						//退格键
				if( (*inputLength) > 0)
				{
					text[(*inputLength) - 1] = '\0';
					(*inputLength) -- ;
					(*x_input) -= 25;
					clrmous(mouseX,mouseY);
					setfillstyle(SOLID_FILL,BLACK);
					bar((*x_input),(*y_input),(*x_input)+20,(*y_input)+24);
					save_bk_mou(mouseX,mouseY);
					drawmous(mouseX,mouseY);
					if((*x_input) <= 5)
					{
						(*x_input) = 600;
						if((*y_input) - 30 >= 240)
						{
							(*y_input) -= 30;
						}
					}
					
				}
				break;
			case 13:						//回车
			case 27:						//ESC
				(*inputFlag) = 0;
				break;
			default:
				if((*inputLength) < maxLength)
				{
					text[(*inputLength)] = ch;
					(*inputLength)++;
					memset(textTemp,'\0',sizeof(textTemp));
					sprintf(textTemp,"%c",ch);
					if((*x_input) < 550)
					{
						clrmous(mouseX,mouseY);
						settextstyle(DEFAULT_FONT,HORIZ_DIR,3);
						setcolor(color);
						outtextxy((*x_input),(*y_input),textTemp);

						save_bk_mou(mouseX,mouseY);
						drawmous(mouseX,mouseY);

						(*x_input) += 25;
					}					
				}
				break;
		}
	}
	return;
}

///////////////////////////////////
//函数名：inputPassword
//功能：输入法【所用字体为（DEFAULT_FONT,HORIZ_DIR,3）//（3号默认字体）】
//入口参数：起始位置的x,y坐标的地址，是否在输入法文本框内的标志，文本长度的地址，指向文本的字符串(这些变量都要在调用该函数的函数处定义好，把地址传进来),颜色
//返回值：void
///////////////////////////////////
void inputPassword(int * x_input, int * y_input,int * inputFlag,int * inputLength, char * text, int color)
{
	int maxLength = 12; //文本输入最大长度12
	if(kbhit() != 0)
	{
		int ch = 0;			
		char textTemp[1] = {'\0'};	
		ch = getch();
		switch(ch)
		{
			case 8:  						//退格键
				if( (*inputLength) > 0)
				{
					text[(*inputLength) - 1] = '\0';
					(*inputLength) -- ;
					(*x_input) -= 25;
					clrmous(mouseX,mouseY);
					setfillstyle(SOLID_FILL,BLACK);
					bar((*x_input),(*y_input),(*x_input)+25,(*y_input)+20);
					save_bk_mou(mouseX,mouseY);
					drawmous(mouseX,mouseY);
					if((*x_input) <= 5)
					{
						(*x_input) = 600;
						if((*y_input) - 30 >= 240)
						{
							(*y_input) -= 30;
						}
					}
					
				}
				break;
			case 13:						//回车
			case 27:						//ESC
				(*inputFlag) = 0;
				break;
			default:
				if((*inputLength) < maxLength)
				{
					text[(*inputLength)] = ch;
					(*inputLength)++;
					memset(textTemp,'\0',sizeof(textTemp));
					sprintf(textTemp,"%c",ch);
					if((*x_input) < 550)
					{
						clrmous(mouseX,mouseY);
						settextstyle(DEFAULT_FONT,HORIZ_DIR,3);
						setcolor(color);
						outtextxy((*x_input),(*y_input),"*");

						save_bk_mou(mouseX,mouseY);
						drawmous(mouseX,mouseY);

						(*x_input) += 25;
					}
				}
				break;
		}
	}
}

///////////////////////////////////
//函数名：DiscardInput
//功能：丢弃非输入法状态下的键盘输入
//入口参数：void
//返回值：void
///////////////////////////////////
void DiscardInput(void)
{
	if(kbhit() != 0)
	{
		getch();
	}
}

///////////////////////////////////
//函数名：popWindow
//功能：在屏幕中央弹窗（点OK后重画界面【有输入法的地方记得调用前重新初始化变量】)（含提示文字和一个用于点击的OK框）
//入口参数：画界面的函数名，弹窗状态变量的地址，汉字字符串的地址
//返回值：void
///////////////////////////////////
void popWindow(void(*draw_screen)(void), int * isPopWindow, char *s)
{
	if((*isPopWindow) == 0)
	{
		clrmous(mouseX,mouseY);
		setcolor(BLACK);
		bar(166,100,474,344); 	//清除弹窗后面的背景
		setcolor(DARKGRAY);
		setlinestyle(SOLID_LINE,0,NORM_WIDTH);
		rectangle(166,100,474,344);
		printHZ_withoutRec(220, 150,s,48,DARKGRAY);
		rectangle(232,236,414,306);
		settextstyle(DEFAULT_FONT,HORIZ_DIR,5);
		outtextxy(285,250,"OK");
		
		save_bk_mou(mouseX,mouseY);
		drawmous(mouseX,mouseY);
		
		(*isPopWindow) = 1;
	}
	else
	{
		if(mouse_press(232,236,414,306) == 1)
		{
			change_page(draw_screen);
			(*isPopWindow) = 0;
		}		
	}
	
	return;
}

///////////////////////////////////
//函数名：popWindow_withoutFlush
//功能：在屏幕中央弹窗（点OK后不重画界面，而是使用putimage恢复弹窗前界面）（含提示文字和一个用于点击的OK框）
//入口参数：存储图像的指针的地址，弹窗状态变量的地址，汉字字符串的地址
//返回值：int。点击确定返回1，没点击返回0
///////////////////////////////////
int popWindow_withoutFlush(void ** buf, int * isPopWindow, char *s)
{
	int size;
	
	if((*isPopWindow) == 0)
	{
		size=imagesize(166,100,474,344);
		(*buf)=malloc(size);
		clrmous(mouseX,mouseY);
		if((*buf)!=NULL)
		{
			getimage(166,100,474,344,(*buf));
		}
		else
		{
			exitFunc("popWindow buf malloc error!");
		}
		clrmous(mouseX,mouseY);

		setcolor(BLACK);
		setfillstyle(SOLID_FILL,BLACK);
		bar(166,100,474,344); 	
		setcolor(DARKGRAY);
		setlinestyle(SOLID_LINE,0,NORM_WIDTH);
		rectangle(166,100,474,344);
		printHZ_withoutRec(220, 150,s,48,DARKGRAY);
		rectangle(232,236,414,306);
		settextstyle(DEFAULT_FONT,HORIZ_DIR,5);
		outtextxy(285,250,"OK");
		
		save_bk_mou(mouseX,mouseY);
		drawmous(mouseX,mouseY);
		
		(*isPopWindow) = 1;

	}
	else
	{
		if(mouse_press(232,236,414,306) == 1)
		{
			clrmous(mouseX,mouseY);
			setcolor(BLACK);
			
			bar(166,100,474,344); 	//清除原有的弹窗
			
			putimage(166,100,(*buf),COPY_PUT);
			free((*buf));
			
			save_bk_mou(mouseX,mouseY);
			drawmous(mouseX,mouseY);
			
			(*buf) = NULL;
			(*isPopWindow) = 0;
			
			delay(200);

			return 1;
		}
	}
	
	return 0;
}


/*
函数名：recordWrite
功能：写行驶记录到record.txt
入口参数：id,汽车结构体变量pCar
返回值：void
*/
void recordWrite(char * p,PCAR pCar)
{
	time_t now;
	FILE* fp;
	now = time(0);
	tm info = *localtime(&now);
	int year = info.tm_year + 1900;
	int month = info.tm_mon + 1;
	int day = info.tm_mday;
	int hour = info.tm_hour;
	int minute = info.tm_min;
	char ch;
	char temp[80] = {'\0'};
	int length = 0;
	int max = 0;
	
	if ((fp = fopen("record.txt", "r")) == NULL)
	{
		settextjustify(LEFT_TEXT,TOP_TEXT);          //左部对齐，顶部对齐
		settextstyle(GOTHIC_FONT,HORIZ_DIR,1);					//黑体笔划输出，水平输出，24*24点阵
		outtextxy(10,10,"Can't open file!Press any key to quit...");
		getch();
		exit(1);
	}
	
	while ( (ch = getc(fp)) != EOF)
	{
		if (ch == '[')
		{
			memset(temp, '\0', sizeof(temp));
			length = 0;
			while ( (ch = getc(fp)) != ']')
			{
				temp[length] = ch;
				length++;
			}
		}
		if (max < atoi(temp))
		{
			max = atoi(temp);
		}
	}
	
	fclose(fp);
	
	if ((fp = fopen("record.txt", "a")) == NULL)
	{
		settextjustify(LEFT_TEXT,TOP_TEXT);          //左部对齐，顶部对齐
		settextstyle(GOTHIC_FONT,HORIZ_DIR,1);					//黑体笔划输出，水平输出，24*24点阵
		outtextxy(10,10,"Can't open file!Press any key to quit...");
		getch();
		exit(1);
	}
	
	fprintf(fp, "[%d]\nUSER:%s\n", max + 1, p);
	fprintf(fp,"DIST:%lf\n",pCar->hasMileage);
	//fprintf(fp,"ELEL:\n",pCar->electricityLeft);
	fprintf(fp, "TIME:");
	fprintf(fp, "%d/%d/%d/%d:%d  -  ", pCar->info.tm_year + 1900, pCar->info.tm_mon + 1, pCar->info.tm_mday, pCar->info.tm_hour, pCar->info.tm_min);	

	
	fprintf(fp, "%d/%d/%d/%d:%d\n", year, month, day, hour, minute);	

	fclose(fp);

	return;
}

///////////////////////////////////
//函数名：barRecWithCenter
//功能：用中心点x,y和大小size绘制有颜色的矩形（车）
//入口参数：中心点x,y，大小size
//返回值：void
///////////////////////////////////
void barRecWithCenter(int centerX,int centerY,int size)
{
	setfillstyle(SOLID_FILL,GREEN);
	bar(centerX-size,centerY-size,centerX+size,centerY+size);
	return;
}

///////////////////////////////////
//函数名：exitFunc
//功能：程序出错时输出错误信息并退出程序
//入口参数：错误信息errorMessage
//返回值：void
///////////////////////////////////
void exitFunc(char * errorMessage)
{
	settextjustify(LEFT_TEXT,TOP_TEXT);          
	settextstyle(GOTHIC_FONT,HORIZ_DIR,1);					
	outtextxy(10,10,errorMessage);
	delay(2000);
	exit(-1);
	return;
}

/*
函数名：testStringIsAllNumbers
功能：测试字符串是否全为数字
入口参数：字符串
返回值：若全是数字返回1，不是返回0
*/
int testStringIsAllNumbers(char * str)
{
	return strspn(str,"0123456789")==strlen(str);
}

/*
函数名：testStringIsFloat
功能：测试字符串是否对应浮点数
入口参数：字符串
返回值：若是浮点数返回1，不是返回0
*/
int testStringIsFloat(char * str)
{
	if(strspn(str,".0123456789")==strlen(str) && strlen(str) > 0)
	{
		if(str[0] != '.' && str[strlen(str) - 3] == '.')
		{
			return 1;
		}
		return 0;
	}
	return 0;
}

/*
函数名：button
功能：按钮阴影效果
入口参数：鼠标坐标，颜色
返回值：void
*/
void button(int x1, int y1, int x2, int y2, int color1, int color2)
{
	clrmous(mouseX, mouseY);
	delay(10);
	setcolor(color1);
	setlinestyle(SOLID_LINE,0,NORM_WIDTH);
	setfillstyle(1, color2);
	bar(x1,y1,x2,y2);
	return;
} 







