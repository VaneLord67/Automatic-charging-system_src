///////////////////////////////////
//myf.cpp
//���ֹ��ܺ�����ʵ��
///////////////////////////////////
#include"common.h"
#include"myf.h"
#define HZ_OFFSET 4 		//���ֵ�ƫ����



///////////////////////////////////
//��������printHZ
//���ܣ���x,y����ӡsָ��ĺ����ַ���(�����ο�)
//��ڲ�������һ�����ֵ����꣺x,y��
//        �������ַ�����s��
//        ����С��flag��
//        ����ɫ��color��
//����ֵ��void
///////////////////////////////////
void printHZ(int x, int y,char *s,int flag,int color)
{
	//�ж�s�Ƿ�ȫΪ���֣����ϸ��жϣ���Ϊ��if��s�����ż����Ӣ���ַ���������Ҳ�ᱻ�ж�Ϊfalse
	if( strlen(s) % 2 != 0)
	{
		settextjustify(LEFT_TEXT,TOP_TEXT);          
		settextstyle(GOTHIC_FONT,HORIZ_DIR,1);					
		outtextxy(10,10,"String cannot include english char!Press any key to quit...");
		getch();
		exit(1);
	}
	int length = strlen(s) / 2;
	int part = flag + HZ_OFFSET;
	
	setcolor(DARKGRAY);
	setlinestyle(SOLID_LINE,0,NORM_WIDTH);

	rectangle(x,y,x+flag*length*1.1+2,y+flag);
	puthz(x,y,s,flag,part,color);
	
	return;
}

///////////////////////////////////
//��������printHZ_withoutRec
//���ܣ���x,y����ӡsָ��ĺ����ַ���(�������ο�)
//��ڲ�������һ�����ֵ����꣺x,y��
//        �������ַ�����s��
//        ����С��flag��
//        ����ɫ��color��
//����ֵ��void
///////////////////////////////////
void printHZ_withoutRec(int x, int y,char *s,int flag,int color)
{
	int part = flag + HZ_OFFSET;
	
	puthz(x,y,s,flag,part,color);
	
	return;
}

///////////////////////////////////
//��������printText
//���ܣ���x,y����ӡsָ���Ӣ���ַ���(�����ο�)
//��ڲ�������һ���ַ������꣺x,y��
//        ���ַ�����s��
//        ����С��flag (0-10)��
//        ����ɫ��color��
//����ֵ��void
///////////////////////////////////
void printText(int x, int y,char *s,int flag,int color)
{
	setcolor(color);
	settextstyle(DEFAULT_FONT,HORIZ_DIR,flag);
	setlinestyle(SOLID_LINE,0,NORM_WIDTH);
	rectangle(x-5,y-5,x+flag*8*strlen(s)+2,y+flag*8);
	outtextxy(x,y,s);
	
	return;
}


///////////////////////////////////
//��������printText_withoutRec
//���ܣ���x,y����ӡsָ���Ӣ���ַ���(�������ο�)
//��ڲ�������һ���ַ������꣺x,y��
//        ���ַ�����s��
//        ����С��flag (0-10)��
//        ����ɫ��color��
//����ֵ��void
///////////////////////////////////
void printText_withoutRec(int x, int y,char *s,int flag,int color)
{
	setcolor(color);
	settextstyle(DEFAULT_FONT,HORIZ_DIR,flag);
	setlinestyle(SOLID_LINE,0,NORM_WIDTH);
	outtextxy(x,y,s);
	
	return;
}

///////////////////////////////////
//��������change_page
//���ܣ�ҳ���л�
//��ڲ�������ҳ��ĺ����ĵ�ַ
//����ֵ��void
///////////////////////////////////
void change_page(void(*draw_screen)(void))
{
	clrmous(mouseX,mouseY);
	delay(100);
	draw_screen();
	save_bk_mou(mouseX,mouseY);
	drawmous(mouseX,mouseY);
	
	return;
}

///////////////////////////////////
//��������showMousePos
//���ܣ����Ͻ���ʾ�������
//��ڲ�������ҳ��ĺ����ĵ�ַ
//����ֵ��void
///////////////////////////////////
void showMousePos(void)
{
	int xn,yn,buttonsn;
	char x[5] = {'\0'};
	char y[5] = {'\0'};
	mread(&xn,&yn,&buttonsn);   
	if(!(xn == mouseX && yn == mouseY))
	{
		setfillstyle(SOLID_FILL,BLACK);
		bar(0,0,124,46);     //���ԭ�е�����
		sprintf(x,"%d",mouseX);
		sprintf(y,"%d",mouseY);
		settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
		outtextxy(0,13,x);
		outtextxy(0,30,y);
	}
		
	return;
}

///////////////////////////////////
//��������inputText
//���ܣ����뷨����������Ϊ��DEFAULT_FONT,HORIZ_DIR,3��//��3��Ĭ�����壩��
//��ڲ�������ʼλ�õ�x,y����ĵ�ַ���Ƿ������뷨�ı����ڵı�־���ı����ȵĵ�ַ��ָ���ı����ַ���(��Щ������Ҫ�ڵ��øú����ĺ���������ã��ѵ�ַ������),��ɫ
//����ֵ��void
///////////////////////////////////
void inputText(int * x_input, int * y_input,int * inputFlag,int * inputLength, char * text, int color)
{
	int maxLength = 12; //�ı�������󳤶�12
	if(kbhit() != 0)
	{
		int ch = 0;			
		char textTemp[1] = {'\0'};	
		ch = getch();
		switch(ch)
		{
			case 8:  						//�˸��
				if( (*inputLength) > 0)
				{
					text[(*inputLength) - 1] = '\0';
					(*inputLength) -- ;
					(*x_input) -= 25;
					clrmous(mouseX,mouseY);
					setfillstyle(SOLID_FILL,BLACK);
					bar((*x_input),(*y_input),(*x_input)+20,(*y_input)+24);
					save_bk_mou(mouseX,mouseY);
					drawmous(mouseX,mouseY);
					if((*x_input) <= 5)
					{
						(*x_input) = 600;
						if((*y_input) - 30 >= 240)
						{
							(*y_input) -= 30;
						}
					}
					
				}
				break;
			case 13:						//�س�
			case 27:						//ESC
				(*inputFlag) = 0;
				break;
			default:
				if((*inputLength) < maxLength)
				{
					text[(*inputLength)] = ch;
					(*inputLength)++;
					memset(textTemp,'\0',sizeof(textTemp));
					sprintf(textTemp,"%c",ch);
					if((*x_input) < 550)
					{
						clrmous(mouseX,mouseY);
						settextstyle(DEFAULT_FONT,HORIZ_DIR,3);
						setcolor(color);
						outtextxy((*x_input),(*y_input),textTemp);

						save_bk_mou(mouseX,mouseY);
						drawmous(mouseX,mouseY);

						(*x_input) += 25;
					}
					// else
					// {
						// x = 5;
						// y += 30;
						// outtextxy(x,y,textTemp);
						// x += 15;
					// }
					
				}
				break;
				
		}
	}
	
	return;
}

///////////////////////////////////
//��������inputPassword
//���ܣ����뷨����������Ϊ��DEFAULT_FONT,HORIZ_DIR,3��//��3��Ĭ�����壩��
//��ڲ�������ʼλ�õ�x,y����ĵ�ַ���Ƿ������뷨�ı����ڵı�־���ı����ȵĵ�ַ��ָ���ı����ַ���(��Щ������Ҫ�ڵ��øú����ĺ���������ã��ѵ�ַ������),��ɫ
//����ֵ��void
///////////////////////////////////
void inputPassword(int * x_input, int * y_input,int * inputFlag,int * inputLength, char * text, int color)
{
	int maxLength = 12; //�ı�������󳤶�12
	if(kbhit() != 0)
	{
		int ch = 0;			
		char textTemp[1] = {'\0'};	
		ch = getch();
		switch(ch)
		{
			case 8:  						//�˸��
				if( (*inputLength) > 0)
				{
					text[(*inputLength) - 1] = '\0';
					(*inputLength) -- ;
					(*x_input) -= 25;
					clrmous(mouseX,mouseY);
					setfillstyle(SOLID_FILL,BLACK);
					bar((*x_input),(*y_input),(*x_input)+25,(*y_input)+20);
					save_bk_mou(mouseX,mouseY);
					drawmous(mouseX,mouseY);
					if((*x_input) <= 5)
					{
						(*x_input) = 600;
						if((*y_input) - 30 >= 240)
						{
							(*y_input) -= 30;
						}
					}
					
				}
				break;
			case 13:						//�س�
			case 27:						//ESC
				(*inputFlag) = 0;
				break;
			default:
				if((*inputLength) < maxLength)
				{
					text[(*inputLength)] = ch;
					(*inputLength)++;
					memset(textTemp,'\0',sizeof(textTemp));
					sprintf(textTemp,"%c",ch);
					if((*x_input) < 550)
					{
						clrmous(mouseX,mouseY);
						settextstyle(DEFAULT_FONT,HORIZ_DIR,3);
						setcolor(color);
						outtextxy((*x_input),(*y_input),"*");

						save_bk_mou(mouseX,mouseY);
						drawmous(mouseX,mouseY);

						(*x_input) += 25;
					}
					// else
					// {
						// x = 5;
						// y += 30;
						// outtextxy(x,y,textTemp);
						// x += 15;
					// }
				}
				break;
				
		}
	}
	
	return;
}

///////////////////////////////////
//��������DiscardInput
//���ܣ����������뷨״̬�µļ�������
//��ڲ�����void
//����ֵ��void
///////////////////////////////////
void DiscardInput(void)
{
	if(kbhit() != 0)
	{
		getch();
	}
	
	return;
}

///////////////////////////////////
//��������popWindow
//���ܣ�����Ļ���뵯������OK���ػ����桾�����뷨�ĵط��ǵõ���ǰ���³�ʼ��������)������ʾ���ֺ�һ�����ڵ����OK��
//��ڲ�����������ĺ�����������״̬�����ĵ�ַ�������ַ����ĵ�ַ
//����ֵ��void
///////////////////////////////////
void popWindow(void(*draw_screen)(void), int * isPopWindow, char *s)
{
	if((*isPopWindow) == 0)
	{
		setcolor(BLACK);
		bar(166,100,474,344); 	//�����������ı���
		setcolor(DARKGRAY);
		setlinestyle(SOLID_LINE,0,NORM_WIDTH);
		rectangle(166,100,474,344);
		printHZ_withoutRec(220, 150,s,48,DARKGRAY);
		rectangle(232,236,414,306);
		settextstyle(DEFAULT_FONT,HORIZ_DIR,5);
		outtextxy(285,250,"OK");
		
		(*isPopWindow) = 1;
	}
	else
	{
		if(mouse_press(232,236,414,306) == 1)
		{
			change_page(draw_screen);
			(*isPopWindow) = 0;
		}		
	}
	
	return;
}

///////////////////////////////////
//��������popWindow_withoutFlush
//���ܣ�����Ļ���뵯������OK���ػ����棬����ʹ��putimage�ָ�����ǰ���棩������ʾ���ֺ�һ�����ڵ����OK��
//��ڲ������洢ͼ���ָ��ĵ�ַ������״̬�����ĵ�ַ�������ַ����ĵ�ַ
//����ֵ��void
///////////////////////////////////
void popWindow_withoutFlush(void ** buf, int * isPopWindow, char *s)
{
	int size;
	
	if((*isPopWindow) == 0)
	{
		size=imagesize(166,100,474,344);
		(*buf)=malloc(size);
		if((*buf)!=NULL)
		{
			getimage(166,100,474,344,(*buf));
		}
		else
		{
			settextjustify(LEFT_TEXT,TOP_TEXT);          
			settextstyle(GOTHIC_FONT,HORIZ_DIR,1);					
			outtextxy(10,10,"Error!");
			delay(1000);
			exit(-1);
		}
		
		clrmous(mouseX,mouseY);
		// delay(100);
		
		setcolor(BLACK);
		bar(166,100,474,344); 	//�����������ı���
		setcolor(DARKGRAY);
		setlinestyle(SOLID_LINE,0,NORM_WIDTH);
		rectangle(166,100,474,344);
		printHZ_withoutRec(220, 150,s,48,DARKGRAY);
		rectangle(232,236,414,306);
		settextstyle(DEFAULT_FONT,HORIZ_DIR,5);
		outtextxy(285,250,"OK");
		
		save_bk_mou(mouseX,mouseY);
		drawmous(mouseX,mouseY);
		
		(*isPopWindow) = 1;
	}
	else
	{
		if(mouse_press(232,236,414,306) == 1)
		{
			clrmous(mouseX,mouseY);
			// delay(100);

			setcolor(BLACK);
			bar(166,100,474,344); 	//���ԭ�еĵ���

			putimage(166,100,(*buf),COPY_PUT);
			free((*buf));
			
			save_bk_mou(mouseX,mouseY);
			drawmous(mouseX,mouseY);
			
			(*buf) = NULL;
			(*isPopWindow) = 0;
		}		
	}
	
	return;
}


/*
��������recordWrite
���ܣ�д��ʻ��¼��record.txt
��ڲ�����id,�����ṹ�����pCar
����ֵ��void
*/
void recordWrite(char * p,PCAR pCar)
{
	time_t now;
	FILE* fp;
	now = time(0);
	tm info = *localtime(&now);
	int year = info.tm_year + 1900;
	int month = info.tm_mon + 1;
	int day = info.tm_mday;
	int hour = info.tm_hour;
	int minute = info.tm_min;
	char ch;
	char temp[80] = {'\0'};
	int length = 0;
	int max = 0;
	
	if ((fp = fopen("record.txt", "r")) == NULL)
	{
		settextjustify(LEFT_TEXT,TOP_TEXT);          //�󲿶��룬��������
		settextstyle(GOTHIC_FONT,HORIZ_DIR,1);					//����ʻ������ˮƽ�����24*24����
		outtextxy(10,10,"Can't open file!Press any key to quit...");
		getch();
		exit(1);
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
	
	if ((fp = fopen("record.txt", "a")) == NULL)
	{
		settextjustify(LEFT_TEXT,TOP_TEXT);          //�󲿶��룬��������
		settextstyle(GOTHIC_FONT,HORIZ_DIR,1);					//����ʻ������ˮƽ�����24*24����
		outtextxy(10,10,"Can't open file!Press any key to quit...");
		getch();
		exit(1);
	}
	
	fprintf(fp, "[%d]\nUSER:%s\n", max + 1, p);
	fprintf(fp,"DIST:%d\n",pCar->hasMileage);
	//fprintf(fp,"ELEL:\n",pCar->electricityLeft);
	fprintf(fp, "TIME:");
	fprintf(fp, "%d/%d/%d/%d:%d  -  ", pCar->info.tm_year + 1900, pCar->info.tm_mon + 1, pCar->info.tm_mday, pCar->info.tm_hour, pCar->info.tm_min);	

	
	fprintf(fp, "%d/%d/%d/%d:%d\n", year, month, day, hour, minute);	

	fclose(fp);

	return;
}

// /*
// ��������recordOut
// ���ܣ��ص���ʼ����/�˳����� ��д��ʱ�䵽record.txt
// ��ڲ�����void
// ����ֵ��void
// */
// void recordOut(void)
// {
	// time_t now;
	// FILE* fp;
	// now = time(0);
	// tm info = *localtime(&now);
	// int year = info.tm_year + 1900;
	// int month = info.tm_mon + 1;
	// int day = info.tm_mday;
	// int hour = info.tm_hour;
	// int minute = info.tm_min;
	// //int second = info.tm_sec;

	// if ((fp = fopen("record.txt", "a")) == NULL)
	// {
		// fprintf(stderr, "���ļ�����\n");
		// exit(EXIT_FAILURE);
	// }

	// fprintf(fp, "%d/%d/%d/%d:%d\n", year, month, day, hour, minute);

	// //fprintf(stdout, "��ʻ��¼¼��ɹ���\n");

	// fclose(fp);

	// return;
// }


// /*
// ��������recordIn
// ���ܣ���¼ʱд��ʱ�䵽record.txt
// ��ڲ�����id,�����ṹ�����pCar
// ����ֵ��void
// */
// void recordIn(char * p,PCAR pCar)
// {
	// time_t now;
	// FILE* fp;
	// char ch;
	// char temp[80] = {'\0'};
	// int length = 0;
	// int max = 0;
	// now = time(0);
	// pCar->info = *localtime(&now);
	// int year = pCar->info.tm_year + 1900;
	// int month = pCar->info.tm_mon + 1;
	// int day = pCar->info.tm_mday;
	// int hour = pCar->info.tm_hour;
	// int minute = pCar->info.tm_min;
	// //int second = info.tm_sec;
	
	// if ((fp = fopen("record.txt", "r")) == NULL)
	// {
		// settextjustify(LEFT_TEXT,TOP_TEXT);          //�󲿶��룬��������
		// settextstyle(GOTHIC_FONT,HORIZ_DIR,1);					//����ʻ������ˮƽ�����24*24����
		// outtextxy(10,10,"Can't open file!Press any key to quit...");
		// getch();
		// exit(1);
	// }
	
	// while ( (ch = getc(fp)) != EOF)
	// {
		// if (ch == '[')
		// {
			// memset(temp, '\0', sizeof(temp));
			// length = 0;
			// while ( (ch = getc(fp)) != ']')
			// {
				// temp[length] = ch;
				// length++;
			// }
		// }
		// if (max < atoi(temp))
		// {
			// max = atoi(temp);
		// }
	// }
	
	// fclose(fp);
	
	// if ((fp = fopen("record.txt", "a")) == NULL)
	// {
		// settextjustify(LEFT_TEXT,TOP_TEXT);          //�󲿶��룬��������
		// settextstyle(GOTHIC_FONT,HORIZ_DIR,1);					//����ʻ������ˮƽ�����24*24����
		// outtextxy(10,10,"Can't open file!Press any key to quit...");
		// getch();
		// exit(1);
	// }
	// fprintf(fp, "[%d]\nUSER:%s\n", max + 1, p);
	// fprintf(fp,"DIST:%d\n",pCar->hasMileage);
	// //fprintf(fp,"ELEL:\n",pCar->electricityLeft);
	// fprintf(fp, "TIME:");
	// fprintf(fp, "%d/%d/%d/%d:%d  -  ", year, month, day, hour, minute);	
	
	// fclose(fp);
	
	
	// if ((fp = fopen("record.txt", "a")) == NULL)
	// {
		// settextjustify(LEFT_TEXT,TOP_TEXT);          //�󲿶��룬��������
		// settextstyle(GOTHIC_FONT,HORIZ_DIR,1);					//����ʻ������ˮƽ�����24*24����
		// outtextxy(10,10,"Can't open file!Press any key to quit...");
		// getch();
		// exit(1);
	// }

	// fprintf(fp, "%d/%d/%d/%d:%d\n", year, month, day, hour, minute);
	

	// //fprintf(stdout, "��ʻ��¼¼��ɹ���\n");

	// fclose(fp);

	// return;
// }





///////////////////////////////////
//��������playSound
//���ܣ���������
//��ڲ�����void
//����ֵ��void
///////////////////////////////////
// void playSound(void)
// {
	// int freq[96]={784,660,588,660,523,523,
	// 588,494,440,523,392,392,
	// 330,392,440,523,784,440,523,392,
	// 784,1048,880,784,660,784,588,588,
	// 588,660,494,440,392,440,523,588,
	// 330,523,440,392,440,523,392,392,
	// 660,784,494,588,440,523,392,392,
	// 330,392,330,392,392,440,494,588,440,440,392,440,
	// 523,588,784,660,588,660,588,523,440,392,
	// 330,523,440,523,440,392,330,392,440,523,
	// 392,392,660,784,588,660,588,523,494,440,784,784};
	// int dely[96]={25,50,12,12,50,50,
	// 25,50,12,12,50,50,
	// 50,38,12,38,12,12,12,25,
	// 38,12,12,12,12,12,50,50,
	// 38,12,25,25,38,12,25,25,
	// 25,25,12,12,12,12,50,50,
	// 38,12,25,25,12,12,50,25,
	// 12,12,12,12,12,12,12,12,50,25,12,12,
	// 38,12,25,25,25,12,12,25,12,12,
	// 50,50,12,12,12,12,12,12,12,12,
	// 50,25,12,12,12,12,12,12,25,25,50,50};
	// while(1)
	// {
		// if(playIndex >= 96)
		// {
			// playIndex = 0;
		// }
		// sound(freq[playIndex]);  
		// end = clock();
		// total = (double)(end - start) / CLOCKS_PER_SEC;
		// if(total * 1000 >= (double)(10*dely[playIndex]))
		// {
			// start = clock();
			// playIndex++;
			// continue;
		// }
		// else
		// {
			// break;
		// }
	// }
	
	// return;
// }











