/////////////////
//换电金额计算界面
////////////////
//change money cal
#include"page16.h"
#include"page14.h"

/*
函数名：p16
功能：换电金额计算界面
入口参数：汽车指针pCar
返回值：int类型，返回page的值
*/
int p16(PCAR pCar)
{
    #ifdef DEBUGMODE
    //pCar->electricityLeft = 50;
    #endif

	int page = 16;

    double electricityTemp = pCar->electricityLeft;
    char electricityStringTemp[20] = {'\0'};

    int isPopWindow = 0;
    void *buf = NULL;

    char calMoneyString[50] = {'\0'};

    double calMoney = (MAX_ELECTRICITY-pCar->electricityLeft) * PRICE_PER_KWH;

	change_page(page16_screen);

    sprintf(electricityStringTemp,"%.1lf",electricityTemp);
    printText_withoutRec(132,155,electricityStringTemp,3,DARKGRAY);

    sprintf(calMoneyString,"%.2f",calMoney);
    printText_withoutRec(132,325,calMoneyString,3,DARKGRAY);
	
	while(page == 16)
	{
        newmouse(&mouseX,&mouseY,&press);
        #ifdef SHOWMOUSE
        showMousePos();
        #endif

        if(0 == isPopWindow)
        {
            if(mouse_press(401,409,508,459) == 1)			//取消 (no)
            {
                page = 4;
            }
            if(mouse_press(123,409,230,459) == 1)			//确定 (yes)
            {
                if(pCar->balance < calMoney)
                {
                    popWindow_withoutFlush(&buf,&isPopWindow,"余额不足"); //no money
                    continue;
                }
                pCar->balance -= calMoney;
                updateBalance(pCar);
                page = 11;          //转到换电界面 (turn to elec-change page)
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
函数名：page16_screen
功能：绘制换电金额计算界面
入口参数：void
返回值：void
*/
void page16_screen(void)
{
    char maxElecString[50] = {'\0'};
    sprintf(maxElecString,"%.0f",MAX_ELECTRICITY);
    
	cleardevice();
	setbkcolor(LIGHTCYAN);
	printHZ_withoutRec(200,20,"换电金额",48,DARKGRAY);
	printHZ_withoutRec(122,100,"当前电量",32,DARKGRAY);
	printHZ_withoutRec(122,100+90,"目标电量",32,DARKGRAY);
	printHZ_withoutRec(122,100+90+90,"预计花费",32,DARKGRAY);

    printText_withoutRec(341,155,"kWh",3,DARKGRAY);
    printText_withoutRec(341,240,"kWh",3,DARKGRAY);

    printText_withoutRec(132,240,maxElecString,3,DARKGRAY);

	printHZ_withoutRec(341,318,"元",32,DARKGRAY);

    setlinestyle(SOLID_LINE,0,NORM_WIDTH);

	setfillstyle(SOLID_FILL,DARKGRAY);
	bar(112,408,122+48*2*1.1+2,408+48);
	bar(390,408,400+48*2*1.1+2,408+48);
	floodfill(123,409,DARKGRAY); 
	floodfill(401,409,DARKGRAY);
	printHZ(122, 408,"确定",48,WHITE);
	printHZ(400, 408,"取消",48,WHITE);
	return;
}
