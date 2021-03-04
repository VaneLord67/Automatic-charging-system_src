////////////////////////
//主函数
////////////////////////
#include"common.h"
#include"main.h"

//定义一些全局变量便于鼠标使用
void *buffer;
union REGS regs;

int mouseX;
int mouseY;
int press=0;
int flag=0;

int main(void)
{
	int graphDriver = VGA;
	int graphMode = VGAHI;
	int page = 0;
	initgraph(&graphDriver,&graphMode,"C:\\BORLANDC\\BGI");
	initMouse();
	delay(1000);
	//给一个汽车分配内存空间并初始化各个值，整个程序仅存在一辆汽车
	PCAR pCar = (PCAR)malloc(sizeof(CAR));
	pCar->electricityLeft = 100;	//剩余电量
	pCar->airConditioningFlag = 0; //空调状态
	pCar->lightFlag = 0;			//车灯状态
	pCar->windowFlag = 0;			//车窗状态
	pCar->musicFlag = 0; 			//音乐播放器状态
	pCar->runState = 0;			//行驶状态（熄火0、行驶1、制动2）
	
	
	page = 5;
	
	while(1)
	{
		switch(page)
		{
			case 0:   //初始界面
				page = p0();
				break;
			case 1:   //注册界面
				page = p1();
				break;
			case 2:   //登录界面
				page = p2();
				break;
			case 3:  //退出
				free(pCar);
				closegraph();
				delay(1000);
				exit(0);
			case 4:
				page = p4();
				break;
			case 5:
				page = p5(pCar);
				break;
			default:
				page = 0;			//出现其他异常情况退回到初始界面
				break;
			
		}
	}
	
}
