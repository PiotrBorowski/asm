.text
.globl rdtsc
rdtsc:
	push %ebx
	xor %eax, %eax
	rdtsc
	pop %ebx
ret
