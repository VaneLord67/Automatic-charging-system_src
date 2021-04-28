/////////////////
//行驶记录查询界面
////////////////

#include"page9.h"

/*
函数名：p9
功能：行驶记录查询界面
入口参数：汽车指针pCar
返回值：int类型，返回page的值
*/
int p9(PCAR pCar)
{
	int page = 9;
	int maxPage = 1;				//最大页数
	int max = 0;
	int pageCurrent = 1;			//当前页数
	char pageCurrentString[10] = {'\0'}; //当前页数转化成的字符串
	char maxPageString[10] = {'\0'}; 	//最大页数转化成的字符串
	int skip[MAX_RECORD] = {0};

	if(pCar->isAdmin == 1)
	{
		maxPage = maxPageQuery(&max);
	}
	else if(pCar->isAdmin == 0)
	{
		maxPage = maxPageQueryForUser(pCar,skip);
	}
	
	change_page(page9_screen);
	printText_withoutRec(250,360,"1",3,DARKGRAY);
	sprintf(maxPageString,"%d",maxPage);
	printText_withoutRec(370,360,maxPageString,3,DARKGRAY);
	
	//进入时显示第一页的记录
	if(pCar->isAdmin == 0)
	{
		findRecordForUser(1,skip);
	}
	else if(pCar->isAdmin == 1)
	{
		findRecordForAdmin(1,max);
	}
	
	#ifdef DEBUGMODE
	// char output[50] = {'\0'};
	// sprintf(output,"%d",maxPage);
	//printText_withoutRec(20, 82,output,3,DARKGRAY);
	#endif
	
	while(page == 9)
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
				
				if(pCar->isAdmin == 0)
				{
					findRecordForUser(pageCurrent,skip);
				}
				else if(pCar->isAdmin == 1)
				{
					findRecordForAdmin(pageCurrent,max);
				}

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

				if(pCar->isAdmin == 0)
				{
					findRecordForUser(pageCurrent,skip);
				}
				else if(pCar->isAdmin == 1)
				{
					findRecordForAdmin(pageCurrent,max);
				}

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

				if(pCar->isAdmin == 0)
				{
					findRecordForUser(pageCurrent,skip);
				}
				else if(pCar->isAdmin == 1)
				{
					findRecordForAdmin(pageCurrent,max);
				}
				
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
				
				if(pCar->isAdmin == 0)
				{
					findRecordForUser(pageCurrent,skip);
				}
				else if(pCar->isAdmin == 1)
				{
					findRecordForAdmin(pageCurrent,max);
				}
				
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

			if(pCar->isAdmin == 0)
			{
				page = 4;			//是用户则返回到数据显示界面
			}
			else if(pCar->isAdmin == 1)
			{
				page = 13;			//是管理员则返回到管理员界面
			}
		}
		
	}
	
	return page;
}

/*
函数名：page9_screen
功能：绘制行驶记录查询界面
入口参数：void
返回值：void
*/
void page9_screen(void)
{
	cleardevice();
	setbkcolor(LIGHTCYAN);
	setcolor(DARKGRAY);
	printHZ_withoutRec(150,20,"行驶记录查询",48,DARKGRAY);
	
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
函数名：maxPageQuery
功能：返回行驶记录文件（record.txt）中最大页数(一页显示SIZE条)
入口参数：void
返回值：int最大页数
*/
int maxPageQuery(int * getMax)
{
	int maxPage = 1;
	int max = 1;
	int length = 0;
	char temp[80] = {'\0'};
	char ch;
	FILE * fp = NULL;
	fp = fopen("record.txt","r");
	//打开文件失败则退出程序
	if( fp == NULL )
	{
		settextjustify(LEFT_TEXT,TOP_TEXT);          //左部对齐，顶部对齐
		settextstyle(GOTHIC_FONT,HORIZ_DIR,1);					//黑体笔划输出，水平输出，24*24点阵
		outtextxy(10,10,"Can't open file!Press any key to quit...");
		getch();
		exit(1);
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
函数名：maxPageQueryForUser
功能：返回行驶记录文件（record.txt）中最大页数(一页显示SIZE条)
入口参数：汽车指针pCar,跳过行数skip地址
返回值：int最大页数
*/
int maxPageQueryForUser(PCAR pCar,int * skip)
{
	char userTemp[50] = {'\0'};
	int skipCnt = 0;
	int maxPage = 1;
	int cnt = 0;
	int i = 0;
	char temp[80] = {'\0'};
	FILE * fp = NULL;
	fp = fopen("record.txt","r");
	if( fp == NULL )
	{
		exitFunc("file open error!");
	}
	memset(temp,'\0',sizeof(temp));

	strcat(userTemp,"USER:");
	strcat(userTemp,pCar->id);
	for(i=1; fgets(temp,80,fp) != NULL; )
	{
		skipCnt++;
		temp[strlen(temp) - 1] = '\0';
		if(strcmp(temp,userTemp) == 0)
		{
			skip[i] = skipCnt;
			cnt++;
			i++;
		}
	}
	maxPage = ceil((double)cnt / SIZE);

	fclose(fp);
	return maxPage;
}

/*
函数名：findRecordForUser
功能：输出用户行驶记录
入口参数：当前页面pageCurrent
返回值：void
*/
void findRecordForUser(int pageCurrent,int * skip)
{
	int x = 30;
	int y = 90;
	RECORD rec;
	FILE * fp = NULL;
	int startIndex = (pageCurrent - 1) * SIZE + 1;	//该页起始索引
	int i = 0;
	int j = 0;
	int k = 0;
	char temp[80] = {'\0'};
	fp = fopen("record.txt","r");
	if( fp == NULL )
	{
		exitFunc("file record.txt open error!");
	}

	for(i = startIndex, k = 0; i < startIndex+SIZE; i++, k++)
	{
		if(skip[i] != 0)	
		{
			for(j = 0;j < skip[i] - 1; j++)
			{
				fgets(temp,80,fp);
			}

			clrmous(mouseX,mouseY);

			sprintf(rec.index,"[%d]",startIndex+k);

			fgets(temp,80,fp);
			strcpy(rec.user,temp);
			rec.user[strlen(rec.user) - 1] = '\0';
			
			fgets(temp,80,fp);
			strcpy(rec.mileage,temp);
			rec.mileage[strlen(rec.mileage) - 1] = '\0';

			fgets(temp,80,fp);
			strcpy(rec.time,temp);
			rec.time[strlen(rec.time) - 1] = '\0';
			
			printText_withoutRec(x, y,rec.index,1,DARKGRAY);
			y += 30;
			printText_withoutRec(x, y,rec.user,1,DARKGRAY);
			y += 30;
			printText_withoutRec(x, y,rec.mileage,1,DARKGRAY);
			y += 30;
			printText_withoutRec(x, y,rec.time,1,DARKGRAY);
			y += 30;
			setfillstyle(SOLID_FILL,BLACK);
			bar(20,110 + k * 120,63,130 + k * 120);
			printHZ_withoutRec(25,110 + k * 120 + 5,"用户",16,DARKGRAY);
			bar(20,140 + k * 120,63,160 + k * 120);
			printHZ_withoutRec(25,140 + k * 120 + 5,"里程",16,DARKGRAY);
			bar(20,170 + k * 120,63,190 + k * 120);
			printHZ_withoutRec(25,170 + k * 120 + 5,"时间",16,DARKGRAY);
			save_bk_mou(mouseX,mouseY);
			drawmous(mouseX,mouseY);

			fseek(fp,0L,SEEK_SET);
		}
		else
		{
			break;
		}
	}

	fclose(fp);
	return;
}



void findRecordForAdmin(int pageCurrent,int max)
{
	RECORD rec;
	//int max = 1;
	int startIndex = (pageCurrent - 1) * SIZE + 1;
	int i, j, k;
	int x = 30;
	int y = 90;
	char temp[80] = {'\0'};
	FILE * fp = NULL;
	fp = fopen("record.txt","r");
	if( fp == NULL )
	{
		exitFunc("file record.txt open error!");
	}
	
	for(i=0;i<(startIndex-1) * 4;i++)
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
		strcpy(rec.mileage,temp);
		rec.mileage[strlen(rec.mileage) - 1] = '\0';

		fgets(temp,80,fp);
		strcpy(rec.time,temp);
		rec.time[strlen(rec.time) - 1] = '\0';
		
		printText_withoutRec(x, y,rec.index,1,DARKGRAY);
		y += 30;
		printText_withoutRec(x, y,rec.user,1,DARKGRAY);
		y += 30;
		printText_withoutRec(x, y,rec.mileage,1,DARKGRAY);
		y += 30;
		printText_withoutRec(x, y,rec.time,1,DARKGRAY);
		y += 30;
		setfillstyle(SOLID_FILL,BLACK);
		bar(20,110 + k * 120,63,130 + k * 120);
		printHZ_withoutRec(25,110 + k * 120 + 5,"用户",16,DARKGRAY);
		bar(20,140 + k * 120,63,160 + k * 120);
		printHZ_withoutRec(25,140 + k * 120 + 5,"里程",16,DARKGRAY);
		bar(20,170 + k * 120,63,190 + k * 120);
		printHZ_withoutRec(25,170 + k * 120 + 5,"时间",16,DARKGRAY);
		save_bk_mou(mouseX,mouseY);
		drawmous(mouseX,mouseY);

	}
	fclose(fp);
	return;
}

/*
函数名：findRecord
功能：输出行驶记录
入口参数：当前页面pageCurrent,汽车指针pCar
返回值：void
*/
/* void findRecord(int pageCurrent,PCAR pCar)
{
	RECORD rec;
	int max = 1;
	int startIndex = (pageCurrent - 1) * SIZE + 1;
	int length = 0;
	int i;
	int x = 30;
	int y = 90;
	char ch;
	char temp[80] = {'\0'};
	char userTemp[50] = {'\0'};
	FILE * fp = NULL;
	fp = fopen("record.txt","r");
	if( fp == NULL )
	{
		exitFunc("file record.txt open error!");
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
	
	fseek(fp,0,SEEK_SET);
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
		if (startIndex == atoi(temp))
		{
			break;
		}
	}
	// fseek(fp,-1 - (strlen(temp)) - 1,SEEK_CUR);			//定位至startIndex那一行的开头

	//定位至startIndex那一行的开头
	memset(temp,'\0',sizeof(temp));
	fseek(fp,-1L,SEEK_CUR);
	while ( (ch = getc(fp)) != '[' )
	{
		fseek(fp,-2L,SEEK_CUR);
	}
	fseek(fp,-1L,SEEK_CUR);
	
	#ifdef DEBUGMODE
	char output[50] = {'\0'};
	//sprintf(output,"%d",strlen(temp));
	sprintf(output,"%d",ftell(fp));
	//sprintf(output,"%s",temp);
	//printText_withoutRec(20, 82,output,3,DARKGRAY);
	#endif
	
	memset(temp,'\0',sizeof(temp));

	//将USER: + pCar->id 存到temp中便于一会与扫描过程中的rec.user比较，实现用户只能查询自己行驶记录的功能
	strcat(userTemp,"USER:");
	strcat(userTemp,pCar->id);

	//扫描每一行,填充rec.如果不足SIZE条就用max-startIndex+1条
	for(i = 0; i < ( (startIndex + 2) <= max ? SIZE : (max-startIndex+1) );i++)
	{
		clrmous(mouseX,mouseY);
		fgets(temp,80,fp);
		//strcpy(rec.index,temp);
		sprintf(rec.index,"[%d]",startIndex+i);
		//rec.index[strlen(rec.index) - 1] = '\0';		//防止输出\n导致Bug,把\n换成\0,下同
		fgets(temp,80,fp);
		strcpy(rec.user,temp);

		rec.user[strlen(rec.user) - 1] = '\0';
		if(strcmp(rec.user,userTemp) != 0)		//让用户只能查自己的行驶记录
		{
			fgets(temp,80,fp);
			fgets(temp,80,fp);			//跳过两行,读下一条
			i--;
			continue;
		}
		fgets(temp,80,fp);
		strcpy(rec.mileage,temp);
		rec.mileage[strlen(rec.mileage) - 1] = '\0';
		fgets(temp,80,fp);
		strcpy(rec.time,temp);
		rec.time[strlen(rec.time) - 1] = '\0';
		printText_withoutRec(x, y,rec.index,1,DARKGRAY);
		y += 30;
		printText_withoutRec(x, y,rec.user,1,DARKGRAY);
		y += 30;
		printText_withoutRec(x, y,rec.mileage,1,DARKGRAY);
		y += 30;
		printText_withoutRec(x, y,rec.time,1,DARKGRAY);
		y += 30;
		setfillstyle(SOLID_FILL,BLACK);
		bar(20,110 + i * 120,63,130 + i * 120);
		printHZ_withoutRec(25,110 + i * 120 + 5,"用户",16,DARKGRAY);
		bar(20,140 + i * 120,63,160 + i * 120);
		printHZ_withoutRec(25,140 + i * 120 + 5,"里程",16,DARKGRAY);
		bar(20,170 + i * 120,63,190 + i * 120);
		printHZ_withoutRec(25,170 + i * 120 + 5,"时间",16,DARKGRAY);
		save_bk_mou(mouseX,mouseY);
		drawmous(mouseX,mouseY);
	}
	fclose(fp);
	return;
}

 */
