#ifndef _PAGE7_H_
#define _PAGE7_H_

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
��������page7_screen
���ܣ����Ƶ���ģ��
��ڲ�����void
����ֵ��void
*/
void page7_screen(void);

/*
��������p7
���ܣ�����ģ��
��ڲ����������ṹ�����pCar
����ֵ��int���ͣ�����page��ֵ
*/
int p7(PCAR pCar);

#endif