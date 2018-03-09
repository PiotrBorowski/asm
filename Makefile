<<<<<<< HEAD
all: hello clean

=======
>>>>>>> b72753f24c0507ac89f3de0c79ce75af7404d2ac
hello:	hello.o
	ld -o hello hello.o

hello.o:	hello.s
		as -o hello.o hello.s
<<<<<<< HEAD

clean:
	rm hello.o
=======
>>>>>>> b72753f24c0507ac89f3de0c79ce75af7404d2ac
