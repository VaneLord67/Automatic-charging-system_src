#ifndef _PAGE11_H_
#define _PAGE11_H_

#include"myf.h"

/*
��������page11_screen
���ܣ�����һ���������
��ڲ�����void
����ֵ��void
*/
void page11_screen(void);

/*
��������p11
���ܣ�һ���������
��ڲ����������ṹ�����pCar
����ֵ��int���ͣ�����page��ֵ
*/
int p11(PCAR pCar);

/*
��������CarElecWrite_change
���ܣ������������仯д���ļ�elec.txt��
��ڲ�����id,�����ṹ��ָ��pCar���������ǰ����p1
����ֵ��void
*/
void CarElecWrite_change(char * p, PCAR pCar, double *p1);

#endif
