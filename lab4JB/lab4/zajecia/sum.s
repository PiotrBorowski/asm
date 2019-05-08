.text
.globl sum
.type sum, @function
sum:
	addq %rdi, %rsi
	movq %rsi, %rax
	ret
