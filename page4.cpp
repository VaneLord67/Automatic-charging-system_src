/////////////////
//��¼�ɹ���ת����
////////////////

#include"common.h"
#include"page4.h"

int p4(void)
{
	int page = 4;
	change_page(page4_screen);
	
	while(page == 4)
	{		
		if(1 == isPlaySound)
		{
			playSound();
		}
		newmouse(&mouseX,&mouseY,&press);
		showMousePos();
		if(mouse_press(237, 303, 388, 404) == 1)      //������ذ�ť
		{
			page = 0;
			break;
		}
		else if(mouse_press(413,303,564,404) == 1)        //����˳���ť
		{
			isPlaySound = 0;
			nosound();
			page = 3;
			break;
		}
		else if(mouse_press(47,303,198,404) == 1)			//������Ű�ť
		{
			if(0 == isPlaySound)
			{
				start = clock();
				isPlaySound = 1;
			}
		}		
		else if(mouse_press(150,64,498,209) == 1)		//���CJR(ȡ������)
		{
			isPlaySound = 0;
			nosound();
		}
	}
	return page;
}

void page4_screen(void)
{
	cleardevice();
	setbkcolor(BLACK);
	setlinestyle(SOLID_LINE,0,NORM_WIDTH);
	
	// printText(20,20,"HELLO",6,RED);
	
	rectangle(47,303,198,404);
	rectangle(237,303,388,404);
	rectangle(413,303,564,404);
	puthz(59,319,"����",48,52,RED);
	puthz(251,319,"����",48,52,RED);
	puthz(429,319,"�˳�",48,52,RED);
	
	rectangle(150,64,498,209);
	settextstyle(DEFAULT_FONT,HORIZ_DIR,10);
	setcolor(BLUE);
	outtextxy(174,90,"CJR");
	return;
}












