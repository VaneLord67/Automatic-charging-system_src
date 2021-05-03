
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
	int num = 0;
	change_page(page0_screen);
	
	while(page == 0)
	{
		newmouse(&mouseX,&mouseY,&press);
		#ifdef SHOWMOUSE
		showMousePos();
		#endif
		
		if(mouse_press(40,400,200,440) == 1)      //press register button点击注册按钮	
		{
			page = 1;
		}
		else if(mouse_press(440,400,600,440) == 1)        //press quit button 点击退出按钮
		{
			page = 3;
		}
		else if(mouse_press(240,400,400,440) == 1)			//press login button 点击登录按钮
		{
			page = 2;
		}
		else if(mouse_press(40,400,200,440) == 2)
		{
			if(num == 0)               //void light over two times 防止反复标亮
			{
				button(40,400,200,440,DARKGRAY,WHITE);
				puthz(80,404,"注册",32,40,DARKGRAY);		//puthz "register"
				num = 1;
			} 
			continue;
		}
		else if(mouse_press(440,400,600,440) == 2)
		{
			if(num == 0)               
			{
				button(440,400,600,440,DARKGRAY,WHITE);
				puthz(480,404,"退出",32,40,DARKGRAY);		//puthz "quit"
				num = 2;
			} 
			continue;
		}
		else if(mouse_press(240,400,400,440) == 2)
		{
			if(num == 0)               
			{
				button(240,400,400,440,DARKGRAY,WHITE);
				puthz(280,404,"登录",32,40,DARKGRAY);		//puthz "login"
				num = 3;
			} 
			continue;
		}
		else
		{
			if(num != 0);
			{
				switch(num)
				{
					case 1:
						button(40,400,200,440,DARKGRAY,DARKGRAY);
						puthz(80,404,"注册",32,40,WHITE);			//puthz "register"
						break;
					case 2:
						button(440,400,600,440,DARKGRAY,DARKGRAY);
						puthz(480,404,"退出",32,40,WHITE);			//puthz "quit"
						break;
					case 3:
						button(240,400,400,440,DARKGRAY,DARKGRAY);
						puthz(280,404,"登录",32,40,WHITE);			//puthz "login"
						break;	
				}
				num = 0;
			}
			continue;
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
	setbkcolor(LIGHTCYAN);
	setcolor(DARKGRAY);
	setlinestyle(SOLID_LINE,0,NORM_WIDTH);         //设置界面图形参数 
	
	line(315,0,315,40);
	line(325,0,325,40);
	arc(320,80,0,180,40);
	rectangle(270,80,370,90);
	rectangle(290,90,300,120);
	rectangle(340,90,350,120);      //充电插头图像 
	
	setlinestyle(SOLID_LINE,0,THICK_WIDTH);
	circle(260,320,10);
	circle(260,320,20);
	circle(380,320,10);
	circle(380,320,20);
	line(290,320,350,320);
	arc(260,320,0,180,30);
	arc(380,320,0,180,30);
	line(230,320,200,320);
	line(410,320,440,320);
	line(200,320,200,250);
	line(440,320,440,250);
	line(200,250,240,250);
	line(440,250,400,250);           //汽车图像 
	line(240,250,270,190);
	line(400,250,370,190);
	line(370,190,270,190);
	int a[] = {315,250,250,250,275,200,315,200,315,250};
	drawpoly(5,a);
	int b[] = {325,250,390,250,365,200,325,200,325,250};
	drawpoly(5,b);
	circle(340,270,5);
	circle(300,270,5);
	 
	setlinestyle(SOLID_LINE,0,NORM_WIDTH);
	line(320+200,200,300+200,260);
	line(320+200,200,310+200,250);
	line(310+200,250,340+200,250);
	line(340+200,250,320+200,310);
	line(320+200,310,330+200,260);
	line(330+200,260,300+200,260);
	line(300+200,260,320+200,200);     //闪电图像 (RIGHT)
	
	line(320-200,200,300-200,260);
	line(320-200,200,310-200,250);
	line(310-200,250,340-200,250);
	line(340-200,250,320-200,310);
	line(320-200,310,330-200,260);
	line(330-200,260,300-200,260);
	line(300-200,260,320-200,200);     //闪电图像  
	
	setfillstyle(SOLID_FILL,DARKGRAY);
	rectangle(40,400,200,440);
	rectangle(240,400,400,440);
	rectangle(440,400,600,440);
	
	floodfill(441,401,DARKGRAY);
	floodfill(41,401,DARKGRAY);
	floodfill(241,401,DARKGRAY);
	
	setfillstyle(SOLID_FILL,YELLOW);
	floodfill(303+200,257,DARKGRAY);
	floodfill(303-200,257,DARKGRAY);
	floodfill(293,93,DARKGRAY);
	floodfill(343,93,DARKGRAY);
	floodfill(320,1,DARKGRAY);
	setfillstyle(SOLID_FILL,LIGHTGREEN);
	floodfill(320,210,DARKGRAY);
	floodfill(320,77,DARKGRAY);
	setfillstyle(SOLID_FILL,BROWN);
	floodfill(273,320,DARKGRAY);
	floodfill(393,320,DARKGRAY);
	floodfill(320,85,DARKGRAY);
	
	printHZ_withoutRec(60,60,"新能源",48,LIGHTBLUE);
	printHZ_withoutRec(80,120,"汽车",48,LIGHTBLUE);
	printHZ_withoutRec(440,60,"充电",48,LIGHTBLUE);
	printHZ_withoutRec(440,120,"系统",48,LIGHTBLUE);
	
	puthz(80,404,"注册",32,40,WHITE);
	puthz(280,404,"登录",32,40,WHITE);
	puthz(480,404,"退出",32,40,WHITE);

	return;
}














