#include "include/kernel.h"

/*
 * memcpy
 * Copy from source to destination. Assumes that
 * source and destination are not overlapping.
 */
unsigned short *memcpy(unsigned short *dest, const unsigned short *src, int count) {
    for (int i = 0; i < count; i++) {
        dest[i] = src[i];
    }
    return dest;
}

unsigned short *memcpyw(unsigned short *dest, const unsigned short *src, int count) {
    for (int i = 0; i < count; i++) {
        dest[i] = src[i];
    }
    return dest;
}

/*
 * memset
 * Set 'count' bytes to 'val'.
 */
unsigned char *memset(unsigned char *dest, unsigned char val, int count)
{
    int i;
    i = 0;
    for (; i < count; ++i) {
        dest[i] = val;
    }
    return dest;
}

/*
 * memsetw
 * Set 'count' shorts to 'val'.
 */
unsigned short *memsetw(unsigned short *dest, unsigned short val, int count)
{
  int i;
  i = 0;
  for ( ; i < count; ++i) {
    dest[i] = val;
  }
  return dest;
}

/*
 * strlen
 * Returns the length of a given 'str'.
 */
int strlen(const char *str)
{
  int i = 0;
  while(str[i] != (char)0) {
    ++i;
  }
  return i;
}

/*
 * inportb
 * Read from an I/O port.
 */
unsigned char inportb(unsigned short port)
{
  unsigned char rv;
  __asm__ __volatile__("inb %1, %0" : "=a"(rv) : "dN"(port));
  return rv;
}

/*
 * outportb
 * Write to an I/O port.
 */
void outportb(unsigned short port, unsigned char data)
{
  __asm__ __volatile__("outb %1, %0" : : "dN"(port), "a"(data));
}

/*
 * Kernel entry point
 */
int main()
{
        gdt_install();
        idt_install();
        isrs_install();
        irq_install();
        init_video();
        puts("Hello world!\n");
        for(;;);
        return 0;
}
