#ifndef _logo_H_
#define _logo_H_

extern void *buffer;
extern union REGS regs;

extern int mouseX;
extern int mouseY;
extern int press;
extern int flag;


void logo_screen(void);

#endif