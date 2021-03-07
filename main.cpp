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
	delay(200);
	//给一个汽车分配内存空间并初始化各个值，整个工程仅存在这一辆汽车
	PCAR pCar = (PCAR)malloc(sizeof(CAR));
	initCar(pCar);			//初始化汽车参数
	
	page = 0;
	
	while(1)
	{
		switch(page)
		{
			case 0:   //初始界面
				//每到初始界面就重新生成一辆车，防止两个用户对同一个内存进行操作
				free(pCar);
				PCAR pCar = (PCAR)malloc(sizeof(CAR));
				initCar(pCar);			//初始化汽车参数
				//recordOut();
				page = p0();
				break;
			case 1:   //注册界面
				page = p1();
				break;
			case 2:   //登录界面
				page = p2(pCar);
				break;
			case 3:  //退出
				if(pCar->loginFlag == 1)		//如果登陆过才写记录
				{
					recordWrite(pCar->id,pCar);
				}
				electricityWrite(pCar);		//写剩余电量到文件energy.txt中
				free(pCar);				//退出前释放堆内存
				closegraph();
				delay(1000);			//delay防止鼠标出现连点Bug
				exit(0);
			case 4:
				page = p4(pCar);	//数据显示界面
				break;
			case 5:
				page = p5(pCar);		//中控模块
				break;
			case 6:
				page = p6(pCar);		//里程计算器
				break;
			case 7:
				page = p7(pCar);		//电量模块
				break;
			case 8:
				page = p8();			//个人中心（有行驶记录查询功能）
				break;
			case 9:
				page = p9();			//行驶记录查询
				break;
			case 10:					//一键充电界面
				page = p10(pCar);
				break;
			case 11:
				page = p11(pCar);
				break;
			default:
				page = 0;			//出现其他异常情况退回到初始界面
				break;
			
		}
	}
	
}

/*
函数名：initCar
功能：初始化汽车参数
入口参数：汽车结构体指针pCar
返回值：void
*/
void initCar(PCAR pCar)
{
	//读取energy.txt中的剩余电量
	FILE * fp = NULL;
	char temp[80] = {'\0'};
	fp = fopen("energy.txt","r");
	if ( fp == NULL )
	{
		settextjustify(LEFT_TEXT,TOP_TEXT);          //左部对齐，顶部对齐
		settextstyle(GOTHIC_FONT,HORIZ_DIR,1);					//黑体笔划输出，水平输出，24*24点阵
		outtextxy(10,10,"Can't open file!Press any key to quit...");
		getch();
		exit(1);
	}
	fgets(temp,80,fp);
	pCar->electricityLeft = atoi(temp);
	//fscanf(fp,"%d",pCar->electricityLeft);
	//pCar->electricityLeft = 70;	//剩余电量(现改为从文件energy.txt中读)
	pCar->hasMileage = 0;			//行驶里程
	pCar->airConditioningFlag = 0; //空调状态
	pCar->lightFlag = 0;			//车灯状态
	pCar->windowFlag = 0;			//车窗状态
	pCar->musicFlag = 0; 			//音乐播放器状态
	pCar->runState = 0;			//行驶状态（熄火0、行驶1、制动2）
	pCar->temperature = 30;			//车外温度初始化为30度
	pCar->speed = 60;				//汽车速度初始化为60km/h
	pCar->k = 0;					//数学模型K值初始化为0
	pCar->kEquipment = 0;			//数学模型有关设备的k值初始化为0
	pCar->b = 0;				//数学模型b值初始化为0 
	pCar->loginFlag = 0;			//登陆状态初始化为0
	pCar->start = 0;
	// pCar->temp = 0;
}

/*
函数名：electricityWrite
功能：剩余电量写入文件energy.txt
入口参数：汽车结构体指针pCar
返回值：void
*/
void electricityWrite(PCAR pCar)
{
	FILE * fp = NULL;
	fp = fopen("energy.txt","w");
	if ( fp == NULL )
	{
		settextjustify(LEFT_TEXT,TOP_TEXT);          //左部对齐，顶部对齐
		settextstyle(GOTHIC_FONT,HORIZ_DIR,1);					//黑体笔划输出，水平输出，24*24点阵
		outtextxy(10,10,"Can't open file!Press any key to quit...");
		getch();
		exit(1);
	}
	
	fprintf(fp,"%d",pCar->electricityLeft);
	
	fclose(fp);
	return;
}

