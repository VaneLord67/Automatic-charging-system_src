/////////////////
//里程计算界面
////////////////
//mileage cal
#include"page6.h"

/*
函数名：p6
功能：里程计算界面的功能
入口参数：汽车结构体指针pCar
返回值：int类型，返回page的值
*/
int p6(PCAR pCar)		//mileage cal func
{
	int page = 6;
	int temperatureTemp = pCar->temperature;
	double electricityTemp = pCar->electricityLeft;
	double mileageTemp = 0;
	int kTemp = 10;
	char electricityStringTemp[20];
	char temperatureStringTemp[5];
	char mileageStringTemp[20];
	change_page(page6_screen);
	// switch(pCar->runState)
	// {
		// case 0:				//熄火
			// //mileageTemp = (pCar->electricityLeft)*(pCar->k + 10)+(pCar->b);
			// kTemp = 10;
			// break;
		// case 1:				//行驶
			// //mileageTemp = (pCar->electricityLeft)*(pCar->k)+(pCar->b);
			// kTemp = ;
			// break;
		// case 2:
			// //mileageTemp = (pCar->electricityLeft)*(pCar->k + 2)+(pCar->b);
			// kTemp = pCar->k - 8;
			// break;
		// default:
			// break;
	// }
	mileageTemp = (pCar->electricityLeft)*(kTemp+pCar->kEquipment) / 2 +(pCar->b);
	//printf("%d\n",pCar->kEquipment);
	itoa(temperatureTemp,temperatureStringTemp,10);
	//itoa(electricityTemp,electricityStringTemp,10);
	sprintf(electricityStringTemp,"%.1f",electricityTemp);
	sprintf(mileageStringTemp,"%.1f",mileageTemp);
	//itoa(mileageTemp,mileageStringTemp,10);
	printText_withoutRec(230,258,temperatureStringTemp,3,DARKGRAY);
	printText_withoutRec(199,155,electricityStringTemp,3,DARKGRAY);
	printText_withoutRec(250,80,mileageStringTemp,3,DARKGRAY);
	
	while(page == 6)
	{
		newmouse(&mouseX,&mouseY,&press);
		#ifdef SHOWMOUSE
		showMousePos();
		#endif
		
		setfillstyle(SOLID_FILL,DARKGRAY);
		if(pCar->airConditioningFlag == 1)
		{
			floodfill(520,150,DARKGRAY);
		}
		if(pCar->lightFlag == 1)
		{
			floodfill(520,200,DARKGRAY);
		}
		if(pCar->musicFlag == 1)
		{
			floodfill(520,250,DARKGRAY);
		}
		if(pCar->windowFlag == 1)
		{
			floodfill(520,300,DARKGRAY);
		}
		
		//注：double类型数据比较时不能用== 和 !=
		if(fabs(electricityTemp - pCar->electricityLeft) > 1e-05 )
		{
			clrmous(mouseX,mouseY);
			setfillstyle(SOLID_FILL,BLACK);
			setcolor(BLACK);
			bar(174,148,296,191);
			electricityTemp = pCar->electricityLeft;
			// itoa(electricityTemp,electricityStringTemp,10);
			sprintf(electricityStringTemp,"%.1f",electricityTemp);
			printText_withoutRec(165,110,electricityStringTemp,3,DARKGRAY);
			save_bk_mou(mouseX,mouseY);
			drawmous(mouseX,mouseY);
		}
		
		if(temperatureTemp != pCar->temperature)
		{
			clrmous(mouseX,mouseY);
			setfillstyle(SOLID_FILL,BLACK);
			setcolor(BLACK);
			bar(204,256,285,279);
			temperatureTemp = pCar->temperature;
			itoa(temperatureTemp,temperatureStringTemp,10);
			printText_withoutRec(230,258,temperatureStringTemp,3,DARKGRAY);
			save_bk_mou(mouseX,mouseY);
			drawmous(mouseX,mouseY);
		}
		
		if(fabs(mileageTemp -  (pCar->electricityLeft)*(kTemp+pCar->kEquipment) / 2 +(pCar->b)) > 1e-5)
		{
			clrmous(mouseX,mouseY);
			setfillstyle(SOLID_FILL,BLACK);
			setcolor(BLACK);
			bar(250,80,376,107);
			mileageTemp = (pCar->electricityLeft)*(kTemp+pCar->kEquipment) / 2 +(pCar->b);
			// mileageTemp = (pCar->electricityLeft)*(pCar->k)+(pCar->b);
			//itoa(mileageTemp,mileageStringTemp,10);
			sprintf(mileageStringTemp,"%.1f",mileageTemp);
			printText_withoutRec(250,80,mileageStringTemp,3,DARKGRAY);
			save_bk_mou(mouseX,mouseY);
			drawmous(mouseX,mouseY);
		}
		
		if(mouse_press(170,250,212,282) == 1)				//down outside car temperature 减少车外温度
		{
			if(pCar->temperature >= 10 && pCar->temperature <= 30)
			{
				pCar->temperature = pCar->temperature - 10;
				//pCar->kEquipment -= 1;
				pCar->kEquipment -= 1;
				delay(200);
			}
		}
		
		if(mouse_press(316,250,350,282) == 1)				//up outside car temperature增加车外温度
		{
			if(pCar->temperature >= 0 && pCar->temperature < 30)
			{
				pCar->temperature = pCar->temperature + 10;
				pCar->kEquipment += 1;
				delay(200);
			}
		}
		
		if(mouse_press(390,408,400+48+48+10,408+48) == 1)			//quit 退出
		{
			page = 3;
		}
		
		if(mouse_press(112,408,122+48+48+10,408+48) == 1)			//back 返回
		{
			page = 4;
		}
		
	}
	return page;
}

/*
函数名：page6_screen
功能：里程计算界面绘制
入口参数：void
返回值：void
*/
void page6_screen(void)		//mileage cal func draw
{
	cleardevice();
	setbkcolor(LIGHTCYAN);
	setcolor(DARKGRAY);	
	setlinestyle(SOLID_LINE,0,THICK_WIDTH);
	rectangle(40,180,130,220);
	rectangle(130,185,138,215);
	line(47,190,47,210);
	line(115,190,115,210);
	line(105,200,125,200);
	circle(40,300,5);
	rectangle(44,298,132,302);
	printHZ_withoutRec(180, 10,"里程计算器",48,DARKGRAY);			//"mileage cal"
	printHZ_withoutRec(375, 70,"公里",32,DARKGRAY);					//"km"
	printHZ_withoutRec(30,150,"剩余电量：",24,DARKGRAY);			//"left elec"
	printHZ_withoutRec(30,250,"车外温度：",24,DARKGRAY);			//"outside car temperature"
	printHZ_withoutRec(400,140,"空调：",24,DARKGRAY);				//"airconditioning"
	printHZ_withoutRec(400,190,"车灯：",24,DARKGRAY);				//"car light"
	printHZ_withoutRec(400,240,"音乐：",24,DARKGRAY);				//"music"
	printHZ_withoutRec(400,290,"天窗：",24,DARKGRAY);				//"sky window"
	setlinestyle(SOLID_LINE,0,NORM_WIDTH);
	rectangle(170,250,350,280);
	circle(520,150,7);
	circle(520,200,7);
	circle(520,250,7);
	circle(520,300,7);
	line(195,259,181,268);
	line(181,268,195,275);
	line(324,259,338,268);
	line(338,268,324,275);
	
	printHZ_withoutRec(285,258,"℃",24,DARKGRAY);			//"she shi du"
	
	printText_withoutRec(300,155,"KWh",2,DARKGRAY);
	
	setfillstyle(SOLID_FILL,DARKGRAY);
	bar(112,408,122+48*2*1.1+2,408+48);
	bar(390,408,400+48*2*1.1+2,408+48);
	floodfill(123,409,DARKGRAY); 
	floodfill(401,409,DARKGRAY);
	printHZ(122, 408,"返回",48,WHITE);				//"back"
	printHZ(400, 408,"退出",48,WHITE);				//"quit"
	
	return;
}
