#include"common.h"
#include"page0.h"

/*
��������p0
���ܣ���ʼ����Ĺ���
��ڲ�����void
����ֵ��int���ͣ�����page��ֵ
*/
int p0(void)
{
	int page = 0;
	change_page(page0_screen);
	
	while(page == 0)
	{
		// if(1 == isPlaySound)
		// {
			// playSound();
		// }
		newmouse(&mouseX,&mouseY,&press);
		showMousePos();
		
		if(mouse_press(237, 303, 388, 404) == 1)      //���ע�ᰴť
		{
			page = 1;
		}
		else if(mouse_press(413,303,564,404) == 1)        //����˳���ť
		{
			nosound();
			page = 3;
		}
		else if(mouse_press(47,303,198,404) == 1)			//�����¼��ť
		{
			page = 2;
		}
		
	}
	return page;
	
}

/*
��������page0_screen
���ܣ����Ƴ�ʼ����
��ڲ�����void
����ֵ��void
*/
void page0_screen(void)
{
	cleardevice();
	setbkcolor(WHITE);
	setlinestyle(SOLID_LINE,0,NORM_WIDTH);
	// rectangle(150,64,498,209);
	printHZ_withoutRec(25,93,"����Դ�����Զ����ϵͳ",48,DARKGRAY);
	rectangle(47,303,198,404);
	rectangle(237,303,388,404);
	rectangle(413,303,564,404);
	puthz(59,319,"��¼",48,52,DARKGRAY);
	puthz(251,319,"ע��",48,52,DARKGRAY);
	puthz(429,319,"�˳�",48,52,DARKGRAY);
	// settextstyle(DEFAULT_FONT,HORIZ_DIR,10);
	// outtextxy(174,90,"DEMO");
	return;
}














