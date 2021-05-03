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

#define MAX_ELECTRICITY 70.0			//������
#define WARNING_ELECTRICITY 15.0		//�������
#define PRICE_PER_KWH 0.5       //һ�ȵ�ļ�Ǯ
// #define SHOWMOUSE					//��define������ʾ�������
#define DEBUGMODE					//��define�������DEBUGģʽ��

//�����ṹ����
typedef struct car
{
	double electricityLeft;	//ʣ�����
	double destElec;		//���ʱĿ�����
	double hasMileage; //����ʻ���
	
	//��������״̬0Ϊ�رգ�1Ϊ����
	int airConditioningFlag; //�յ�״̬
	int lightFlag;			//����״̬
	int windowFlag;			//����״̬
	int musicFlag; 			//���ֲ�����״̬
	
	int runState;			//��ʻ״̬��Ϩ��0����ʻ1���ƶ�2��
	int temperature;		//�����¶�
	int speed;				//�����ٶ�(60km/h)
	int k;					//��ѧģ��kֵ
	int kEquipment;			//��ѧģ�����豸��Ӧ��k
	int b;					//��ѧģ��bֵ
	int loginFlag;			//��¼״̬��0δ��¼��1�ѵ�¼
	
	//ͨ��ʱ������������ʻ��̵ı���
	int start;				//��ʼʱ��
	int temp;				//��ʱʱ��
	
	tm info;				//��ʻ��¼��ʼʱ��
	char id[20];			//������id������¼ʱ���û�����
	
	//���ڵ�ͼ�ϵ�����
	int x;
	int y;

	int isAdmin;		//�Ƿ�Ϊ����Ա
	double balance;		//�û����
}CAR,*PCAR;

extern void *buffer;
extern union REGS regs;

extern int mouseX;
extern int mouseY;
extern int press;
extern int flag;

///////////////////////////////////
//��������printHZ
//���ܣ���x,y����ӡsָ��ĺ����ַ���(�����ο�)
//��ڲ�������һ�����ֵ����꣺x,y��
//        �������ַ�����s��
//        ����С��flag��
//        ����ɫ��color��
//����ֵ��void
///////////////////////////////////
void printHZ(int x, int y,char *s,int flag,int color);

///////////////////////////////////
//��������printHZ_withoutRec
//���ܣ���x,y����ӡsָ��ĺ����ַ���(�������ο�)
//��ڲ�������һ�����ֵ����꣺x,y��
//        �������ַ�����s��
//        ����С��flag��
//        ����ɫ��color��
//����ֵ��void
///////////////////////////////////
void printHZ_withoutRec(int x, int y,char *s,int flag,int color);

///////////////////////////////////
//��������printText
//���ܣ���x,y����ӡsָ���Ӣ���ַ���(�����ο�)
//��ڲ�������һ���ַ������꣺x,y��
//        ���ַ�����s��
//        ����С��flag (0-10)��
//        ����ɫ��color��
//����ֵ��void
///////////////////////////////////
void printText(int x, int y,char *s,int flag,int color);


///////////////////////////////////
//��������printText_withoutRec
//���ܣ���x,y����ӡsָ���Ӣ���ַ���(�������ο�)
//��ڲ�������һ���ַ������꣺x,y��
//        ���ַ�����s��
//        ����С��flag (0-10)��
//        ����ɫ��color��
//����ֵ��void
///////////////////////////////////
void printText_withoutRec(int x, int y,char *s,int flag,int color);

///////////////////////////////////
//��������change_page
//���ܣ�ҳ���л�
//��ڲ�������ҳ��ĺ����ĵ�ַ
//����ֵ��void
///////////////////////////////////
void change_page(void(*draw_screen)(void));

///////////////////////////////////
//��������showMousePos
//���ܣ����Ͻ���ʾ�������
//��ڲ�������ҳ��ĺ����ĵ�ַ
//����ֵ��void
///////////////////////////////////
void showMousePos(void);

///////////////////////////////////
//��������inputText
//���ܣ����뷨����������Ϊ��DEFAULT_FONT,HORIZ_DIR,3��//��3��Ĭ�����壩��
//��ڲ�������ʼλ�õ�x,y����ĵ�ַ���Ƿ������뷨�ı����ڵı�־���ı����ȵĵ�ַ��ָ���ı����ַ���(��Щ������Ҫ�ڵ��øú����ĺ���������ã��ѵ�ַ������)
//����ֵ��void
///////////////////////////////////
void inputText(int * x_input, int * y_input,int * inputFlag,int * inputLength, char * text, int color);

///////////////////////////////////
//��������inputTextWithLength
//���ܣ����뷨����������Ϊ��DEFAULT_FONT,HORIZ_DIR,3��//��3��Ĭ�����壩�������Ƴ��Ȱ汾��
//��ڲ�������ʼλ�õ�x,y����ĵ�ַ���Ƿ������뷨�ı����ڵı�־���ı����ȵĵ�ַ��ָ���ı����ַ���(��Щ������Ҫ�ڵ��øú����ĺ���������ã��ѵ�ַ������),��ɫ,�ı���󳤶�
//����ֵ��void
///////////////////////////////////
void inputTextWithLength(int * x_input, int * y_input,int * inputFlag,int * inputLength, char * text, int color,int maxLength);

///////////////////////////////////
//��������inputPassword
//���ܣ����뷨����������Ϊ��DEFAULT_FONT,HORIZ_DIR,3��//��3��Ĭ�����壩��
//��ڲ�������ʼλ�õ�x,y����ĵ�ַ���Ƿ������뷨�ı����ڵı�־���ı����ȵĵ�ַ��ָ���ı����ַ���(��Щ������Ҫ�ڵ��øú����ĺ���������ã��ѵ�ַ������),��ɫ
//����ֵ��void
///////////////////////////////////
void inputPassword(int * x_input, int * y_input,int * inputFlag,int * inputLength, char * text, int color);

///////////////////////////////////
//��������DiscardInput
//���ܣ����������뷨״̬�µļ�������
//��ڲ�����void
//����ֵ��void
///////////////////////////////////
void DiscardInput(void);

///////////////////////////////////
//��������popWindow
//���ܣ�����Ļ���뵯��������ʾ���ֺ�һ�����ڵ����OK��
//��ڲ�����������ĺ�����������״̬�����ĵ�ַ�������ַ����ĵ�ַ
//����ֵ��void
///////////////////////////////////
void popWindow(void(*draw_screen)(void), int * isPopWindow, char *s);

///////////////////////////////////
//��������popWindow_withoutFlush
//���ܣ�����Ļ���뵯������OK���ػ����棬����ʹ��putimage�ָ�����ǰ���棩������ʾ���ֺ�һ�����ڵ����OK��
//��ڲ������洢ͼ���ָ��ĵ�ַ������״̬�����ĵ�ַ�������ַ����ĵ�ַ����״̬�����ĵ�ַ�������ַ����ĵ�ַ
//����ֵ��int�����ȷ������1��û�������0
///////////////////////////////////
int popWindow_withoutFlush(void ** buf, int * isPopWindow, char *s);

///////////////////////////////////
//��������recordOut
//���ܣ��ص���ʼ����/�˳����� ��д��ʱ�䵽record.txt
//��ڲ�����void
//����ֵ��void
///////////////////////////////////
void recordOut(void);

///////////////////////////////////
//��������recordWrite
//���ܣ�д��ʻ��¼��record.txt
//��ڲ�����id,�����ṹ�����pCar
//����ֵ��void
///////////////////////////////////
void recordWrite(char * p,PCAR pCar);

///////////////////////////////////
//��������barRecWithCenter
//���ܣ������ĵ�x,y�ʹ�Сsize��������ɫ�ľ��Σ�����
//��ڲ��������ĵ�x,y����Сsize
//����ֵ��void
///////////////////////////////////
void barRecWithCenter(int centerX,int centerY,int size);

///////////////////////////////////
//��������exitFunc
//���ܣ��������ʱ���������Ϣ���˳�����
//��ڲ�����������ϢerrorMessage
//����ֵ��void
///////////////////////////////////
void exitFunc(char * errorMessage);

/*
��������testStringIsAllNumbers
���ܣ������ַ����Ƿ�ȫΪ����
��ڲ������ַ���
����ֵ����ȫ�����ַ���1�����Ƿ���0
*/
int testStringIsAllNumbers(char * str);

/*
��������testStringIsFloat
���ܣ������ַ����Ƿ��Ӧ������
��ڲ������ַ���
����ֵ�����Ǹ���������1�����Ƿ���0
*/
int testStringIsFloat(char * str);

/*
��������button
���ܣ���ť��ӰЧ��
��ڲ�����������꣬��ɫ
����ֵ��void
*/
void button(int x1, int y1, int x2, int y2, int color1, int color2);

#endif














