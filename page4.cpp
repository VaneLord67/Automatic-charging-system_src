/////////////////
//������ʾ����
////////////////

#include"common.h"
#include"page4.h"

int p4(PCAR pCar)
{
	int isPopWindow = 0;
	void * buf;
	
	int page = 4;
	int electricityTemp = pCar->electricityLeft;
	int hasMileageTemp = pCar->hasMileage;
	int total = 0; 	//ʱ��֮��
	char electricityStringTemp[5];
	char hasMileageStringTemp[20];
	itoa(electricityTemp,electricityStringTemp,10);
	itoa(hasMileageTemp,hasMileageStringTemp,10);
	
	change_page(page4_screen);
	printText_withoutRec(165,110,electricityStringTemp,3,DARKGRAY);
	printText_withoutRec(165,200,hasMileageStringTemp,3,DARKGRAY);
	
	//��������runState״̬������ť
	switch(pCar->runState)
	{
		case 0:
			clrmous(mouseX,mouseY);
			setfillstyle(SOLID_FILL,GREEN);
			bar(530, 104, 602, 137);
			printHZ(370+80+80,104,"Ϩ��",32,YELLOW);
			save_bk_mou(mouseX,mouseY);
			drawmous(mouseX,mouseY);
			break;
		case 1:
			clrmous(mouseX,mouseY);
			setfillstyle(SOLID_FILL,GREEN);
			bar(370,104,443,137);
			printHZ(370,104,"��ʻ",32,YELLOW);
			save_bk_mou(mouseX,mouseY);
			drawmous(mouseX,mouseY);
			break;
		case 2:
			clrmous(mouseX,mouseY);
			setfillstyle(SOLID_FILL,GREEN);
			bar(451,104,522,137);
			printHZ(370+80,104,"�ƶ�",32,YELLOW);
			save_bk_mou(mouseX,mouseY);
			drawmous(mouseX,mouseY);
			break;
		default:
			pCar->runState = 0;
			break;
	}
	
	
	while(page == 4)
	{		
		newmouse(&mouseX,&mouseY,&press);
		showMousePos();
		
		if(0 == isPopWindow)
		{
			if(pCar->runState == 1)
			{
				pCar->temp = clock();
				total = (double)(pCar->temp - pCar->start) / CLOCKS_PER_SEC;
				if(total >= 1)
				{
					pCar->electricityLeft -= (total * pCar->speed) / (pCar->k + pCar->kEquipment);
					if(pCar->electricityLeft < 0)
					{
						pCar->electricityLeft = 0;
						pCar->runState = 0;
						clrmous(mouseX,mouseY);
						setfillstyle(SOLID_FILL,BLACK);
						bar(370, 104,602, 137);
						setfillstyle(SOLID_FILL,GREEN);
						bar(530, 104, 602, 137);
						printHZ(370+80+80,104,"Ϩ��",32,YELLOW);
						printHZ(370,104,"��ʻ",32,DARKGRAY);
						printHZ(370+80,104,"�ƶ�",32,DARKGRAY);
						save_bk_mou(mouseX,mouseY);
						drawmous(mouseX,mouseY);
					}
					pCar->hasMileage += total * pCar->speed;
					pCar->start = clock();
				}
			}
			
			if(electricityTemp != pCar->electricityLeft)
			{
				setfillstyle(SOLID_FILL,BLACK);
				setcolor(BLACK);
				bar(160,108,250,140);
				electricityTemp = pCar->electricityLeft;
				itoa(electricityTemp,electricityStringTemp,10);
				printText_withoutRec(165,110,electricityStringTemp,3,DARKGRAY);
				
			}
			
			if(hasMileageTemp != pCar->hasMileage)
			{
				setfillstyle(SOLID_FILL,BLACK);
				setcolor(BLACK);
				bar(160,108+90,250,140+90);
				hasMileageTemp = pCar->hasMileage;
				itoa(hasMileageTemp,hasMileageStringTemp,10);
				printText_withoutRec(165,200,hasMileageStringTemp,3,DARKGRAY);
			}
			if(mouse_press(370, 104, 443, 137) == 1 && pCar->runState != 1)			//��ʻ״̬
			{
				if(pCar->electricityLeft <= 0)
				{
					//clrmous(mouseX,mouseY);
					popWindow_withoutFlush(&buf, &isPopWindow, "��������");	
					// save_bk_mou(mouseX,mouseY);
					// drawmous(mouseX,mouseY);
					continue;
				}
				pCar->k = 10;
				pCar->runState = 1;			
				pCar->start = clock();
				clrmous(mouseX,mouseY);
				setfillstyle(SOLID_FILL,GREEN);
				bar(370,104,443,137);
				printHZ(370,104,"��ʻ",32,YELLOW);
				setfillstyle(SOLID_FILL,BLACK);
				bar(370+80,104,602,137);
				printHZ(370+80,104,"�ƶ�",32,DARKGRAY);
				printHZ(370+80+80,104,"Ϩ��",32,DARKGRAY);
				save_bk_mou(mouseX,mouseY);
				drawmous(mouseX,mouseY);
			}
			if(mouse_press(451, 104, 522, 137) == 1 && pCar->runState != 2)		//�ƶ�״̬
			{
				if(pCar->electricityLeft <= 0)
				{
					//clrmous(mouseX,mouseY);
					popWindow_withoutFlush(&buf, &isPopWindow, "��������");	
					// save_bk_mou(mouseX,mouseY);
					// drawmous(mouseX,mouseY);
					continue;
				}
				pCar->k = 20;
				pCar->runState = 2;			
				clrmous(mouseX,mouseY);
				setfillstyle(SOLID_FILL,BLACK);
				bar(370, 104,602, 137);
				setfillstyle(SOLID_FILL,GREEN);
				bar(451,104,522,137);
				printHZ(370+80,104,"�ƶ�",32,YELLOW);
				printHZ(370,104,"��ʻ",32,DARKGRAY);
				printHZ(370+80+80,104,"Ϩ��",32,DARKGRAY);
				save_bk_mou(mouseX,mouseY);
				drawmous(mouseX,mouseY);
			}
			if(mouse_press(533, 104, 602, 137) == 1 && pCar->runState != 0)		//Ϩ��״̬
			{
				pCar->k = 0;
				pCar->runState = 0;			
				clrmous(mouseX,mouseY);
				setfillstyle(SOLID_FILL,BLACK);
				bar(370, 104,602, 137);
				setfillstyle(SOLID_FILL,GREEN);
				bar(530, 104, 602, 137);
				printHZ(370+80+80,104,"Ϩ��",32,YELLOW);
				printHZ(370,104,"��ʻ",32,DARKGRAY);
				printHZ(370+80,104,"�ƶ�",32,DARKGRAY);
				save_bk_mou(mouseX,mouseY);
				drawmous(mouseX,mouseY);
			}
			if(mouse_press(372, 156, 512, 188) == 1)      //�п�ģ��
			{
				page = 5;
			}
			
			if(mouse_press(370,104+50+50,513,239) == 1)							//����ģ��
			{
				page = 7;
			}
			
			if(mouse_press(370, 104+50+50+50,550,288) == 1)			//��̼�����
			{
				page = 6;					
			}
			
			if(mouse_press(370, 104+50+50+50+50,511,339) == 1)
			{
				page = 8;
			}
			
			if(mouse_press(401,409,508,459) == 1)			//�˳�
			{
				page = 3;
			}
			
			if(mouse_press(123,409,230,459) == 1)			//ע��
			{
				recordWrite(pCar->id,pCar);
				pCar->loginFlag = 0;
				page = 0;
			}
		}
		else
		{
			//clrmous(mouseX,mouseY);
			popWindow_withoutFlush(&buf, &isPopWindow, "");
			// save_bk_mou(mouseX,mouseY);
			// drawmous(mouseX,mouseY);
		}
		
		
		
		
	}
	return page;
}

void page4_screen(void)
{
	cleardevice();
	setbkcolor(WHITE);
	setcolor(DARKGRAY);
	setlinestyle(SOLID_LINE,0,NORM_WIDTH);
	
	printHZ_withoutRec(200,20,"������ʾ",48,DARKGRAY);
	printHZ_withoutRec(30, 110,"ʣ�������",24,DARKGRAY);
	printHZ_withoutRec(30, 200,"��ʻ��̣�",24,DARKGRAY);
	printHZ_withoutRec(30+200+50, 200,"����",24,DARKGRAY);
	printHZ(370,104,"��ʻ",32,DARKGRAY);
	printHZ(370+80,104,"�ƶ�",32,DARKGRAY);
	printHZ(370+80+80,104,"Ϩ��",32,DARKGRAY);
	printHZ(370,104+50,"�пع���",32,DARKGRAY);
	printHZ(370,104+50+50,"��������",32,DARKGRAY);
	printHZ(370, 104+50+50+50,"��̼�����",32,DARKGRAY);
	printHZ(370, 104+50+50+50+50,"��������",32,DARKGRAY);
	printText_withoutRec(249,112,"KWh",2,DARKGRAY);
	
	// rectangle(237,303,388,404);
	// rectangle(413,303,564,404);
	// puthz(251,319,"����",48,52,DARKGRAY);
	// puthz(429,319,"�˳�",48,52,DARKGRAY);
	
	printHZ(122, 408,"ע��",48,DARKGRAY);
	printHZ(400, 408,"�˳�",48,DARKGRAY);
	
	
	return;
}










