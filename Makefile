.PHONY: all clean install

all: kernel

kernel: start.o link.ld main.o vga.o GDT.o IDT.o isrs.o irq.o timer.o
	ld -m elf_i386 -T link.ld -o kernel *.o

%.o: %.c
	gcc -Wall -m32 -O0 -fstrength-reduce -fomit-frame-pointer -finline-functions -nostdinc -fno-builtin -fno-pic -ffreestanding -I./include -c -o $@ $<

start.o: start.asm
	nasm -f elf -o start.o start.asm

clean:
	rm -f *.o kernel
