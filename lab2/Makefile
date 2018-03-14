all: long clean

long: long.o
	ld -o long long.o

long.o: long.s
	as -o long.o long.s

clean:
	rm long.o
