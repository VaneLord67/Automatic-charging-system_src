#ifndef _PAGE17_H_
#define _PAGE17_H_

#include"myf.h"

#define SIZE 2			//һҳ��ʾ����
#define MAX_RECORD 500	//��༸����¼

//������¼�ṹ�壬�����������û������ѡ�������ʱ�� 
typedef struct elec 
{
	char index[10];
	char user[20];
	char elec[60];
	char money[50];
	char time[60];
	char mode[20];
}ELEC,*pELEC;

/*
��������p17
���ܣ�����Ա������ѯ���� 
��ڲ���������ָ��pCar
����ֵ��int���ͣ�����page��ֵ
*/
int p17(PCAR pCar);

/*
��������page17_screen
���ܣ����Ƴ���¼��ѯ����
��ڲ�����void
����ֵ��void
*/
void page17_screen(void);

/*
��������maxPageQueryForElec 
���ܣ����س���¼�ļ���elec.txt�������ҳ��(һҳ��ʾSIZE��)
��ڲ�����void
����ֵ��int���ҳ��
*/
int maxPageQueryForElec(int * getMax);

/*
��������findRecordForElec
���ܣ��������¼
��ڲ�������ǰҳ��pageCurrent
����ֵ��void
*/
void findRecordForElec(int pageCurrent,int max);

#endif
