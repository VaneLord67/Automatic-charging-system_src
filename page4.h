#ifndef _PAGE4_H_
#define _PAGE4_H_

#include"myf.h"

/*
��������page4_screen
���ܣ�����������ʾ����
��ڲ�����void
����ֵ��void
*/
void page4_screen(void);

/*
��������p4
���ܣ�������ʾ����
��ڲ���������ָ��pCar
����ֵ��int���ͣ�����page��ֵ
*/
int p4(PCAR pCar);

/*
��������turnToState0
���ܣ�ת����Ϩ��״̬�Ľ���Ч��
��ڲ�����void
����ֵ��void
*/
void turnToState0(void);

/*
��������turnToState1
���ܣ�ת������ʻ״̬�Ľ���Ч��
��ڲ�����void
����ֵ��void
*/
void turnToState1(void);

/*
��������turnToState2
���ܣ�ת�����ƶ�״̬�Ľ���Ч��
��ڲ�����void
����ֵ��void
*/
void turnToState2(void);

/*
��������turnOffCarFacility
���ܣ����Ϩ���ر����������豸
��ڲ���������ָ��pCar
����ֵ��void
*/
void turnOffCarFacility(PCAR pCar);

/*
��������carInfoWrite
���ܣ�����ʣ�������λ��д���ļ�carinfo.txt
��ڲ����������ṹ��ָ��pCar
����ֵ��void
*/
void carInfoWrite(PCAR pCar);

#endif