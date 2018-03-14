.data
liczba1:
	.long 0x10304008, 0x701100FF, 0x45100020, 0x08570030
liczba2:
	.long 0xF040500C, 0x00220026, 0x321000CB, 0x04520031

liczba1_len = . - liczba1
liczba2_len = . - liczba2

SYSWRITE = 4
STDOUT = 1
SYSEXIT = 1
EXIT_SUCCESS = 0

.bss
.comm buf, 512

.text
.global _start

_start:
	
	mov $4, %edx
	clc
	pushf
loop:
	movl liczba1(,%edx,4), %eax
	movl liczba2(,%edx,4), %ebx
	dec %edx
	popf
	adcl %ebx,%eax
	pushf
	mov %eax,$buf(,%edx,4)
	cmp $0, %edx
	jne loop

	popf
	jnc exit
	push $1


exit:
	
	mov $SYSEXIT, %eax
	mov $EXIT_SUCCESS, %ebx
	int $0x80
