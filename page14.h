#ifndef _PAGE14_H_
#define _PAGE14_H_

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

/*
��������page14_screen
���ܣ����Ƴ�ֵ����
��ڲ�����void
����ֵ��void
*/
void page14_screen(void);

/*
��������p14
���ܣ���ֵ����
��ڲ���������ָ��pCar
����ֵ��int���ͣ�����page��ֵ
*/
int p14(PCAR pCar);

/*
��������updateBalance
���ܣ������û����
��ڲ������û�ָ��pCar
����ֵ��void
*/
void updateBalance(PCAR pCar);

/*
��������card_check
���ܣ�������п��˺�����
��ڲ����������ı�cardText,�����ı�cardpasText
����ֵ��int���ͣ�1Ϊ���ͨ����0Ϊ��鲻ͨ��
*/
int card_check(char * cardIDText,char * passwordText);

#endif
