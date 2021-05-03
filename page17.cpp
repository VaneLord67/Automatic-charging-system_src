//管理员电量查询界面

#include"page17.h" 

/*
函数名：p17
功能：管理员电量查询界面 
入口参数：汽车指针pCar
返回值：int类型，返回page的值
*/
int p17(PCAR pCar)
{
	int page = 17;
	int maxPage = 1;				//最大页数
	int max = 0;
	int pageCurrent = 1;			//当前页数
	char pageCurrentString[10] = {'\0'}; //当前页数转化成的字符串
	char maxPageString[10] = {'\0'}; 	//最大页数转化成的字符串
	
	if(pCar->isAdmin == 1)
	{
		maxPage = maxPageQueryForElec(&max);
	}
	
	change_page(page17_screen);
	printText_withoutRec(250,360,"1",3,DARKGRAY);
	sprintf(maxPageString,"%d",maxPage);
	printText_withoutRec(370,360,maxPageString,3,DARKGRAY);
	
	findRecordForElec(1,max);             //进入时显示第一页的记录
	
	
	#ifdef DEBUGMODE
	// char output[50] = {'\0'};
	// sprintf(output,"%d",maxPage);
	//printText_withoutRec(20, 82,output,3,DARKGRAY);
	#endif
	
	while(page == 17)
	{
		newmouse(&mouseX,&mouseY,&press);
		#ifdef SHOWMOUSE
		showMousePos();
		#endif
		
		if(mouse_press(140,350,186,390) == 1)			//减少页数
		{
			if(pageCurrent > 1)
			{
				pageCurrent -= 1;
				setfillstyle(SOLID_FILL,BLACK);
				bar(20,90,383,347);
						
				findRecordForElec(pageCurrent,max);

				bar(209,360,310,388);
				sprintf(pageCurrentString,"%d",pageCurrent);
				printText_withoutRec(210,360,pageCurrentString,3,DARKGRAY);
				delay(200);
			}
			else if(pageCurrent == 1)
			{
				pageCurrent = maxPage;
				setfillstyle(SOLID_FILL,BLACK);
				bar(20,90,383,347);

				findRecordForElec(pageCurrent,max);

				bar(209,360,310,388);
				sprintf(pageCurrentString,"%d",pageCurrent);
				printText_withoutRec(210,360,pageCurrentString,3,DARKGRAY);
				delay(200);
			}
		}
		
		if(mouse_press(432,350,487,390) == 1)			//增加页数
		{
			if(pageCurrent < maxPage)
			{
				pageCurrent += 1;
				setfillstyle(SOLID_FILL,BLACK);
				bar(20,90,383,347);				//刷新界面

				findRecordForElec(pageCurrent,max);

				bar(209,360,310,388);			//刷新当前页数
				sprintf(pageCurrentString,"%d",pageCurrent);
				printText_withoutRec(210,360,pageCurrentString,3,DARKGRAY);
				delay(200);
			}
			else if(pageCurrent == maxPage)
			{
				pageCurrent = 1;
				setfillstyle(SOLID_FILL,BLACK);
				bar(20,90,383,347);				//刷新界面
				
				findRecordForElec(pageCurrent,max);
				
				bar(209,360,310,388);			//刷新当前页数
				sprintf(pageCurrentString,"%d",pageCurrent);
				printText_withoutRec(210,360,pageCurrentString,3,DARKGRAY);
				delay(200);
				
			}
		}
		
		if(mouse_press(390,408,400+48*2*1.1+2,408+48) == 1)			//退出
		{
			page = 3;
		}
		
		if(mouse_press(112,408,122+48*2*1.1+2,408+48) == 1)			//返回
		{
			page = 13;
		}
		
	}
	
	return page;
}

/*
函数名：page17_screen
功能：绘制充电记录查询界面
入口参数：void
返回值：void
*/
void page17_screen(void)
{
	cleardevice();
	setbkcolor(LIGHTCYAN);
	setcolor(DARKGRAY);
	printHZ_withoutRec(150,20,"充电记录查询",48,DARKGRAY);
	
	rectangle(112,350,508,392);
	setlinestyle(SOLID_LINE,0,NORM_WIDTH);
	line(172,351,150,370);
	line(150,370,172,390);
	line(451,351,473,370);
	line(473,370,451,390);
	
	line(337,359,312,388);
	
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
函数名：maxPageQueryForElec 
功能：返回充电记录文件（elec.txt）中最大页数(一页显示SIZE条)
入口参数：void
返回值：int最大页数
*/
int maxPageQueryForElec(int * getMax)
{
	int maxPage = 1;
	int max = 1;
	int length = 0;
	char temp[80] = {'\0'};
	char ch;
	FILE * fp = NULL;
	fp = fopen("elec.txt","r");
	
	if( fp == NULL )
	{
		exitFunc("open elec.txt error!");
	}
	memset(temp,'\0',sizeof(temp));
	
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
	*getMax = max;
	
	maxPage = ceil((double)max / SIZE);
	fclose(fp);
	
	return maxPage;
}


/*
函数名：findRecordForElec
功能：输出充电记录
入口参数：当前页面pageCurrent
返回值：void
*/
void findRecordForElec(int pageCurrent,int max)
{
	ELEC rec;
	int startIndex = (pageCurrent - 1) * SIZE + 1;
	int i, j, k;
	int x = 30;
	int y = 90;
	char temp[80] = {'\0'};
	FILE * fp = NULL;
	fp = fopen("elec.txt","r");
	if( fp == NULL )
	{
		exitFunc("file elec.txt open error!");
	}
	
	
	for(i=0;i<(startIndex-1) * 6;i++)
	{
		fgets(temp,80,fp);
	}

	for(i = startIndex, k = 0; i < startIndex+SIZE; i++, k++)
	{	
		if(i == max + 1)
		{
			break;
		}
		clrmous(mouseX,mouseY);
		
		fgets(temp,80,fp);
		sprintf(rec.index,"[%d]",startIndex+k);

		fgets(temp,80,fp);
		strcpy(rec.user,temp);
		rec.user[strlen(rec.user) - 1] = '\0';
		
		fgets(temp,80,fp);
		strcpy(rec.mode,temp);
		rec.mode[strlen(rec.mode) - 1] = '\0';
		
		fgets(temp,80,fp);
		strcpy(rec.elec,temp);
		rec.elec[strlen(rec.elec) - 1] = '\0';

		fgets(temp,80,fp);
		strcpy(rec.money,temp);
		rec.money[strlen(rec.money) - 1] = '\0';
		
		fgets(temp,80,fp);
		strcpy(rec.time,temp);
		rec.time[strlen(rec.time) - 1] = '\0';
		
		printText_withoutRec(x, y,rec.index,1,DARKGRAY);
		y += 20;
		printText_withoutRec(x, y,rec.user,1,DARKGRAY);
		y += 20;
		printText_withoutRec(x, y,rec.mode,1,DARKGRAY);
		y += 20;
		printText_withoutRec(x, y,rec.elec,1,DARKGRAY);
		y += 20;
		printText_withoutRec(x, y,rec.money,1,DARKGRAY);
		y += 20;
		printText_withoutRec(x, y,rec.time,1,DARKGRAY);
		y += 20;
		setfillstyle(SOLID_FILL,BLACK);
		bar(20,100 + k * 120,63,120 + k * 120);
		printHZ_withoutRec(25,100 + k * 120 + 5,"用户",16,DARKGRAY);
		bar(20,120 + k * 120,63,140 + k * 120);
		printHZ_withoutRec(25,120 + k * 120 + 5,"模式",16,DARKGRAY);
		bar(20,140 + k * 120,63,160 + k * 120);
		printHZ_withoutRec(25,140 + k * 120 + 5,"电量",16,DARKGRAY);
		bar(20,160 + k * 120,63,180 + k * 120);
		printHZ_withoutRec(25,160 + k * 120 + 5,"花费",16,DARKGRAY);
		bar(20,180 + k * 120,63,200 + k * 120);
		printHZ_withoutRec(25,180 + k * 120 + 5,"时间",16,DARKGRAY);
		save_bk_mou(mouseX,mouseY);
		drawmous(mouseX,mouseY);

	}
	fclose(fp);
	return;
}
