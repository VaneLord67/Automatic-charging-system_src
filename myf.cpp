///////////////////////////////////
//myf.cpp
//���ֹ��ܺ�����ʵ��
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

#define HZ_OFFSET 4 		//���ֵ�ƫ����

///////////////////////////////////
//��������printHZ
//���ܣ���x,y����ӡsָ��ĺ����ַ���(�����ο�)
//��ڲ�������һ�����ֵ����꣺x,y��
//        �������ַ�����s��
//        ����С��flag��
//        ����ɫ��color��
//����ֵ��void
///////////////////////////////////
void printHZ(int x, int y,char *s,int flag,int color)
{
	//�ж�s�Ƿ�ȫΪ���֣����ϸ��жϣ���Ϊ��if��s�����ż����Ӣ���ַ���������Ҳ�ᱻ�ж�Ϊfalse
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
//��������printHZ_withoutRec
//���ܣ���x,y����ӡsָ��ĺ����ַ���(�������ο�)
//��ڲ�������һ�����ֵ����꣺x,y��
//        �������ַ�����s��
//        ����С��flag��
//        ����ɫ��color��
//����ֵ��void
///////////////////////////////////
void printHZ_withoutRec(int x, int y,char *s,int flag,int color)
{
	int part = flag + HZ_OFFSET;
	
	puthz(x,y,s,flag,part,color);
	
	return;
}

///////////////////////////////////
//��������printText
//���ܣ���x,y����ӡsָ���Ӣ���ַ���(�����ο�)
//��ڲ�������һ���ַ������꣺x,y��
//        ���ַ�����s��
//        ����С��flag (0-10)��
//        ����ɫ��color��
//����ֵ��void
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
//��������printText_withoutRec
//���ܣ���x,y����ӡsָ���Ӣ���ַ���(�������ο�)
//��ڲ�������һ���ַ������꣺x,y��
//        ���ַ�����s��
//        ����С��flag (0-10)��
//        ����ɫ��color��
//����ֵ��void
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
//��������change_page
//���ܣ�ҳ���л�
//��ڲ�������ҳ��ĺ����ĵ�ַ
//����ֵ��void
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
//��������showMousePos
//���ܣ����Ͻ���ʾ�������
//��ڲ�������ҳ��ĺ����ĵ�ַ
//����ֵ��void
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
		bar(0,0,80,46);     //���ԭ�е�����
		sprintf(x,"%d",mouseX);
		sprintf(y,"%d",mouseY);
		settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
		outtextxy(0,13,x);
		outtextxy(0,30,y);
	}
		
	return;
}

///////////////////////////////////
//��������inputText
//���ܣ����뷨����������Ϊ��DEFAULT_FONT,HORIZ_DIR,3��//��3��Ĭ�����壩��
//��ڲ�������ʼλ�õ�x,y����ĵ�ַ���Ƿ������뷨�ı����ڵı�־���ı����ȵĵ�ַ��ָ���ı����ַ���(��Щ������Ҫ�ڵ��øú����ĺ���������ã��ѵ�ַ������),��ɫ
//����ֵ��void
///////////////////////////////////
void inputText(int * x_input, int * y_input,int * inputFlag,int * inputLength, char * text, int color)
{
	int maxLength = 12; //�ı�������󳤶�12
	if(kbhit() != 0)
	{
		int ch = 0;			
		char textTemp[1] = {'\0'};	
		ch = getch();
		switch(ch)
		{
			case 8:  						//�˸��
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
			case 13:						//�س�
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
//��������inputTextWithLength
//���ܣ����뷨����������Ϊ��DEFAULT_FONT,HORIZ_DIR,3��//��3��Ĭ�����壩�������Ƴ��Ȱ汾��
//��ڲ�������ʼλ�õ�x,y����ĵ�ַ���Ƿ������뷨�ı����ڵı�־���ı����ȵĵ�ַ��ָ���ı����ַ���(��Щ������Ҫ�ڵ��øú����ĺ���������ã��ѵ�ַ������),��ɫ,�ı���󳤶�
//����ֵ��void
///////////////////////////////////
void inputTextWithLength(int * x_input, int * y_input,int * inputFlag,int * inputLength, char * text, int color,int maxLength)
{
	//int maxLength = 12; //�ı�������󳤶�12
	if(kbhit() != 0)
	{
		int ch = 0;			
		char textTemp[1] = {'\0'};	
		ch = getch();
		switch(ch)
		{
			case 8:  						//�˸��
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
			case 13:						//�س�
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
//��������inputPassword
//���ܣ����뷨����������Ϊ��DEFAULT_FONT,HORIZ_DIR,3��//��3��Ĭ�����壩��
//��ڲ�������ʼλ�õ�x,y����ĵ�ַ���Ƿ������뷨�ı����ڵı�־���ı����ȵĵ�ַ��ָ���ı����ַ���(��Щ������Ҫ�ڵ��øú����ĺ���������ã��ѵ�ַ������),��ɫ
//����ֵ��void
///////////////////////////////////
void inputPassword(int * x_input, int * y_input,int * inputFlag,int * inputLength, char * text, int color)
{
	int maxLength = 12; //�ı�������󳤶�12
	if(kbhit() != 0)
	{
		int ch = 0;			
		char textTemp[1] = {'\0'};	
		ch = getch();
		switch(ch)
		{
			case 8:  						//�˸��
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
			case 13:						//�س�
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
//��������DiscardInput
//���ܣ����������뷨״̬�µļ�������
//��ڲ�����void
//����ֵ��void
///////////////////////////////////
void DiscardInput(void)
{
	if(kbhit() != 0)
	{
		getch();
	}
}

///////////////////////////////////
//��������popWindow
//���ܣ�����Ļ���뵯������OK���ػ����桾�����뷨�ĵط��ǵõ���ǰ���³�ʼ��������)������ʾ���ֺ�һ�����ڵ����OK��
//��ڲ�����������ĺ�����������״̬�����ĵ�ַ�������ַ����ĵ�ַ
//����ֵ��void
///////////////////////////////////
void popWindow(void(*draw_screen)(void), int * isPopWindow, char *s)
{
	if((*isPopWindow) == 0)
	{
		clrmous(mouseX,mouseY);
		setcolor(BLACK);
		bar(166,100,474,344); 	//�����������ı���
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
//��������popWindow_withoutFlush
//���ܣ�����Ļ���뵯������OK���ػ����棬����ʹ��putimage�ָ�����ǰ���棩������ʾ���ֺ�һ�����ڵ����OK��
//��ڲ������洢ͼ���ָ��ĵ�ַ������״̬�����ĵ�ַ�������ַ����ĵ�ַ
//����ֵ��int�����ȷ������1��û�������0
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
			
			bar(166,100,474,344); 	//���ԭ�еĵ���
			
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
��������recordWrite
���ܣ�д��ʻ��¼��record.txt
��ڲ�����id,�����ṹ�����pCar
����ֵ��void
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
		settextjustify(LEFT_TEXT,TOP_TEXT);          //�󲿶��룬��������
		settextstyle(GOTHIC_FONT,HORIZ_DIR,1);					//����ʻ������ˮƽ�����24*24����
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
		settextjustify(LEFT_TEXT,TOP_TEXT);          //�󲿶��룬��������
		settextstyle(GOTHIC_FONT,HORIZ_DIR,1);					//����ʻ������ˮƽ�����24*24����
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
//��������barRecWithCenter
//���ܣ������ĵ�x,y�ʹ�Сsize��������ɫ�ľ��Σ�����
//��ڲ��������ĵ�x,y����Сsize
//����ֵ��void
///////////////////////////////////
void barRecWithCenter(int centerX,int centerY,int size)
{
	setfillstyle(SOLID_FILL,GREEN);
	bar(centerX-size,centerY-size,centerX+size,centerY+size);
	return;
}

///////////////////////////////////
//��������exitFunc
//���ܣ��������ʱ���������Ϣ���˳�����
//��ڲ�����������ϢerrorMessage
//����ֵ��void
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
��������testStringIsAllNumbers
���ܣ������ַ����Ƿ�ȫΪ����
��ڲ������ַ���
����ֵ����ȫ�����ַ���1�����Ƿ���0
*/
int testStringIsAllNumbers(char * str)
{
	return strspn(str,"0123456789")==strlen(str);
}

/*
��������testStringIsFloat
���ܣ������ַ����Ƿ��Ӧ������
��ڲ������ַ���
����ֵ�����Ǹ���������1�����Ƿ���0
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
��������button
���ܣ���ť��ӰЧ��
��ڲ�����������꣬��ɫ
����ֵ��void
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







