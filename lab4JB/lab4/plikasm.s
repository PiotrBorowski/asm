.data
napis: .ascii "Hello %s\n\0"
napis2: .ascii "Piotr\0"

.extern sum_in_C
.extern numer_in_C
.globl main
main:

pushl $napis2
pushl $napis
call printf

pushl $5
pushl number_in_C
call sum_in_C

call exit
