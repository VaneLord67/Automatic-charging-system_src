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
int press;
int flag=0;
//����һЩȫ�ֱ����������ֲ���ʹ��
int playIndex=0;
int isPlaySound=0;
clock_t start = 0;
clock_t end = 0;
double total = 0;

int main(void)
{
	int graphDriver = VGA;
	int graphMode = VGAHI;
	int page = 0;
	initgraph(&graphDriver,&graphMode,"C:\\BORLANDC\\BGI");
	initMouse();
	delay(1000);
	
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
				nosound();
				closegraph();
				exit(0);
			case 4:
				page = p4();
				break;
			case 5:
				page = p5();
				break;
			default:
				page = 0;			//���������쳣����˻ص���ʼ����
				break;
			
		}
	}
	
}
