#ifndef _PAGE4_H_
#define _PAGE4_H_

extern void *buffer;
extern union REGS regs;

extern int mouseX;
extern int mouseY;
extern int press;
extern int flag;

extern int playIndex;
extern int isPlaySound;
extern clock_t start;
extern clock_t end;
extern double total;

void page4_screen(void);
int p4(void);

#endif