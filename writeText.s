.data
msg: .ascii "Write text (5): \n"
msg_len = . - msg
msg2: .ascii "Written text: "
msg2_len = . - msg2
newline: .ascii "\n"
newline_len = . - newline
buf: .ascii "     "
buf_len = . - buf
SYSREAD = 3
SYSWRITE = 4
STDOUT = 1
STDIN = 0
SYSEXIT = 1
EXIT_SUCCESS = 0

.text
.global _start
_start:

wypiszmsg:
	mov $SYSWRITE, %eax
	mov $STDOUT, %ebx
	mov $msg, %ecx
	mov $msg_len, %edx
	int $0x80

wczytaj:
	mov $SYSREAD, %eax
	mov $STDIN, %ebx
	mov $buf, %ecx
	mov $buf_len, %edx
	int $0x80

wypiszmsg2:
	mov $SYSWRITE, %eax
        mov $STDOUT, %ebx
        mov $msg2, %ecx
        mov $msg2_len, %edx
	int $0x80

wypisz:
	mov $SYSWRITE, %eax
        mov $STDOUT, %ebx
        mov $buf, %ecx
        mov %buf_len, %edx
        int $0x80

wypisznewline:
	mov $SYSWRITE, %eax
        mov $STDOUT, %edi
        mov $newline, %esi
        mov $newline_len, %edx
	int $0x80	

        mov $SYSEXIT, %eax
        mov $EXIT_SUCCESS, %ebx
        int $0x80
