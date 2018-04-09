.code32
.data
liczba1:
	.long 0x00304008, 0x70000000, 0x00000001, 0x00000001
liczba2:
	.long 0xF040500C, 0x00000000, 0xFFFFFFFF, 0x00000001


SYSEXIT = 1
EXIT_SUCCESS = 0

.text
.global _start

_start:
	mov $4, %edx
	clc
	pushf
loop:
	sub $1, %edx
	movl liczba1(,%edx,4), %eax
	movl liczba2(,%edx,4), %ebx

	popf
	adcl %ebx,%eax
	push %eax
	pushf

	
	cmp $0, %edx
	jne loop
	popf
	jnc exit
	push $1

exit:
	mov $SYSEXIT, %eax
	mov $EXIT_SUCCESS, %ebx
	int $0x80
