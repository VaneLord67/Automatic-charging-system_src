#ifndef _PAGE1_H_
#define _PAGE1_H_

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
��������page1_screen
���ܣ�����ע�����
��ڲ�����void
����ֵ��void
*/
void page1_screen(void);

/*
��������p1
���ܣ�ע�������ƺ���
��ڲ���������ָ��
����ֵ��page
*/
int p1(PCAR pCar);

/*
��������Register
���ܣ�ע��
��ڲ������û����ı�userText,�����ı�passwordText������Ա��־λadminMode
����ֵ��int���ͣ�1Ϊ�ɹ���0Ϊ���ɹ�
*/
int Register(char * userText, char * passwordText,int adminMode);

/*
��������check
���ܣ�����˺������ʽ
��ڲ������û����ı�userText,�����ı�passwordText
����ֵ��int���ͣ�1Ϊ��ʽ�ϸ�0Ϊ���ϸ� 
*/
int check(char * userText, char * passwordText);


#endif
