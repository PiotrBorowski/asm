
liczba1:
        .long 0x00004008, 0x70000000, 0x00000001, 0x00000001
liczba2:
        .long 0xF040500C, 0x00000000, 0xFFFFFFFF, 0x00000001

l1_len = . - liczba1


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
        sbbl %ebx,%eax
        push %eax
        pushf


        cmp $0, %edx
        jne loop
        popf
        jnc exit
        push $0xFFFFFFFF

exit:
        mov $SYSEXIT, %eax
        mov $EXIT_SUCCESS, %ebx
        int $0x80

