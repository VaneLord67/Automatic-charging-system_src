#ifndef _PAGE15_H_
#define _PAGE15_H_

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


/*
��������page15_screen
���ܣ����Ƴ����������
��ڲ�����void
����ֵ��void
*/
void page15_screen(void);

/*
��������p15
���ܣ������������
��ڲ���������ָ��pCar
����ֵ��int���ͣ�����page��ֵ
*/
int p15(PCAR pCar);


#endif