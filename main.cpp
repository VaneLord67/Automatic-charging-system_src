////////////////////////
//������
////////////////////////

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
	
	#ifdef DEBUGMODE
	page = 0;		
	#endif
	
	while(1)
	{
		switch(page)
		{
			case 0:   //��ʼ����
				//ÿ����ʼ�������������һ��������ֹ�����û���ͬһ���ڴ���в���
				free(pCar);
				PCAR pCar = (PCAR)malloc(sizeof(CAR));
				initCar(pCar);			//��ʼ����������
				page = p0();
				break;
			case 1:   //ע�����
				page = p1(pCar);
				break;
			case 2:   //��¼����
				page = p2(pCar);
				break;
			case 3:  //�˳�
				if(pCar->loginFlag == 1 && pCar->isAdmin == 0)		//�����½����д��¼
				{
					recordWrite(pCar->id,pCar);
				}
				if(pCar->isAdmin == 0)			//�û�д�ļ�
				{
					carInfoWrite(pCar);		//��������Ϣд��carinfo.txt��
				}
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
			case 8:
				page = p8();			//�������ģ�����ʻ��¼��ѯ���ܣ�
				break;
			case 9:
				page = p9(pCar);			//��ʻ��¼��ѯ
				break;
			case 10:					//һ��������
				page = p10(pCar);
				break;
			case 11:					//һ���������
				page = p11(pCar);
				break;
			case 12:					//��ͼ�ƶ�����
				page = p12(pCar);
				break;
			case 13:					
				page = p13(pCar);		//����Ա����
				break;
			case 14:
				page = p14(pCar);		//��ֵ����
				break;
			case 15:
				page = p15(pCar);		//�����������
				break;
			case 16:
				page = p16(pCar);		//������������
				break;
			case 17:
				page = p17(pCar);       //����¼��ѯ���� 
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
	//��ȡcarinfo.txt�е�ʣ�����
	FILE * fp = NULL;
	char temp[80] = {'\0'};
	fp = fopen("carinfo.txt","r");
	if ( fp == NULL )
	{
		exitFunc("file carinfo.txt open error!");
	}
	fgets(temp,80,fp);
	pCar->electricityLeft = atof(temp);
	fgets(temp,80,fp);
	pCar->x = atoi(temp);
	fgets(temp,80,fp);
	pCar->y = atoi(temp);

	if(pCar->x == 0 || pCar->y == 0)
	{
		pCar->x = 240;
		pCar->y = 240;
	}

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
	pCar->isAdmin = 0;
	pCar->balance = 0;				
	
	fclose(fp);
}

/*
��������carInfoWrite
���ܣ�����ʣ�������λ��д���ļ�carinfo.txt
��ڲ����������ṹ��ָ��pCar
����ֵ��void
*/
void carInfoWrite(PCAR pCar)
{
	FILE * fp = NULL;
	fp = fopen("carinfo.txt","w");
	if ( fp == NULL )
	{
		exitFunc("open carinfo.txt file error!");
	}
	
	fprintf(fp,"%lf\n",pCar->electricityLeft);
	fprintf(fp,"%d\n",pCar->x);
	fprintf(fp,"%d\n",pCar->y);
	
	fclose(fp);
	return;
}

