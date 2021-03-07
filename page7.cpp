/////////////////
//电量模块
////////////////

#include"common.h"
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
	
	change_page(page7_screen);
	
	while(page == 7)
	{
		newmouse(&mouseX,&mouseY,&press);
		#ifdef SHOWMOUSE
		showMousePos();
		#endif
		
		if(mouse_press(235,160,380,196) == 1)			//一键充电
		{
			pCar->electricityLeft = 70;
		}
		
		if(mouse_press(235,160+50+50,379,397) == 1)		//一键换电
		{
			pCar->electricityLeft = 70;
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