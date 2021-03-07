/////////////////
//��ʻ��¼��ѯ����
////////////////

#include"common.h"
#include"page9.h"

/*
��������p9
���ܣ���ʻ��¼��ѯ����
��ڲ�����void
����ֵ��int���ͣ�����page��ֵ
*/
int p9(void)
{
	int page = 9;
	int maxPage = 1;				//���ҳ��
	int pageCurrent = 1;			//��ǰҳ��
	char pageCurrentString[10] = {'\0'}; //��ǰҳ��ת���ɵ��ַ���
	char maxPageString[10] = {'\0'}; 	//���ҳ��ת���ɵ��ַ���

	maxPage = maxPageQuery();
	
	change_page(page9_screen);
	printText_withoutRec(250,360,"1",3,DARKGRAY);
	sprintf(maxPageString,"%d",maxPage);
	printText_withoutRec(370,360,maxPageString,3,DARKGRAY);
	
	//����ʱ��ʾ��һҳ�ļ�¼
	findRecord(1);
	
	#ifdef DEBUGMODE
	char output[50] = {'\0'};
	sprintf(output,"%d",maxPage);
	//printText_withoutRec(20, 82,output,3,DARKGRAY);
	#endif
	
	while(page == 9)
	{
		newmouse(&mouseX,&mouseY,&press);
		#ifdef SHOWMOUSE
		showMousePos();
		#endif
		
		if(mouse_press(140,350,186,390) == 1)			//����ҳ��
		{
			if(pageCurrent > 1)
			{
				pageCurrent -= 1;
				setfillstyle(SOLID_FILL,BLACK);
				bar(30,90,383,347);
				findRecord(pageCurrent);
				bar(222,360,310,388);
				sprintf(pageCurrentString,"%d",pageCurrent);
				printText_withoutRec(250,360,pageCurrentString,3,DARKGRAY);
				delay(200);
			}
		}
		
		if(mouse_press(432,350,487,390) == 1)			//����ҳ��
		{
			if(pageCurrent < maxPage)
			{
				pageCurrent += 1;
				setfillstyle(SOLID_FILL,BLACK);
				bar(20,90,383,347);				//ˢ�½���
				findRecord(pageCurrent);
				bar(222,360,310,388);			//ˢ�µ�ǰҳ��
				sprintf(pageCurrentString,"%d",pageCurrent);
				printText_withoutRec(250,360,pageCurrentString,3,DARKGRAY);
				delay(200);
			}
		}
		
		if(mouse_press(401,409,508,459) == 1)			//�˳�
		{
			page = 3;
		}
		
		if(mouse_press(123,409,230,459) == 1)			//����
		{
			page = 4;
		}
		
	}
	
	return page;
}

/*
��������page9_screen
���ܣ�������ʻ��¼��ѯ����
��ڲ�����void
����ֵ��void
*/
void page9_screen(void)
{
	cleardevice();
	setbkcolor(WHITE);
	printHZ_withoutRec(150,20,"��ʻ��¼��ѯ",48,DARKGRAY);
	printHZ(122, 408,"����",48,DARKGRAY);
	printHZ(400, 408,"�˳�",48,DARKGRAY);
	
	rectangle(122,350,508,392);
	setlinestyle(SOLID_LINE,0,NORM_WIDTH);
	line(172,351,150,370);
	line(150,370,172,390);
	line(451,351,473,370);
	line(473,370,451,390);
	
	line(337,359,312,388);
	
	return;
}

/*
��������maxPageQuery
���ܣ�������ʻ��¼�ļ���record.txt�������ҳ��(һҳ��ʾSIZE��)
��ڲ�����void
����ֵ��int���ҳ��
*/
int maxPageQuery(void)
{
	int maxPage = 1;
	int max = 1;
	int length = 0;
	char temp[80] = {'\0'};
	char ch;
	FILE * fp = NULL;
	fp = fopen("record.txt","r");
	//���ļ�ʧ�����˳�����
	if( fp == NULL )
	{
		settextjustify(LEFT_TEXT,TOP_TEXT);          //�󲿶��룬��������
		settextstyle(GOTHIC_FONT,HORIZ_DIR,1);					//����ʻ������ˮƽ�����24*24����
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
	
	maxPage = ceil((double)max / SIZE);
	fclose(fp);
	
	return maxPage;
}


/*
��������findRecord
���ܣ������ʻ��¼
��ڲ�������ǰҳ��pageCurrent
����ֵ��void
*/
void findRecord(int pageCurrent)
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
	FILE * fp = NULL;
	fp = fopen("record.txt","r");
	if( fp == NULL )
	{
		settextjustify(LEFT_TEXT,TOP_TEXT);          //�󲿶��룬��������
		settextstyle(GOTHIC_FONT,HORIZ_DIR,1);					//����ʻ������ˮƽ�����24*24����
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
	
	
	// fseek(fp,-1 - (strlen(temp)) - 1,SEEK_CUR);			//��λ��startIndex��һ�еĿ�ͷ
	
	//��λ��startIndex��һ�еĿ�ͷ
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
	//ɨ��ÿһ��,���rec.�������SIZE������max-startIndex+1��
	for(i = 0;i < ( (startIndex + 2) <= max ? SIZE : (max-startIndex+1) );i++)
	{
		clrmous(mouseX,mouseY);
		fgets(temp,80,fp);
		strcpy(rec.index,temp);
		rec.index[strlen(rec.index) - 1] = '\0';		//��ֹ���\n����Bug,��\n����\0,��ͬ
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
		bar(20,110 + i * 120,63,130 + i * 120);
		printHZ_withoutRec(25,110 + i * 120 + 5,"�û�",16,DARKGRAY);
		bar(20,140 + i * 120,63,160 + i * 120);
		printHZ_withoutRec(25,140 + i * 120 + 5,"���",16,DARKGRAY);
		bar(20,170 + i * 120,63,190 + i * 120);
		printHZ_withoutRec(25,170 + i * 120 + 5,"ʱ��",16,DARKGRAY);
		save_bk_mou(mouseX,mouseY);
		drawmous(mouseX,mouseY);
	}
	
	fclose(fp);
	
	return;
}

