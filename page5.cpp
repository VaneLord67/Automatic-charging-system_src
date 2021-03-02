
#include"common.h"
#include"page5.h"

/*
函数名：p5
功能：中控模块
入口参数：void
返回值：int类型，返回page的值
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
		
		if(mouse_press(413,303,564,404) == 1)        //点击退出按钮
		{
			// nosound();
			page = 3;
		}
		if(mouse_press(108,104,186,145) == 1 && airConditioningFlag == 0)		//点击空调的“开”按钮
		{
			clrmous(mouseX,mouseY);
			delay(100);
			
			airConditioningFlag = 1;
			setcolor(DARKGRAY);
			setfillstyle(SOLID_FILL,WHITE);
			bar(186,104,186+78,145);
			rectangle(186,104,186+78,145);
			puthz(140+78,115,"关",24,28,DARKGRAY);
			
			setfillstyle(SOLID_FILL,GREEN);
			bar(108,104,186,145);
			puthz(140,115+100,"开",24,28,DARKGRAY);
			
			save_bk_mou(mouseX,mouseY);
			drawmous(mouseX,mouseY);
			
		}
		if(mouse_press(186,104,186+78,145) == 1 && airConditioningFlag == 1)	//点击空调的“关”按钮
		{
			clrmous(mouseX,mouseY);
			delay(100);
			
			airConditioningFlag = 0;
			
			setcolor(DARKGRAY);
			setfillstyle(SOLID_FILL,RED);
			bar(186,104,186+78,145);
			rectangle(186,104,186+78,145);
			puthz(140+78,115,"关",24,28,DARKGRAY);
			
			setcolor(DARKGRAY);
			setfillstyle(SOLID_FILL,WHITE);
			bar(108,104,186,145);
			rectangle(108,104,186,145);
			puthz(140,115,"开",24,28,DARKGRAY);
			
			
			save_bk_mou(mouseX,mouseY);
			drawmous(mouseX,mouseY);
		}
		
		if(mouse_press(237, 303, 388, 404) == 1)      //点击返回按钮
		{
			page = 0;
		}
	}
	
	return page;
}

/*
函数名：page5_screen
功能：绘制中控模块界面
入口参数：void
返回值：void
*/
void page5_screen(void)
{
	cleardevice();
	setbkcolor(WHITE);
	setlinestyle(SOLID_LINE,0,NORM_WIDTH);
	setcolor(DARKGRAY);
	printHZ_withoutRec(26, 100,"空调",24,DARKGRAY);
	rectangle(108,104,186,145);
	puthz(140,115,"开",24,28,DARKGRAY);
	rectangle(186,104,186+78,145);
	setfillstyle(SOLID_FILL,LIGHTBLUE);
	bar(186,104,186+78,145);
	puthz(140+78,115,"关",24,28,WHITE);
	
	printHZ(200,20,"中控模块",48,DARKGRAY);
	
	printHZ_withoutRec(26, 200,"车灯",24,DARKGRAY);
	setcolor(DARKGRAY);
	setfillstyle(SOLID_FILL,LIGHTBLUE);
	rectangle(108,104+100,186,145+100);
	puthz(140,115+100,"开",24,28,DARKGRAY);
	rectangle(186,104+100,186+78,145+100);
	bar(186,104+100,186+78,145+100);
	puthz(140+78,115+100,"关",24,28,DARKGRAY);
	
	printHZ_withoutRec(26+300, 100,"天窗",24,DARKGRAY);
	rectangle(108+300,104,186+300,145);
	puthz(140+300,115,"开",24,28,DARKGRAY);
	rectangle(186+300,104,186+78+300,145);
	setfillstyle(SOLID_FILL,LIGHTBLUE);
	bar(186+300,104,186+78+300,145);
	puthz(140+78+300,115,"关",24,28,DARKGRAY);
	
	printHZ_withoutRec(26+300, 200,"音乐",24,DARKGRAY);
	setcolor(DARKGRAY);
	setfillstyle(SOLID_FILL,LIGHTBLUE);
	rectangle(108+300,104+100,186+300,145+100);
	puthz(140+300,115+100,"开",24,28,DARKGRAY);
	rectangle(186+300,104+100,186+78+300,145+100);
	bar(186+300,104+100,186+78+300,145+100);
	puthz(140+78+300,115+100,"关",24,28,DARKGRAY);
	
	rectangle(237,303,388,404);
	rectangle(413,303,564,404);
	puthz(251,319,"返回",48,52,DARKGRAY);
	puthz(429,319,"退出",48,52,DARKGRAY);
	
	return;
}