SYSCALL32 = 0x80
EXIT = 1
STDIN = 0
READ = 3
STDOUT = 1
WRITE = 4
BUF_SIZE = 254

.data
komunikat: .ascii "Hello\n"
rozmiar = .-komunikat
TEXT_SIZE: .long 0

.bss
.comm BUFOR, BUF_SIZE

.globl _start
.text
_start:
movl $rozmiar, %edx
movl $komunikat, %ecx
movl $STDOUT, %ebx
movl $WRITE, %eax
int $SYSCALL32

movl $BUF_SIZE, %edx
movl $BUFOR, %ecx
movl $STDIN, %ebx
movl $READ, %eax
int $SYSCALL32

movl %eax, TEXT_SIZE	#liczba wczytanych znakow

movl $TEXT_SIZE, %edx
movl $BUFOR, %ecx
movl $STDOUT, %ebx
movl $WRITE, %eax
int $SYSCALL32


movl TEXT_SIZE, %ecx

zmien:
movb BUFOR(,%ecx,1), %al
movb %al, %bl
andb $0xDF, %bl

cmpb $'Z', %bl 
ja skip			#czy jest powyzej kodu Z
subb $'A', %bl
jb skip			#czy jest ponizej kodu A
xorb $0x20, %al
movb %al, BUFOR(,%ecx,1)

skip:
decl %ecx
cmpl $-1, %ecx
jne zmien


movl $TEXT_SIZE, %edx
movl $BUFOR, %ecx
movl $STDOUT, %ebx
movl $WRITE, %eax
int $SYSCALL32

movl $EXIT, %eax
int $SYSCALL32
