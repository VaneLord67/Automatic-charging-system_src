#ifndef _PAGE10_H_
#define _PAGE10_H_

#include"myf.h"

/*
��������updateBalance
���ܣ������û����
��ڲ������û�ָ��pCar
����ֵ��void
*/
void updateBalance(PCAR pCar);

/*
��������page10_screen
���ܣ�����һ��������
��ڲ�����void
����ֵ��void
*/
void page10_screen(void);

/*
��������p10
���ܣ�һ��������
��ڲ����������ṹ�����pCar
����ֵ��int���ͣ�����page��ֵ
*/
int p10(PCAR pCar);

/*
��������CarElecWrite_charge
���ܣ������������仯д���ļ�elec.txt��
��ڲ�����id,�����ṹ��ָ��pCar���������ǰ����p1
����ֵ��void
*/
void CarElecWrite_charge(char * p, PCAR pCar, double *p1);

/*
��������drawcircle;
����:��ָ��λ�û�һ��Բ 
��ڲ�����Բ������
����ֵ��void
*/
void drawcircle(int x,int y);

#endif
