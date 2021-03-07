#ifndef _PAGE9_H_
#define _PAGE9_H_

extern void *buffer;
extern union REGS regs;

extern int mouseX;
extern int mouseY;
extern int press;
extern int flag;

#define SIZE 2

//������¼�ṹ�壬�����������û���ʱ�䡢���
typedef struct record
{
	char index[10];
	char user[20];
	char time[60];
	char mileage[10];
	//char electricityLeft[5];
}RECORD,*pRECORD;

/*
��������page9_screen
���ܣ�������ʻ��¼��ѯ����
��ڲ�����void
����ֵ��void
*/
void page9_screen(void);


/*
��������p9
���ܣ���ʻ��¼��ѯ����
��ڲ�����void
����ֵ��int���ͣ�����page��ֵ
*/
int p9(void);

/*
��������maxPageQuery
���ܣ�������ʻ��¼�ļ���record.txt�������ҳ��(һҳ��ʾ3��)
��ڲ�����void
����ֵ��int���ҳ��
*/
int maxPageQuery(void);

/*
��������findRecord
���ܣ������ʻ��¼
��ڲ�������ǰҳ��pageCurrent
����ֵ��void
*/
void findRecord(int pageCurrent);

#endif