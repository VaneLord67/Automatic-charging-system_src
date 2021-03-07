#ifndef _MY_F_H_
#define _MY_F_H_

//�����ṹ����
typedef struct car
{
	int electricityLeft;	//ʣ�����
	int hasMileage; //����ʻ���
	
	//��������״̬0Ϊ�رգ�1Ϊ����
	int airConditioningFlag; //�յ�״̬
	int lightFlag;			//����״̬
	int windowFlag;			//����״̬
	int musicFlag; 			//���ֲ�����״̬
	
	int runState;			//��ʻ״̬��Ϩ��0����ʻ1���ƶ�2��
	int temperature;		//�����¶�
	int speed;				//�����ٶ�(60km/h)
	int k;					//��ѧģ��kֵ
	int kEquipment;			//��ѧģ�����豸��Ӧ��k
	int b;					//��ѧģ��bֵ
	int loginFlag;			//��¼״̬��0δ��¼��1�ѵ�¼
	
	//ͨ��ʱ������������ʻ��̵ı���
	int start;				//��ʼʱ��
	int temp;				//��ʱʱ��
	
	tm info;				//��ʻ��¼��ʼʱ��
	char id[20];			//������id������¼ʱ���û�����
}CAR,*PCAR;



extern void *buffer;
extern union REGS regs;

extern int mouseX;
extern int mouseY;
extern int press;
extern int flag;


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
//��������inputPassword
//���ܣ����뷨����������Ϊ��DEFAULT_FONT,HORIZ_DIR,3��//��3��Ĭ�����壩��
//��ڲ�������ʼλ�õ�x,y����ĵ�ַ���Ƿ������뷨�ı����ڵı�־���ı����ȵĵ�ַ��ָ���ı����ַ���(��Щ������Ҫ�ڵ��øú����ĺ���������ã��ѵ�ַ������),��ɫ
//����ֵ��void
///////////////////////////////////
void inputPassword(int * x_input, int * y_input,int * inputFlag,int * inputLength, char * text, int color);

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


//��������recordOut
//���ܣ��ص���ʼ����/�˳����� ��д��ʱ�䵽record.txt
//��ڲ�����void
//����ֵ��void
///////////////////////////////////
void recordOut(void);




// /*
// ��������recordIn
// ���ܣ���¼ʱд��ʱ�䵽record.txt
// ��ڲ�����id,�����ṹ�����pCar
// ����ֵ��void
// */
//void recordIn(char *p,PCAR pCar);

///////////////////////////////////
//��������recordWrite
//���ܣ�д��ʻ��¼��record.txt
//��ڲ�����id,�����ṹ�����pCar
//����ֵ��void
///////////////////////////////////
void recordWrite(char * p,PCAR pCar);


///////////////////////////////////
//��������playSound
//���ܣ���������
//��ڲ�����void
//����ֵ��void
///////////////////////////////////
// void playSound(void);


#endif














