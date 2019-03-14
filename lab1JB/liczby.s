SYSCALL32 = 0x80
EXIT = 1
STDIN = 0
READ = 3
STDOUT = 1
WRITE = 4

.data

liczba:
	 .int 0b0000111100001111
rozm = .-liczba
wynik: .ascii "             \n"
wynik_rozm = .-wynik
#.bss
#.comm wynik, 4

.globl _start
.text
_start:

movl liczba, %eax
movl $wynik_rozm-1, %edi

petla:
movl $10, %ebx
divl %ebx

addl $48, %edx
movb %dl, wynik(%edi)
xorl %edx, %edx
decl %edi

cmpl $0, %eax
jne petla

movl $wynik_rozm, %edx
movl $wynik, %ecx
movl $STDOUT, %ebx
movl $WRITE, %eax
int $SYSCALL32


movl $EXIT, %eax
int $SYSCALL32

