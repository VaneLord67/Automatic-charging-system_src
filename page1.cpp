/*
ע�����
*/

#include"page1.h"

/*
��������p1
���ܣ�ע�����Ĺ���
��ڲ���������ָ��pCar
����ֵ��int���ͣ�����page��ֵ
*/
int p1(PCAR pCar)
{
	int page = 1;
	int isPopWindow = 0;
	int adminMode = 0;
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
		#ifdef SHOWMOUSE
		showMousePos();
		#endif
		
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
			
			if(mouse_press(237,303,388,380) == 1)      //������ذ�ť
			{
				page = 0;
			}
			else if(mouse_press(427,303,564,380) == 1)        //����˳���ť
			{
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
			else if(mouse_press(47,303,198,380) == 1) 			//���ע���
			{
				if(check(userText,passwordText) == 0)
				{
					popWindow_withoutFlush(&buf, &isPopWindow, "��ʽ����");	
				}
				
				if(Register(userText,passwordText,adminMode) == 1)
				{
					if(adminMode == 1)
					{
						pCar->isAdmin = 1;
					}
					popWindow_withoutFlush(&buf, &isPopWindow, "ע��ɹ�");
								//ע��ɹ�����ת������ʾ����
				}
				else
				{
					popWindow_withoutFlush(&buf, &isPopWindow, "ע��ʧ��");
				}
			}
			else if(mouse_press(434,423,490,470) == 1)			//�������Աģʽ
			{
				delay(200);
				clrmous(mouseX,mouseY);
				if(adminMode == 0)
				{
					adminMode = 1;
					setfillstyle(SOLID_FILL,YELLOW);
					bar(434,423,490,470);
					setfillstyle(SOLID_FILL,BLACK);
				}
				else if(adminMode == 1)
				{
					adminMode = 0;
					setfillstyle(SOLID_FILL,BLACK);
					bar(434,423,490,470);
				}
				save_bk_mou(mouseX,mouseY);
				drawmous(mouseX,mouseY);
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
	setbkcolor(LIGHTCYAN);
	setcolor(DARKGRAY);
	setlinestyle(SOLID_LINE,0,THICK_WIDTH);
	circle(40,100,13);
	line(20,140,60,140);
	line(20,140,33,111);
	line(60,140,47,111);            //�û�ͼ�� 
	circle(41,241,14);
	line(40,240-13,40,195);
	line(40,195,55,195);
	line(40,205,55,205);            //����ͼ�� 
	setlinestyle(SOLID_LINE,0,NORM_WIDTH);
	rectangle(79,77,223,148);
	rectangle(246,77,567,148);
	rectangle(79,190,223,260);
	rectangle(246,190,567,260);
	puthz(90,90,"�û���",48,40,DARKGRAY);
	puthz(100,203,"����",48,48,DARKGRAY);
	
	setfillstyle(SOLID_FILL,DARKGRAY);
	bar(47,303,198,380);
	bar(237,303,388,380);
	bar(427,303,564,380);
	puthz(67,319,"ע��",48,52,WHITE);
	puthz(257,319,"����",48,52,WHITE);
	puthz(447,319,"�˳�",48,52,WHITE);

	puthz(135,423,"����Աģʽ",48,52,DARKGRAY);
	rectangle(433,422,491,471);
	
	return;
}


/*
��������Register
���ܣ�ע��
��ڲ������û����ı�userText�������ı�passwordText,����Աģʽ��־λadminMode
����ֵ��int���ͣ�1Ϊע��ɹ���0Ϊע��ʧ��
*/
int Register(char * userText, char * passwordText,int adminMode)
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

	if(adminMode == 0)
	{
		if ((fp = fopen("user.txt", "r")) == NULL)
		{
			exitFunc("open user.txt error");
		}
	}
	else if(adminMode == 1)
	{
		if ((fp = fopen("admin.txt", "r")) == NULL)
		{
			exitFunc("open admin.txt error");
		}
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

	if(adminMode == 0)
	{
		if ((fp = fopen("user.txt", "a")) == NULL)
		{
			exitFunc("open user.txt error");
		}
	}
	else if(adminMode == 1)
	{
		if ((fp = fopen("admin.txt", "a")) == NULL)
		{
			exitFunc("open admin.txt error");
		}
	}

	fprintf(fp, "[%d]\nID:",max+1);
	// fprintf(fp, "ID:");
	fprintf(fp, "%s\n", id);
	fprintf(fp, "PASSWORD:");
	fprintf(fp, "%s\n", password);

	if(adminMode == 0)
	{
		fprintf(fp,"BALANCE:0\n");			//��ʼ���Ϊ0
	}

	fclose(fp);
	return 1;
}


/*
��������check
���ܣ�����˺������ʽ
��ڲ������û����ı�userText,�����ı�passwordText
����ֵ��int���ͣ�1Ϊ��ʽ�ϸ�0Ϊ���ϸ� 
*/
int check(char * userText, char * passwordText)
{
	char *p1, *p2;
	p1=userText;
	p2=passwordText;
	while(*p1 != '\0')
	{
		if(*p1 != ' ' && *p1 != '@' && *p1 != '/' && *p1 != ',' && *p1 != '.')
		{
			*p1++;
		}
		else
		{
			return 0;
		}
	}
	
	while(*p2 != '\0')
	{
		if(*p2 != ' ')
		{
			*p2++;
		}
		else
		{
			return 0;
		}
	}
	
	return 1;
	
}




