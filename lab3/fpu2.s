.code32
	
.data
l1:
	.float 900000000
			
l2:
        .float 0.0000000001

cw: .short 0	


SYSEXIT = 1	
EXIT_SUCCESS = 0

.text
.global _start
_start:

setCW:
	FSTCW cw	#pobieram control word do cw
	FWAIT 	
	MOV cw, %ax 	#zaladowanie cw do ax

#zerowanie bitow precyzji, reszta bez zmian, nastepnie ustawianie
	AND $0xFCFF, %ax 	#1111 1100 1111 1111  PC
	OR $0x0000, %ax 	#SINGLE 32bit R4
	#OR $0x0200, %ax 	#DOUBLE 64bit R8
	#OR $0x0300, %ax 	#EXTENDED 80bit R10
#zerowanie bitow zaokraglania, reszta bez zmian, nast ustawianie
	AND $0xF3FF, %ax 	#1111 0011 1111 1111 RC
	#OR $0x0000, %ax 	#zaokr do najblizszej lub parzystej
	#OR $0x0400, %ax 	#zaokr w dol
	OR $0x0800, %ax 	#zaokr w gore
	#OR $0x0C00, %ax 	#truncate

	MOV %ax, cw
	FLDCW cw   #zaladowanie control word

set:
	#wpycham l1 potem l2, czyli l1jest na st1 l2 na st0
	FLD l1
	FLD l2

div:	
	FDIV %st(1), %st(0)		

exit:
	MOV $SYSEXIT, %eax
	MOV $EXIT_SUCCESS, %ebx
	INT $0x80
