#ifndef _PAGE16_H_
#define _PAGE16_H_

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
��������page16_screen
���ܣ����ƻ�����������
��ڲ�����void
����ֵ��void
*/
void page16_screen(void);

/*
��������p16
���ܣ�������������
��ڲ���������ָ��pCar
����ֵ��int���ͣ�����page��ֵ
*/
int p16(PCAR pCar);


#endif