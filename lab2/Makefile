all: long longsub clean

long: long.o
	ld -m elf_i386 -o long long.o

long.o: long.s
	as --32 -o long.o long.s

longsub: longsub.o
	ld -m elf_i386 -o longsub longsub.o

longsub.o: longsub.s
	as --32 -o longsub.o longsub.s


clean:
	rm long.o
	rm longsub.o
