/////////////////
//һ���������
////////////////

#include"page11.h"

/*
��������p11
���ܣ�һ���������
��ڲ����������ṹ�����pCar
����ֵ��int���ͣ�����page��ֵ
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
	int start = clock();			//��ʼʱ��
	int temp;			//��ʱʱ��
	double total = 0; 	//ʱ��֮��
	int i = 0;
	double elecStart = pCar->electricityLeft;	//����ʼ����
	double *elecBefore = NULL;

	change_page(page11_screen);
	
	clrmous(mouseX,mouseY);

	/*printHZ_withoutRec(106,270,"����Ϊ��ָ�ɻ����ˡ�����",32,DARKGRAY);
	delay(2000);
	setfillstyle(SOLID_FILL,BLACK);
	bar(106,270,545,316);
	printHZ_withoutRec(106,270,"����������ǰ������������",32,DARKGRAY);
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
	
	delay(2000);*/
	
	setcolor(DARKGRAY);
	setlinestyle(SOLID_LINE,0,THICK_WIDTH);
	setfillstyle(SOLID_FILL,LIGHTCYAN);
	line(1,363,639,363);
	rectangle(300,80,540,363);                                 //����վ
	printHZ_withoutRec(340,90,"����վ",48,DARKGRAY);
	
	printHZ_withoutRec(50,90,"����״̬",48,DARKGRAY);
	rectangle(60,150,240,170);
	setfillstyle(SOLID_FILL,RED);
	floodfill(63,153,DARKGRAY);
	setfillstyle(SOLID_FILL,LIGHTCYAN);                       //����״̬�� 
	
	setlinestyle(SOLID_LINE,0,THICK_WIDTH);
	circle(140,345,15);
	circle(220,345,15);
	ellipse(140,345,0,180,25,25);
	ellipse(220,345,0,180,25,25);
	line(165,345,195,345);
	int a[] = {115,345,100,345,100,300,125,300,145,260,215,260,235,300,260,300,260,345,245,345};
	drawpoly(10,a);
	int b[] = {135,300,150,270,175,270,175,300,135,300};
	drawpoly(5,b);
	int c[] = {185,300,185,270,210,270,225,300,185,300};
	drawpoly(5,c);                                             //����
	
	delay(1000);
	
	setcolor(LIGHTCYAN);
	line(300,239,300,361);
	setcolor(DARKGRAY);
	
	delay(500);
	
	printHZ_withoutRec(100,380,"�������ڽ��뻻��վ",48,DARKGRAY);
	
	while(1)
	{
		temp = clock();
		total = (double)(temp - start) / CLOCKS_PER_SEC;
		if(total >= 0.4)
		{
			if(i <= 7*30)
			{
				size = imagesize(99,240,261,361);
				buf = malloc(size);
				getimage(99+i,239,261+i,361,buf);
				putimage(99+i,239,buf,1);
				putimage(99+30+i,239,buf,0);
				free(buf);
				i += 30;
				start = clock();
			}
			else
			{
				line(300,239,300,363);
				break;
			}
		}	
	}                                                 //������ʻ���� 
	
	delay(500);
	bar(1,370,639,480);
		
	printHZ_withoutRec(130,380,"ƽ̨������������",48,DARKGRAY);
	
	getimage(99+i,239,261+i,361,buf);
	putimage(99+i,239,buf,1);
	putimage(99+i,239-43,buf,0);
	line(400,320,360,320);
	line(440,320,480,320);
	line(380+5,320,380+5,361);	
	line(380-5,320,380-5,361);
	line(460+5,320,460+5,361);
	line(460-5,320,460-5,361);                      //������ƽ̨���� 
	
	delay(1000);
	bar(1,370,639,480);
	
	printHZ_withoutRec(130,380,"����ȡ���������",48,DARKGRAY);
	
	line(420,361,420,340);
	int d[] = {410,340,410,355,430,355,430,340};
	drawpoly(4,d);
	
	delay(500);
	

	size = imagesize(409,340,431,360);
	buf = malloc(size);
	getimage(409,340,431,360,buf);
	putimage(409,340,buf,1);
	putimage(409,320,buf,0);
	line(420,360,420,340);
	delay(500);
	putimage(409,320,buf,1);
	putimage(409,304,buf,0);
	line(420,340,420,316);                         //��е������ 
	
	delay(1000);
	floodfill(63,153,DARKGRAY);
	
	putimage(409,304,buf,1);
	putimage(409,320,buf,0);
	free(buf);
	setcolor(RED);
	line(405,320,435,320);
	setcolor(DARKGRAY);
	delay(500);
	size = imagesize(404,319,436,340);
	buf = malloc(size);
	getimage(404,319,436,340,buf);
	putimage(404,319,buf,1);
	putimage(404,340,buf,0);
	delay(500);
	putimage(404,340,buf,1);                        //ȡ��Ҫ�����ĵ��
	
	bar(1,370,639,480);
	
	printHZ_withoutRec(130,380,"���ڸ����������",48,DARKGRAY);
	delay(1000);
	
	line(420,361,420,340);
	int e[] = {410,340,410,355,430,355,430,340};
	drawpoly(4,e); 
	setcolor(GREEN);
	line(405,340,435,340);
	setcolor(DARKGRAY);
	delay(500);
	size = imagesize(404,340,436,360);
	buf = malloc(size);
	getimage(404,340,436,360,buf);
	putimage(404,340,buf,1);
	putimage(404,320,buf,0);
	line(420,360,420,340);
	delay(500);
	getimage(404,320,436,340,buf);
	putimage(404,320,buf,1);
	putimage(404,301,buf,0);
	free(buf);
	line(420,340,420,316);     
	line(404,301,435,301);                                    //�����µ��
	
	delay(500);
	
	setfillstyle(SOLID_FILL,GREEN);
	floodfill(63,153,DARKGRAY);
	setfillstyle(SOLID_FILL,LIGHTCYAN);
	
	size = imagesize(409,302,431,320);
	buf = malloc(size);	
	getimage(409,303,431,320,buf);
	putimage(409,303,buf,1);
	putimage(409,320,buf,0);
	delay(500);
	putimage(409,320,buf,1);
	putimage(409,340,buf,0);
	delay(500);
	putimage(409,340,buf,1);
	free(buf); 
	setcolor(LIGHTCYAN);
	line(420,320,420,363);
	setcolor(DARKGRAY);
	line(400,363,440,363);                                    //��е�۽���
	
	bar(1,370,639,480);
	delay(500);
	
	printHZ_withoutRec(130,380,"ƽ̨���ڽ�������",48,DARKGRAY);

	setfillstyle(SOLID_FILL,LIGHTCYAN);
	setlinestyle(SOLID_LINE,0,LIGHTCYAN);
	bar(360,319,480,361);
	size = imagesize(99+i,239-43,261+i,361-43);
	buf = malloc(size);
	getimage(99+i,239-43,261+i,361-43,buf);
	putimage(99+i,239-43,buf,1);
	putimage(99+i,239,buf,0);
	free(buf);                                               //�������� 
	
	delay(1000);
	bar(1,370,639,480);
	
	printHZ_withoutRec(100,380,"��������ʻ������վ",48,DARKGRAY);
	
	setcolor(LIGHTCYAN);
	line(300,239,300,361);
	setcolor(DARKGRAY);
	delay(500);
	
	i = 0;
	while(1)
	{
		temp = clock();
		total = (double)(temp - start) / CLOCKS_PER_SEC;
		if(total >= 0.4)
		{
			if(i <= 7*30)
			{
				size = imagesize(339,240,501,361);
				buf = malloc(size);
				getimage(339-i,239,501-i,361,buf);
				putimage(339-i,239,buf,1);
				putimage(339-30-i,239,buf,0);
				free(buf);
				i += 30;
				start = clock();
			}
			else
			{
				line(300,239,300,363);
				break;
			}
		}	
	}                                                    //����ʻ������վ 
	
	bar(1,370,639,480);
	delay(1000);

	/*while(1)
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
	printHZ_withoutRec(106,270,"����������Ϊ�����硣����",32,DARKGRAY);
	
	delay(2000);*/
	
	pCar->electricityLeft = MAX_ELECTRICITY;
		
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
		
		if(0 == isPopWindow)
		{
			
			if(pCar->electricityLeft == MAX_ELECTRICITY)
			{
				elecBefore = &elecStart;
				CarElecWrite_change(pCar->id, pCar, elecBefore);    
				popWindow_withoutFlush(&p, &isPopWindow, "�������");	
			}
					
			// if(mouse_press(401,409,508,459) == 1)			//�˳�
			// {
			// 	page = 3;
			// }
	
			// if(mouse_press(123,409,230,459) == 1)			//��ֹ
			// {
			// 	page = 4;
			// }
				
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
��������page11_screen
���ܣ�����һ��������
��ڲ�����void
����ֵ��void
*/
void page11_screen(void)
{
	cleardevice();
	setbkcolor(LIGHTCYAN);
	printHZ_withoutRec(200,20,"һ������",48,DARKGRAY);
	
	//printHZ(122, 408,"��ֹ",48,DARKGRAY);
	//printHZ(400, 408,"�˳�",48,DARKGRAY);
	return;
}

/*
��������CarElecWrite_change
���ܣ������������仯д���ļ�elec.txt��
��ڲ�����id,�����ṹ��ָ��pCar���������ǰ����p1
����ֵ��void
*/
void CarElecWrite_change(char * p, PCAR pCar, double *elecBefore)
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
	fprintf(fp, "MODE:change\n");
	fprintf(fp,"ELEC:%.2lf -> %.2lf\n",r,t);
	fprintf(fp,"COST:%.2lf\n",k);
	fprintf(fp, "TIME:");
	fprintf(fp, "%d/%d/%d/%d:%d\n", year, month, day, hour, minute);	

	fclose(fp);

	return;
}
