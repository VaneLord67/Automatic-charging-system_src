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
int press;
int flag=0;
//定义一些全局变量便于音乐播放使用
int playIndex=0;
int isPlaySound=0;
clock_t start = 0;
clock_t end = 0;
double total = 0;

int main(void)
{
	int graphDriver = VGA;
	int graphMode = VGAHI;
	int page = 0;
	initgraph(&graphDriver,&graphMode,"C:\\BORLANDC\\BGI");
	initMouse();
	delay(1000);
	
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
				nosound();
				closegraph();
				exit(0);
			case 4:
				page = p4();
				break;
			case 5:
				page = p5();
				break;
			default:
				page = 0;			//出现其他异常情况退回到初始界面
				break;
			
		}
	}
	
}
