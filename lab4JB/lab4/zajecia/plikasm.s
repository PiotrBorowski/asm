.data
format: .ascii "Hello %s\n\0"
napis: .ascii "World\0"

.text
.globl main
main:

movq $napis, %rsi
movq $format, %rdi
movq $0, %rax
call printf

call exit
