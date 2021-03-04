#ifndef _PAGE0_H_
#define _PAGE0_H_

extern void *buffer;
extern union REGS regs;

extern int mouseX;
extern int mouseY;
extern int press;
extern int flag;

void page0_screen(void);
int p0(void);

#endif