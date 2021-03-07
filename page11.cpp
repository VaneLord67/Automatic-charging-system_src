/////////////////
//一键充电界面
////////////////

#include"common.h"
#include"page11.h"

/*
函数名：p11
功能：一键换电界面
入口参数：汽车结构体变量pCar
返回值：int类型，返回page的值
*/
int p11(PCAR pCar)
{
	#ifdef DEBUGMODE
	//pCar->electricityLeft = 10;
	#endif
	
	int isPopWindow = 0;
	void * p = NULL;
	void * buf = NULL;
	unsigned int size = 0;
	int page = 11;
	int start = clock();			//起始时间
	int temp;			//临时时间
	int total = 0; 	//时间之差
	int i = 0;
	// int chargeStart = clock();
	// int chargeTemp;
	// int total = 0;
	
	//double percentage = (double)pCar->electricityLeft / MAX_ELECTRICITY;		//充电百分比
	
	change_page(page11_screen);
	
	clrmous(mouseX,mouseY);

	
	//进度条
	// setfillstyle(SOLID_FILL,GREEN);
	// bar(176,339,(457-176)*percentage+176,388);
	
	printHZ_withoutRec(106,270,"正在为您指派机器人。。。",32,DARKGRAY);
	delay(2000);
	setfillstyle(SOLID_FILL,BLACK);
	bar(106,270,545,316);
	printHZ_withoutRec(106,270,"机器人正在前往汽车。。。",32,DARKGRAY);
	//delay(2000);
	setcolor(DARKGRAY);
	setlinestyle(SOLID_LINE,0,NORM_WIDTH);
	line(64,246,543,246);
	
	ellipse(200,150,-60,240,30,30);
	line(186,177,202,245);
	line(216,177,202,245);
	
	ellipse(200+235,150,-60,240,30,30);
	line(186+235,177,202+235,245);
	line(216+235,177,202+235,245);
	
	delay(2000);

	while(1)
	{
		temp = clock();
		total = (double)(temp - start) / CLOCKS_PER_SEC;
		if(total >= 1)
		{
			if(i <= 2*55)
			{
				size = imagesize(170,120,230,245);
				buf = malloc(size);
				getimage(170+i,120,230+i,245,buf);
				putimage(170+i,120,buf,1);
				putimage(170+i+55,120,buf,0);
				free(buf);
				i += 55;
				start = clock();
			}
			else
			{
				break;
			}
		}	
	}
	
	delay(1000);
	bar(106,270,545,316);
	printHZ_withoutRec(106,270,"机器人正在为车换电。。。",32,DARKGRAY);
	
	delay(2000);
	
	pCar->electricityLeft = MAX_ELECTRICITY;
	
	// bar(106,270,545,316);
	// printHZ_withoutRec(106,270,"机器人正在为车换电。。。",32,DARKGRAY);
	
	
	#ifdef DEBUGMODE
	//char output[50] = {'\0'};
	//sprintf(output,"%lf",percentage);
	//printText_withoutRec(20, 82,output,3,DARKGRAY);
	#endif
	
	while(page == 11)
	{
		newmouse(&mouseX,&mouseY,&press);
		#ifdef SHOWMOUSE
		showMousePos();
		#endif
		
		temp = clock();
		total = (double)(temp - start) / CLOCKS_PER_SEC;
		// if(total >= 1)
		// {
			// if(i <= 2*55)
			// {
				// size = imagesize(170,120,230,245);
				// buf = malloc(size);
				// getimage(170+i,120,230+i,245,buf);
				// putimage(170+i,120,buf,1);
				// putimage(170+i+55,120,buf,0);
				// free(buf);
				// i += 55;
			// }
		// }
		
		if(0 == isPopWindow)
		{
			
			if(pCar->electricityLeft == MAX_ELECTRICITY)
			{
				popWindow_withoutFlush(&p, &isPopWindow, "电已充满");	
			}
			
			
			if(mouse_press(401,409,508,459) == 1)			//退出
			{
				page = 3;
			}
			
			if(mouse_press(123,409,230,459) == 1)			//中止
			{
				page = 4;
			}
				
		}
		else
		{
			popWindow_withoutFlush(&p, &isPopWindow, "");	
			if(0 == isPopWindow)
			{
				page = 4;
			}
		}
		
		
		
	}
	
	return page;
	
}


/*
函数名：page11_screen
功能：绘制一键充电界面
入口参数：void
返回值：void
*/
void page11_screen(void)
{
	cleardevice();
	setbkcolor(WHITE);
	printHZ_withoutRec(200,20,"一键换电",48,DARKGRAY);
	//printHZ(200,160,"行驶记录查询",32,DARKGRAY);
	
	// setcolor(DARKGRAY);
	// rectangle(176,339,457,388);				//充电进度条边框
	
	
	printHZ(122, 408,"中止",48,DARKGRAY);
	printHZ(400, 408,"退出",48,DARKGRAY);
	return;
}