/*
ע�����
*/
#include"common.h"
#include"page1.h"

/*
��������p1
���ܣ�ע�����Ĺ���
��ڲ�����void
����ֵ��int���ͣ�����page��ֵ
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
			
			//��������֮��ĵط�ȡ�����뷨
			if(mouse_press(0,0,639,479) == 1 && mouse_press(246,77,567,148) != 1 && mouse_press(246,190,567,260) != 1)
			{
				isInPasswordText = 0;
				isInUserText = 0;
			}
			
			if(mouse_press(237, 303, 388, 404) == 1)      //������ذ�ť
			{
				page = 0;
			}
			else if(mouse_press(413,303,564,404) == 1)        //����˳���ť
			{
				nosound();
				page = 3;
			}
			else if(mouse_press(246,77,567,148) == 1) 		//����û��������
			{
				isInPasswordText = 0;
				isInUserText = 1;
			}
			else if(mouse_press(246,190,567,260) == 1)			//������������
			{
				isInUserText = 0;
				isInPasswordText = 1;
			}
			else if(mouse_press(47,303,198,404) == 1) 			//���ע���
			{
				if( Register(userText,passwordText) == 1 )
				{
					popWindow_withoutFlush(&buf, &isPopWindow, "ע��ɹ�");
				}
				else
				{
					popWindow_withoutFlush(&buf, &isPopWindow, "ע��ʧ��");
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
��������page1_screen
���ܣ�����ע�����
��ڲ�����void
����ֵ��void
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
	puthz(93,92,"�û���",48,40,DARKGRAY);
	puthz(93,205,"����",48,52,DARKGRAY);
	
	rectangle(47,303,198,404);
	rectangle(237,303,388,404);
	rectangle(413,303,564,404);
	puthz(59,319,"ע��",48,52,DARKGRAY);
	puthz(251,319,"����",48,52,DARKGRAY);
	puthz(429,319,"�˳�",48,52,DARKGRAY);
	
	return;
}


/*
��������Register
���ܣ�ע��
��ڲ������û����ı�userText�������ı�passwordText
����ֵ��int���ͣ�1Ϊע��ɹ���0Ϊע��ʧ��
*/
int Register(char * userText, char * passwordText)
{
	int max = 0;   //�洢�����ļ����������ֵ
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
	fseek(fp, 0L, SEEK_SET);				//���涨λ���ļ���ʼ�����������ID�Ƿ����ִ�ID�غϡ�
	while (temp != NULL)
	{
		if ((temp[0] == 'I') && (temp[1] == 'D') && (temp[2] == ':'))      //��user.txt�ж�λ�� ��ID:�� ����ȡð�ź�����ַ�����
		{
			strcpy(id_temp, temp + 3);
			p = strchr(id_temp, '\n');               // �����з�����ɿ��ַ�
			*p = '\0';								 //

			if (strcmp(id_temp, id) == 0)
			{
				// fprintf(stderr, "����ID���ִ�ID�غϣ�ע��ʧ�ܣ������ԣ�\n");
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
		settextjustify(LEFT_TEXT,TOP_TEXT);          //�󲿶��룬��������
		settextstyle(GOTHIC_FONT,HORIZ_DIR,1);					//����ʻ������ˮƽ�����24*24����
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









