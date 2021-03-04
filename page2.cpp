/*
��¼����
*/
#include"common.h"
#include"page2.h"

/*
��������p2
���ܣ���¼����Ĺ���
��ڲ�����void
����ֵ��int���ͣ�����page��ֵ
*/
int p2(void)
{
	int page = 2;
	
	char userText[20] = {'\0'};
	char passwordText[20] = {'\0'};
	int loginFlag = 0;
	int isPopWindow = 0;
	int isInUserText = 0;
	int isInPasswordText = 0;
	int userTextLength = 0;
	int passwordTextLength = 0;
	
	int x_userTextInput = 250;
	int y_userTextInput = 100;
	
	int x_PasswordTextInput = 250;
	int y_PasswordTextInput = 213;
	
	change_page(page2_screen);
	
	while(page == 2)
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
		
		if(0 == isPopWindow)			//û�е���ʱ����if
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
			else if(mouse_press(47,303,198,404) == 1) 			//�����¼��
			{
				if( (loginFlag = Login(userText,passwordText)) == 1 )
				{
					popWindow(page2_screen,&isPopWindow,"��¼�ɹ�");
				}
				else
				{
					popWindow(page2_screen,&isPopWindow,"��¼ʧ��");
				}
			}
		}
		else		//����״̬��
		{	
			memset(userText,'\0',sizeof(userText));
			memset(passwordText,'\0',sizeof(passwordText));

			isInUserText = 0;
			isInPasswordText = 0;
			userTextLength = 0;
			passwordTextLength = 0;
			
			x_userTextInput = 250;
			y_userTextInput = 100;;
			
			x_PasswordTextInput = 250;
			y_PasswordTextInput = 213;
			popWindow(page2_screen,&isPopWindow,"");
			if(0 == isPopWindow) 
			{
				if(1 == loginFlag)
				{
					page = 5;
				}
			}
		}
		
	}
	return page;
}

/*
��������page2_screen
���ܣ����Ƶ�¼����
��ڲ�����void
����ֵ��void
*/
void page2_screen(void)
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
	puthz(59,319,"��¼",48,52,DARKGRAY);
	puthz(251,319,"����",48,52,DARKGRAY);
	puthz(429,319,"�˳�",48,52,DARKGRAY);
	
	return;
}

/*
��������Login
���ܣ���¼
��ڲ������û����ı�userText�������ı�passwordText
����ֵ��int���ͣ�1Ϊ��¼�ɹ���0Ϊ��¼ʧ��
*/
int Login(char * userText, char * passwordText)
{
	FILE* fp = NULL;
	char id[80] = {'\0'};
	char password[80] = {'\0'};
	char temp[80] = {'\0'};
	char id_temp[80] = {'\0'};
	char password_temp[80] = {'\0'};
	char* p = NULL;
	
	if ((fp = fopen("user.txt", "r")) == NULL)
	{
		settextjustify(LEFT_TEXT,TOP_TEXT);          //�󲿶��룬��������
		settextstyle(GOTHIC_FONT,HORIZ_DIR,1);					//����ʻ������ˮƽ�����24*24����
		outtextxy(10,10,"Can't open file!Press any key to quit...");
		getch();
		exit(1);
	}
	strcpy(id,userText);
	strcpy(password,passwordText);
	
	fgets(temp, 80, fp);

	while (temp != NULL)
	{
		if ((temp[0] == 'I') && (temp[1] == 'D') && (temp[2] == ':'))
		{
			strcpy(id_temp, temp + 3);
			p = strchr(id_temp, '\n');
			*p = '\0';
			if (strcmp(id_temp, id) == 0)
			{
				fgets(temp, 80, fp);
				strcpy(password_temp, temp + 9);
				p = strchr(password_temp, '\n');
				*p = '\0';
				if (strcmp(password_temp, password) == 0)
				{
					fclose(fp);
					return 1;
				}
			}
		}
		fgets(temp, 80, fp);
		if (feof(fp) != 0)
		{
			break;
		}
	}
	fclose(fp);
	return 0;
}









