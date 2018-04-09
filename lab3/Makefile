all: fpu fpu2 clean

fpu: fpu.o
	ld -m elf_i386 -o fpu fpu.o
fpu.o: fpu.s
	as --32 -o fpu.o fpu.s
fpu2: fpu2.o
	ld -m elf_i386 -o fpu2 fpu2.o
fpu2.o: fpu2.s
	as --32 -o fpu2.o fpu2.s

clean:
	rm fpu.o
	rm fpu2.o
