/////////////////
//一键充电界面
////////////////
//charge elec
#include"page10.h"


/*
函数名：p10
功能：一键充电界面
入口参数：汽车结构体变量pCar,目标电量
返回值：int类型，返回page的值 
*/
int p10(PCAR pCar)
{
	#ifdef DEBUGMODE
	//pCar->electricityLeft = 10;
	#endif
	
	int isPopWindow = 0;
	void * p = NULL;
	int page = 10;
	int start = clock();			//起始时间
	int temp;			//临时时间
	int total = 0; 	//时间之差
	double elecStart = pCar->electricityLeft;	//充电初始电量
	double hasPayMoney = 0;			//已花费金额
	char hasPayMoneyString[50] = {'\0'};
	double *elecBefore = NULL;
	// int r = 0;
	// int chargeStart = clock();
	// int chargeTemp;
	// int total = 0;
	
	double percentage = (double)pCar->electricityLeft / MAX_ELECTRICITY;		//充电百分比 (elec percentage)
	
	change_page(page10_screen);
	
	clrmous(mouseX,mouseY);

	/*printHZ_withoutRec(106,270,"正在为您指派机器人。。。",32,DARKGRAY);
	delay(2000);
	setfillstyle(SOLID_FILL,BLACK);
	bar(106,270,545,316);
	printHZ_withoutRec(106,270,"机器人正在前往汽车。。。",32,DARKGRAY);

	setcolor(DARKGRAY);
	setlinestyle(SOLID_LINE,0,NORM_WIDTH);
	line(64,246,543,246);
	
	ellipse(200,150,-60,240,30,30);
	line(186,177,202,245);
	line(216,177,202,245);
	
	ellipse(200+235,150,-60,240,30,30);
	line(186+235,177,202+235,245);
	line(216+235,177,202+235,245);
	
	delay(2000);*/
	
	setcolor(DARKGRAY);
	setlinestyle(SOLID_LINE,0,THICK_WIDTH);
	rectangle(100,140,220,240);
	int e[] = {160,160,140,195,165,195,160,220,180,185,155,185,160,160};
	drawpoly(7,e);              //flash
	setfillstyle(SOLID_FILL,YELLOW);
	floodfill(160,190,DARKGRAY);
	line(150,240,150,360);
	line(170,240,170,360);   //充电桩chong dian zhuang
	line(80,360,560,360);
	
	int a[] = {400,270,400,330,540,330,540,270,530,270,500,210,440,210,410,270,400,270};
	drawpoly(9,a);      
	int b[] = {420,270,445,220,495,220,520,270,420,270};
	drawpoly(5,b);
	int c[] = {435,300,445,290,455,300,445,310,435,300};
	drawpoly(5,c);
	int d[] = {485,300,495,290,505,300,495,310,485,300};
	drawpoly(5,d);
	line(430,330,430,360);
	line(445,330,445,360);
	line(495,330,495,360);
	line(510,330,510,360);    //汽车car
	
	line(220,180,250,180);
	line(220,200,250,200);
	ellipse(250,250,0,90,70,70);
	ellipse(250,250,0,90,50,50);
	ellipse(370,250,180,270,50,50);
	ellipse(370,250,180,270,70,70);
	line(400,300,370,300);
	line(400,320,370,320);     //输电管道guan dao
	
	printHZ_withoutRec(160,370,"正在配置充电设置。。。",24,DARKGRAY);
	delay(100); 
	drawcircle(235,190);
	delay(100);
	drawcircle(258,191);
	delay(100);
	drawcircle(280,198);
	delay(100);
	drawcircle(302,220);
	delay(100);
	drawcircle(310,250);
	delay(100);
	drawcircle(318,280);
	delay(100);
	drawcircle(340,302);
	delay(100);
	drawcircle(362,310);
	delay(100);
	drawcircle(385,310);             //电量输送动画 dong hua
	
	
	
		
	/*机器人移动动画
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
	}*/ 
	
	delay(1000);
	setfillstyle(SOLID_FILL,LIGHTCYAN);
	bar(160,370,480,400);
	printHZ_withoutRec(160,370,"充电桩正在为车充电。。。",24,DARKGRAY);
	
	
	//进度条
	setcolor(DARKGRAY);
	rectangle(380,140,560,170);	
	printHZ_withoutRec(420,180,"电量状态",24,DARKGRAY);			//充电进度条边框 jindu tiao
	
	setfillstyle(SOLID_FILL,GREEN);
	bar(380,140,(560-380)*percentage+380,170);
	
	delay(2000);
	
	#ifdef DEBUGMODE
	//char output[50] = {'\0'};
	//ssprintf(output,"%lf",percentage);
	//printText_withoutRec(20, 82,output,3,DARKGRAY);
	#endif
	
	while(page == 10)
	{
		newmouse(&mouseX,&mouseY,&press);
		#ifdef SHOWMOUSE
		showMousePos();
		#endif

		#ifdef DEBUGMODE
		// pCar->electricityLeft = 20;
		//pCar->destElec = 50;
		#endif
		
		temp = clock();
		total = (double)(temp - start) / CLOCKS_PER_SEC;
		
		if(0 == isPopWindow)
		{
			if(total >= 1 && pCar->electricityLeft <= MAX_ELECTRICITY)
			{
				if(pCar->electricityLeft >= pCar->destElec)
				{
					pCar->electricityLeft = pCar->destElec;
					// pCar->balance -= (pCar->destElec-elecStart) * PRICE_PER_KWH;
					// updateBalance(pCar);
					elecBefore = &elecStart;
					CarElecWrite_charge(pCar->id, pCar, elecBefore);                                                                                    
					popWindow_withoutFlush(&p, &isPopWindow, "充电完成");  //success
					continue;
				}

				//防止电量溢出
				if(pCar->electricityLeft + 5 <= MAX_ELECTRICITY)
				{	
					pCar->electricityLeft += 5;
				}
				else
				{
					pCar->electricityLeft = pCar->destElec;
				}
				percentage = (double)pCar->electricityLeft / MAX_ELECTRICITY;
				hasPayMoney = (pCar->electricityLeft - elecStart) * PRICE_PER_KWH;
				setfillstyle(SOLID_FILL,BLACK);
				bar(280,84,440,118);
				sprintf(hasPayMoneyString,"%.2lf",hasPayMoney);
				printText_withoutRec(298,90,hasPayMoneyString,3,DARKGRAY);

				clrmous(mouseX,mouseY);

				setfillstyle(SOLID_FILL,GREEN);
				bar(380,140,(560-380)*percentage+380,170);

				save_bk_mou(mouseX,mouseY);
				drawmous(mouseX,mouseY);
				
				start = clock();
			}
			
			if(mouse_press(401,409,508,459) == 1)			//退出 exit
			{
				page = 3;
			}
			
			if(mouse_press(123,409,230,459) == 1)			//中止 stop
			{
				popWindow_withoutFlush(&p, &isPopWindow, "充电中止");
				//page = 4;
			}

		}
		else
		{
			popWindow_withoutFlush(&p, &isPopWindow, "");
			if(0 == isPopWindow)
			{
				pCar->balance -= hasPayMoney;
				updateBalance(pCar);
				page = 4;
			}
		}

	}
	
	return page;
	
}


/*
函数名：page10_screen
功能：绘制一键充电界面
入口参数：void
返回值：void
*/
void page10_screen(void)
{
	cleardevice();
	setbkcolor(LIGHTCYAN);
	printHZ_withoutRec(200,20,"一键充电",48,DARKGRAY);
	printHZ_withoutRec(68,85,"已花费金额：",32,DARKGRAY);
	printHZ_withoutRec(450,85,"元",32,DARKGRAY);
	
	printHZ(122, 408,"中止",48,DARKGRAY);  //stop
	printHZ(400, 408,"退出",48,DARKGRAY);  //exit
	return;
}


/*
函数名：CarElecWrite_charge
功能：将汽车电量变化写入文件elec.txt中
入口参数：id,汽车结构体指针pCar，汽车充电前电量p1
返回值：void
*/
void CarElecWrite_charge(char * p, PCAR pCar, double *elecBefore)
{
	FILE * fp = NULL;
	char ch;
	char temp[80] = {'\0'};
	int length = 0;
	int max = 0;
	
	time_t now;
	now = time(0);
	tm info = *localtime(&now);
	int year = info.tm_year + 1900;
	int month = info.tm_mon + 1;
	int day = info.tm_mday;
	int hour = info.tm_hour;
	int minute = info.tm_min;
	
	if ((fp = fopen("elec.txt", "r")) == NULL)
	{
		exitFunc("open elec.txt error!");
	}
	
	while ( (ch = getc(fp)) != EOF)
	{
		if (ch == '[')
		{
			memset(temp, '\0', sizeof(temp));
			length = 0;
			while ( (ch = getc(fp)) != ']')
			{
				temp[length] = ch;
				length++;
			}
		}
		if (max < atoi(temp))
		{
			max = atoi(temp);
		}
	}
	
	fclose(fp);
	
	if ((fp = fopen("elec.txt", "a")) == NULL)
	{
		exitFunc("open elec.txt error!");
	}
	
	
	double t=pCar->electricityLeft;
	double s=PRICE_PER_KWH;
	double r=*elecBefore;
	double k=(t-r)*s;
	fprintf(fp, "[%d]\nUSER:%s\n", max + 1, p);
	fprintf(fp, "MODE:charge\n");
	fprintf(fp,"ELEC:%.2lf -> %.2lf\n",r,t);
	fprintf(fp,"COST:%.2lf\n",k);
	fprintf(fp, "TIME:");
	fprintf(fp, "%d/%d/%d/%d:%d\n", year, month, day, hour, minute);	

	fclose(fp);

	return;
}

/*
函数名：drawcircle;
功能:在指定位置画一个圆 
入口参数：圆心坐标
返回值：void
*/
void drawcircle(int x,int y)
{
	setcolor(DARKGRAY);
	setlinestyle(SOLID_LINE,0,NORM_WIDTH);
	setfillstyle(SOLID_FILL,YELLOW);
	circle(x,y,7.5);
	floodfill(x,y,DARKGRAY);
	return;
}
