/////////////////
//数据显示界面
////////////////
//data show
#include"page4.h"

/*
函数名：p4
功能：数据显示界面
入口参数：汽车指针pCar
返回值：int类型，返回page的值
*/
int p4(PCAR pCar)
{
	//这两个功能变量用于弹窗
	int isPopWindow = 0;
	void * buf = NULL;
	
	int page = 4;
	int num = 0;
	
	double electricityTemp = pCar->electricityLeft;
	double hasMileageTemp = pCar->hasMileage;
	double balanceTemp = pCar->balance;
	
	int total = 0; 	//时间之差
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
	
	//根据汽车runState状态高亮按钮
	//accroding car runState to light button
	switch(pCar->runState)
	{
		case 0:
			clrmous(mouseX,mouseY);
			setfillstyle(SOLID_FILL,DARKGRAY);
			bar(530, 104, 602, 137);
			printHZ(370+80+80,104,"熄火",32,WHITE);		//"misfire"
			save_bk_mou(mouseX,mouseY);
			drawmous(mouseX,mouseY);
			break;
		case 1:
			clrmous(mouseX,mouseY);
			setfillstyle(SOLID_FILL,DARKGRAY);
			bar(370,104,443,137);
			printHZ(370,104,"行驶",32,WHITE);			//"drive"
			save_bk_mou(mouseX,mouseY);
			drawmous(mouseX,mouseY);
			break;
		case 2:
			clrmous(mouseX,mouseY);
			setfillstyle(SOLID_FILL,DARKGRAY);
			bar(451,104,522,137);
			printHZ(370+80,104,"制动",32,WHITE);		//"stop"
			save_bk_mou(mouseX,mouseY);
			drawmous(mouseX,mouseY);
			break;
		//非常规情况置为熄火状态
		default:
			pCar->runState = 0;
			clrmous(mouseX,mouseY);
			setfillstyle(SOLID_FILL,DARKGRAY);
			bar(530, 104, 602, 137);
			printHZ(370+80+80,104,"熄火",32,WHITE);			//"misfire"
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
				popWindow_withoutFlush(&buf,&isPopWindow,"电量告急");		//"elec urgent"
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
						// printHZ(370+80+80,104,"熄火",32,YELLOW);
						// printHZ(370,104,"行驶",32,DARKGRAY);
						// printHZ(370+80,104,"制动",32,DARKGRAY);
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
			
			//注：double类型数据比较时不能用“==”
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
			if(mouse_press(370, 104, 443, 137) == 1 && pCar->runState != 1)			//driving state 行驶状态
			{
				
				if(pCar->electricityLeft <= 0)
				{
					//clrmous(mouseX,mouseY);
					popWindow_withoutFlush(&buf, &isPopWindow, "电量不足");		//"elec is not enough"
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
				// printHZ(370,104,"行驶",32,YELLOW);
				// setfillstyle(SOLID_FILL,BLACK);
				// bar(370+80,104,602,137);
				// printHZ(370+80,104,"制动",32,DARKGRAY);
				// printHZ(370+80+80,104,"熄火",32,DARKGRAY);
				// save_bk_mou(mouseX,mouseY);
				// drawmous(mouseX,mouseY);
			}
			if(mouse_press(451, 104, 522, 137) == 1 && pCar->runState != 2)		//stop State 制动状态
			{
				if(pCar->electricityLeft <= 0)
				{
					popWindow_withoutFlush(&buf, &isPopWindow, "电量不足");			//"elec is not enough"
					continue;
				}
				turnToState2();

				pCar->k = 20;
				pCar->runState = 2;			
				pCar->speed = 0;
				
			}
			if(mouse_press(533, 104, 602, 137) == 1 && pCar->runState != 0)		//misfire State 熄火状态
			{
				pCar->k = 0;
				pCar->runState = 0;			
				turnOffCarFacility(pCar);
				turnToState0();
			}
			
			if(mouse_press(372, 156+30, 512, 188+30) == 1)      //center controll 中控模块
			{
				if(pCar->runState == 0)
				{
					popWindow_withoutFlush(&buf, &isPopWindow, "请启动车辆");	//"please open the car "
					clrmous(mouseX,mouseY);
					setfillstyle(SOLID_FILL,BLACK);
                    bar(180,140,472,215);
                    printHZ_withoutRec(195, 150,"请启动车辆",48,DARKGRAY);		//"please open the car"
					save_bk_mou(mouseX,mouseY);
					drawmous(mouseX,mouseY);
					continue;
				}
				page = 5;
			}
			else if(mouse_press(370, 104+80+50,550,238+30) == 1)			//mileage cal 里程计算器
			{
				page = 6;					
			}			
			else if(mouse_press(370, 104+80+50+50,511,289+30) == 1)			//personal center 个人中心
			{
				page = 8;				
			}
			else if(mouse_press(372, 156+30, 512, 188+30) == 2)
			{
				if(num == 0)
				{
					button(370, 155+30, 512, 188+30,DARKGRAY,DARKGRAY);
					printHZ(370,104+80,"中控功能",32,WHITE);			//"center controll"
					num = 1;
				}
				continue;
			}
			else if(mouse_press(370, 104+80+50,550,238+30) == 2)
			{
				if(num == 0)
				{
					button(370, 104+80+50,550,238+30,DARKGRAY,DARKGRAY);
					printHZ(370, 104+80+50,"里程计算器",32,WHITE);		//"mileage cal"
					num = 2;
				}
				continue;
			}
			else if(mouse_press(370, 104+80+50+50,511,289+30) == 2)
			{
				if(num == 0)
				{
					button(370, 104+80+50+50,511,289+30,DARKGRAY,DARKGRAY);
					printHZ(370, 104+80+50+50,"个人中心",32,WHITE);		//"personal center"
					num = 3;
				}
				continue;
			}							
			else if(mouse_press(380,408,516,456) == 1)			//quit 退出
			{
				page = 3;
			}			
			else if(mouse_press(102,408,238,456) == 1)			//logout 注销
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
							printHZ(370,104+80,"中控功能",32,DARKGRAY);		//"center controll function"
							break;
						case 2:
							button(370, 104+80+50,550,238+30,DARKGRAY,LIGHTCYAN);
							printHZ(370, 104+80+50,"里程计算器",32,DARKGRAY);		//"mileage cal"
							break;
						case 3:
							button(370, 104+80+50+50,511,289+30,DARKGRAY,LIGHTCYAN);
							printHZ(370, 104+80+50+50,"个人中心",32,DARKGRAY);		//"personal center"
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
函数名：page4_screen
功能：绘制数据显示界面
入口参数：void
返回值：void
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
	printHZ_withoutRec(200,20,"数据显示",48,DARKGRAY);		//"data show"
	printHZ_withoutRec(30, 110,"剩余电量：",24,DARKGRAY);		//"left elec"
	printHZ_withoutRec(30, 200,"行驶里程：",24,DARKGRAY);		//"hasmileage"
	printHZ_withoutRec(30, 290,"剩余余额：",24,DARKGRAY);		//"left balance"
	printHZ_withoutRec(280, 200,"公里",24,DARKGRAY);			//"km"
	printHZ_withoutRec(320, 290,"元",24,DARKGRAY);				//"yuan"
	printHZ(370,104,"行驶",32,DARKGRAY);						//"drive"
	printHZ(370+80,104,"制动",32,DARKGRAY);						//"stop"
	printHZ(370+80+80,104,"熄火",32,DARKGRAY);					//"misfire"
	printHZ(370,104+80,"中控功能",32,DARKGRAY);					//"center controll func"
	printHZ(370,104+80+50,"里程计算器",32,DARKGRAY);			//"mileage cal"
	printHZ(370,104+80+50+50,"个人中心",32,DARKGRAY);			//"personal center"
	printText_withoutRec(280,112,"KWh",2,DARKGRAY);				
	
	setfillstyle(SOLID_FILL,DARKGRAY);	
	bar(102,408,238,456);
	bar(380,408,516,456);
	printHZ_withoutRec(122, 408,"注销",48,WHITE);				//"logout"
	printHZ_withoutRec(400, 408,"退出",48,WHITE);				//"quit"
		
	return;
}

/*
函数名：turnToState0
功能：转换成熄火状态的界面效果
入口参数：void
返回值：void
*/
void turnToState0(void)
{
	clrmous(mouseX,mouseY);
	setfillstyle(SOLID_FILL,BLACK);
	bar(370, 104,602, 137);
	setfillstyle(SOLID_FILL,DARKGRAY);
	bar(530, 104, 602, 137);
	printHZ(370+80+80,104,"熄火",32,WHITE);				//"misfire"
	printHZ(370,104,"行驶",32,DARKGRAY);				//"drive"
	printHZ(370+80,104,"制动",32,DARKGRAY);				//"stop"
	save_bk_mou(mouseX,mouseY);
	drawmous(mouseX,mouseY);

	return;
}

/*
函数名：turnToState1
功能：转换成行驶状态的界面效果
入口参数：void
返回值：void
*/
void turnToState1(void)
{
	clrmous(mouseX,mouseY);
	setfillstyle(SOLID_FILL,BLACK);
	bar(370, 104,602, 137);
	setfillstyle(SOLID_FILL,DARKGRAY);
	bar(530, 104, 602, 137);
	printHZ(370+80+80,104,"熄火",32,WHITE);				//"misfire"
	printHZ(370,104,"行驶",32,DARKGRAY);				//"drive"
	printHZ(370+80,104,"制动",32,DARKGRAY);				//"stop"
	save_bk_mou(mouseX,mouseY);
	drawmous(mouseX,mouseY);

	return;
}

/*
函数名：turnToState2
功能：转换成制动状态的界面效果
入口参数：void
返回值：void
*/
void turnToState2(void)
{
	clrmous(mouseX,mouseY);
	setfillstyle(SOLID_FILL,BLACK);
	bar(370, 104,602, 137);
	setfillstyle(SOLID_FILL,DARKGRAY);
	bar(451,104,522,137);
	printHZ(370+80,104,"制动",32,WHITE);			//"stop"
	printHZ(370,104,"行驶",32,DARKGRAY);			//"drive"
	printHZ(370+80+80,104,"熄火",32,DARKGRAY);			//"misfire"
	save_bk_mou(mouseX,mouseY);
	drawmous(mouseX,mouseY);

	return;
}

/*
函数名：turnOffCarFacility
功能：点击熄火后关闭汽车所有设备
入口参数：汽车指针pCar
返回值：void
*/
void turnOffCarFacility(PCAR pCar)
{
	pCar->airConditioningFlag = 0;
	pCar->lightFlag = 0;
	pCar->windowFlag = 0;
	pCar->musicFlag = 0;
	return ;
}







