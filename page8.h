#ifndef _PAGE8_H_
#define _PAGE8_H_

extern void *buffer;
extern union REGS regs;

extern int mouseX;
extern int mouseY;
extern int press;
extern int flag;

/*
��������page8_screen
���ܣ����Ƶ���ģ��
��ڲ�����void
����ֵ��void
*/
void page8_screen(void);

/*
��������p8
���ܣ�����ģ��
��ڲ�����void
����ֵ��int���ͣ�����page��ֵ
*/
int p8(void);

#endif