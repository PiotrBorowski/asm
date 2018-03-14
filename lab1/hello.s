SYSEXIT = 1
EXIT_SUCCESS = 0
SYSWRITE = 4
STDOUT = 1

.text
msg: .ascii "Hello! \n"
msg_len = . - msg

.global _start
_start:

movl 	$msg_len, %edx
movl 	$msg, %ecx
movl	$STDOUT, %ebx
movl	$SYSWRITE, %eax
int 	$0x80

mov 	$SYSEXIT, %eax
mov 	$EXIT_SUCCESS, %ebx

int 	$0x80
