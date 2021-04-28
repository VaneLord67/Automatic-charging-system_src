//page12 ��ͼ����

#include"map.h"

/*
��������p12
���ܣ���ͼ�ƶ�������ƹ��ܺ���
��ڲ���������ָ��pCar
����ֵ��page��ֵ
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
				if(mouse_press(215,120,325,165) == 1)		//press goto here button //������˴���ť.
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
			
			if(mouse_press(506,422,611,465) == 1)		//������ذ�ť
			{
				if(buf != NULL)
				{
					free(buf);						//�ͷ�ͼ���ڴ�
				}
				page = 4;
				pCar->k = 20;
				pCar->runState = 2;			
				pCar->speed = 0;
			}
			if(mouse_press(506,222,612,270) == 1 && G.vexs[getCarInWhichVex(pCar,&G)].chargeFlag == 1)		//������
			{
				if(pCar->electricityLeft == MAX_ELECTRICITY)
				{
					popWindow_withoutFlush(&popWindowBuf,&isPopWindow,"��������");
					continue;
				}
				pCar->runState = 0;
				page = 15;
			}
			if(mouse_press(506,322,614,371) == 1 && G.vexs[getCarInWhichVex(pCar,&G)].chargeFlag == 2)		//�������
			{
				if(pCar->electricityLeft == MAX_ELECTRICITY)
				{
					popWindow_withoutFlush(&popWindowBuf,&isPopWindow,"��������");
					continue;
				}
				pCar->runState = 0;
				page = 16;
			}
			if(pCar->electricityLeft < WARNING_ELECTRICITY && hasWarning == 0)
			{
				popWindow_withoutFlush(&popWindowBuf,&isPopWindow,"�����漱");
				hasWarning = 1;
			}
			/*
			if(mouse_press(506,222,612,270) == 2 && G.vexs[getCarInWhichVex(pCar,&G)].chargeFlag == 1);
			{
					if(num = 0);
					{
						button(506,222,612,270,DARKGRAY,DARKGRAY);
						printHZ(506,222,"���",48,WHITE);
						num = 1;
					}
					continue;
			}
			if(mouse_press(506,322,614,371) == 1 && G.vexs[getCarInWhichVex(pCar,&G)].chargeFlag == 2);
			{
					if(num = 0);
					{
						button(506,322,614,371,DARKGRAY,DARKGRAY);
						printHZ(506,322,"����",48,WHITE);
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
						printHZ(506,222,"���",48,DARKGRAY);
						break;
					case 2:
						button(506,322,614,371,DARKGRAY,LIGHTCYAN);
						printHZ(506,322,"����",48,DARKGRAY);
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
//��������ShortestPath_Dijkstra
//���ܣ��Ͻ�˹�����㷨
//��ڲ�����ͼ�ĵ�ַ����ʼ�˵㣬·�������·������
//����ֵ��void
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
//��������createMGraphFromFile
//���ܣ����ļ��д���ͼ
//��ڲ�����ͼ�ĵ�ַ
//����ֵ��void
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
		//settextjustify(LEFT_TEXT,TOP_TEXT);          //�󲿶��룬��������
		//settextstyle(GOTHIC_FONT,HORIZ_DIR,1);					//����ʻ������ˮƽ�����24*24����
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
//��������findWay
//���ܣ��ҵ���㵽�յ��·��
//��ڲ������յ㣬·����·�����鳤��
//����ֵ��ָ��·����ָ��
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
//��������apartSpaceRead
//���ܣ���������ַ���source�е�������ȡ����д��x��y
//��ڲ������ַ���source��x,y�ĵ�ַ
//����ֵ��void
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
//��������apartSpaceReadNode
//���ܣ���������ַ���source�е�������ȡ����д��x��y,flag
//��ڲ������ַ���source��x,y,flag�ĵ�ַ
//����ֵ��void
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
//��������drawMap
//���ܣ����Ƶ�ͼ���
//��ڲ�����ͼ�ĵ�ַ
//����ֵ��void
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
//��������drawMapLine
//���ܣ����Ƶ�ͼ�ı�����
//��ڲ�����void
//����ֵ��void
///////////////////////////////////
// void drawMapLine(void)
// {
// 	//��������
// 	line(0,120,480,120);
// 	line(0,240,480,240);
// 	line(0,360,480,360);
// 	//��������
// 	line(120,0,120,480);
// 	line(240,0,240,480);
// 	line(360,0,360,480);
// 	return;
// }

///////////////////////////////////
//��������drawMapCar
//���ܣ���������
//��ڲ���������ָ��pCar
//����ֵ��void
///////////////////////////////////
void drawMapCar(PCAR pCar)
{
	setfillstyle(SOLID_FILL,GREEN);
	barRecWithCenter(pCar->x,pCar->y,CAR_SIZE);
	setfillstyle(SOLID_FILL,BLACK);
	return;
}

///////////////////////////////////
//��������drawNodeLine
//���ܣ����Ƶ�ͼ���֮��ı�
//��ڲ�����ͼ�ĵ�ַ
//����ֵ��void
///////////////////////////////////
void drawNodeLine(MGraph * G)
{
	int i,j;
	for(i=0;i<G->numVertexes;i++)
	{
		for(j=0;j<G->numVertexes;j++)
		{
			//double����ֵ���Ƚϲ�����==��!=
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
��������carMoveAfterClick
���ܣ�������ó����ƶ�
��ڲ���������ָ�룬ͼ�ĵ�ַ��x��y�ĵ�ַ������ͼ��bufָ��ĵ�ַ������idx
����ֵ��void
*/
void carMoveAfterClick(PCAR pCar,MGraph * G,int * xTemp,int * yTemp,void ** buf,int idx)
{
	int i,j,k,w;
	float kLine,bLine;	//������ֱ��·��������б�ʣ��ؾࣩ
	int carInWhichVex = -1;		//�������ĸ���ͼ����Ӧ���±�
	Patharc p; 
	ShortPathTable D;
	int wayLength = 0;
	int *way = NULL;
	i = idx;

	clrmous(mouseX,mouseY);	
	
	if(G->vexs[i].chargeFlag == 1) 	//������׮,������簴ť
	{
		lightChargeButton();
		lightOffChargeFullButton();
	}
	else if(G->vexs[i].chargeFlag == 2)	//���ﻻ��׮���������簴ť
	{
		lightChargeFullButton();
		lightOffChargeButton();
	}
	else
	{
		lightOffChargeButton();
		lightOffChargeFullButton();
	}
	
	(*xTemp) = G->vexs[i].x;						//��ȡ������ĵ�ͼ����λ��
	(*yTemp) = G->vexs[i].y;
	
	carInWhichVex = getCarInWhichVex(pCar,G);		//�õ�����������ͼ����±�
	if(carInWhichVex == -1)
	{
		return;
	}
	ShortestPath_Dijkstra((*G),carInWhichVex,&p,&D);	//ʹ�õϽ�˹�����㷨	
	
	pCar->hasMileage += D[i] / DISTANCE_RATIO;
	pCar->electricityLeft -= (D[i] / DISTANCE_RATIO * 2) / (pCar->k + pCar->kEquipment);
	
	way = findWay(i, &p,&wayLength,G);		//�õ�������Ŀ�����·������way
	
	for(j=0;j<wayLength;j++)
	{
		if(way[j] == -1)
		{
			break;
		}
		
		(*xTemp) = G->vexs[way[j]].x;
		(*yTemp) = G->vexs[way[j]].y;
	
		if((*xTemp) == pCar->x)		//����x���ʱ�������0����������ĸ�����������÷�֧�ṹ�����⴦��
		{
			while(1)
			{
				if(pCar->x == (*xTemp) && pCar->y == (*yTemp))
				{
					break;
				}
				putimage(pCar->x - CAR_SIZE,pCar->y - CAR_SIZE,(*buf),0);//�ָ����ɳ����ǵ�ͼ��
				free((*buf));
				
				changeCarPos(&(pCar->y),(*yTemp));				
				mallocBuf(pCar->x - CAR_SIZE,pCar->y - CAR_SIZE,pCar->x + CAR_SIZE,pCar->y + CAR_SIZE,buf);
				drawMapCar(pCar);//����һ��λ�õĳ�					
				delay(100);
			}
		}
		else		//һ������£���k��b
		{
			kLine = ((float)((*yTemp) - pCar->y)) / ((*xTemp) - pCar->x);
			bLine = ((float)(*yTemp)) - (kLine * (*xTemp));
			
			while(1)
			{
				if(pCar->x == (*xTemp) && pCar->y == (*yTemp))
				{
					break;
				}
				putimage(pCar->x - CAR_SIZE,pCar->y - CAR_SIZE,(*buf),0);//�ָ����ɳ����ǵ�ͼ��
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
					pCar->y = (int)(kLine * pCar->x + bLine);//��������x,y����ֱ�߱仯
				}
				
				mallocBuf(pCar->x - CAR_SIZE,pCar->y - CAR_SIZE,pCar->x + CAR_SIZE,pCar->y + CAR_SIZE,buf);
				drawMapCar(pCar);//����һ��λ�õĳ�		
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
//��������isPressPosInVex
//���ܣ��ж������λ���Ƿ�Ϊ��ͼ���
//��ڲ�������ͼ�������
//����ֵ��1Ϊ�棬0Ϊ��
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
//��������getCarInWhichVex
//���ܣ���ȡ�������ĸ���ͼ�����
//��ڲ���������ָ�룬ͼ�ĵ�ַ
//����ֵ���������ڵ�ͼ����±�
///////////////////////////////////
int getCarInWhichVex(PCAR pCar,MGraph * G)
{
	int i;
	for(i=0;i<G->numVertexes;i++)
	{
		if(pCar->x > G->vexs[i].x-ROUND_RADIUS && pCar->x < G->vexs[i].x+ROUND_RADIUS && pCar->y > G->vexs[i].y-ROUND_RADIUS && pCar->y < G->vexs[i].y+ROUND_RADIUS)
		{
			//�ҵ��ͷ��ؽ����±�
			return i;
		}
	}
	//û�ҵ�ʱ����-1
	return -1;
}

///////////////////////////////////
//��������mallocBuf
//���ܣ���buf����ռ䣬�����������������Ϣ
//��ڲ�����ͼ��λ��x1,y1,x2,y2��ָ��buf�ĵ�ַ
//����ֵ��void
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
//��������changeCarPos
//���ܣ���������λ��
//��ڲ���������λ�õ�ַ��Ŀ��ص�temp
//����ֵ��void
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
//��������changeCarPosSlow
//���ܣ�������������λ��
//��ڲ���������λ�õ�ַ��Ŀ��ص�temp
//����ֵ��void
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
��������page12_screen
���ܣ���ͼ�������
��ڲ�����void
����ֵ��void
*/
void page12_screen(void)
{
	cleardevice();
	setbkcolor(LIGHTCYAN);
	printHZ(506,222,"���",48,DARKGRAY);
	printHZ(506,322,"����",48,DARKGRAY);
	printHZ(506, 422,"����",48,DARKGRAY);
	
	//������ʾ��Ϣ
	setfillstyle(SOLID_FILL,GREEN);
	barRecWithCenter(518,40,CAR_SIZE);
	setfillstyle(SOLID_FILL,BLACK);
	printHZ_withoutRec(530, 35,"����λ��",16,DARKGRAY);
	
	setfillstyle(SOLID_FILL,RED);
	pieslice(518,100,1,360,20);
	setcolor(RED);
	line(518,100,538,100);
	printHZ_withoutRec(545, 95,"���վ",16,DARKGRAY);
		
	setfillstyle(SOLID_FILL,BLUE);
	pieslice(518,170,1,360,20);
	setcolor(BLUE);
	line(518,170,538,170);
	printHZ_withoutRec(545, 165,"����վ",16,DARKGRAY);
	
	setfillstyle(SOLID_FILL,BLACK);
	setcolor(DARKGRAY);
	
	return;
}

/*
��������lightChargeButton
���ܣ�������簴ť
��ڲ�����void
����ֵ��void
*/
void lightChargeButton(void)
{
	setcolor(YELLOW);
	rectangle(506,222,613,270);			
	setcolor(DARKGRAY);
	return;
}

/*
��������lightChargeFullButton
���ܣ��������簴ť
��ڲ�����void
����ֵ��void
*/
void lightChargeFullButton(void)
{
	setcolor(YELLOW);
	rectangle(506,322,613,370);
	setcolor(DARKGRAY);
	return;
}

/*
��������lightOffChargeButton
���ܣ�Ϩ���簴ť
��ڲ�����void
����ֵ��void
*/
void lightOffChargeButton(void)
{
	setcolor(DARKGRAY);
	rectangle(506,222,613,270);			
	return;
}

/*
��������lightOffChargeFullButton
���ܣ�Ϩ�𻻵簴ť
��ڲ�����void
����ֵ��void
*/
void lightOffChargeFullButton(void)
{
	setcolor(DARKGRAY);
	rectangle(506,322,613,370);
	return;
}

/*
��������testCarPos
���ܣ��鿴���������Ƿ�Ϊ����ֵ�������������ָ���Ĭ��״̬
��ڲ���������ָ��pCar
����ֵ��void
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
��������showStationDesc
���ܣ���ʾվ����Ϣ
��ڲ�������Ϣ������־������ַ����Ϣ����ָ���ַ������ָ�룬ͼ�ĵ�ַ
����ֵ������ĵ�ͼ����±�
*/
int showStationDesc(int * descPopWindow,void ** descBuf,PCAR pCar,MGraph * G)
{
	int i,w;
	int carInWhichVex = -1;		//�������ĸ���ͼ����Ӧ���±�
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
		
				carInWhichVex = getCarInWhichVex(pCar,G);		//�õ�����������ͼ����±�
				if(carInWhichVex == -1)
				{
					break;
				}

				fp = fopen("station.txt","r");
				if(fp == NULL)
				{
					exitFunc("station.txt open error!");
				}

				ShortestPath_Dijkstra((*G),carInWhichVex,&p,&D);	//ʹ�õϽ�˹�����㷨		
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
				printHZ_withoutRec(10, 10,"վ����",32, DARKGRAY);
				printHZ_withoutRec(10, 70,"���룺",32, DARKGRAY);
				printHZ_withoutRec(218, 125,"���˴�",32, DARKGRAY);
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
��������showStationName
���ܣ���ʾվ������
��ڲ�����ͼ�ĵ�ַ
����ֵ��void
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
