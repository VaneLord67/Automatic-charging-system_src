/////////////////
//里程计算界面
////////////////

#include"common.h"
#include"page6.h"

int p6(PCAR pCar)
{
	int page = 6;
	int temperatureTemp = pCar->temperature;
	int electricityTemp = pCar->electricityLeft;
	int mileageTemp = 0;
	int kTemp = 10;
	char electricityStringTemp[5];
	char temperatureStringTemp[5];
	char mileageStringTemp[5];
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
	mileageTemp = (pCar->electricityLeft)*(kTemp+pCar->kEquipment)+(pCar->b);
	//printf("%d\n",pCar->kEquipment);
	itoa(temperatureTemp,temperatureStringTemp,10);
	itoa(electricityTemp,electricityStringTemp,10);
	itoa(mileageTemp,mileageStringTemp,10);
	printText_withoutRec(230,258,temperatureStringTemp,3,DARKGRAY);
	printText_withoutRec(199,155,electricityStringTemp,3,DARKGRAY);
	printText_withoutRec(250,80,mileageStringTemp,3,DARKGRAY);
	
	while(page == 6)
	{
		newmouse(&mouseX,&mouseY,&press);
		showMousePos();
		
		if(electricityTemp != pCar->electricityLeft)
		{
			clrmous(mouseX,mouseY);
			setfillstyle(SOLID_FILL,BLACK);
			setcolor(BLACK);
			bar(174,148,285,191);
			electricityTemp = pCar->electricityLeft;
			itoa(electricityTemp,electricityStringTemp,10);
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
		
		if(mileageTemp !=  (pCar->electricityLeft)*(kTemp+pCar->kEquipment)+(pCar->b))
		{
			clrmous(mouseX,mouseY);
			setfillstyle(SOLID_FILL,BLACK);
			setcolor(BLACK);
			bar(250,80,358,102);
			mileageTemp = (pCar->electricityLeft)*(kTemp+pCar->kEquipment)+(pCar->b);
			// mileageTemp = (pCar->electricityLeft)*(pCar->k)+(pCar->b);
			itoa(mileageTemp,mileageStringTemp,10);
			printText_withoutRec(250,80,mileageStringTemp,3,DARKGRAY);
			save_bk_mou(mouseX,mouseY);
			drawmous(mouseX,mouseY);
		}
		
		if(mouse_press(170,250,212,282) == 1)				//减少车外温度
		{
			if(pCar->temperature >= 10 && pCar->temperature <= 30)
			{
				pCar->temperature = pCar->temperature - 10;
				//pCar->kEquipment -= 1;
				pCar->kEquipment -= 1;
				delay(200);
			}
		}
		
		if(mouse_press(316,250,350,282) == 1)				//增加车外温度
		{
			if(pCar->temperature >= 0 && pCar->temperature < 30)
			{
				pCar->temperature = pCar->temperature + 10;
				pCar->kEquipment += 1;
				delay(200);
			}
		}
		
		if(mouse_press(401,409,508,459) == 1)			//退出
		{
			page = 3;
		}
		
		if(mouse_press(123,409,230,459) == 1)			//返回
		{
			page = 4;
		}
		
		
	}
	
	return page;
}

void page6_screen(void)
{
	cleardevice();
	setbkcolor(WHITE);
	printHZ_withoutRec(180, 10,"里程计算器",48,DARKGRAY);
	printHZ_withoutRec(375, 70,"公里",32,DARKGRAY);
	printHZ_withoutRec(30,150,"剩余电量：",24,DARKGRAY);
	printHZ_withoutRec(30,250,"车外温度：",24,DARKGRAY);
	setcolor(DARKGRAY);
	rectangle(170,250,350,280);
	line(195,259,181,268);
	line(181,268,195,275);
	line(324,259,338,268);
	line(338,268,324,275);
	
	printHZ_withoutRec(285,258,"℃",24,DARKGRAY);
	
	printText_withoutRec(300,155,"KWh",2,DARKGRAY);
	
	printHZ(122, 408,"返回",48,DARKGRAY);
	printHZ(400, 408,"退出",48,DARKGRAY);
	
	return;
}
