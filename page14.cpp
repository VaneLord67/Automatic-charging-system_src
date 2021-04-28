/////////////////
//��ֵ����
////////////////

#include"page14.h"

/*
��������p14
���ܣ���ֵ����
��ڲ���������ָ��pCar
����ֵ��int���ͣ�����page��ֵ
*/
int p14(PCAR pCar)
{
	int page = 14;
    int isPayFlag = 0;
    int isPopWindow = 0;
    void *buf = NULL;

    int isInCardID = 0;
    int isInPassword = 0;
    int isInBalance = 0;

    int x_cardID = 132;
    int y_cardID = 148;
    int x_password = 132;
    int y_password = 240;
    int x_balance = 132;
    int y_balance = 335;

    int cardIDLength = 0;
    int passwordLength = 0;
    int balanceLength = 0;

    char cardIDText[50] = {'\0'};
    char passwordText[50] = {'\0'};
    char balanceText[50] = {'\0'};
	
	change_page(page14_screen);
	
	while(page == 14)
	{
		newmouse(&mouseX,&mouseY,&press);
		#ifdef SHOWMOUSE
		showMousePos();
		#endif

        if(0 == isPopWindow)
        {
            if(isInCardID == 1)
            {
                inputText(&x_cardID,&y_cardID,&isInCardID, &cardIDLength,cardIDText,DARKGRAY);
            }
            else if(isInPassword == 1)
            {
                inputPassword(&x_password,&y_password,&isInPassword, &passwordLength,passwordText,DARKGRAY);
            }
            else if(isInBalance == 1)
            {
                inputText(&x_balance,&y_balance,&isInBalance, &balanceLength,balanceText,DARKGRAY);
            }
            else
            {
                DiscardInput();
            }

            if(press == 1 && mouse_press(122,140,520,185) != 1 && mouse_press(122,230,520,190+85) != 1 && mouse_press(122,230+90,520,190+85+90) != 1)   //��������ط�ȡ������򼤻�״̬
			{
				isInCardID = 0;
				isInPassword = 0;
                isInBalance = 0;
			}

            if(mouse_press(122,140,520,185) == 1)       //������������
            {
                isInCardID = 1;
                isInPassword = 0;
                isInBalance = 0;
            }

            if(mouse_press(122,230,520,190+85) == 1)       //������������
            {
                isInPassword = 1;
                isInCardID = 0;
                isInBalance = 0;
            }

            if(mouse_press(122,230+90,520,190+85+90) == 1)       //�����������
            {
                isInBalance = 1;
                isInCardID = 0;
                isInPassword = 0;
            }	

            if(mouse_press(261,408,261+48*2*1.1+2,408+48) == 1)       //�����ֵ
            {
                if(strlen(cardIDText) == 0)
                {
                    popWindow_withoutFlush(&buf,&isPopWindow,"����Ϊ��");
                    continue;
                }

                if(strlen(passwordText) == 0)
                {
                    popWindow_withoutFlush(&buf,&isPopWindow,"����Ϊ��");
                    continue;
                }

                if(strlen(balanceText) == 0)
                {
                    popWindow_withoutFlush(&buf,&isPopWindow,"���Ϊ��");
                    continue;
                }
                
                if(testStringIsAllNumbers(cardIDText) == 0)
                {
                    popWindow_withoutFlush(&buf,&isPopWindow,"���ŷǷ�");
                    continue;
                }

                if(testStringIsFloat(balanceText) != 1)
                {
                    popWindow_withoutFlush(&buf,&isPopWindow,"���Ƿ�");
                    continue;
                }

                //���������������ܳ�ֵ�ɹ�
                popWindow_withoutFlush(&buf,&isPopWindow,"��ֵ�ɹ�");
                pCar->balance += atof(balanceText);
                updateBalance(pCar);
                isPayFlag = 1;
                continue;

            } 
            if(mouse_press(261,408,261+48*2*1.1+2,408+48) == 1)
            {
                if((isPayFlag = card_check(cardIDText,passwordText)) == 1)
               	{
               		popWindow_withoutFlush(&buf,&isPopWindow,"��ֵ�ɹ�");
               		pCar->balance += atof(balanceText);
               		updateBalance(pCar);
               		isPayFlag = 1;
               		continue;
				}
				else
				{
					popWindow_withoutFlush(&buf,&isPopWindow,"��ֵʧ��");
				}
			}
            
					

            if(mouse_press(400,408,400+48*2*1.1+2,408+48) == 1)			//�˳�
            {
                page = 3;
            }
            
            if(mouse_press(122,408,122+48*2*1.1+2,408+48) == 1)			//����
            {
                page = 4;
            }
        }
        else
        {
            if(popWindow_withoutFlush(&buf,&isPopWindow,"") == 1)
            {
                if(isPayFlag == 1)
                {
                    page = 4;
                }
            }
        }

	}

    if(buf != NULL)
    {
        free(buf);
    }
	return page;
}


/*
��������page14_screen
���ܣ����Ƴ�ֵ����
��ڲ�����void
����ֵ��void
*/
void page14_screen(void)
{
	cleardevice();
	setbkcolor(LIGHTCYAN);
	setcolor(DARKGRAY); 
	printHZ_withoutRec(200,20,"��ֵ����",48,DARKGRAY);
	printHZ_withoutRec(122,100,"���п���",32,DARKGRAY);
	printHZ_withoutRec(122,100+90,"����",32,DARKGRAY);
	printHZ_withoutRec(122,100+90+90,"���",32,DARKGRAY);

    setlinestyle(SOLID_LINE,0,NORM_WIDTH);
    rectangle(122,140,520,185);
    rectangle(122,230,520,190+85);
    rectangle(122,230+90,520,190+85+90);

	setfillstyle(SOLID_FILL,DARKGRAY);
	bar(261,408,261+48*2*1.1+2,408+48);
	bar(122,408,122+48*2*1.1+2,408+48);
	bar(400,408,400+48*2*1.1+2,408+48);
    printHZ(261,408,"��ֵ",48,WHITE);
	printHZ(122, 408,"����",48,WHITE);
	printHZ(400, 408,"�˳�",48,WHITE);
	return;
}

/*
��������updateBalance
���ܣ������û����
��ڲ������û�ָ��pCar
����ֵ��void
*/
void updateBalance(PCAR pCar)
{
    FILE * fp = NULL;
    FILE * fpTemp = NULL;
    char * p = NULL;
    char temp[80] = {'\0'};
    char id_temp[80] = {'\0'};
    int hasUpdate = 0;
    fp = fopen("user.txt","r+");
    fpTemp = fopen("temp.txt","w");
    if(fp == NULL)
    {
        exitFunc("user.txt open error!");
    }
    if(fpTemp == NULL)
    {
        exitFunc("temp.txt create error!");
    }

    while(fgets(temp,80,fp) != NULL)
    {
        if ((temp[0] == 'I') && (temp[1] == 'D') && (temp[2] == ':'))
		{
            fprintf(fpTemp,"%s",temp);  //����ID
			strcpy(id_temp, temp + 3);
			p = strchr(id_temp, '\n');
			*p = '\0';
			if (strcmp(id_temp, pCar->id) == 0 && hasUpdate == 0)
			{
				fgets(temp, 80, fp);        //ִ�к�ָ�������һ��
                fprintf(fpTemp,"%s",temp);  //��������
                fprintf(fpTemp,"BALANCE:%.2lf\n",pCar->balance);       //���������д�������ļ���
                //fprintf(fpTemp,"BALANCE:0\n");       //���������д�������ļ���
                fgets(temp,80,fp);          //����ԭ�ļ������һ��
                hasUpdate = 1;
			}
            // else
            // {
            //     //fprintf(fpTemp,"%s",temp);
            // }
        }
        else
        {
            fprintf(fpTemp,"%s",temp);
        }
        
    }

	fclose(fp);
    fclose(fpTemp);

    //����ѻ����ļ��е������ٸ��Ƶ�ԭ�ļ�
    fp = fopen("user.txt","w");
    if(fp == NULL)
    {
        exitFunc("user.txt open error!");
    }
    fpTemp = fopen("temp.txt","r");
    if(fpTemp == NULL)
    {
        exitFunc("temp.txt read error!");
    }
    while(fgets(temp,80,fpTemp) != NULL)
    {
        fprintf(fp,"%s",temp);
    }

    fclose(fp);
    fclose(fpTemp);

    return;
}

/*
��������card_check
���ܣ�������п��˺�����
��ڲ����������ı�cardText,�����ı�cardpasText
����ֵ��int���ͣ�1Ϊ���ͨ����0Ϊ��鲻ͨ��
*/
int card_check(char * cardIDText,char * passwordText)
{
	FILE* fp = NULL;
	char card[80] = {'\0'};
	char password[80] = {'\0'};
	char card_temp[80] = {'\0'};
	char password_temp[80] = {'\0'};
	char *p = NULL;
	char temp[80] = {'\0'};
	
	if((fp = fopen("card.txt","r")) == NULL)
	{
		exitFunc("open file card.txt error!");
	} 
	
	strcpy(card,cardIDText);
	strcpy(password,passwordText);
	fgets(temp, 80, fp);
	
	while(temp != NULL)
	{
		if ((temp[0] == 'I') && (temp[1] == 'D') && (temp[2] == ':'))
		{
			strcpy(card_temp, temp + 3);
			p = strchr(card_temp, '\n');
			*p = '\0';
			if (strcmp(card_temp,card) == 0)
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
    return 0;
} 
