#ifndef _PAGE1_H_
#define _PAGE1_H_

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

void page1_screen(void);
int p1(void);
int Register(char * userText, char * passwordText);

#endif