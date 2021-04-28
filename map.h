#ifndef _MAP_H_
#define _MAP_H_

#include"myf.h"

#define MAXVEX 15			//���Ľ����
#define GRAPH_INFINITY 65535		//�ڽӾ���INFINITYֵ
#define CAR_SIZE 5					//����ͼ��Ĵ�С
#define delta 10		//��������仯һ���ƶ�dx
#define SLOW_DELTA 1	//б�ʴ�ʱ�����ƶ��仯dx
#define ROUND_RADIUS 10		//��ͼ���İ뾶
#define DISTANCE_RATIO 60 //��ͼ����������ʵ����֮������ű��� 60Ϊ��С����ʮ��֮һ
#define STATION_NAME_OFFSET 50

typedef int Patharc[MAXVEX];//���ڴ洢���·���±������
typedef double ShortPathTable[MAXVEX]; //���ڴ洢���������·����Ȩֵ��

typedef struct mapNode
{
	int x;			//��ͼ��������x,y
	int y;
	int chargeFlag;	//��׮��־λ��0�ǵ�׮��1���׮��2����׮
}MAPNODE,*PMAPNODE;

typedef struct
{
	MAPNODE vexs[MAXVEX];
	double arc[MAXVEX][MAXVEX];
	int numVertexes, numEdges;
}MGraph;

/*
��������page12_screen
���ܣ���ͼ�������
��ڲ�����void
����ֵ��void
*/
void page12_screen(void);

///////////////////////////////////
//��������p12
//���ܣ���ͼ�ƶ�������ƹ��ܺ���
//��ڲ���������ָ��pCar
//����ֵ��page��ֵ
///////////////////////////////////
int p12(PCAR pCar);

///////////////////////////////////
//��������createMGraphFromFile
//���ܣ����ļ��д���ͼ
//��ڲ�����ͼ�ĵ�ַ
//����ֵ��void
///////////////////////////////////
void createMGraphFromFile(MGraph * G);

///////////////////////////////////
//��������ShortestPath_Dijkstra
//���ܣ��Ͻ�˹�����㷨
//��ڲ�����ͼ�ĵ�ַ����ʼ�˵㣬·�������·������
//����ֵ��void
///////////////////////////////////
void ShortestPath_Dijkstra(MGraph G, int v0, Patharc* p, ShortPathTable* D);

///////////////////////////////////
//��������findWay
//���ܣ��ҵ���㵽�յ��·��
//��ڲ�������㣬�յ㣬·����·�����鳤��
//����ֵ��ָ��·����ָ��
///////////////////////////////////
int * findWay(int dest, Patharc* p,int * wayLength,MGraph * G);

///////////////////////////////////
//��������drawMap
//���ܣ����Ƶ�ͼ���
//��ڲ�����ͼ�ĵ�ַ
//����ֵ��void
///////////////////////////////////
void drawMap(MGraph* G);

///////////////////////////////////
//��������drawMapLine
//���ܣ����Ƶ�ͼ�ı�����
//��ڲ�����void
//����ֵ��void
///////////////////////////////////
// void drawMapLine(void);

///////////////////////////////////
//��������drawMapCar
//���ܣ���������
//��ڲ���������ָ��pCar
//����ֵ��void
///////////////////////////////////
void drawMapCar(PCAR pCar);

///////////////////////////////////
//��������drawNodeLine
//���ܣ����Ƶ�ͼ���֮��ı�
//��ڲ�����ͼ�ĵ�ַ
//����ֵ��void
///////////////////////////////////
void drawNodeLine(MGraph * G);

///////////////////////////////////
//��������apartSpaceRead
//���ܣ���������ַ���source�е�������ȡ����д��x��y
//��ڲ������ַ���source��x,y�ĵ�ַ
//����ֵ��void
///////////////////////////////////
void apartSpaceRead(char * source,int * x,int * y);

///////////////////////////////////
//��������apartSpaceReadNode
//���ܣ���������ַ���source�е�������ȡ����д��x��y,flag
//��ڲ������ַ���source��x,y,flag�ĵ�ַ
//����ֵ��void
///////////////////////////////////
void apartSpaceReadNode(char * source,int * x,int * y,int * flag);

///////////////////////////////////
//��������isPressPosInVex
//���ܣ��ж������λ���Ƿ�Ϊ��ͼ���
//��ڲ�������ͼ�������
//����ֵ��1Ϊ�棬0Ϊ��
///////////////////////////////////
int isPressPosInVex(MAPNODE m);

///////////////////////////////////
//��������mallocBuf
//���ܣ���buf����ռ䣬�����������������Ϣ
//��ڲ�����ͼ��λ��x1,y1,x2,y2��ָ��buf�ĵ�ַ
//����ֵ��void
///////////////////////////////////
void mallocBuf(int x1,int y1,int x2,int y2,void ** buf);

///////////////////////////////////
//��������changeCarPos
//���ܣ���������λ��
//��ڲ���������λ�õ�ַ��Ŀ��ص�temp
//����ֵ��void
///////////////////////////////////
void changeCarPos(int * pos,int temp);

///////////////////////////////////
//��������changeCarPosSlow
//���ܣ�������������λ��
//��ڲ���������λ�õ�ַ��Ŀ��ص�temp
//����ֵ��void
///////////////////////////////////
void changeCarPosSlow(int * pos,int temp);

///////////////////////////////////
//��������getCarInWhichVex
//���ܣ���ȡ�������ĸ���ͼ�����
//��ڲ���������ָ�룬ͼ�ĵ�ַ
//����ֵ���������ڵ�ͼ����±�
///////////////////////////////////
int getCarInWhichVex(PCAR pCar,MGraph * G);

/*
��������lightChargeButton
���ܣ�������簴ť
��ڲ�����void
����ֵ��void
*/
void lightChargeButton(void);

/*
��������lightChargeFullButton
���ܣ��������簴ť
��ڲ�����void
����ֵ��void
*/
void lightChargeFullButton(void);

/*
��������lightOffChargeButton
���ܣ�Ϩ���簴ť
��ڲ�����void
����ֵ��void
*/
void lightOffChargeButton(void);

/*
��������lightOffChargeFullButton
���ܣ�Ϩ�𻻵簴ť
��ڲ�����void
����ֵ��void
*/
void lightOffChargeFullButton(void);

/*
��������testCarPos
���ܣ��鿴���������Ƿ�Ϊ����ֵ�������������ָ���Ĭ��״̬
��ڲ���������ָ��pCar
����ֵ��void
*/
void testCarPos(PCAR pCar);

/*
��������showStationDesc
���ܣ���ʾվ����Ϣ
��ڲ�������Ϣ������־������ַ����Ϣ����ָ���ַ������ָ�룬ͼ�ĵ�ַ
����ֵ������ĵ�ͼ����±�
*/
int showStationDesc(int * descPopWindow,void ** descBuf,PCAR pcar,MGraph * G);

/*
��������carMoveAfterClick
���ܣ�������ó����ƶ�
��ڲ���������ָ�룬ͼ�ĵ�ַ��x��y�ĵ�ַ������ͼ��bufָ��ĵ�ַ������idx
����ֵ��void
*/
void carMoveAfterClick(PCAR pCar, MGraph * G, int * xTemp, int * yTemp, void ** buf, int idx);

/*
��������showStationName
���ܣ���ʾվ������
��ڲ�����ͼ�ĵ�ַ
����ֵ��void
*/
void showStationName(MGraph * G);

#endif