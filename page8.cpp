/////////////////
//�������Ľ���
////////////////

#include"common.h"
#include"page8.h"

/*
��������p8
���ܣ��������Ľ���
��ڲ�����void
����ֵ��int���ͣ�����page��ֵ
*/
int p8(void)
{
	int page = 8;
	
	change_page(page8_screen);
	
	while(page == 8)
	{
		newmouse(&mouseX,&mouseY,&press);
		#ifdef SHOWMOUSE
		showMousePos();
		#endif
		
		if(mouse_press(200,20,415,192) == 1)			//��ʻ��¼��ѯ
		{
			page = 9;
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
��������page8_screen
���ܣ����Ƹ������Ľ���
��ڲ�����void
����ֵ��void
*/
void page8_screen(void)
{
	cleardevice();
	setbkcolor(WHITE);
	printHZ_withoutRec(200,20,"��������",48,DARKGRAY);
	printHZ(200,160,"��ʻ��¼��ѯ",32,DARKGRAY);
	printHZ(122, 408,"����",48,DARKGRAY);
	printHZ(400, 408,"�˳�",48,DARKGRAY);
	return;
}