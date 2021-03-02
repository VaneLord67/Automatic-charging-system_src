#ifndef _MY_F_H_
#define _MY_F_H_

extern void *buffer;
extern union REGS regs;

extern int mouseX;
extern int mouseY;
extern int press;
extern int flag;

extern int playIndex;
extern int isPlaySound;
extern clock_t start;
extern clock_t end;
extern double total;

///////////////////////////////////
//��������printHZ
//���ܣ���x,y����ӡsָ��ĺ����ַ���(�����ο�)
//��ڲ�������һ�����ֵ����꣺x,y��
//        �������ַ�����s��
//        ����С��flag��
//        ����ɫ��color��
//����ֵ��void
///////////////////////////////////
void printHZ(int x, int y,char *s,int flag,int color);

///////////////////////////////////
//��������printHZ_withoutRec
//���ܣ���x,y����ӡsָ��ĺ����ַ���(�������ο�)
//��ڲ�������һ�����ֵ����꣺x,y��
//        �������ַ�����s��
//        ����С��flag��
//        ����ɫ��color��
//����ֵ��void
///////////////////////////////////
void printHZ_withoutRec(int x, int y,char *s,int flag,int color);

///////////////////////////////////
//��������printText
//���ܣ���x,y����ӡsָ���Ӣ���ַ���(�����ο�)
//��ڲ�������һ���ַ������꣺x,y��
//        ���ַ�����s��
//        ����С��flag (0-10)��
//        ����ɫ��color��
//����ֵ��void
///////////////////////////////////
void printText(int x, int y,char *s,int flag,int color);


///////////////////////////////////
//��������printText_withoutRec
//���ܣ���x,y����ӡsָ���Ӣ���ַ���(�������ο�)
//��ڲ�������һ���ַ������꣺x,y��
//        ���ַ�����s��
//        ����С��flag (0-10)��
//        ����ɫ��color��
//����ֵ��void
///////////////////////////////////
void printText_withoutRec(int x, int y,char *s,int flag,int color);

///////////////////////////////////
//��������change_page
//���ܣ�ҳ���л�
//��ڲ�������ҳ��ĺ����ĵ�ַ
//����ֵ��void
///////////////////////////////////
void change_page(void(*draw_screen)(void));

///////////////////////////////////
//��������showMousePos
//���ܣ����Ͻ���ʾ�������
//��ڲ�������ҳ��ĺ����ĵ�ַ
//����ֵ��void
///////////////////////////////////
void showMousePos(void);

///////////////////////////////////
//��������inputText
//���ܣ����뷨����������Ϊ��DEFAULT_FONT,HORIZ_DIR,3��//��3��Ĭ�����壩��
//��ڲ�������ʼλ�õ�x,y����ĵ�ַ���Ƿ������뷨�ı����ڵı�־���ı����ȵĵ�ַ��ָ���ı����ַ���(��Щ������Ҫ�ڵ��øú����ĺ���������ã��ѵ�ַ������)
//����ֵ��void
///////////////////////////////////
void inputText(int * x_input, int * y_input,int * inputFlag,int * inputLength, char * text, int color);

///////////////////////////////////
//��������DiscardInput
//���ܣ����������뷨״̬�µļ�������
//��ڲ�����void
//����ֵ��void
///////////////////////////////////
void DiscardInput(void);

///////////////////////////////////
//��������popWindow
//���ܣ�����Ļ���뵯��������ʾ���ֺ�һ�����ڵ����OK��
//��ڲ�����������ĺ�����������״̬�����ĵ�ַ�������ַ����ĵ�ַ
//����ֵ��void
///////////////////////////////////
void popWindow(void(*draw_screen)(void), int * isPopWindow, char *s);

///////////////////////////////////
//��������popWindow_withoutFlush
//���ܣ�����Ļ���뵯������OK���ػ����棬����ʹ��putimage�ָ�����ǰ���棩������ʾ���ֺ�һ�����ڵ����OK��
//��ڲ������洢ͼ���ָ��ĵ�ַ������״̬�����ĵ�ַ�������ַ����ĵ�ַ����״̬�����ĵ�ַ�������ַ����ĵ�ַ
//����ֵ��void
///////////////////////////////////
void popWindow_withoutFlush(void ** buf, int * isPopWindow, char *s);

///////////////////////////////////
//��������playSound
//���ܣ���������
//��ڲ�����void
//����ֵ��void
///////////////////////////////////
void playSound(void);


#endif














