////////////////////////
//主函数
////////////////////////

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
	
	#ifdef DEBUGMODE
	page = 0;		
	#endif
	
	while(1)
	{
		switch(page)
		{
			case 0:   //open screen 初始界面
				//每到初始界面就重新生成一辆车，防止两个用户对同一个内存进行操作
				free(pCar);
				PCAR pCar = (PCAR)malloc(sizeof(CAR));
				initCar(pCar);			//初始化汽车参数
				page = p0();
				break;
			case 1:   //register screen 注册界面
				page = p1(pCar);
				break;
			case 2:   //login screen 登录界面
				page = p2(pCar);
				break;
			case 3:  //退出
				if(pCar->loginFlag == 1 && pCar->isAdmin == 0)		//write record if has logined 如果登陆过才写记录
				{
					recordWrite(pCar->id,pCar);
				}
				if(pCar->isAdmin == 0)			//if is common user,write carinfo 用户写文件
				{
					carInfoWrite(pCar);		//write car info into carinfo.txt 将汽车信息写到carinfo.txt中
				}
				free(pCar);				//退出前释放堆内存
				closegraph();
				delay(1000);			//delay防止鼠标出现连点Bug
				exit(0);
			case 4:
				page = p4(pCar);	//show data 数据显示界面
				break;
			case 5:
				page = p5(pCar);		//center control 中控模块
				break;
			case 6:
				page = p6(pCar);		//cal 里程计算器
				break;
			case 8:
				page = p8();			//personal center 个人中心
				break;
			case 9:
				page = p9(pCar);			//driving record query 行驶记录查询
				break;
			case 10:					//charge elec 一键充电界面
				page = p10(pCar);
				break;
			case 11:					//change 一键换电界面
				page = p11(pCar);
				break;
			case 12:					//map 地图移动界面
				page = p12(pCar);
				break;
			case 13:					
				page = p13(pCar);		//admin 管理员界面
				break;
			case 14:
				page = p14(pCar);		//charge money 充值界面
				break;
			case 15:
				page = p15(pCar);		//cal charge money 充电金额计算界面
				break;
			case 16:
				page = p16(pCar);		//cal change money换电金额计算界面
				break;
			case 17:
				page = p17(pCar);       //charge record query 充电记录查询界面 
				break;
			default:
				page = 0;			//default trun to page0 出现其他异常情况退回到初始界面
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
	//读取carinfo.txt中的剩余电量
	//read left elec from carinfo.txt
	FILE * fp = NULL;
	char temp[80] = {'\0'};
	fp = fopen("carinfo.txt","r");
	if ( fp == NULL )
	{
		exitFunc("file carinfo.txt open error!");
	}
	fgets(temp,80,fp);
	pCar->electricityLeft = atof(temp);
	fgets(temp,80,fp);
	pCar->x = atoi(temp);
	fgets(temp,80,fp);
	pCar->y = atoi(temp);

	if(pCar->x == 0 || pCar->y == 0)
	{
		pCar->x = 217;
		pCar->y = 405;
	}

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
	pCar->isAdmin = 0;
	pCar->balance = 0;				
	
	fclose(fp);
}

/*
函数名：carInfoWrite
功能：汽车剩余电量、位置写入文件carinfo.txt
入口参数：汽车结构体指针pCar
返回值：void
*/
void carInfoWrite(PCAR pCar)
{
	FILE * fp = NULL;
	fp = fopen("carinfo.txt","w");
	if ( fp == NULL )
	{
		exitFunc("open carinfo.txt file error!");
	}
	
	fprintf(fp,"%lf\n",pCar->electricityLeft);
	fprintf(fp,"%d\n",pCar->x);
	fprintf(fp,"%d\n",pCar->y);
	
	fclose(fp);
	return;
}

