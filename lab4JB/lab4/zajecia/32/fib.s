.text
.globl fib
.type fib, @function
fib:
pushl %ebp
mov %esp, %ebp

movl $0, %eax
movl $1, %ecx

mov 8(%ebp), %ebx

loop:
addl %ecx, %eax
xchg %ecx, %eax
decl %ebx
cmpl $1, %ebx
jne loop

end: 
movl %ecx, %eax

mov %ebp, %esp
popl %ebp
ret

