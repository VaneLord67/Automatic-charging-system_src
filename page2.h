#ifndef _PAGE2_H_
#define _PAGE2_H_

#include"myf.h"

/*
��������page2_screen
���ܣ���¼�������
��ڲ�����void
����ֵ��void
*/
void page2_screen(void);

/*
��������p2
���ܣ���¼����Ĺ���
��ڲ����������ṹ��ָ��pCar
����ֵ��int���ͣ�����page��ֵ
*/
int p2(PCAR pCar);

/*
��������Login
���ܣ���¼
��ڲ������û����ı�userText�������ı�passwordText,����Աģʽ��־λadminMode,����ָ��pCar
����ֵ��int���ͣ�1Ϊ��¼�ɹ���0Ϊ��¼ʧ��
*/
int Login(char * userText, char * passwordText,int adminMode,PCAR pCar);



#endif