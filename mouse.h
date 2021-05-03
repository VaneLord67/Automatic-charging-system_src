#ifndef _MY_MOUSE_H_
#define _MY_MOUSE_H_

#include"myf.h"

/*
��������initMouse
����:��ʼ�����
��ڲ�����void
����ֵ��void
*/
void initMouse(void);	

/*
��������save_bk_mou
����:������걳��
��ڲ������������nx,ny
����ֵ��void
*/
void save_bk_mou(int nx,int ny);	

/*
��������mouse
����:�����
��ڲ������������x,y
����ֵ��void
*/
void mouse(int x,int y);	

/*
��������drawmous
����:���Ļ���
��ڲ������������nx,ny
����ֵ��void
*/
void drawmous(int nx,int ny);	

/*
��������mread
����:�������Ϣ
��ڲ������������nx,ny�ĵ�ַ����갴�µ�ַ
����ֵ��void
*/
void mread(int *nx,int *ny,int *nbuttons); 

/*
��������newmouse
����:�������
��ڲ������������nx,ny�ĵ�ַ����갴�µ�ַ
����ֵ��void
*/
void newmouse(int *nx,int *ny,int *nbuttons);	

/*
��������clrmous
����:������
��ڲ������������nx,ny
����ֵ��void
*/
void clrmous(int nx,int ny);	

/*
��������mouse_press
����:��������
��ڲ��������ο�x1,y1,x2,y2
����ֵ��int������Ϊ1���ڿ���Ϊ2���Ҽ�Ϊ3
*/
int mouse_press(int x1, int y1, int x2, int y2);	

/*
��������mouse_pressCenter
����:����������ʹ�С���������
��ڲ�������������x,y����Сsize
����ֵ��int������Ϊ1���ڿ���Ϊ2���Ҽ�Ϊ3
*/
int mouse_pressCenter(int centerX,int centerY,int size); 

#endif