/////////////////
//����ģ��
////////////////

#include"common.h"
#include"page7.h"

/*
��������p7
���ܣ�����ģ��
��ڲ����������ṹ�����pCar
����ֵ��int���ͣ�����page��ֵ
*/
int p7(PCAR pCar)
{
	int page = 7;
	
	change_page(page7_screen);
	
	while(page == 7)
	{
		newmouse(&mouseX,&mouseY,&press);
		#ifdef SHOWMOUSE
		showMousePos();
		#endif
		
		if(mouse_press(235,160,380,196) == 1)			//һ�����
		{
			pCar->electricityLeft = 70;
		}
		
		if(mouse_press(235,160+50+50,379,397) == 1)		//һ������
		{
			pCar->electricityLeft = 70;
		}
		
		if(mouse_press(401,409,508,459) == 1)			//�˳�
		{
			page = 3;
		}
		
		if(mouse_press(123,409,230,459) == 1)			//����
		{
			page = 4;
		}
		
	}
	
	return page;
}

/*
��������page7_screen
���ܣ����Ƶ���ģ��
��ڲ�����void
����ֵ��void
*/
void page7_screen(void)
{
	cleardevice();
	setbkcolor(WHITE);
	printHZ_withoutRec(200,20,"��������",48,DARKGRAY);
	printHZ(235,160,"һ�����",32,DARKGRAY);
	printHZ(235,160+50+50,"һ������",32,DARKGRAY);
	printHZ(122, 408,"����",48,DARKGRAY);
	printHZ(400, 408,"�˳�",48,DARKGRAY);
	return;
}