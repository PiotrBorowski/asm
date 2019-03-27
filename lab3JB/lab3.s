SYSCALL32 = 0x80
EXIT = 1
STDIN = 0
READ = 3
STDOUT = 1
WRITE = 4
BUF_SIZE = 254
BASE = 10

.data
BUF: .space BUF_SIZE
TEXT_SIZE: .long 0

.globl _start
.text
_start:

movl $BUF_SIZE, %edx
movl $BUF, %ecx
movl $STDIN, %ebx
movl $READ, %eax
int $SYSCALL32
movl %eax, TEXT_SIZE

pushl %eax
pushl $BUF
call horner


movl $EXIT, %eax
int $SYSCALL32

.type horner, @function
horner:
pushl %ebp
movl %esp, %ebp
#subl $4, %esp #miejsce na zmienna lokalna

movl  8(%ebp), %ebx	#pierwszy argument
movl 12(%ebp), %ecx	#drugi argument
################################

decl %ecx
movl $0, %eax
movl $0, %edx
movl $0, %edi

movb (%ebx, %edi, 1), %al
subb $'0', %al
incl %edi

loop:

movl $10, %edx
mull %edx
xorl %edx, %edx
movb (%ebx, %edi, 1), %dl
subb $'0', %dl
addl %edx, %eax

incl %edi
cmpl %edi, %ecx
jne loop
################################
end:
movl %ebp, %esp
popl %ebp
ret


