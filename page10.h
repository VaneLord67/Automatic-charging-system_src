#ifndef _PAGE10_H_
#define _PAGE10_H_



extern void *buffer;
extern union REGS regs;

extern int mouseX;
extern int mouseY;
extern int press;
extern int flag;

/*
��������page10_screen
���ܣ����Ƶ���ģ��
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

#endif