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
	delay(1000);
	//��һ�����������ڴ�ռ䲢��ʼ������ֵ���������������һ������
	PCAR pCar = (PCAR)malloc(sizeof(CAR));
	pCar->electricityLeft = 100;	//ʣ�����
	pCar->airConditioningFlag = 0; //�յ�״̬
	pCar->lightFlag = 0;			//����״̬
	pCar->windowFlag = 0;			//����״̬
	pCar->musicFlag = 0; 			//���ֲ�����״̬
	pCar->runState = 0;			//��ʻ״̬��Ϩ��0����ʻ1���ƶ�2��
	
	
	page = 5;
	
	while(1)
	{
		switch(page)
		{
			case 0:   //��ʼ����
				page = p0();
				break;
			case 1:   //ע�����
				page = p1();
				break;
			case 2:   //��¼����
				page = p2();
				break;
			case 3:  //�˳�
				free(pCar);
				closegraph();
				delay(1000);
				exit(0);
			case 4:
				page = p4();
				break;
			case 5:
				page = p5(pCar);
				break;
			default:
				page = 0;			//���������쳣����˻ص���ʼ����
				break;
			
		}
	}
	
}
