/////////////////
//����ģ��
////////////////

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
	
	int isPopWindow = 0;
	void * buf = NULL;
	
	change_page(page7_screen);
	
	while(page == 7)
	{
		newmouse(&mouseX,&mouseY,&press);
		#ifdef SHOWMOUSE
		showMousePos();
		#endif
		
		if(0 == isPopWindow)
		{
			if(mouse_press(235,160,380,196) == 1)			//һ�����
			{
				if(pCar->electricityLeft >= MAX_ELECTRICITY)
				{
					popWindow_withoutFlush(&buf, &isPopWindow, "��������");
					continue;
				}
				page = 10;
			}
			
			if(mouse_press(235,160+50+50,379,397) == 1)		//һ������
			{
				delay(200);	//��ֹ����
				if(pCar->electricityLeft >= MAX_ELECTRICITY)
				{
					popWindow_withoutFlush(&buf, &isPopWindow, "��������");
					continue;
				}
				page = 11;
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
		else
		{
			popWindow_withoutFlush(&buf, &isPopWindow, "");
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