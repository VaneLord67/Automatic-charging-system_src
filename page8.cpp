/////////////////
//个人中心界面
////////////////

#include"common.h"
#include"page8.h"

/*
函数名：p8
功能：个人中心界面
入口参数：void
返回值：int类型，返回page的值
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
		
		if(mouse_press(200,20,415,192) == 1)			//行驶记录查询
		{
			page = 9;
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
函数名：page8_screen
功能：绘制个人中心界面
入口参数：void
返回值：void
*/
void page8_screen(void)
{
	cleardevice();
	setbkcolor(WHITE);
	printHZ_withoutRec(200,20,"个人中心",48,DARKGRAY);
	printHZ(200,160,"行驶记录查询",32,DARKGRAY);
	printHZ(122, 408,"返回",48,DARKGRAY);
	printHZ(400, 408,"退出",48,DARKGRAY);
	return;
}