/*
��¼����
*/

#include"page2.h"

/*
��������p2
���ܣ���¼����Ĺ���
��ڲ����������ṹ��ָ��pCar
����ֵ��int���ͣ�����page��ֵ
*/
int p2(PCAR pCar)
{
	int page = 2;
	
	time_t now = time(0);
	char userText[20] = {'\0'};
	char passwordText[20] = {'\0'};
	int loginFlag = 0;
	int adminMode = 0;
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
		if(0 == isPopWindow)			//û�е���ʱ����if
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
			else if(mouse_press(47,303,198,380) == 1) 			//�����¼��
			{			
				if( (loginFlag = Login(userText,passwordText,adminMode,pCar)) == 1 )
				{
					if(adminMode == 1)
					{
						pCar->isAdmin = 1;
					}
					pCar->info = *localtime(&now);
					strcpy(pCar->id,userText);
					// recordIn(userText,pCar);
					pCar->loginFlag = 1;
					popWindow(page2_screen,&isPopWindow,"��¼�ɹ�");
				}
				else
				{
					popWindow(page2_screen,&isPopWindow,"��¼ʧ��");
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
					if(pCar->isAdmin == 0)
					{
						page = 4;
					}
					else if(pCar->isAdmin == 1)
					{
						page = 13;
					}
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
	puthz(67,319,"��¼",48,52,WHITE);
	puthz(257,319,"����",48,52,WHITE);
	puthz(447,319,"�˳�",48,52,WHITE);

	puthz(135,423,"����Աģʽ",48,52,DARKGRAY);
	rectangle(433,422,491,471);
	
	return;
}

/*
��������Login
���ܣ���¼
��ڲ������û����ı�userText�������ı�passwordText,����Աģʽ��־λadminMode,����ָ��pCar
����ֵ��int���ͣ�1Ϊ��¼�ɹ���0Ϊ��¼ʧ��
*/
int Login(char * userText, char * passwordText,int adminMode,PCAR pCar)
{
	FILE* fp = NULL;
	char id[80] = {'\0'};
	char password[80] = {'\0'};
	char temp[80] = {'\0'};
	char id_temp[80] = {'\0'};
	char password_temp[80] = {'\0'};
	char* p = NULL;
	
	if(adminMode == 0)
	{
		if ((fp = fopen("user.txt", "r")) == NULL)
		{
			exitFunc("open file user.txt error!");
		}
	}
	else if(adminMode == 1)
	{
		if ((fp = fopen("admin.txt", "r")) == NULL)
		{
			exitFunc("open file admin.txt error!");
		}
	}
	
	strcpy(id,userText);
	strcpy(password,passwordText);
	
	fgets(temp, 80, fp);

	//��ȡuser.txt�еĽ��Ҹ�ֵ��pCar->balance
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
					fgets(temp,80,fp);
					if(adminMode == 0)
					{
						p = &temp[8];
						p[strlen(p)-1] = '\0';
						pCar->balance = atof(p);

					}
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









