#ifndef _PAGE11_H_
#define _PAGE11_H_



extern void *buffer;
extern union REGS regs;

extern int mouseX;
extern int mouseY;
extern int press;
extern int flag;

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

#endif