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
		newmouse(&mouseX,&mouseY,&press);
		showMousePos();
		if(mouse_press(237, 303, 388, 404) == 1)      //������ذ�ť
		{
			page = 0;
			break;
		}
		else if(mouse_press(413,303,564,404) == 1)        //����˳���ť
		{
			page = 3;
			break;
		}
		
	}
	return page;
}

void page4_screen(void)
{
	cleardevice();
	setbkcolor(BLACK);
	setlinestyle(SOLID_LINE,0,NORM_WIDTH);
	
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












