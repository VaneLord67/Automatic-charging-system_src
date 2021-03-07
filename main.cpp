////////////////////////
//������
////////////////////////
#include"common.h"
#include"main.h"


//����һЩȫ�ֱ����������ʹ��
void *buffer;
union REGS regs;

int mouseX;
int mouseY;
int press=0;
int flag=0;

int main(void)
{
	int graphDriver = VGA;
	int graphMode = VGAHI;
	int page = 0;
	initgraph(&graphDriver,&graphMode,"C:\\BORLANDC\\BGI");
	initMouse();
	delay(200);
	//��һ�����������ڴ�ռ䲢��ʼ������ֵ���������̽�������һ������
	PCAR pCar = (PCAR)malloc(sizeof(CAR));
	initCar(pCar);			//��ʼ����������
	
	page = 0;
	
	while(1)
	{
		switch(page)
		{
			case 0:   //��ʼ����
				//ÿ����ʼ�������������һ��������ֹ�����û���ͬһ���ڴ���в���
				free(pCar);
				PCAR pCar = (PCAR)malloc(sizeof(CAR));
				initCar(pCar);			//��ʼ����������
				//recordOut();
				page = p0();
				break;
			case 1:   //ע�����
				page = p1();
				break;
			case 2:   //��¼����
				page = p2(pCar);
				break;
			case 3:  //�˳�
				if(pCar->loginFlag == 1)		//�����½����д��¼
				{
					recordWrite(pCar->id,pCar);
				}
				electricityWrite(pCar);		//дʣ��������ļ�energy.txt��
				free(pCar);				//�˳�ǰ�ͷŶ��ڴ�
				closegraph();
				delay(1000);			//delay��ֹ����������Bug
				exit(0);
			case 4:
				page = p4(pCar);	//������ʾ����
				break;
			case 5:
				page = p5(pCar);		//�п�ģ��
				break;
			case 6:
				page = p6(pCar);		//��̼�����
				break;
			case 7:
				page = p7(pCar);		//����ģ��
				break;
			case 8:
				page = p8();			//�������ģ�����ʻ��¼��ѯ���ܣ�
				break;
			case 9:
				page = p9();			//��ʻ��¼��ѯ
				break;
			case 10:					//һ��������
				page = p10(pCar);
				break;
			case 11:
				page = p11(pCar);
				break;
			default:
				page = 0;			//���������쳣����˻ص���ʼ����
				break;
			
		}
	}
	
}

/*
��������initCar
���ܣ���ʼ����������
��ڲ����������ṹ��ָ��pCar
����ֵ��void
*/
void initCar(PCAR pCar)
{
	//��ȡenergy.txt�е�ʣ�����
	FILE * fp = NULL;
	char temp[80] = {'\0'};
	fp = fopen("energy.txt","r");
	if ( fp == NULL )
	{
		settextjustify(LEFT_TEXT,TOP_TEXT);          //�󲿶��룬��������
		settextstyle(GOTHIC_FONT,HORIZ_DIR,1);					//����ʻ������ˮƽ�����24*24����
		outtextxy(10,10,"Can't open file!Press any key to quit...");
		getch();
		exit(1);
	}
	fgets(temp,80,fp);
	pCar->electricityLeft = atoi(temp);
	//fscanf(fp,"%d",pCar->electricityLeft);
	//pCar->electricityLeft = 70;	//ʣ�����(�ָ�Ϊ���ļ�energy.txt�ж�)
	pCar->hasMileage = 0;			//��ʻ���
	pCar->airConditioningFlag = 0; //�յ�״̬
	pCar->lightFlag = 0;			//����״̬
	pCar->windowFlag = 0;			//����״̬
	pCar->musicFlag = 0; 			//���ֲ�����״̬
	pCar->runState = 0;			//��ʻ״̬��Ϩ��0����ʻ1���ƶ�2��
	pCar->temperature = 30;			//�����¶ȳ�ʼ��Ϊ30��
	pCar->speed = 60;				//�����ٶȳ�ʼ��Ϊ60km/h
	pCar->k = 0;					//��ѧģ��Kֵ��ʼ��Ϊ0
	pCar->kEquipment = 0;			//��ѧģ���й��豸��kֵ��ʼ��Ϊ0
	pCar->b = 0;				//��ѧģ��bֵ��ʼ��Ϊ0 
	pCar->loginFlag = 0;			//��½״̬��ʼ��Ϊ0
	pCar->start = 0;
	// pCar->temp = 0;
}

/*
��������electricityWrite
���ܣ�ʣ�����д���ļ�energy.txt
��ڲ����������ṹ��ָ��pCar
����ֵ��void
*/
void electricityWrite(PCAR pCar)
{
	FILE * fp = NULL;
	fp = fopen("energy.txt","w");
	if ( fp == NULL )
	{
		settextjustify(LEFT_TEXT,TOP_TEXT);          //�󲿶��룬��������
		settextstyle(GOTHIC_FONT,HORIZ_DIR,1);					//����ʻ������ˮƽ�����24*24����
		outtextxy(10,10,"Can't open file!Press any key to quit...");
		getch();
		exit(1);
	}
	
	fprintf(fp,"%d",pCar->electricityLeft);
	
	fclose(fp);
	return;
}

