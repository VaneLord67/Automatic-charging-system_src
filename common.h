#ifndef _COMMON_H_
#define _COMMON_H_

#include<graphics.h>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<dos.h>
#include<bios.h>
#include<string.h>
#include<time.h>
#include"mouse.h"
#include"hz.h"
#include"myf.h"
#include<malloc.h>

//汽车结构声明
typedef struct car
{
	int electricityLeft;	//剩余电量
	int hasMileage; //已行驶里程
	//下列四种状态0为关闭，1为开启
	int airConditioningFlag; //空调状态
	int lightFlag;			//车灯状态
	int windowFlag;			//车窗状态
	int musicFlag; 			//音乐播放器状态
	int runState;			//行驶状态（熄火0、行驶1、制动2）
	
}CAR,*PCAR;

#endif