//����Ա��½�����

#include"page13.h"

/*
��������p13
���ܣ�����Ա����
��ڲ���������ָ��pCar
����ֵ��int���ͣ�����page��ֵ
*/
int p13(PCAR pCar)
{
    int page = 13;

    #ifdef DEBUGMODE
    pCar->isAdmin = 1;
    #endif

    change_page(page13_screen);

    while(page == 13)
    {
        #ifdef SHOWMOUSE
		showMousePos();
		#endif

        newmouse(&mouseX,&mouseY,&press);

        if(mouse_press(215,152,429,184) == 1)       //��ʻ��¼��ѯ
        {
            page = 9;
        }
        
        if(mouse_press(215,242,429,274) == 1)       //������¼��ѯ
        {
            page = 17;
        }

        if(mouse_press(390,408,400+48*2*1.1+2,408+48) == 1)			//�˳�
        {
            page = 3;
        }
			
        if(mouse_press(112,408,122+48*2*1.1+2,408+48) == 1)			//ע��
        {
            pCar->loginFlag = 0;
            page = 0;
        }
        

    }

    return page;
}

/*
��������page13_screen
���ܣ����ƹ���Ա����
��ڲ�����void
����ֵ��void
*/
void page13_screen()
{
    //����Ա����
    cleardevice();
	setbkcolor(LIGHTCYAN);
	setcolor(DARKGRAY);
	
	setlinestyle(SOLID_LINE,0,THICK_WIDTH);
	int a[] = {135,140,175,140,175,190,155,180,135,190,135,140};
	drawpoly(6,a);
	circle(152,157,8);
	line(158,163,168,173);
	
	int b[] = {135,230,175,230,175,280,155,270,135,280,135,230};
	drawpoly(6,b);
	int c[] = {155,240,147,252,163,252,155,264};
	drawpoly(4,c);
	
    setlinestyle(SOLID_LINE,0,NORM_WIDTH);

	printHZ_withoutRec(200,20,"����Ա����",48,DARKGRAY);
    printHZ(215,150,"��ʻ��¼��ѯ",32,DARKGRAY);
    printHZ(215,240,"����¼��ѯ",32,DARKGRAY);
    
    setfillstyle(SOLID_FILL,DARKGRAY);
	bar(112,408,122+48*2*1.1+2,408+48);
	bar(390,408,400+48*2*1.1+2,408+48);
	floodfill(123,409,DARKGRAY); 
	floodfill(401,409,DARKGRAY);
	printHZ(122, 408,"ע��",48,WHITE);
	printHZ(400, 408,"�˳�",48,WHITE);

    return;
}
