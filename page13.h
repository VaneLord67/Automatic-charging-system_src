#ifndef _PAGE13_H_
#define _PAGE13_H_

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
��������page13_screen
���ܣ����ƹ���Ա����
��ڲ�����void
����ֵ��void
*/
void page13_screen(void);

/*
��������p13
���ܣ�����Ա����
��ڲ���������ָ��pCar
����ֵ��int���ͣ�����page��ֵ
*/
int p13(PCAR pCar);

#endif