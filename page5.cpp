
#include"common.h"
#include"page5.h"

/*
��������p5
���ܣ��п�ģ��
��ڲ�����void
����ֵ��int���ͣ�����page��ֵ
*/
int p5(void)
{
	int page = 5;
	int airConditioningFlag = 0;
	
	delay(1000);
	change_page(page5_screen);
	delay(1000);
	
	while(page == 5)
	{
		newmouse(&mouseX,&mouseY,&press);
		showMousePos();
		
		if(mouse_press(413,303,564,404) == 1)        //����˳���ť
		{
			// nosound();
			page = 3;
		}
		if(mouse_press(108,104,186,145) == 1 && airConditioningFlag == 0)		//����յ��ġ�������ť
		{
			clrmous(mouseX,mouseY);
			delay(100);
			
			airConditioningFlag = 1;
			setcolor(DARKGRAY);
			setfillstyle(SOLID_FILL,WHITE);
			bar(186,104,186+78,145);
			rectangle(186,104,186+78,145);
			puthz(140+78,115,"��",24,28,DARKGRAY);
			
			setfillstyle(SOLID_FILL,GREEN);
			bar(108,104,186,145);
			puthz(140,115+100,"��",24,28,DARKGRAY);
			
			save_bk_mou(mouseX,mouseY);
			drawmous(mouseX,mouseY);
			
		}
		if(mouse_press(186,104,186+78,145) == 1 && airConditioningFlag == 1)	//����յ��ġ��ء���ť
		{
			clrmous(mouseX,mouseY);
			delay(100);
			
			airConditioningFlag = 0;
			
			setcolor(DARKGRAY);
			setfillstyle(SOLID_FILL,RED);
			bar(186,104,186+78,145);
			rectangle(186,104,186+78,145);
			puthz(140+78,115,"��",24,28,DARKGRAY);
			
			setcolor(DARKGRAY);
			setfillstyle(SOLID_FILL,WHITE);
			bar(108,104,186,145);
			rectangle(108,104,186,145);
			puthz(140,115,"��",24,28,DARKGRAY);
			
			
			save_bk_mou(mouseX,mouseY);
			drawmous(mouseX,mouseY);
		}
		
		if(mouse_press(237, 303, 388, 404) == 1)      //������ذ�ť
		{
			page = 0;
		}
	}
	
	return page;
}

/*
��������page5_screen
���ܣ������п�ģ�����
��ڲ�����void
����ֵ��void
*/
void page5_screen(void)
{
	cleardevice();
	setbkcolor(WHITE);
	setlinestyle(SOLID_LINE,0,NORM_WIDTH);
	setcolor(DARKGRAY);
	printHZ_withoutRec(26, 100,"�յ�",24,DARKGRAY);
	rectangle(108,104,186,145);
	puthz(140,115,"��",24,28,DARKGRAY);
	rectangle(186,104,186+78,145);
	setfillstyle(SOLID_FILL,LIGHTBLUE);
	bar(186,104,186+78,145);
	puthz(140+78,115,"��",24,28,WHITE);
	
	printHZ(200,20,"�п�ģ��",48,DARKGRAY);
	
	printHZ_withoutRec(26, 200,"����",24,DARKGRAY);
	setcolor(DARKGRAY);
	setfillstyle(SOLID_FILL,LIGHTBLUE);
	rectangle(108,104+100,186,145+100);
	puthz(140,115+100,"��",24,28,DARKGRAY);
	rectangle(186,104+100,186+78,145+100);
	bar(186,104+100,186+78,145+100);
	puthz(140+78,115+100,"��",24,28,DARKGRAY);
	
	printHZ_withoutRec(26+300, 100,"�촰",24,DARKGRAY);
	rectangle(108+300,104,186+300,145);
	puthz(140+300,115,"��",24,28,DARKGRAY);
	rectangle(186+300,104,186+78+300,145);
	setfillstyle(SOLID_FILL,LIGHTBLUE);
	bar(186+300,104,186+78+300,145);
	puthz(140+78+300,115,"��",24,28,DARKGRAY);
	
	printHZ_withoutRec(26+300, 200,"����",24,DARKGRAY);
	setcolor(DARKGRAY);
	setfillstyle(SOLID_FILL,LIGHTBLUE);
	rectangle(108+300,104+100,186+300,145+100);
	puthz(140+300,115+100,"��",24,28,DARKGRAY);
	rectangle(186+300,104+100,186+78+300,145+100);
	bar(186+300,104+100,186+78+300,145+100);
	puthz(140+78+300,115+100,"��",24,28,DARKGRAY);
	
	rectangle(237,303,388,404);
	rectangle(413,303,564,404);
	puthz(251,319,"����",48,52,DARKGRAY);
	puthz(429,319,"�˳�",48,52,DARKGRAY);
	
	return;
}