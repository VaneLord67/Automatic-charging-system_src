#ifndef _MY_MOUSE_TEST_H_
#define _MY_MOUSE_TEST_H_

void initMouse(void);	//��ʼ�����
void save_bk_mou(int nx,int ny);	//������걳��
void mouse(int x,int y);		//�����
void drawmous(int nx,int ny);	//���Ļ���
void mread(int *nx,int *ny,int *nbuttons); //�������Ϣ
void newmouse(int *nx,int *ny,int *nbuttons);	//�������
void clrmous(int nx,int ny);	//������
int mouse_press(int x1, int y1, int x2, int y2);	//��������

#endif