all: fpu clean

fpu: fpu.o
	ld -m elf_i386 -o fpu fpu.o
fpu.o: fpu.s
	as --32 -o fpu.o fpu.s
clean:
	rm fpu.o
