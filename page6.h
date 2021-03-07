#ifndef _PAGE6_H_
#define _PAGE6_H_

extern void *buffer;
extern union REGS regs;

extern int mouseX;
extern int mouseY;
extern int press;
extern int flag;


void page6_screen(void);
int p6(PCAR pCar);

#endif