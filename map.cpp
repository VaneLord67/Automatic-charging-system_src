//page12 地图界面

#include"map.h"

/*
函数名：p12
功能：地图移动界面控制功能函数
入口参数：汽车指针pCar
返回值：page的值
*/
int p12(PCAR pCar)
{
	#ifdef DEBUGMODE
	//pCar->electricityLeft = 70;
	#endif

	// int xCurrentCenter = 240;
	// int yCurrentCenter = 240;
	
	int page = 12;
	MGraph G;
	int xTemp;
	int yTemp;
	void * buf = NULL;
	void * popWindowBuf = NULL;
	void * descBuf = NULL;
	int descPopWindow = 0;
	int isPopWindow = 0;
	int hasWarning = 0;
	int idx = -1;
	// int num = 0;

	createMGraphFromFile(&G);

	clrmous(mouseX,mouseY);
	page12_screen();
	drawMap(&G);
	drawNodeLine(&G);
	showStationName(&G);
	
	mallocBuf(pCar->x - CAR_SIZE,pCar->y - CAR_SIZE,pCar->x + CAR_SIZE,pCar->y + CAR_SIZE,&buf);
	drawMapCar(pCar);

	
	save_bk_mou(mouseX,mouseY);
	drawmous(mouseX,mouseY);
	
	while(page == 12)
	{
		#ifdef SHOWMOUSE
		//showMousePos();
		#endif
		newmouse(&mouseX,&mouseY,&press);
		
		
		if(0 == isPopWindow)
		{
			if(descPopWindow == 0)
			{
				idx = showStationDesc(&descPopWindow,&descBuf,pCar,&G);
			}
			else if(descPopWindow == 1)
			{
				if(mouse_press(215,120,325,165) == 1)		//press goto here button //点击到此处按钮.
				{
					descPopWindow = 0;
					clrmous(mouseX,mouseY);
					putimage(0,0,descBuf,COPY_PUT);
					save_bk_mou(mouseX,mouseY);
					drawmous(mouseX,mouseY);
					free(descBuf);
					descBuf = NULL;
					carMoveAfterClick(pCar,&G,&xTemp,&yTemp,&buf,idx);
				}
				else if(mouse_press(2,120,67,166) == 1)
				{
					descPopWindow = 0;
					clrmous(mouseX,mouseY);
					putimage(0,0,descBuf,COPY_PUT);
					free(descBuf);
					descBuf = NULL;
					save_bk_mou(mouseX,mouseY);
					drawmous(mouseX,mouseY);
				}
			}

			if(G.vexs[getCarInWhichVex(pCar,&G)].chargeFlag == 1)
			{
				lightChargeButton();
				lightOffChargeFullButton();
			}
			else if(G.vexs[getCarInWhichVex(pCar,&G)].chargeFlag == 2)
			{
				lightChargeFullButton();
				lightOffChargeButton();
			}
			else
			{
				lightOffChargeButton();
				lightOffChargeFullButton();
			}
			
			if(mouse_press(506,422,611,465) == 1)		//点击返回按钮
			{
				if(buf != NULL)
				{
					free(buf);						//释放图像内存
				}
				page = 4;
				pCar->k = 20;
				pCar->runState = 2;			
				pCar->speed = 0;
			}
			if(mouse_press(506,222,612,270) == 1 && G.vexs[getCarInWhichVex(pCar,&G)].chargeFlag == 1)		//点击充电
			{
				if(pCar->electricityLeft == MAX_ELECTRICITY)
				{
					popWindow_withoutFlush(&popWindowBuf,&isPopWindow,"电量已满");
					continue;
				}
				pCar->runState = 0;
				page = 15;
			}
			if(mouse_press(506,322,614,371) == 1 && G.vexs[getCarInWhichVex(pCar,&G)].chargeFlag == 2)		//点击换电
			{
				if(pCar->electricityLeft == MAX_ELECTRICITY)
				{
					popWindow_withoutFlush(&popWindowBuf,&isPopWindow,"电量已满");
					continue;
				}
				pCar->runState = 0;
				page = 16;
			}
			if(pCar->electricityLeft < WARNING_ELECTRICITY && hasWarning == 0)
			{
				popWindow_withoutFlush(&popWindowBuf,&isPopWindow,"电量告急");
				hasWarning = 1;
			}
			/*
			if(mouse_press(506,222,612,270) == 2 && G.vexs[getCarInWhichVex(pCar,&G)].chargeFlag == 1);
			{
					if(num = 0);
					{
						button(506,222,612,270,DARKGRAY,DARKGRAY);
						printHZ(506,222,"充电",48,WHITE);
						num = 1;
					}
					continue;
			}
			if(mouse_press(506,322,614,371) == 1 && G.vexs[getCarInWhichVex(pCar,&G)].chargeFlag == 2);
			{
					if(num = 0);
					{
						button(506,322,614,371,DARKGRAY,DARKGRAY);
						printHZ(506,322,"换电",48,WHITE);
						num = 2;
					}
					continue;
			}
			if(num != 0);
			{
				switch(num)
				{
					case 1:
						button(506,222,612,270,DARKGRAY,LIGHTCYAN);
						printHZ(506,222,"充电",48,DARKGRAY);
						break;
					case 2:
						button(506,322,614,371,DARKGRAY,LIGHTCYAN);
						printHZ(506,322,"换电",48,DARKGRAY);
						break;
				}
				num = 0;
			}*/
		}
		else
		{
			popWindow_withoutFlush(&popWindowBuf,&isPopWindow,"");
		}
	}
	if(descBuf != NULL)
	{
		free(descBuf);
		descBuf = NULL;
	}

	return page;
}

///////////////////////////////////
//函数名：ShortestPath_Dijkstra
//功能：迪杰斯特拉算法
//入口参数：图的地址，起始端点，路径，最短路径长度
//返回值：void
///////////////////////////////////
void ShortestPath_Dijkstra(MGraph G, int v0, Patharc* P, ShortPathTable* D)
{
	int v, w, k;
	double min;
	int final[MAXVEX];
	for (v = 0; v < G.numVertexes; v++)
	{
		final[v] = 0;
		(*D)[v] = G.arc[v0][v];
		(*P)[v] = 0;
	}
	(*D)[v0] = 0;
	final[v0] = 1;

	for (v = 1; v < G.numVertexes; v++)
	{
		min = GRAPH_INFINITY;
		for (w = 0; w < G.numVertexes; w++)
		{
			if (!final[w] && (*D)[w] < min )
			{
				k = w;
				min = (*D)[w];
			}
		}
		final[k] = 1;
		for (w = 0; w < G.numVertexes; w++)
		{
			if (!final[w] && (min + G.arc[k][w] < (*D)[w]))
			{
				(*D)[w] = min + G.arc[k][w];
				(*P)[w] = k;
			}
		}
	}
	return;
}

///////////////////////////////////
//函数名：createMGraphFromFile
//功能：从文件中创建图
//入口参数：图的地址
//返回值：void
///////////////////////////////////
void createMGraphFromFile(MGraph * G)
{
	int i, j, k;
	double i_x,i_y,j_x,j_y;
	double w;
	FILE * fp = NULL;
	char temp[20] = {'\0'};
	fp = fopen("map.txt","r");
	if(fp == NULL)
	{
		//settextjustify(LEFT_TEXT,TOP_TEXT);          //左部对齐，顶部对齐
		//settextstyle(GOTHIC_FONT,HORIZ_DIR,1);					//黑体笔划输出，水平输出，24*24点阵
		//outtextxy(10,10,"Can't open file!Press any key to quit...");
		//getch();
		exit(1);
	}
	fgets(temp,20,fp);
	apartSpaceRead(temp,&G->numVertexes,&G->numEdges);
	for (i = 0; i < G->numVertexes; i++)
	{
		for (j = 0; j < G->numVertexes; j++)
		{
			G->arc[i][j] = GRAPH_INFINITY;
		}
	}
	for (i =0; i < G->numVertexes; i++)
	{
		fgets(temp,20,fp);
		apartSpaceReadNode(temp,&G->vexs[i].x,&G->vexs[i].y,&G->vexs[i].chargeFlag);
	}
	for (k = 0; k < G->numEdges; k++)
	{
		fgets(temp,20,fp);
		apartSpaceRead(temp,&i,&j);
		i_x = (double)G->vexs[i].x;
		i_y = (double)G->vexs[i].y;
		j_x = (double)G->vexs[j].x;
		j_y = (double)G->vexs[j].y;
		w = sqrt(pow(i_x - j_x, 2) + pow(i_y - j_y, 2));
		//w = sqrt((G->vexs[i].x - G->vexs[j].x) * (G->vexs[i].x - G->vexs[j].x) + (G->vexs[i].y - G->vexs[j].y) * (G->vexs[i].y - G->vexs[j].y) );
		G->arc[i][j] = w;
		G->arc[j][i] = G->arc[i][j];
	}
	fclose(fp);
	return;
}

///////////////////////////////////
//函数名：findWay
//功能：找到起点到终点的路径
//入口参数：终点，路径，路径数组长度
//返回值：指向路径的指针
///////////////////////////////////
int * findWay(int dest, Patharc* p,int * wayLength,MGraph *G)
{
	int i,j;
	j = 1;
	int * way = (int*)malloc(G->numVertexes * sizeof(int));
	
	if (way == NULL)
	{
		fprintf(stderr, "malloc error!\n");
		exit(EXIT_FAILURE);
	}

	for(i=0;i<G->numVertexes;i++)
	{
		way[i] = -1;
	}
	way[0] = dest;
	i = dest;
	i = (*p)[i];
	while(i != 0)
	{
		way[j] = i;
		j++;
		i = (*p)[i];
	}
	*wayLength = j;
	j--;
	
	int* reverseWay = (int*)malloc((*wayLength) * sizeof(int));
	
	for(i=0;j>=0;i++,j--)
	{
		reverseWay[i] = way[j];
	}
	
	free(way);
	return reverseWay;
}

///////////////////////////////////
//函数名：apartSpaceRead
//功能：将输入的字符串source中的数据提取出来写入x和y
//入口参数：字符串source，x,y的地址
//返回值：void
///////////////////////////////////
void apartSpaceRead(char * source,int * x,int * y)
{
	char * p = NULL;
	char * q = NULL;
	p = source;

	while( (*p) != '\0')
	{
		if((*p) == ' ')
		{
			(*p) = '\0';
			p++;
			break;
		}
		else
		{
			p++;
		}
	}
	q = p;
	while ((*q) != '\0')
	{
		if ((*q) == '\n')
		{
			*q = '\0';
			break;
		}
		else
		{
			q++;
		}
	}
	*x = atoi(source);
	*y = atoi(p);
}

///////////////////////////////////
//函数名：apartSpaceReadNode
//功能：将输入的字符串source中的数据提取出来写入x和y,flag
//入口参数：字符串source，x,y,flag的地址
//返回值：void
///////////////////////////////////
void apartSpaceReadNode(char * source,int * x,int * y,int * flag)
{
	char * p = NULL;
	char * q = NULL;
	char * r = NULL;
	p = source;
	while( (*p) != '\0')
	{
		if((*p) == ' ')
		{
			(*p) = '\0';
			p++;
			break;
		}
		else
		{
			p++;
		}
	}
	q = p;
	while ((*q) != '\0')
	{
		if ((*q) == ' ')
		{
			*q = '\0';
			q++;
			break;
		}
		else
		{
			q++;
		}
	}
	r = q;
	while ((*r) != '\0')
	{
		if ((*r) == '\n')
		{
			*r = '\0';
			break;
		}
		else
		{
			r++;
		}
	}
	*x = atoi(source);
	*y = atoi(p);
	*flag = atoi(q);
}

///////////////////////////////////
//函数名：drawMap
//功能：绘制地图结点
//入口参数：图的地址
//返回值：void
///////////////////////////////////
void drawMap(MGraph* G)
{
	int i = 0;
	//drawMapLine();
	for(i = 0;i < G->numVertexes;i++)
	{
		if(G->vexs[i].chargeFlag == 0)
		{
			setfillstyle(SOLID_FILL,DARKGRAY);
		}
		else if(G->vexs[i].chargeFlag == 1)
		{
			setfillstyle(SOLID_FILL,RED);
		}
		else if(G->vexs[i].chargeFlag == 2)
		{
			setfillstyle(SOLID_FILL,BLUE);
		}
		pieslice(G->vexs[i].x,G->vexs[i].y,1,360,ROUND_RADIUS);
	}
	setfillstyle(SOLID_FILL,DARKGRAY);
	return;
}

///////////////////////////////////
//函数名：drawMapLine
//功能：绘制地图的背景线
//入口参数：void
//返回值：void
///////////////////////////////////
// void drawMapLine(void)
// {
// 	//横三条线
// 	line(0,120,480,120);
// 	line(0,240,480,240);
// 	line(0,360,480,360);
// 	//竖三条线
// 	line(120,0,120,480);
// 	line(240,0,240,480);
// 	line(360,0,360,480);
// 	return;
// }

///////////////////////////////////
//函数名：drawMapCar
//功能：绘制汽车
//入口参数：汽车指针pCar
//返回值：void
///////////////////////////////////
void drawMapCar(PCAR pCar)
{
	setfillstyle(SOLID_FILL,GREEN);
	barRecWithCenter(pCar->x,pCar->y,CAR_SIZE);
	setfillstyle(SOLID_FILL,BLACK);
	return;
}

///////////////////////////////////
//函数名：drawNodeLine
//功能：绘制地图结点之间的边
//入口参数：图的地址
//返回值：void
///////////////////////////////////
void drawNodeLine(MGraph * G)
{
	int i,j;
	for(i=0;i<G->numVertexes;i++)
	{
		for(j=0;j<G->numVertexes;j++)
		{
			//double类型值做比较不能用==和!=
			if(fabs(G->arc[i][j] - GRAPH_INFINITY) > 1)
			{
				setcolor(YELLOW);
				setlinestyle(SOLID_LINE,0,THICK_WIDTH);
				// line(G->vexs[i].x-ROUND_RADIUS,G->vexs[i].y-ROUND_RADIUS,G->vexs[j].x+ROUND_RADIUS,G->vexs[j].y-ROUND_RADIUS);
				// line(G->vexs[i].x-ROUND_RADIUS,G->vexs[i].y+ROUND_RADIUS,G->vexs[j].x+ROUND_RADIUS,G->vexs[j].y+ROUND_RADIUS);
				line(G->vexs[i].x,G->vexs[i].y,G->vexs[j].x,G->vexs[j].y);
				setlinestyle(SOLID_LINE,0,NORM_WIDTH);
			}
		}
	}
	return;
}

/*
函数名：carMoveAfterClick
功能：点击后让车辆移动
入口参数：汽车指针，图的地址，x和y的地址，汽车图像buf指针的地址，索引idx
返回值：void
*/
void carMoveAfterClick(PCAR pCar,MGraph * G,int * xTemp,int * yTemp,void ** buf,int idx)
{
	int i,j,k,w;
	float kLine,bLine;	//汽车的直线路径参数（斜率，截距）
	int carInWhichVex = -1;		//汽车在哪个地图结点对应的下标
	Patharc p; 
	ShortPathTable D;
	int wayLength = 0;
	int *way = NULL;
	i = idx;

	clrmous(mouseX,mouseY);	
	
	if(G->vexs[i].chargeFlag == 1) 	//到达充电桩,点亮充电按钮
	{
		lightChargeButton();
		lightOffChargeFullButton();
	}
	else if(G->vexs[i].chargeFlag == 2)	//到达换电桩，点亮换电按钮
	{
		lightChargeFullButton();
		lightOffChargeButton();
	}
	else
	{
		lightOffChargeButton();
		lightOffChargeFullButton();
	}
	
	(*xTemp) = G->vexs[i].x;						//获取鼠标点击的地图结点的位置
	(*yTemp) = G->vexs[i].y;
	
	carInWhichVex = getCarInWhichVex(pCar,G);		//得到汽车所处地图结点下标
	if(carInWhichVex == -1)
	{
		return;
	}
	ShortestPath_Dijkstra((*G),carInWhichVex,&p,&D);	//使用迪杰斯特拉算法	
	
	pCar->hasMileage += D[i] / DISTANCE_RATIO;
	pCar->electricityLeft -= (D[i] / DISTANCE_RATIO * 2) / (pCar->k + pCar->kEquipment);
	
	way = findWay(i, &p,&wayLength,G);		//得到汽车到目标结点的路径数组way
	
	for(j=0;j<wayLength;j++)
	{
		if(way[j] == -1)
		{
			break;
		}
		
		(*xTemp) = G->vexs[way[j]].x;
		(*yTemp) = G->vexs[way[j]].y;
	
		if((*xTemp) == pCar->x)		//两点x相等时相减等于0，不能做分母，故在这里用分支结构做特殊处理
		{
			while(1)
			{
				if(pCar->x == (*xTemp) && pCar->y == (*yTemp))
				{
					break;
				}
				putimage(pCar->x - CAR_SIZE,pCar->y - CAR_SIZE,(*buf),0);//恢复被旧车覆盖的图像
				free((*buf));
				
				changeCarPos(&(pCar->y),(*yTemp));				
				mallocBuf(pCar->x - CAR_SIZE,pCar->y - CAR_SIZE,pCar->x + CAR_SIZE,pCar->y + CAR_SIZE,buf);
				drawMapCar(pCar);//画新一个位置的车					
				delay(100);
			}
		}
		else		//一般情况下，有k和b
		{
			kLine = ((float)((*yTemp) - pCar->y)) / ((*xTemp) - pCar->x);
			bLine = ((float)(*yTemp)) - (kLine * (*xTemp));
			
			while(1)
			{
				if(pCar->x == (*xTemp) && pCar->y == (*yTemp))
				{
					break;
				}
				putimage(pCar->x - CAR_SIZE,pCar->y - CAR_SIZE,(*buf),0);//恢复被旧车覆盖的图像
				free((*buf));

				if(fabs(kLine > 4))
				{
					changeCarPosSlow(&(pCar->x),(*xTemp));
				}
				else
				{
					changeCarPos(&(pCar->x),(*xTemp));
				}
				// if(pCar->y == (int)(kLine * pCar->x + bLine))
				// {
				// 	pCar->x = *xTemp;
				// 	pCar->y = *yTemp;
				// }
				if(fabs(pCar->x - (*xTemp)) <= 2)
				{
					pCar->x = *xTemp;
					pCar->y = *yTemp;
				}
				else
				{
					pCar->y = (int)(kLine * pCar->x + bLine);//车的坐标x,y随着直线变化
				}
				
				mallocBuf(pCar->x - CAR_SIZE,pCar->y - CAR_SIZE,pCar->x + CAR_SIZE,pCar->y + CAR_SIZE,buf);
				drawMapCar(pCar);//画新一个位置的车		
				delay(100);
			}		
			

		}
	}
	free(way);
	save_bk_mou(mouseX,mouseY);
	drawmous(mouseX,mouseY);

	return;
}

///////////////////////////////////
//函数名：isPressPosInVex
//功能：判断鼠标点击位置是否为地图结点
//入口参数：地图结点数组
//返回值：1为真，0为假
///////////////////////////////////
int isPressPosInVex(MAPNODE m)
{
	if(mouseX>(m.x-ROUND_RADIUS) && mouseX < (m.x+ROUND_RADIUS) && mouseY > (m.y-ROUND_RADIUS) && mouseY < (m.y+ROUND_RADIUS))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

///////////////////////////////////
//函数名：getCarInWhichVex
//功能：获取汽车在哪个地图结点中
//入口参数：汽车指针，图的地址
//返回值：汽车所在地图结点下标
///////////////////////////////////
int getCarInWhichVex(PCAR pCar,MGraph * G)
{
	int i;
	for(i=0;i<G->numVertexes;i++)
	{
		if(pCar->x > G->vexs[i].x-ROUND_RADIUS && pCar->x < G->vexs[i].x+ROUND_RADIUS && pCar->y > G->vexs[i].y-ROUND_RADIUS && pCar->y < G->vexs[i].y+ROUND_RADIUS)
		{
			//找到就返回结点的下标
			return i;
		}
	}
	//没找到时返回-1
	return -1;
}

///////////////////////////////////
//函数名：mallocBuf
//功能：给buf分配空间，若出错则输出错误信息
//入口参数：图像位置x1,y1,x2,y2，指针buf的地址
//返回值：void
///////////////////////////////////
void mallocBuf(int x1,int y1,int x2,int y2,void ** buf)
{
	int size = 0;
	
	size = imagesize(x1,y1,x2,y2);
	(*buf) = malloc(size);
	if((*buf) != NULL)
	{
		getimage(x1,y1,x2,y2,(*buf));
	}
	else
	{
		exitFunc("(*buf) malloc error!");
	}
	
	return;
}

///////////////////////////////////
//函数名：changeCarPos
//功能：更改汽车位置
//入口参数：汽车位置地址，目标地点temp
//返回值：void
///////////////////////////////////
void changeCarPos(int * pos,int temp)
{
	if((*pos) > temp)
	{
		(*pos) -= (int)delta;
		if((*pos) < temp)
		{
			(*pos) = temp;
		}
	}
	else if((*pos) < temp)
	{
		(*pos) += (int)delta;
		if((*pos) > temp)
		{
			(*pos) = temp;
		}
	}
	
	return;
}

///////////////////////////////////
//函数名：changeCarPosSlow
//功能：缓慢更改汽车位置
//入口参数：汽车位置地址，目标地点temp
//返回值：void
///////////////////////////////////
void changeCarPosSlow(int * pos,int temp)
{
	if((*pos) > temp)
	{
		(*pos) -= (int)SLOW_DELTA;
		if((*pos) < temp)
		{
			(*pos) = temp;
		}
	}
	else if((*pos) < temp)
	{
		(*pos) += (int)SLOW_DELTA;
		if((*pos) > temp)
		{
			(*pos) = temp;
		}
	}
	
	return;
}

/*
函数名：page12_screen
功能：地图界面绘制
入口参数：void
返回值：void
*/
void page12_screen(void)
{
	cleardevice();
	setbkcolor(LIGHTCYAN);
	printHZ(506,222,"充电",48,DARKGRAY);
	printHZ(506,322,"换电",48,DARKGRAY);
	printHZ(506, 422,"返回",48,DARKGRAY);
	
	//绘制提示信息
	setfillstyle(SOLID_FILL,GREEN);
	barRecWithCenter(518,40,CAR_SIZE);
	setfillstyle(SOLID_FILL,BLACK);
	printHZ_withoutRec(530, 35,"您的位置",16,DARKGRAY);
	
	setfillstyle(SOLID_FILL,RED);
	pieslice(518,100,1,360,20);
	setcolor(RED);
	line(518,100,538,100);
	printHZ_withoutRec(545, 95,"充电站",16,DARKGRAY);
		
	setfillstyle(SOLID_FILL,BLUE);
	pieslice(518,170,1,360,20);
	setcolor(BLUE);
	line(518,170,538,170);
	printHZ_withoutRec(545, 165,"换电站",16,DARKGRAY);
	
	setfillstyle(SOLID_FILL,BLACK);
	setcolor(DARKGRAY);
	
	return;
}

/*
函数名：lightChargeButton
功能：点亮充电按钮
入口参数：void
返回值：void
*/
void lightChargeButton(void)
{
	setcolor(YELLOW);
	rectangle(506,222,613,270);			
	setcolor(DARKGRAY);
	return;
}

/*
函数名：lightChargeFullButton
功能：点亮换电按钮
入口参数：void
返回值：void
*/
void lightChargeFullButton(void)
{
	setcolor(YELLOW);
	rectangle(506,322,613,370);
	setcolor(DARKGRAY);
	return;
}

/*
函数名：lightOffChargeButton
功能：熄灭充电按钮
入口参数：void
返回值：void
*/
void lightOffChargeButton(void)
{
	setcolor(DARKGRAY);
	rectangle(506,222,613,270);			
	return;
}

/*
函数名：lightOffChargeFullButton
功能：熄灭换电按钮
入口参数：void
返回值：void
*/
void lightOffChargeFullButton(void)
{
	setcolor(DARKGRAY);
	rectangle(506,322,613,370);
	return;
}

/*
函数名：testCarPos
功能：查看汽车坐标是否为正常值，如果不正常则恢复到默认状态
入口参数：汽车指针pCar
返回值：void
*/
void testCarPos(PCAR pCar)
{
	if(pCar->x == 0 || pCar->y == 0)
	{
		pCar->x = 217;
		pCar->y = 405;
	}
	return;
}

/*
函数名：showStationDesc
功能：显示站点信息
入口参数：信息弹窗标志变量地址，信息弹窗指针地址，汽车指针，图的地址
返回值：点击的地图结点下标
*/
int showStationDesc(int * descPopWindow,void ** descBuf,PCAR pCar,MGraph * G)
{
	int i,w;
	int carInWhichVex = -1;		//汽车在哪个地图结点对应的下标
	ShortPathTable D;
	Patharc p;
	char stationName[50] = {'\0'};
	char distance[50] = {'\0'};
	FILE * fp = NULL;

	memset(stationName,'\0',sizeof(stationName));

	if(press == 1)
	{
		for(i=0;i<G->numVertexes;i++)
		{
			if(isPressPosInVex(G->vexs[i]) == 1)
			{
				delay(150);
				clrmous(mouseX,mouseY);	
		
				carInWhichVex = getCarInWhichVex(pCar,G);		//得到汽车所处地图结点下标
				if(carInWhichVex == -1)
				{
					break;
				}

				fp = fopen("station.txt","r");
				if(fp == NULL)
				{
					exitFunc("station.txt open error!");
				}

				ShortestPath_Dijkstra((*G),carInWhichVex,&p,&D);	//使用迪杰斯特拉算法		
				sprintf(distance,"%.2lf",D[i] / DISTANCE_RATIO);		//get distance
				memset(stationName,'\0',sizeof(stationName));
				for(w=0;w<=i;w++)
				{
					memset(stationName,'\0',sizeof(stationName));
					fgets(stationName,50,fp);
				}
				if(*descPopWindow == 0)
				{
					mallocBuf(0,0,325,165,descBuf);
					*descPopWindow = 1;
				}
				stationName[strlen(stationName) - 1] = '\0';
				setfillstyle(SOLID_FILL,BLACK);
				bar(0,0,325,165);
				setcolor(DARKGRAY);
				rectangle(0,0,325,165);
				rectangle(215,120,325,165);
				rectangle(0,120,65,165);
				setlinestyle(SOLID_LINE,0,THICK_WIDTH);
				line(15,122,50,162);
				line(50,122,15,162);
				setlinestyle(SOLID_LINE,0,NORM_WIDTH);
				printHZ_withoutRec(10, 10,"站名：",32, DARKGRAY);
				printHZ_withoutRec(10, 70,"距离：",32, DARKGRAY);
				printHZ_withoutRec(218, 125,"到此处",32, DARKGRAY);
				printHZ_withoutRec(117, 10,stationName,32, DARKGRAY);
				printText_withoutRec(128, 75,distance,3,DARKGRAY);
				printText_withoutRec(260, 75,"km",3,DARKGRAY);

				save_bk_mou(mouseX,mouseY);
				drawmous(mouseX,mouseY);

				fclose(fp);
				break;
			}
		}
	}
	return i;
}

/*
函数名：showStationName
功能：显示站点名称
入口参数：图的地址
返回值：void
*/
void showStationName(MGraph * G)
{
	FILE * fp = NULL;
	int i,j;
	char stationName[50] = {'\0'};
	fp=fopen("station.txt","r");
	if(fp == NULL)
	{
		exitFunc("station.txt open error!");
	}
	for(i=0;i<G->numVertexes;i++)
	{
		fgets(stationName,50,fp);
		stationName[strlen(stationName) - 1] = '\0';
		printHZ_withoutRec(G->vexs[i].x - ROUND_RADIUS - STATION_NAME_OFFSET ,G->vexs[i].y + ROUND_RADIUS,stationName,16,DARKGRAY);
	}
	fclose(fp);
	return;
}
