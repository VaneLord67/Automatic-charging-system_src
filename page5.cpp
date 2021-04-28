//page5 中控界面

#include"page5.h"

/*
函数名：p5
功能：中控模块
入口参数：void
返回值：int类型，返回page的值
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
		
		if(changeToOn(108,104,186,145,&(pCar->airConditioningFlag)) == 1)	
		{
			pCar->kEquipment = pCar->kEquipment - 1;
		}
		if(changeToOff(108+78,104,186+78,145,&(pCar->airConditioningFlag)) == 1)
		{
			pCar->kEquipment = pCar->kEquipment + 1;
		}
		changeToOn(108,104+100,186,145+100,&(pCar->lightFlag));
		changeToOff(108+78,104+100,186+78,145+100,&(pCar->lightFlag));
		changeToOn(108+300,104,186+300,145,&(pCar->windowFlag));
		changeToOff(108+78+300,104,186+78+300,145,&(pCar->windowFlag));
		changeToOn(108+300,104+100,186+300,145+100,&(pCar->musicFlag));
		changeToOff(108+78+300,104+100,186+78+300,145+100,&(pCar->musicFlag));
				
		if(mouse_press(390,408,400+48*2*1.1+2,408+48) == 1)			//退出
		{
			page = 3;
		}
		
		if(mouse_press(112,408,122+48*2*1.1+2,408+48) == 1)			//返回
		{
			page = 4;
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
	setbkcolor(LIGHTCYAN);
	setcolor(DARKGRAY);
	setlinestyle(SOLID_LINE,0,NORM_WIDTH);
	
	printHZ_withoutRec(200,20,"中控功能",48,DARKGRAY);
	printHZ_withoutRec(26, 110,"空调",24,DARKGRAY);
	printHZ_withoutRec(26, 210,"车灯",24,DARKGRAY);
	printHZ_withoutRec(26+300, 110,"天窗",24,DARKGRAY);
	printHZ_withoutRec(26+300, 210,"音乐",24,DARKGRAY);
	
	setlinestyle(SOLID_LINE,0,NORM_WIDTH);
	setcolor(DARKGRAY);
	
	setfillstyle(SOLID_FILL,DARKGRAY);
	bar(112,408,122+48*2*1.1+2,408+48);
	bar(390,408,400+48*2*1.1+2,408+48);
	floodfill(123,409,DARKGRAY); 
	floodfill(401,409,DARKGRAY);
	printHZ(122, 408,"返回",48,WHITE);
	printHZ(400, 408,"退出",48,WHITE);
	
	return;
}

/*
函数名：changeToOn
功能：切换至开启状态
入口参数：矩形框位置，标志地址
返回值：int，切换返回1，未切换返回0
*/
int changeToOn(int x1,int y1,int x2,int y2,int* flag)
{
	if(mouse_press(x1,y1,x2,y2) == 1 && 0 == (*flag))
	{
		(*flag) = 1;
		clrmous(mouseX,mouseY);
		delay(100);
		
		setcolor(DARKGRAY);
		setfillstyle(SOLID_FILL,LIGHTCYAN);
		bar(x1+78,y1,x2+78,y2);
		rectangle(x1+78,y1,x2+78,y2);
		puthz(x1+32+78,y1+11,"关",24,28,DARKGRAY);
		
		setfillstyle(SOLID_FILL,GREEN);
		bar(x1,y1,x2,y2);
		puthz(x1+32,y1+11,"开",24,28,YELLOW);
		
		save_bk_mou(mouseX,mouseY);
		drawmous(mouseX,mouseY);
		return 1;
	}
	return 0;
}

/*
函数名：changeToOff
功能：切换至关闭状态
入口参数：矩形框位置，标志地址
返回值：int，切换返回1，未切换返回0
*/
int changeToOff(int x1,int y1,int x2,int y2,int* flag)
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
		puthz(x1+32,y1+11,"关",24,28,YELLOW);
		
		setcolor(DARKGRAY);
		setfillstyle(SOLID_FILL,LIGHTCYAN);
		bar(x1-78,y1,x2-78,y2);
		rectangle(x1-78,y1,x2-78,y2);
		puthz(x1+32-78,y1+11,"开",24,28,DARKGRAY);
		
		save_bk_mou(mouseX,mouseY);
		drawmous(mouseX,mouseY);
		return 1;
	}
	return 0;
	
	
}
/*
函数名：stateDraw
功能：根据状态绘制界面
入口参数：矩形框位置，标志地址
返回值：void
*/
void stateDraw(int x1,int y1,int x2,int y2,int * flag)
{
	if((*flag) == 0) 
	{
		rectangle(x1,y1,x2,y2);
		puthz(x1+32,y1+11,"开",24,28,DARKGRAY);
		rectangle(x1+78,y1,x2+78,y2);
		setfillstyle(SOLID_FILL,GREEN);
		bar(x1+78,y1,x2+78,y2);
		puthz(x1+32+78,y1+11,"关",24,28,YELLOW);
	}
	else
	{
		setcolor(DARKGRAY);
		setfillstyle(SOLID_FILL,LIGHTCYAN);
		bar(x1+78,y1,x2+78,y2);
		rectangle(x1+78,y1,x2+78,y2);
		puthz(x1+32+78,y1+11,"关",24,28,DARKGRAY);
		
		setfillstyle(SOLID_FILL,GREEN);
		bar(x1,y1,x2,y2);
		puthz(x1+32,y1+11,"开",24,28,YELLOW);
	}
	
	
	return;
}

















