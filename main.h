#ifndef _MAIN_H_
#define _MAIN_H_

#include<graphics.h>
#include<stdio.h>
#include<malloc.h>

#include"page0.h"
#include"page1.h"
#include"page2.h"
#include"page4.h"
#include"page5.h"
#include"page6.h"
#include"page8.h"
#include"page9.h"
#include"page10.h"
#include"page11.h"
#include"map.h"
#include"page13.h"
#include"page14.h"
#include"page15.h"
#include"page16.h"
#include"page17.h"

#include"mouse.h"
#include"hz.h"
#include"myf.h"

/*
��������main
���ܣ�������
��ڲ�����void
����ֵ��int
*/
int main(void);

/*
��������initCar
���ܣ���ʼ����������
��ڲ����������ṹ��ָ��pCar
����ֵ��void
*/
void initCar(PCAR pCar);

/*
��������carInfoWrite
���ܣ�����ʣ�������λ��д���ļ�carinfo.txt
��ڲ����������ṹ��ָ��pCar
����ֵ��void
*/
void carInfoWrite(PCAR pCar);

#endif
