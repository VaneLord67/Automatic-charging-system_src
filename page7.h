#ifndef _PAGE7_H_
#define _PAGE7_H_

extern void *buffer;
extern union REGS regs;

extern int mouseX;
extern int mouseY;
extern int press;
extern int flag;

/*
��������page7_screen
���ܣ����Ƶ���ģ��
��ڲ�����void
����ֵ��void
*/
void page7_screen(void);

/*
��������p7
���ܣ�����ģ��
��ڲ����������ṹ�����pCar
����ֵ��int���ͣ�����page��ֵ
*/
int p7(PCAR pCar);

#endif