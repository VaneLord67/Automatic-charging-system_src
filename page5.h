#ifndef _PAGE5_H_
#define _PAGE5_H_

#include"myf.h"

/*
��������page5_screen
���ܣ������п�ģ�����
��ڲ�����void
����ֵ��void
*/
void page5_screen(void);

/*
��������p5
���ܣ��п�ģ��
��ڲ�����void
����ֵ��int���ͣ�����page��ֵ
*/
int p5(PCAR pCar);

/*
��������stateDraw
���ܣ�����״̬���ƽ���
��ڲ��������ο�λ�ã���־��ַ
����ֵ��void
*/
void stateDraw(int x1,int y1,int x2,int y2,int * flag);

/*
��������changeToOn
���ܣ��л�������״̬
��ڲ��������ο�λ�ã���־��ַ
����ֵ��int���л�����1��δ�л�����0
*/
int changeToOn(int x1,int y1,int x2,int y2,int* flag);


/*
��������changeToOff
���ܣ��л����ر�״̬
��ڲ��������ο�λ�ã���־��ַ
����ֵ��int���л�����1��δ�л�����0
*/
int changeToOff(int x1,int y1,int x2,int y2,int* flag);


#endif