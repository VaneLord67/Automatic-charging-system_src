#include"mouse.h"

extern void *buffer;
extern union REGS regs;

extern int mouseX;
extern int mouseY;
extern int press;
extern int flag;


/*
��������initMouse
���ܣ���ʼ�����
��ڲ�����void
����ֵ��void
*/
void initMouse(void)
{
	int isSuccess;
	int xmin,xmax,ymin,ymax,x_max=625,y_max=480;
	int size;

	xmin=2;
	xmax=x_max-1;
	ymin=8;
	ymax=y_max-2;
	regs.x.ax=0;
	int86(51,&regs,&regs);
	isSuccess=regs.x.ax;
	if(0 == isSuccess)
	{
		printf("Mouse or Mouse Driver Obsent,Please Install!");
		delay(5000);
	}

	//�ɹ���ʼ�����������ˮƽ(07H)�봹ֱ�߽�(08H)

	else
	{
		regs.x.ax=7;
		regs.x.cx=xmin;
		regs.x.dx=xmax;
		int86(51,&regs,&regs);
		regs.x.ax=8;
		regs.x.cx=ymin;
		regs.x.dx=ymax;
		int86(51,&regs,&regs);
	}
	
	

	// mouseX=320,mouseY=240;
	// save_bk_mou(320,240);
	// mouse(mouseX,mouseY);
	newmouse(&mouseX,&mouseY,&press);
	
	flag=1;
	
	//delay(2000);
	
	return;
}

/*
��������save_bk_mou
���ܣ�������걳��
��ڲ��������λ��nx,ny
����ֵ��void
*/
void save_bk_mou(int nx,int ny)//����걳��
{
	int size;

	size=imagesize(nx-1,ny-2,nx+11,ny+17);
	buffer=malloc(size);
	if(buffer!=NULL)
		getimage(nx-1,ny-2,nx+11,ny+17,buffer);
	else
		printf("Error");
	
	return;
}

/*
��������mouse
���ܣ����滭
��ڲ��������λ��x,y
����ֵ��void
*/
void mouse(int x,int y)
{
	setlinestyle(0,0,1);
	setcolor(WHITE);
	line(x,y,x,y+13);
	line(x+1,y+1,x+1,y+12);
	line(x+2,y+2,x+2,y+11);
	line(x+3,y+3,x+3,y+10);
	line(x+4,y+4,x+4,y+12);
	line(x+5,y+5,x+5,y+9);
	line(x+5,y+11,x+5,y+14);
	line(x+6,y+6,x+6,y+9);
	line(x+6,y+13,x+6,y+15);
	line(x+7,y+7,x+7,y+9);
	line(x+8,y+8,x+8,y+9);
	line(x+9,y+9,x+9,y+9);
	
	setcolor(DARKGRAY);
	line(x-1,y-1,x-1,y+14);
	line(x-1,y+14,x+3,y+11);
	line(x+3,y+11,x+3,y+12);
	line(x+3,y+12,x+4,y+13);
	line(x+4,y+13,x+4,y+14);
	line(x+4,y+14,x+7,y+17);
	line(x+7,y+17,x+7,y+13);
	line(x+7,y+13,x+6,y+12);
	line(x+6,y+12,x+6,y+11);
	line(x+6,y+11,x+5,y+10);
	line(x+5,y+10,x+11,y+10);
	line(x+11,y+10,x-1,y-2);
	
	return;
}

/*
��������drawmous
���ܣ������ʾ
��ڲ��������λ��nx,ny
����ֵ��void
*/
void drawmous(int nx,int ny)
{
	if(flag==0)
	{
		setwritemode(COPY_PUT);
	    mouse(nx,ny);
		flag=1;
		
		
	}
}


/*
��������mread
���ܣ���ȡ���λ�ü��䰴ť״̬
��ڲ��������λ��nx,ny����갴ť״̬nbuttons
����ֵ��void
*/
void mread(int *nx,int *ny,int *nbuttons)  
{
	regs.x.ax=3;   //03H:��ȡ���λ�ü��䰴ť״̬
	int86(51,&regs,&regs);   
	*nx = regs.x.cx;
	*ny = regs.x.dx;
	*nbuttons = regs.x.bx;
}


void newmouse(int *nx,int *ny,int *nbuttons)
{
	int xn,yn,buttonsn;                       //��״̬����
	int x0=*nx,y0=*ny,buttons0=*nbuttons;	  //��״̬����������
	mread(&xn,&yn,&buttonsn);          
	*nx = xn;
	*ny = yn;                                 
	*nbuttons = buttonsn;						//����������
	
	// if(buttons0 == *nbuttons)
		// *nbuttons = 0;    //ʹ������������
	
	if(xn == x0 && yn == y0 && buttonsn == buttons0)
		return;            //���״̬������ֱ�ӷ���S

	
	clrmous(x0,y0);        //˵�����״̬�����˸ı�
	save_bk_mou(*nx,*ny);
	drawmous(*nx,*ny);
}



void clrmous(int nx,int ny)//������
{
	if(flag==1)
	{
		setwritemode(XOR_PUT); 
		mouse(nx,ny);
		putimage(nx-1,ny-2,buffer,COPY_PUT);
		free(buffer);
		flag=0;
		setwritemode(COPY_PUT);
		
	
	}
}

int mouse_press(int x1, int y1, int x2, int y2)
{
	//�ڿ��е�����򷵻�1
	if(mouseX > x1 
	&&mouseX < x2
	&&mouseY > y1
	&&mouseY < y2
	&&press == 1)
	{
		return 1;
	}
	
	//�ڿ���δ������򷵻�2
	else if(mouseX > x1 
	&&mouseX < x2
	&&mouseY > y1
	&&mouseY < y2
	&&press == 0)
	{
		return 2;
	}
	
	//�ڿ��е���Ҽ����򷵻�3
	else if(mouseX > x1 
	&&mouseX < x2
	&&mouseY > y1
	&&mouseY < y2
	&&press == 2)
	{
		return 3;
	}
	
	else
	{
		return 0;
	}
}

int mouse_pressCenter(int centerX,int centerY,int size)
{
	int x1 = centerX - size;
	int x2 = centerX + size;
	int y1 = centerY - size;
	int y2 = centerY + size;
	return mouse_press(x1,y1,x2,y2);
}

