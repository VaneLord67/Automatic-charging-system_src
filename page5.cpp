
#include"common.h"
#include"page5.h"

/*
��������p5
���ܣ��п�ģ��
��ڲ�����void
����ֵ��int���ͣ�����page��ֵ
*/
int p5(PCAR pCar)
{
	int page = 5;
	
	change_page(page5_screen);
	clrmous(mouseX,mouseY);
	stateDraw(108,104,186,145,&(pCar->airConditioningFlag));
	stateDraw(108,104+100,186,145+100,&(pCar->lightFlag));
	stateDraw(108+300,104,186+300,145,&(pCar->windowFlag));
	stateDraw(108+300,104+100,186+300,145+100,&(pCar->musicFlag));
	save_bk_mou(mouseX,mouseY);
	drawmous(mouseX,mouseY);

	while(page == 5)
	{
		newmouse(&mouseX,&mouseY,&press);
		showMousePos();
		
		changeToOn(108,104,186,145,&(pCar->airConditioningFlag));
		changeToOff(108+78,104,186+78,145,&(pCar->airConditioningFlag));
		changeToOn(108,104+100,186,145+100,&(pCar->lightFlag));
		changeToOff(108+78,104+100,186+78,145+100,&(pCar->lightFlag));
		changeToOn(108+300,104,186+300,145,&(pCar->windowFlag));
		changeToOff(108+78+300,104,186+78+300,145,&(pCar->windowFlag));
		changeToOn(108+300,104+100,186+300,145+100,&(pCar->musicFlag));
		changeToOff(108+78+300,104+100,186+78+300,145+100,&(pCar->musicFlag));
		
		if(mouse_press(413,303,564,404) == 1)        //����˳���ť
		{
			// nosound();
			page = 3;
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
	
	printHZ(200,20,"�п�ģ��",48,DARKGRAY);
	printHZ_withoutRec(26, 100,"�յ�",24,DARKGRAY);
	printHZ_withoutRec(26, 200,"����",24,DARKGRAY);
	printHZ_withoutRec(26+300, 100,"�촰",24,DARKGRAY);
	printHZ_withoutRec(26+300, 200,"����",24,DARKGRAY);
	
	setlinestyle(SOLID_LINE,0,NORM_WIDTH);
	setcolor(DARKGRAY);
	rectangle(237,303,388,404);
	rectangle(413,303,564,404);
	puthz(251,319,"����",48,52,DARKGRAY);
	puthz(429,319,"�˳�",48,52,DARKGRAY);
	
	return;
}

/*
��������changeToOn
���ܣ��л�������״̬
��ڲ��������ο�λ�ã���־��ַ
����ֵ��void
*/
void changeToOn(int x1,int y1,int x2,int y2,int* flag)
{
	if(mouse_press(x1,y1,x2,y2) == 1 && 0 == (*flag))
	{
		(*flag) = 1;
		clrmous(mouseX,mouseY);
		delay(100);
		
		setcolor(DARKGRAY);
		setfillstyle(SOLID_FILL,WHITE);
		bar(x1+78,y1,x2+78,y2);
		rectangle(x1+78,y1,x2+78,y2);
		puthz(x1+32+78,y1+11,"��",24,28,DARKGRAY);
		
		setfillstyle(SOLID_FILL,GREEN);
		bar(x1,y1,x2,y2);
		puthz(x1+32,y1+11,"��",24,28,YELLOW);
		
		save_bk_mou(mouseX,mouseY);
		drawmous(mouseX,mouseY);
		
	}
}

/*
��������changeToOff
���ܣ��л�������״̬
��ڲ��������ο�λ�ã���־��ַ
����ֵ��void
*/
void changeToOff(int x1,int y1,int x2,int y2,int* flag)
{
	if(mouse_press(x1,y1,x2,y2) == 1 && 1 == (*flag))
	{
		(*flag) = 0;
		clrmous(mouseX,mouseY);
		delay(100);
		
		setcolor(DARKGRAY);
		setfillstyle(SOLID_FILL,GREEN);
		bar(x1,y1,x2,y2);
		rectangle(x1,y1,x2,y2);
		puthz(x1+32,y1+11,"��",24,28,YELLOW);
		
		setcolor(DARKGRAY);
		setfillstyle(SOLID_FILL,WHITE);
		bar(x1-78,y1,x2-78,y2);
		rectangle(x1-78,y1,x2-78,y2);
		puthz(x1+32-78,y1+11,"��",24,28,DARKGRAY);
		
		save_bk_mou(mouseX,mouseY);
		drawmous(mouseX,mouseY);
		
	}
	
	
}
/*
��������stateDraw
���ܣ�����״̬���ƽ���
��ڲ��������ο�λ�ã���־��ַ
����ֵ��void
*/
void stateDraw(int x1,int y1,int x2,int y2,int * flag)
{
	if((*flag) == 0) 
	{
		rectangle(x1,y1,x2,y2);
		puthz(x1+32,y1+11,"��",24,28,DARKGRAY);
		rectangle(x1+78,y1,x2+78,y2);
		setfillstyle(SOLID_FILL,GREEN);
		bar(x1+78,y1,x2+78,y2);
		puthz(x1+32+78,y1+11,"��",24,28,YELLOW);
	}
	else
	{
		setcolor(DARKGRAY);
		setfillstyle(SOLID_FILL,WHITE);
		bar(x1+78,y1,x2+78,y2);
		rectangle(x1+78,y1,x2+78,y2);
		puthz(x1+32+78,y1+11,"��",24,28,DARKGRAY);
		
		setfillstyle(SOLID_FILL,GREEN);
		bar(x1,y1,x2,y2);
		puthz(x1+32,y1+11,"��",24,28,YELLOW);
	}
	
	
	return;
}

















