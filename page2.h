#ifndef _PAGE2_H_
#define _PAGE2_H_

extern void *buffer;
extern union REGS regs;

extern int mouseX;
extern int mouseY;
extern int press;
extern int flag;

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
��ڲ������û����ı�userText�������ı�passwordText
����ֵ��int���ͣ�1Ϊ��¼�ɹ���0Ϊ��¼ʧ��
*/
int Login(char * userText, char * passwordText);



#endif