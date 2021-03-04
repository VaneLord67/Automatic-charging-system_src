#ifndef _PAGE4_H_
#define _PAGE4_H_

extern void *buffer;
extern union REGS regs;

extern int mouseX;
extern int mouseY;
extern int press;
extern int flag;


void page4_screen(void);
int p4(void);

#endif