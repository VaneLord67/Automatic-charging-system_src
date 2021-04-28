#ifndef _PAGE9_H_
#define _PAGE9_H_

#include<graphics.h>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<dos.h>
#include<bios.h>
#include<string.h>
#include<time.h>
#include<malloc.h>
#include<math.h>
#include"mouse.h"
#include"hz.h"
#include"myf.h"

extern void *buffer;
extern union REGS regs;

extern int mouseX;
extern int mouseY;
extern int press;
extern int flag;

#define SIZE 2			//һҳ��ʾ����
#define MAX_RECORD 500	//��༸����¼

//������¼�ṹ�壬�����������û���ʱ�䡢���
typedef struct record
{
	char index[10];
	char user[20];
	char time[60];
	char mileage[50];
	//char electricityLeft[5];
}RECORD,*pRECORD;

/*
��������page9_screen
���ܣ�������ʻ��¼��ѯ����
��ڲ�����void
����ֵ��void
*/
void page9_screen(void);

/*
��������p9
���ܣ���ʻ��¼��ѯ����
��ڲ���������ָ��pCar
����ֵ��int���ͣ�����page��ֵ
*/
int p9(PCAR pCar);

/*
��������maxPageQuery
���ܣ�������ʻ��¼�ļ���record.txt�������ҳ��(һҳ��ʾ3��)
��ڲ�����void
����ֵ��int���ҳ��
*/
int maxPageQuery(int * getMax);

/*
��������maxPageQueryForUser
���ܣ�������ʻ��¼�ļ���record.txt�����û���Ӧ�����ҳ��(һҳ��ʾ3��)
��ڲ�����void
����ֵ��int���ҳ��
*/
int maxPageQueryForUser(PCAR pCar,int * skip);

/*
��������findRecord
���ܣ������ʻ��¼
��ڲ�������ǰҳ��pageCurrent
����ֵ��void
*/
//@Deprecated
//�ѱ�findRecordForAdmin��findRecordForUserȡ��
// void findRecord(int pageCurrent,PCAR pCar);

/*
��������findRecordForAdmin
���ܣ������Ա�����ʻ��¼
��ڲ�������ǰҳ��pageCurrent
����ֵ��void
*/
void findRecordForAdmin(int pageCurrent,int max);

/*
��������findRecordForUser
���ܣ����û������ʻ��¼
��ڲ�������ǰҳ��pageCurrent,�û���Ӧ����������skip
����ֵ��void
*/
void findRecordForUser(int pageCurrent,int * skip);

#endif