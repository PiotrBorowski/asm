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
