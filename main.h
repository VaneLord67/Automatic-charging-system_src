#ifndef _MAIN_H_
#define _MAIN_H_

#include"page0.h"
#include"page1.h"
#include"page2.h"
#include"page4.h"
#include"page5.h"
#include"page6.h"
#include"page7.h"
#include"page8.h"
#include"page9.h"
#include"logo.h"


int main(void);

/*
��������initCar
���ܣ���ʼ����������
��ڲ����������ṹ��ָ��pCar
����ֵ��void
*/
void initCar(PCAR pCar);

/*
��������electricityWrite
���ܣ�ʣ�����д���ļ�energy.txt
��ڲ����������ṹ��ָ��pCar
����ֵ��void
*/
void electricityWrite(PCAR pCar);

#endif