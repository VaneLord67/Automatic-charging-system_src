/////////////////
//�����������
////////////////
//charge money cal
#include"page15.h"

/*
��������p15
���ܣ������������
��ڲ���������ָ��pCar
����ֵ��int���ͣ�����page��ֵ
*/
int p15(PCAR pCar)
{
    #ifdef DEBUGMODE
    //pCar->electricityLeft = 50;
    #endif

	int page = 15;

    double electricityTemp = pCar->electricityLeft;
    char electricityStringTemp[20];

    int isPopWindow = 0;
    void *buf = NULL;

    int isInDestElec = 0;
    int x_destElec = 132;
    int y_destElec = 240;
    int destElecLength = 0;
    char desetElecText[50] = {'\0'};
    char calMoneyString[50] = {'\0'};

    double calMoney = 0;
    double destElec = 0;
 	
	change_page(page15_screen);

    sprintf(electricityStringTemp,"%.1lf",electricityTemp);
    printText_withoutRec(132,155,electricityStringTemp,3,DARKGRAY);
	
	while(page == 15)
	{
        newmouse(&mouseX,&mouseY,&press);
        #ifdef SHOWMOUSE
        showMousePos();
        #endif

        if(0 == isPopWindow)
        {
            if(fabs(electricityTemp - pCar->electricityLeft) > 1e-05 )
            {
                clrmous(mouseX,mouseY);
                setfillstyle(SOLID_FILL,BLACK);
                setcolor(BLACK);
                bar(174,148,296,191);
                electricityTemp = pCar->electricityLeft;
                sprintf(electricityStringTemp,"%.1f",electricityTemp);
                printText_withoutRec(165,110,electricityStringTemp,3,DARKGRAY);
                save_bk_mou(mouseX,mouseY);
                drawmous(mouseX,mouseY);
            }

            if(isInDestElec == 1)
            {
                inputTextWithLength(&x_destElec,&y_destElec,&isInDestElec, &destElecLength,desetElecText,DARKGRAY,5);
            }
            else 
            {
                DiscardInput();
            }

            if(press == 1 && mouse_press(122,230,520,190+85) != 1)   //��������ط�ȡ������򼤻�״̬
            {
                isInDestElec = 0;
            }

            if(mouse_press(122,230,520,190+85) == 1)       //���Ŀ���������� (destin elec)
            {
                isInDestElec = 1;
            }
            
            if(mouse_press(401,409,508,459) == 1)			//ȡ�� (no)
            {
                page = 4;
            }

            if(mouse_press(325,232,485,277) == 1)                          //��������� (check)
            {
                delay(200);
                if(testStringIsFloat(desetElecText) == 0)
                {
                    popWindow_withoutFlush(&buf,&isPopWindow,"�����Ƿ�");  //elec error
                    continue;
                }
                if(atof(desetElecText) <=0 || atof(desetElecText) > MAX_ELECTRICITY || atof(desetElecText) <= pCar->electricityLeft)
                {
                    popWindow_withoutFlush(&buf,&isPopWindow,"�����Ƿ�"); //elec error
                    continue;
                }

                //ˢ��Ԥ�ƻ���
                setfillstyle(SOLID_FILL,BLACK);
				bar(137,329,300,362);
                
                destElec = atof(desetElecText);
                calMoney = (destElec-pCar->electricityLeft) * PRICE_PER_KWH;
                sprintf(calMoneyString,"%.2lf",calMoney);
                printText_withoutRec(137,329,calMoneyString,3,DARKGRAY);

            }
                
            if(mouse_press(123,409,230,459) == 1)			//ȷ�� (yes)
            {
                if(strlen(desetElecText) <= 0)
                {
                    popWindow_withoutFlush(&buf,&isPopWindow,"�����Ƿ�");  //elec error
                    continue;
                }
                destElec = atof(desetElecText);
                
                if(calMoney != (destElec-pCar->electricityLeft) * PRICE_PER_KWH)
                {
                    popWindow_withoutFlush(&buf,&isPopWindow,"�������"); //plz check
                    setfillstyle(SOLID_FILL,BLACK);
                    bar(180,140,472,215);
                    printHZ_withoutRec(195, 150,"�������",48,DARKGRAY); //plz check
                    continue;
                }
                if(pCar->balance < calMoney)
                {
                    popWindow_withoutFlush(&buf,&isPopWindow,"����"); //no money
                    continue;
                }
                pCar->destElec = destElec;
                page = 10;          //ת�������� (turn to charge page)
            }

        }
        else
        {
            popWindow_withoutFlush(&buf,&isPopWindow,"");
        }
    }

	return page;
	
}


/*
��������page15_screen
���ܣ����Ƴ����������
��ڲ�����void
����ֵ��void
*/
void page15_screen(void)
{
	cleardevice();
	setbkcolor(LIGHTCYAN);
	printHZ_withoutRec(200,20,"�����",48,DARKGRAY);
	printHZ_withoutRec(122,100,"��ǰ����",32,DARKGRAY);
	printHZ_withoutRec(122,100+90,"Ŀ�����",32,DARKGRAY);
	printHZ_withoutRec(122,100+90+90,"Ԥ�ƻ���",32,DARKGRAY);

	printHZ_withoutRec(330,233,"������",32,DARKGRAY);
	printHZ_withoutRec(330,330,"Ԫ",32,DARKGRAY);
    rectangle(321,230,487,275);



    setlinestyle(SOLID_LINE,0,NORM_WIDTH);
    rectangle(122,140,520,185);
    rectangle(122,230,313,190+85);
    rectangle(122,230+90,313,190+85+90);

	printHZ(122, 408,"ȷ��",48,DARKGRAY);
	printHZ(400, 408,"ȡ��",48,DARKGRAY);
	return;
}
