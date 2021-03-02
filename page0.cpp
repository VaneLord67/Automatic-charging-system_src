#include"common.h"
#include"page0.h"

/*
函数名：p0
功能：初始界面的功能
入口参数：void
返回值：int类型，返回page的值
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
		
		if(mouse_press(237, 303, 388, 404) == 1)      //点击注册按钮
		{
			page = 1;
		}
		else if(mouse_press(413,303,564,404) == 1)        //点击退出按钮
		{
			nosound();
			page = 3;
		}
		else if(mouse_press(47,303,198,404) == 1)			//点击登录按钮
		{
			page = 2;
		}
		
	}
	return page;
	
}

/*
函数名：page0_screen
功能：绘制初始界面
入口参数：void
返回值：void
*/
void page0_screen(void)
{
	cleardevice();
	setbkcolor(WHITE);
	setlinestyle(SOLID_LINE,0,NORM_WIDTH);
	// rectangle(150,64,498,209);
	printHZ_withoutRec(25,93,"新能源汽车自动充电系统",48,DARKGRAY);
	rectangle(47,303,198,404);
	rectangle(237,303,388,404);
	rectangle(413,303,564,404);
	puthz(59,319,"登录",48,52,DARKGRAY);
	puthz(251,319,"注册",48,52,DARKGRAY);
	puthz(429,319,"退出",48,52,DARKGRAY);
	// settextstyle(DEFAULT_FONT,HORIZ_DIR,10);
	// outtextxy(174,90,"DEMO");
	return;
}














