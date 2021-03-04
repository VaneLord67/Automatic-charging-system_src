#ifndef _PAGE5_H_
#define _PAGE5_H_

extern void *buffer;
extern union REGS regs;

extern int mouseX;
extern int mouseY;
extern int press;
extern int flag;

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
����ֵ��void
*/
void changeToOn(int x1,int y1,int x2,int y2,int* flag);

/*
��������changeToOff
���ܣ��л�������״̬
��ڲ��������ο�λ�ã���־��ַ
����ֵ��void
*/
void changeToOff(int x1,int y1,int x2,int y2,int* flag);


#endif