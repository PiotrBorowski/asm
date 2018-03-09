.text
msg: .ascii "Write text (5): \n"
msg_len = . - msg

msg2: .ascii "Written text: "
msg2_len = . - msg2

newline: .ascii "\n"
newline_len = . - newline

.data
buf: .ascii "     "
buf_len = . - buf
SYSREAD = 3
SYSWRITE = 4
STDOUT = 1
STDIN = 0
SYSEXIT = 1
EXIT_SUCCESS = 0

.global _start
_start:

wypiszmsg:
	mov $SYSWRITE, %eax
	mov $STDOUT, %edi
	mov $msg, %esi
	mov $msg_len, %edx
	int $0x80

wczytaj:
	mov $SYSREAD, %eax
	mov $STDIN, %ebx
	mov $buf, %esi
	mov $buf_len, %edx
	int $0x80
	mov %eax, %ebx

wypiszmsg2:
	mov $SYSWRITE, %eax
        mov $STDOUT, %edi
        mov $msg2, %esi
        mov $msg2_len, %edx
	int $0x80

wypisz:
	mov $SYSWRITE, %eax
        mov $STDOUT, %edi
        mov $buf, %esi
        mov %ebx, %edx
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
