.data
msg: .ascii "Write text (3): \n"
msg_len = . - msg
msg2: .ascii "Same text! "
msg2_len = . - msg2
msg3: .ascii "Not the same"
msg3_len = . - msg3
buf: .ascii "   "
buf_len = . - buf
text: .ascii "ASM"
text_len = . - text
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
	jmp porownaj2

porownaj:
	mov $text, %esi
	mov $buf, %edi
	mov $buf_len, %ecx
	cld
	repe cmpsb
	jecxz rowne

porownaj2:
	mov $0, %esi
	mov $0, %cl
loop:
	mov text(,%esi,1), %al
	mov buf(,%esi,1), %bl
	inc %esi
	cmp %al, %bl
	jne nierowne
	inc %cl
	cmp $buf_len, %cl
	je rowne
	jmp loop

nierowne: 
        mov $SYSWRITE, %eax
        mov $STDOUT, %ebx
        mov $msg3, %ecx
        mov $msg3_len, %edx
        int $0x80
	jmp exit

rowne: 
        mov $SYSWRITE, %eax
        mov $STDOUT, %ebx
        mov $msg2, %ecx
        mov $msg2_len, %edx
        int $0x80

exit: 
	mov $SYSEXIT, %eax
	mov $EXIT_SUCCESS, %ebx
	int $0x80
