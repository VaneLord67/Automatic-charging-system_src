#ifndef _COMMON_H_
#define _COMMON_H_

#include<graphics.h>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<dos.h>
#include<bios.h>
#include<string.h>
#include<time.h>
#include"mouse.h"
#include"hz.h"
#include"myf.h"
#include<malloc.h>

//�����ṹ����
typedef struct car
{
	int electricityLeft;	//ʣ�����
	int hasMileage; //����ʻ���
	//��������״̬0Ϊ�رգ�1Ϊ����
	int airConditioningFlag; //�յ�״̬
	int lightFlag;			//����״̬
	int windowFlag;			//����״̬
	int musicFlag; 			//���ֲ�����״̬
	int runState;			//��ʻ״̬��Ϩ��0����ʻ1���ƶ�2��
	
}CAR,*PCAR;

#endif