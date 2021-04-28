//管理员登陆后界面

#include"page13.h"

/*
函数名：p13
功能：管理员界面
入口参数：汽车指针pCar
返回值：int类型，返回page的值
*/
int p13(PCAR pCar)
{
    int page = 13;

    #ifdef DEBUGMODE
    pCar->isAdmin = 1;
    #endif

    change_page(page13_screen);

    while(page == 13)
    {
        #ifdef SHOWMOUSE
		showMousePos();
		#endif

        newmouse(&mouseX,&mouseY,&press);

        if(mouse_press(215,152,429,184) == 1)       //行驶记录查询
        {
            page = 9;
        }
        
        if(mouse_press(215,242,429,274) == 1)       //电量记录查询
        {
            page = 17;
        }

        if(mouse_press(390,408,400+48*2*1.1+2,408+48) == 1)			//退出
        {
            page = 3;
        }
			
        if(mouse_press(112,408,122+48*2*1.1+2,408+48) == 1)			//注销
        {
            pCar->loginFlag = 0;
            page = 0;
        }
        

    }

    return page;
}

/*
函数名：page13_screen
功能：绘制管理员界面
入口参数：void
返回值：void
*/
void page13_screen()
{
    //管理员界面
    cleardevice();
	setbkcolor(LIGHTCYAN);
	setcolor(DARKGRAY);
    setlinestyle(SOLID_LINE,0,NORM_WIDTH);

	printHZ_withoutRec(200,20,"管理员界面",48,DARKGRAY);
    printHZ(215,150,"行驶记录查询",32,DARKGRAY);
    printHZ(215,240,"充电记录查询",32,DARKGRAY);
    
    setfillstyle(SOLID_FILL,DARKGRAY);
	bar(112,408,122+48*2*1.1+2,408+48);
	bar(390,408,400+48*2*1.1+2,408+48);
	floodfill(123,409,DARKGRAY); 
	floodfill(401,409,DARKGRAY);
	printHZ(122, 408,"注销",48,WHITE);
	printHZ(400, 408,"退出",48,WHITE);

    return;
}
