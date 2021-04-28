#ifndef _MAP_H_
#define _MAP_H_

#include"myf.h"

#define MAXVEX 15			//最多的结点数
#define GRAPH_INFINITY 65535		//邻接矩阵INFINITY值
#define CAR_SIZE 5					//汽车图像的大小
#define delta 10		//汽车距离变化一次移动dx
#define SLOW_DELTA 1	//斜率大时汽车移动变化dx
#define ROUND_RADIUS 10		//地图结点的半径
#define DISTANCE_RATIO 60 //地图结点距离与真实距离之间的缩放倍率 60为缩小到六十分之一
#define STATION_NAME_OFFSET 50

typedef int Patharc[MAXVEX];//用于存储最短路径下标的数组
typedef double ShortPathTable[MAXVEX]; //用于存储到各点最短路径的权值和

typedef struct mapNode
{
	int x;			//地图结点的坐标x,y
	int y;
	int chargeFlag;	//电桩标志位，0非电桩，1充电桩，2换电桩
}MAPNODE,*PMAPNODE;

typedef struct
{
	MAPNODE vexs[MAXVEX];
	double arc[MAXVEX][MAXVEX];
	int numVertexes, numEdges;
}MGraph;

/*
函数名：page12_screen
功能：地图界面绘制
入口参数：void
返回值：void
*/
void page12_screen(void);

///////////////////////////////////
//函数名：p12
//功能：地图移动界面控制功能函数
//入口参数：汽车指针pCar
//返回值：page的值
///////////////////////////////////
int p12(PCAR pCar);

///////////////////////////////////
//函数名：createMGraphFromFile
//功能：从文件中创建图
//入口参数：图的地址
//返回值：void
///////////////////////////////////
void createMGraphFromFile(MGraph * G);

///////////////////////////////////
//函数名：ShortestPath_Dijkstra
//功能：迪杰斯特拉算法
//入口参数：图的地址，起始端点，路径，最短路径长度
//返回值：void
///////////////////////////////////
void ShortestPath_Dijkstra(MGraph G, int v0, Patharc* p, ShortPathTable* D);

///////////////////////////////////
//函数名：findWay
//功能：找到起点到终点的路径
//入口参数：起点，终点，路径，路径数组长度
//返回值：指向路径的指针
///////////////////////////////////
int * findWay(int dest, Patharc* p,int * wayLength,MGraph * G);

///////////////////////////////////
//函数名：drawMap
//功能：绘制地图结点
//入口参数：图的地址
//返回值：void
///////////////////////////////////
void drawMap(MGraph* G);

///////////////////////////////////
//函数名：drawMapLine
//功能：绘制地图的背景线
//入口参数：void
//返回值：void
///////////////////////////////////
// void drawMapLine(void);

///////////////////////////////////
//函数名：drawMapCar
//功能：绘制汽车
//入口参数：汽车指针pCar
//返回值：void
///////////////////////////////////
void drawMapCar(PCAR pCar);

///////////////////////////////////
//函数名：drawNodeLine
//功能：绘制地图结点之间的边
//入口参数：图的地址
//返回值：void
///////////////////////////////////
void drawNodeLine(MGraph * G);

///////////////////////////////////
//函数名：apartSpaceRead
//功能：将输入的字符串source中的数据提取出来写入x和y
//入口参数：字符串source，x,y的地址
//返回值：void
///////////////////////////////////
void apartSpaceRead(char * source,int * x,int * y);

///////////////////////////////////
//函数名：apartSpaceReadNode
//功能：将输入的字符串source中的数据提取出来写入x和y,flag
//入口参数：字符串source，x,y,flag的地址
//返回值：void
///////////////////////////////////
void apartSpaceReadNode(char * source,int * x,int * y,int * flag);

///////////////////////////////////
//函数名：isPressPosInVex
//功能：判断鼠标点击位置是否为地图结点
//入口参数：地图结点数组
//返回值：1为真，0为假
///////////////////////////////////
int isPressPosInVex(MAPNODE m);

///////////////////////////////////
//函数名：mallocBuf
//功能：给buf分配空间，若出错则输出错误信息
//入口参数：图像位置x1,y1,x2,y2，指针buf的地址
//返回值：void
///////////////////////////////////
void mallocBuf(int x1,int y1,int x2,int y2,void ** buf);

///////////////////////////////////
//函数名：changeCarPos
//功能：更改汽车位置
//入口参数：汽车位置地址，目标地点temp
//返回值：void
///////////////////////////////////
void changeCarPos(int * pos,int temp);

///////////////////////////////////
//函数名：changeCarPosSlow
//功能：缓慢更改汽车位置
//入口参数：汽车位置地址，目标地点temp
//返回值：void
///////////////////////////////////
void changeCarPosSlow(int * pos,int temp);

///////////////////////////////////
//函数名：getCarInWhichVex
//功能：获取汽车在哪个地图结点中
//入口参数：汽车指针，图的地址
//返回值：汽车所在地图结点下标
///////////////////////////////////
int getCarInWhichVex(PCAR pCar,MGraph * G);

/*
函数名：lightChargeButton
功能：点亮充电按钮
入口参数：void
返回值：void
*/
void lightChargeButton(void);

/*
函数名：lightChargeFullButton
功能：点亮换电按钮
入口参数：void
返回值：void
*/
void lightChargeFullButton(void);

/*
函数名：lightOffChargeButton
功能：熄灭充电按钮
入口参数：void
返回值：void
*/
void lightOffChargeButton(void);

/*
函数名：lightOffChargeFullButton
功能：熄灭换电按钮
入口参数：void
返回值：void
*/
void lightOffChargeFullButton(void);

/*
函数名：testCarPos
功能：查看汽车坐标是否为正常值，如果不正常则恢复到默认状态
入口参数：汽车指针pCar
返回值：void
*/
void testCarPos(PCAR pCar);

/*
函数名：showStationDesc
功能：显示站点信息
入口参数：信息弹窗标志变量地址，信息弹窗指针地址，汽车指针，图的地址
返回值：点击的地图结点下标
*/
int showStationDesc(int * descPopWindow,void ** descBuf,PCAR pcar,MGraph * G);

/*
函数名：carMoveAfterClick
功能：点击后让车辆移动
入口参数：汽车指针，图的地址，x和y的地址，汽车图像buf指针的地址，索引idx
返回值：void
*/
void carMoveAfterClick(PCAR pCar, MGraph * G, int * xTemp, int * yTemp, void ** buf, int idx);

/*
函数名：showStationName
功能：显示站点名称
入口参数：图的地址
返回值：void
*/
void showStationName(MGraph * G);

#endif