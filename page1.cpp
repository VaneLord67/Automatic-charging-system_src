/*
注册界面
*/
#include"common.h"
#include"page1.h"

/*
函数名：p1
功能：注册界面的功能
入口参数：void
返回值：int类型，返回page的值
*/
int p1(void)
{
	int page = 1;
	int isPopWindow = 0;
	void * buf = NULL;

	char userText[20] = {'\0'};
	char passwordText[20] = {'\0'};
	int isInUserText = 0;
	int isInPasswordText = 0;
	int userTextLength = 0;
	int passwordTextLength = 0;
	
	int x_userTextInput = 250;
	int y_userTextInput = 100;
	
	int x_PasswordTextInput = 250;
	int y_PasswordTextInput = 213;
	
	change_page(page1_screen);
	
	while(page == 1)
	{
		newmouse(&mouseX,&mouseY,&press);

		showMousePos();
		
		if(1 == isInUserText)
		{
			inputText(&x_userTextInput,&y_userTextInput,&isInUserText, &userTextLength,userText,DARKGRAY);
		}
		else if(1 == isInPasswordText)
		{
			inputPassword(&x_PasswordTextInput,&y_PasswordTextInput,&isInPasswordText, &passwordTextLength,passwordText,DARKGRAY);
		}
		else
		{
			DiscardInput();
		}
		
		if( 0 == isPopWindow)
		{
			
			//点击输入框之外的地方取消输入法
			if(mouse_press(0,0,639,479) == 1 && mouse_press(246,77,567,148) != 1 && mouse_press(246,190,567,260) != 1)
			{
				isInPasswordText = 0;
				isInUserText = 0;
			}
			
			if(mouse_press(237, 303, 388, 404) == 1)      //点击返回按钮
			{
				page = 0;
			}
			else if(mouse_press(413,303,564,404) == 1)        //点击退出按钮
			{
				nosound();
				page = 3;
			}
			else if(mouse_press(246,77,567,148) == 1) 		//点击用户名输入框
			{
				isInPasswordText = 0;
				isInUserText = 1;
			}
			else if(mouse_press(246,190,567,260) == 1)			//点击密码输入框
			{
				isInUserText = 0;
				isInPasswordText = 1;
			}
			else if(mouse_press(47,303,198,404) == 1) 			//点击注册框
			{
				if( Register(userText,passwordText) == 1 )
				{
					popWindow_withoutFlush(&buf, &isPopWindow, "注册成功");
				}
				else
				{
					popWindow_withoutFlush(&buf, &isPopWindow, "注册失败");
				}
			}
		}
		else
		{
			popWindow_withoutFlush(&buf, &isPopWindow, "");
		}
		
	}
	return page;
}
/*
函数名：page1_screen
功能：绘制注册界面
入口参数：void
返回值：void
*/
void page1_screen(void)
{
	cleardevice();
	setbkcolor(WHITE);
	setlinestyle(SOLID_LINE,0,NORM_WIDTH);
	rectangle(79,77,223,148);
	rectangle(246,77,567,148);
	rectangle(79,190,223,260);
	rectangle(246,190,567,260);
	puthz(93,92,"用户名",48,40,DARKGRAY);
	puthz(93,205,"密码",48,52,DARKGRAY);
	
	rectangle(47,303,198,404);
	rectangle(237,303,388,404);
	rectangle(413,303,564,404);
	puthz(59,319,"注册",48,52,DARKGRAY);
	puthz(251,319,"返回",48,52,DARKGRAY);
	puthz(429,319,"退出",48,52,DARKGRAY);
	
	return;
}


/*
函数名：Register
功能：注册
入口参数：用户名文本userText，密码文本passwordText
返回值：int类型，1为注册成功，0为注册失败
*/
int Register(char * userText, char * passwordText)
{
	int max = 0;   //存储现有文件中最大索引值
	FILE* fp = NULL;
	char ch;
	char id[80] = {'\0'};
	char password[80] = {'\0'};
	char id_temp[80] = {'\0'};
	char* p = NULL;
	char temp[80] = {'\0'};
	int length = 0;
	if(strlen(userText) == 0)
	{
		return 0;
	}
	if(strlen(passwordText) == 0)
	{
		return 0;
	}

	strcpy(id,userText);
	strcpy(password,passwordText);

	if ((fp = fopen("user.txt", "r")) == NULL)
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
				//ch = getc(fp);
				temp[length] = ch;
				length++;
				//ch = getc(fp);
			}
		}
		if (max < atoi(temp))
		{
			max = atoi(temp);
		}
	}
	memset(temp,'\0',sizeof(temp));
	fgets(temp, 80, fp);
	fseek(fp, 0L, SEEK_SET);				//下面定位至文件开始处，检查输入ID是否与现存ID重合。
	while (temp != NULL)
	{
		if ((temp[0] == 'I') && (temp[1] == 'D') && (temp[2] == ':'))      //在user.txt中定位到 “ID:” 并读取冒号后面的字符串。
		{
			strcpy(id_temp, temp + 3);
			p = strchr(id_temp, '\n');               // 将换行符处理成空字符
			*p = '\0';								 //

			if (strcmp(id_temp, id) == 0)
			{
				// fprintf(stderr, "输入ID与现存ID重合！注册失败！请重试！\n");
				return 0;
			}
		}
		fgets(temp, 80, fp);
		if (feof(fp) != 0)
			break;
	}

	fclose(fp);

	if ((fp = fopen("user.txt", "a")) == NULL)
	{
		settextjustify(LEFT_TEXT,TOP_TEXT);          //左部对齐，顶部对齐
		settextstyle(GOTHIC_FONT,HORIZ_DIR,1);					//黑体笔划输出，水平输出，24*24点阵
		outtextxy(10,10,"Can't open file!Press any key to quit...");
		getch();
		exit(1);
	}

	fprintf(fp, "[%d]\nID:",max+1);
	// fprintf(fp, "ID:");
	fprintf(fp, "%s\n", id);
	fprintf(fp, "PASSWORD:");
	fprintf(fp, "%s\n", password);

	fclose(fp);
	return 1;
}









