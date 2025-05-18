.PHONY: all clean install

all: kernel

install: kernel
	sudo mount disk.img /mnt -o loop
	sudo cp kernel /mnt/kernel
	sudo umount /mnt

kernel: start.o link.ld main.o vga.o
	ld -m elf_i386 -T link.ld -o kernel start.o main.o vga.o

%.o: %.c
	gcc -Wall -m32 -O -fstrength-reduce -fomit-frame-pointer -finline-functions -nostdinc -fno-builtin -fno-pic -ffreestanding -I./include -c -o $@ $<

start.o: start.asm
	nasm -f elf -o start.o start.asm

clean:
	rm -f *.o kernel
