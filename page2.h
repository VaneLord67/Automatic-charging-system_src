#ifndef _PAGE2_H_
#define _PAGE2_H_

extern void *buffer;
extern union REGS regs;

extern int mouseX;
extern int mouseY;
extern int press;
extern int flag;

void page2_screen(void);
int p2(void);
int Login(char * userText, char * passwordText);

#endif