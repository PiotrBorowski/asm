lab1:	lab1.o
	ld lab1.o -m elf_i386 -o lab1

lab1.o:	lab1.s
	as --32 lab1.s -g -o lab1.o

liczby:	liczby.o
	ld liczby.o -m elf_i386 -o liczby

liczby.o:	liczby.s
	as --32 liczby.s -g -o liczby.o
