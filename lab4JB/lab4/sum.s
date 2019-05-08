.data
.globl number1
number1: .int 1

.text
.globl sum
.type sum, @function
sum:
	pushl %ebp
	mov %esp, %ebp
	mov 8(%ebp), %edi
	mov 12(%ebp), %esi

	addl %edi, %esi
	movl %esi, %eax

	mov %ebp, %esp
	popl %ebp
	ret
