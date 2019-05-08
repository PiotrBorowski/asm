.globl fibb
.type fibb, @function
fibb:

cmpq $1, %rdi
je zwroc

cmpq $0, %rdi
je zwroc

decq %rdi
pushq %rdi
call fibb
popq %rdi
pushq %rax

decq %rdi
pushq %rdi
call fibb
popq %rdi

popq %rcx
addq %rcx, %rax
jmp end3

zwroc:
movq %rdi, %rax

end3:

ret

