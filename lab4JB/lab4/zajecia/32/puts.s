.data
format: .ascii "Hello %s\n\0"
napis: .ascii "World\0"

.text
.globl main
main:

pushl $napis
pushl $format
call printf

call exit
