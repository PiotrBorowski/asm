.data
four: .float 4.0
result: .float 0

.text
#sqrt( (a + (b+c)) * (c - (a-b)) * (c + (a-b)) * (a + (b-c)) ) / 4
.globl heron
.type heron, @function
heron:
push %ebp
mov %esp, %ebp

fld 8(%ebp) #a		%st(3)
fld 12(%ebp) #b		2
fld 16(%ebp) #c		1
fldz			#0

fadd %st(1), %st(0)
fadd %st(2), %st(0)
fadd %st(3), %st(0)

fld %st(2)	#załaduj b
fsubr %st(4), %st(0) #a-b
fsubr %st(0), %st(2) #c-(a-b)
fadd  %st(2), %st(0) #c+(a-b)

fld 16(%ebp) #załdauj c
fsubr %st(4), %st(0) #b-c
fadd  %st(5), %st(0) #a+(b-c)

fmul %st(1), %st(0) 
fmul %st(2), %st(0)
fmul %st(3), %st(0)

fsqrt #pierwiastek z iloczynu

fdiv four

mov %ebp, %esp
pop %ebp
ret
