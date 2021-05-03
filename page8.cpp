/////////////////
//�������Ľ���
////////////////

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
		
		if(mouse_press(200-10,160,200+32*6+30,160+32) == 1)			//��ʻ��¼��ѯ
		{
			page = 9;
		}

		if(mouse_press(243-10,240,243+32*4+20,240+32) == 1)			//����ֵ
		{
			page = 14;
		}
		
		if(mouse_press(390,408,400+48*2*1.1+2,408+48) == 1)			//�˳�
		{
			page = 3;
		}
		
		if(mouse_press(112,408,122+48*2*1.1+2,408+48) == 1)			//����
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
	setbkcolor(LIGHTCYAN);
	setcolor(DARKGRAY);
	setfillstyle(SOLID_FILL,DARKGRAY);
	printHZ_withoutRec(200,20,"��������",48,DARKGRAY);
	setlinestyle(SOLID_LINE,0,THICK_WIDTH);
	int a[] = {130,150,170,150,170,200,150,190,130,200,130,150};
	drawpoly(6,a);
	circle(147,167,8);
	line(153,173,163,183);
	int b[] = {150,230,190,230,190,280-15,190-15,280,150,280,150,230};
	drawpoly(6,b);
	line(160,250,180,250);
	line(160,260,180,260);
	line(170,250,160,240);
	line(170,250,180,240);
	line(170,250,170,270);

	bar(200-10,160,200+32*6+30,160+32);
	bar(243-10-15,240,243+32*4+20-15,240+32);
	floodfill(200,160,DARKGRAY);
	floodfill(243,240,DARKGRAY);
	printHZ(200,160,"��ʻ��¼��ѯ",32,WHITE);
	printHZ(243-15,240,"����ֵ",32,WHITE);
	

	setfillstyle(SOLID_FILL,DARKGRAY);
	bar(112,408,122+48*2*1.1+2,408+48);
	bar(390,408,400+48*2*1.1+2,408+48);
	floodfill(123,409,DARKGRAY); 
	floodfill(401,409,DARKGRAY);
	printHZ(122, 408,"����",48,WHITE);
	printHZ(400, 408,"�˳�",48,WHITE);
	
	return;
}
