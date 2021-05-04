/////////////////
//������ʾ����
////////////////
//data show
#include"page4.h"

/*
��������p4
���ܣ�������ʾ����
��ڲ���������ָ��pCar
����ֵ��int���ͣ�����page��ֵ
*/
int p4(PCAR pCar)
{
	//���������ܱ������ڵ���
	int isPopWindow = 0;
	void * buf = NULL;
	
	int page = 4;
	int num = 0;
	
	double electricityTemp = pCar->electricityLeft;
	double hasMileageTemp = pCar->hasMileage;
	double balanceTemp = pCar->balance;
	
	int total = 0; 	//ʱ��֮��
	int hasWarning = 0;
	
	char electricityStringTemp[20];
	char hasMileageStringTemp[20];
	char balanceStringTemp[20];
	sprintf(electricityStringTemp,"%.1lf",electricityTemp);
	sprintf(hasMileageStringTemp,"%.1lf",hasMileageTemp);
	sprintf(balanceStringTemp,"%.2lf",balanceTemp);
	
	change_page(page4_screen);
	clrmous(mouseX,mouseY);
	printText_withoutRec(165,110,electricityStringTemp,3,DARKGRAY);
	printText_withoutRec(165,200,hasMileageStringTemp,3,DARKGRAY);
	printText_withoutRec(165,200+90,balanceStringTemp,3,DARKGRAY);
	save_bk_mou(mouseX,mouseY);
	drawmous(mouseX,mouseY);
	
	//��������runState״̬������ť
	//accroding car runState to light button
	switch(pCar->runState)
	{
		case 0:
			clrmous(mouseX,mouseY);
			setfillstyle(SOLID_FILL,DARKGRAY);
			bar(530, 104, 602, 137);
			printHZ(370+80+80,104,"Ϩ��",32,WHITE);		//"misfire"
			save_bk_mou(mouseX,mouseY);
			drawmous(mouseX,mouseY);
			break;
		case 1:
			clrmous(mouseX,mouseY);
			setfillstyle(SOLID_FILL,DARKGRAY);
			bar(370,104,443,137);
			printHZ(370,104,"��ʻ",32,WHITE);			//"drive"
			save_bk_mou(mouseX,mouseY);
			drawmous(mouseX,mouseY);
			break;
		case 2:
			clrmous(mouseX,mouseY);
			setfillstyle(SOLID_FILL,DARKGRAY);
			bar(451,104,522,137);
			printHZ(370+80,104,"�ƶ�",32,WHITE);		//"stop"
			save_bk_mou(mouseX,mouseY);
			drawmous(mouseX,mouseY);
			break;
		//�ǳ��������ΪϨ��״̬
		default:
			pCar->runState = 0;
			clrmous(mouseX,mouseY);
			setfillstyle(SOLID_FILL,DARKGRAY);
			bar(530, 104, 602, 137);
			printHZ(370+80+80,104,"Ϩ��",32,WHITE);			//"misfire"
			save_bk_mou(mouseX,mouseY);
			drawmous(mouseX,mouseY);
			break;
	}
	
	while(page == 4)
	{		
		newmouse(&mouseX,&mouseY,&press);
		
		#ifdef SHOWMOUSE
		showMousePos();
		#endif
		
		if(0 == isPopWindow)
		{
			if(pCar->electricityLeft < WARNING_ELECTRICITY && pCar->runState == 2 && hasWarning == 0)
			{
				popWindow_withoutFlush(&buf,&isPopWindow,"�����漱");		//"elec urgent"
				hasWarning = 1;
			}

			if(pCar->runState == 1)
			{
				// pCar->temp = clock();
				// total = (double)(pCar->temp - pCar->start) / CLOCKS_PER_SEC;
				// if(total >= 1)
				// {
					// pCar->electricityLeft -= (total * pCar->speed) / (pCar->k + pCar->kEquipment);
					// if(pCar->electricityLeft < 0)
					// {
						// pCar->electricityLeft = 0;
						// pCar->runState = 0;
						// clrmous(mouseX,mouseY);
						// setfillstyle(SOLID_FILL,BLACK);
						// bar(370, 104,602, 137);
						// setfillstyle(SOLID_FILL,GREEN);
						// bar(530, 104, 602, 137);
						// printHZ(370+80+80,104,"Ϩ��",32,YELLOW);
						// printHZ(370,104,"��ʻ",32,DARKGRAY);
						// printHZ(370+80,104,"�ƶ�",32,DARKGRAY);
						// save_bk_mou(mouseX,mouseY);
						// drawmous(mouseX,mouseY);
					// }
					// //pCar->hasMileage += (double)total * pCar->speed;
					// pCar->start = clock();
				// }
			}
			else if(pCar->runState == 2)
			{
				pCar->temp = clock();
				total = (double)(pCar->temp - pCar->start) / CLOCKS_PER_SEC;
				if(total >= 5)
				{
					pCar->electricityLeft -= (2.0 * (total / 5)) / (pCar->k + pCar->kEquipment);
					if(pCar->electricityLeft < 0)
					{
						pCar->electricityLeft = 0;
						pCar->runState = 0;
						turnToState0();
						turnOffCarFacility(pCar);
					}
					//pCar->hasMileage += (double)total * pCar->speed;
					pCar->start = clock();
				}
			}
			
			//ע��double�������ݱȽ�ʱ�����á�==��
			if(fabs(electricityTemp - pCar->electricityLeft) > 0.00001)
			{
				setfillstyle(SOLID_FILL,BLACK);
				setcolor(BLACK);
				bar(160,108,272,145);
				electricityTemp = pCar->electricityLeft;
				// itoa(electricityTemp,electricityStringTemp,10);
				sprintf(electricityStringTemp,"%.1lf",electricityTemp);
				printText_withoutRec(165,110,electricityStringTemp,3,DARKGRAY);
				
			}
			
			if(fabs(hasMileageTemp - pCar->hasMileage) > 0.00001)
			{
				setfillstyle(SOLID_FILL,BLACK);
				setcolor(BLACK);
				bar(160,108+90,278,140+90);
				hasMileageTemp = pCar->hasMileage;
				sprintf(hasMileageStringTemp,"%.1lf",hasMileageTemp);
				//itoa(hasMileageTemp,hasMileageStringTemp,10);
				printText_withoutRec(165,200,hasMileageStringTemp,3,DARKGRAY);
			}

			if(fabs(balanceTemp - pCar->balance) > 1e-5)
			{
				setfillstyle(SOLID_FILL,BLACK);
				setcolor(BLACK);
				bar(160,108+90+90,280,140+90+90);
				balanceTemp = pCar->balance;
				sprintf(balanceStringTemp,"%.2f",balanceTemp);
				//itoa(hasMileageTemp,hasMileageStringTemp,10);
				printText_withoutRec(165,200+90,balanceStringTemp,3,DARKGRAY);
			}
			if(mouse_press(370, 104, 443, 137) == 1 && pCar->runState != 1)			//driving state ��ʻ״̬
			{
				
				if(pCar->electricityLeft <= 0)
				{
					//clrmous(mouseX,mouseY);
					popWindow_withoutFlush(&buf, &isPopWindow, "��������");		//"elec is not enough"
					// save_bk_mou(mouseX,mouseY);
					// drawmous(mouseX,mouseY);
					continue;
				}
				page = 12;
				
				pCar->k = 10;
				pCar->runState = 1;		
				// pCar->speed = 60;
				// pCar->start = clock();
				// clrmous(mouseX,mouseY);
				// setfillstyle(SOLID_FILL,GREEN);
				// bar(370,104,443,137);
				// printHZ(370,104,"��ʻ",32,YELLOW);
				// setfillstyle(SOLID_FILL,BLACK);
				// bar(370+80,104,602,137);
				// printHZ(370+80,104,"�ƶ�",32,DARKGRAY);
				// printHZ(370+80+80,104,"Ϩ��",32,DARKGRAY);
				// save_bk_mou(mouseX,mouseY);
				// drawmous(mouseX,mouseY);
			}
			if(mouse_press(451, 104, 522, 137) == 1 && pCar->runState != 2)		//stop State �ƶ�״̬
			{
				if(pCar->electricityLeft <= 0)
				{
					popWindow_withoutFlush(&buf, &isPopWindow, "��������");			//"elec is not enough"
					continue;
				}
				turnToState2();

				pCar->k = 20;
				pCar->runState = 2;			
				pCar->speed = 0;
				
			}
			if(mouse_press(533, 104, 602, 137) == 1 && pCar->runState != 0)		//misfire State Ϩ��״̬
			{
				pCar->k = 0;
				pCar->runState = 0;			
				turnOffCarFacility(pCar);
				turnToState0();
			}
			
			if(mouse_press(372, 156+30, 512, 188+30) == 1)      //center controll �п�ģ��
			{
				if(pCar->runState == 0)
				{
					popWindow_withoutFlush(&buf, &isPopWindow, "����������");	//"please open the car "
					clrmous(mouseX,mouseY);
					setfillstyle(SOLID_FILL,BLACK);
                    bar(180,140,472,215);
                    printHZ_withoutRec(195, 150,"����������",48,DARKGRAY);		//"please open the car"
					save_bk_mou(mouseX,mouseY);
					drawmous(mouseX,mouseY);
					continue;
				}
				page = 5;
			}
			else if(mouse_press(370, 104+80+50,550,238+30) == 1)			//mileage cal ��̼�����
			{
				page = 6;					
			}			
			else if(mouse_press(370, 104+80+50+50,511,289+30) == 1)			//personal center ��������
			{
				page = 8;				
			}
			else if(mouse_press(372, 156+30, 512, 188+30) == 2)
			{
				if(num == 0)
				{
					button(370, 155+30, 512, 188+30,DARKGRAY,DARKGRAY);
					printHZ(370,104+80,"�пع���",32,WHITE);			//"center controll"
					num = 1;
				}
				continue;
			}
			else if(mouse_press(370, 104+80+50,550,238+30) == 2)
			{
				if(num == 0)
				{
					button(370, 104+80+50,550,238+30,DARKGRAY,DARKGRAY);
					printHZ(370, 104+80+50,"��̼�����",32,WHITE);		//"mileage cal"
					num = 2;
				}
				continue;
			}
			else if(mouse_press(370, 104+80+50+50,511,289+30) == 2)
			{
				if(num == 0)
				{
					button(370, 104+80+50+50,511,289+30,DARKGRAY,DARKGRAY);
					printHZ(370, 104+80+50+50,"��������",32,WHITE);		//"personal center"
					num = 3;
				}
				continue;
			}							
			else if(mouse_press(380,408,516,456) == 1)			//quit �˳�
			{
				page = 3;
			}			
			else if(mouse_press(102,408,238,456) == 1)			//logout ע��
			{
				recordWrite(pCar->id,pCar);
				carInfoWrite(pCar);
				pCar->loginFlag = 0;
				page = 0;
			}
			else
			{
				if(num != 0);
				{
					switch(num)
					{
						case 1:
							button(370, 155+30, 512, 188+30,DARKGRAY,LIGHTCYAN);
							printHZ(370,104+80,"�пع���",32,DARKGRAY);		//"center controll function"
							break;
						case 2:
							button(370, 104+80+50,550,238+30,DARKGRAY,LIGHTCYAN);
							printHZ(370, 104+80+50,"��̼�����",32,DARKGRAY);		//"mileage cal"
							break;
						case 3:
							button(370, 104+80+50+50,511,289+30,DARKGRAY,LIGHTCYAN);
							printHZ(370, 104+80+50+50,"��������",32,DARKGRAY);		//"personal center"
							break;	
					}
					num = 0;
				}
				continue;
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
��������page4_screen
���ܣ�����������ʾ����
��ڲ�����void
����ֵ��void
*/
void page4_screen(void)
{
	cleardevice();
	setbkcolor(LIGHTCYAN);
	setcolor(DARKGRAY);
	
	setlinestyle(SOLID_LINE,0,THICK_WIDTH);
	circle(407,158,15);
	circle(407+80,158,15);
	circle(407+160,158,15);
	line(557,168,577,148);
	line(400,152,400,164);
	int a[] = {406,152,415,158,406,164,406,152};
	drawpoly(4,a);
	line(484,150,484,166);
	line(484,150,492,155);
	line(492,155,484,160);
	
	setlinestyle(SOLID_LINE,0,NORM_WIDTH);
	printHZ_withoutRec(200,20,"������ʾ",48,DARKGRAY);		//"data show"
	printHZ_withoutRec(30, 110,"ʣ�������",24,DARKGRAY);		//"left elec"
	printHZ_withoutRec(30, 200,"��ʻ��̣�",24,DARKGRAY);		//"hasmileage"
	printHZ_withoutRec(30, 290,"ʣ����",24,DARKGRAY);		//"left balance"
	printHZ_withoutRec(280, 200,"����",24,DARKGRAY);			//"km"
	printHZ_withoutRec(320, 290,"Ԫ",24,DARKGRAY);				//"yuan"
	printHZ(370,104,"��ʻ",32,DARKGRAY);						//"drive"
	printHZ(370+80,104,"�ƶ�",32,DARKGRAY);						//"stop"
	printHZ(370+80+80,104,"Ϩ��",32,DARKGRAY);					//"misfire"
	printHZ(370,104+80,"�пع���",32,DARKGRAY);					//"center controll func"
	printHZ(370,104+80+50,"��̼�����",32,DARKGRAY);			//"mileage cal"
	printHZ(370,104+80+50+50,"��������",32,DARKGRAY);			//"personal center"
	printText_withoutRec(280,112,"KWh",2,DARKGRAY);				
	
	setfillstyle(SOLID_FILL,DARKGRAY);	
	bar(102,408,238,456);
	bar(380,408,516,456);
	printHZ_withoutRec(122, 408,"ע��",48,WHITE);				//"logout"
	printHZ_withoutRec(400, 408,"�˳�",48,WHITE);				//"quit"
		
	return;
}

/*
��������turnToState0
���ܣ�ת����Ϩ��״̬�Ľ���Ч��
��ڲ�����void
����ֵ��void
*/
void turnToState0(void)
{
	clrmous(mouseX,mouseY);
	setfillstyle(SOLID_FILL,BLACK);
	bar(370, 104,602, 137);
	setfillstyle(SOLID_FILL,DARKGRAY);
	bar(530, 104, 602, 137);
	printHZ(370+80+80,104,"Ϩ��",32,WHITE);				//"misfire"
	printHZ(370,104,"��ʻ",32,DARKGRAY);				//"drive"
	printHZ(370+80,104,"�ƶ�",32,DARKGRAY);				//"stop"
	save_bk_mou(mouseX,mouseY);
	drawmous(mouseX,mouseY);

	return;
}

/*
��������turnToState1
���ܣ�ת������ʻ״̬�Ľ���Ч��
��ڲ�����void
����ֵ��void
*/
void turnToState1(void)
{
	clrmous(mouseX,mouseY);
	setfillstyle(SOLID_FILL,BLACK);
	bar(370, 104,602, 137);
	setfillstyle(SOLID_FILL,DARKGRAY);
	bar(530, 104, 602, 137);
	printHZ(370+80+80,104,"Ϩ��",32,WHITE);				//"misfire"
	printHZ(370,104,"��ʻ",32,DARKGRAY);				//"drive"
	printHZ(370+80,104,"�ƶ�",32,DARKGRAY);				//"stop"
	save_bk_mou(mouseX,mouseY);
	drawmous(mouseX,mouseY);

	return;
}

/*
��������turnToState2
���ܣ�ת�����ƶ�״̬�Ľ���Ч��
��ڲ�����void
����ֵ��void
*/
void turnToState2(void)
{
	clrmous(mouseX,mouseY);
	setfillstyle(SOLID_FILL,BLACK);
	bar(370, 104,602, 137);
	setfillstyle(SOLID_FILL,DARKGRAY);
	bar(451,104,522,137);
	printHZ(370+80,104,"�ƶ�",32,WHITE);			//"stop"
	printHZ(370,104,"��ʻ",32,DARKGRAY);			//"drive"
	printHZ(370+80+80,104,"Ϩ��",32,DARKGRAY);			//"misfire"
	save_bk_mou(mouseX,mouseY);
	drawmous(mouseX,mouseY);

	return;
}

/*
��������turnOffCarFacility
���ܣ����Ϩ���ر����������豸
��ڲ���������ָ��pCar
����ֵ��void
*/
void turnOffCarFacility(PCAR pCar)
{
	pCar->airConditioningFlag = 0;
	pCar->lightFlag = 0;
	pCar->windowFlag = 0;
	pCar->musicFlag = 0;
	return ;
}







