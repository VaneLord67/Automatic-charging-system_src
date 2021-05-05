/////////////////
//电量模块
////////////////

#include"page7.h"

/*
函数名：p7
功能：电量模块
入口参数：汽车结构体变量pCar
返回值：int类型，返回page的值
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
			if(mouse_press(235,160,380,196) == 1)			//一键充电
			{
				if(pCar->electricityLeft >= MAX_ELECTRICITY)
				{
					popWindow_withoutFlush(&buf, &isPopWindow, "电量已满");
					continue;
				}
				page = 10;
			}
			
			if(mouse_press(235,160+50+50,379,397) == 1)		//一键换电
			{
				delay(200);	//防止连点
				if(pCar->electricityLeft >= MAX_ELECTRICITY)
				{
					popWindow_withoutFlush(&buf, &isPopWindow, "电量已满");
					continue;
				}
				page = 11;
			}
			
			if(mouse_press(401,409,508,459) == 1)			//退出
			{
				page = 3;
			}
			
			if(mouse_press(123,409,230,459) == 1)			//返回
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
函数名：page7_screen
功能：绘制电量模块
入口参数：void
返回值：void
*/
void page7_screen(void)
{
	cleardevice();
	setbkcolor(WHITE);
	printHZ_withoutRec(200,20,"电量管理",48,DARKGRAY);
	printHZ(235,160,"一键充电",32,DARKGRAY);
	printHZ(235,160+50+50,"一键换电",32,DARKGRAY);
	printHZ(122, 408,"返回",48,DARKGRAY);
	printHZ(400, 408,"退出",48,DARKGRAY);
	return;
}