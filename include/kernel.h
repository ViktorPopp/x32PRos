#ifndef KERNEL_H
#define KERNEL_H

/* kernel main */
extern unsigned short *memcpy(unsigned short *dest, const unsigned short *src, int count); // Changed to unsigned short *
extern unsigned short *memcpyw(unsigned short *dest, const unsigned short *src, int count);
extern unsigned char *memset(unsigned char *dest, unsigned char val, int count);
extern unsigned short *memsetw(unsigned short *dest, unsigned short val, int count);
extern int strlen(const char *str);
extern unsigned char inportb(unsigned short port);
extern void outportb(unsigned short port, unsigned char data);

/* vga driver */
extern void cls();
extern void putch(unsigned char c);
extern void puts(const char *str);
extern void settextcolor(unsigned char forecolor, unsigned char backcolor);
extern void init_video();

/* GDT */
extern void gdt_install();
extern void gdt_set_gate(int num, unsigned long base, unsigned long limit, unsigned char access, unsigned char gran);

#endif
