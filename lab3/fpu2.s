.code32
	
.data
l1:
	.float 12.0	
			
l2:
        .float 6.0

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

	#Ustawienie precyzji
	AND $0xFCFF, %ax 	#1111 1100 1111 1111  PC
	OR $0x0000, %ax 	#SINGLE PRECISION - 32bit /24 REAL4
	#OR $0x0200, %ax 	#DOUBLE PRECISION - 64bit /53 REAL8
	#OR $0x0300, %ax 	#EXTENDED PRECISION - 80bit /64 REAL10

	#Ustawienie zaokraglen
	AND $0xF3FF, %ax 	#1111 0011 1111 1111 RC
	OR $0x0000, %ax 	#Zaokraglenie do najblizszej lub parzystej
	#OR $0x0400, %ax 	#Zaokraglenie w dol
	#OR $0x0800, %ax 	#Zaokraglenie w gore
	#OR $0x0C00, %ax 	#truncate

	MOV %ax, cw
	FLDCW cw   #zaladowanie control word

set:
	#wpycham l1 potem l2, czyli l1jest na st1 l2 na st0
	FLD l1
	FLD l2

add:
	FST %st(2)	#kopia st0 do st2, czyli liczby potrzebnej do dzialan
	FADD %st(1), %st(0)	#dodawanie i wynik w st0
	FST %st(3)	#wynik z st0 trafia do st3

sub:
	FXCH %st(2)	#zamieniam zachowana liczbe w st2 z st0
	FST %st(2)	#zachowuje st0 w st2
	FSUB %st(1), %st(0) #wynik w st0
	FST %st(4)	#kopia wyniku z st0 do st4

mul:
	FXCH %st(2)	
	FST %st(2)	
	FMUL %st(1), %st(0)	
	FST %st(5)	#kopia wyniku do st5

div:	
	FXCH %st(2)	
	FST %st(2)
	FDIV %st(1), %st(0)	
	FST %st(6)	

exit:
	MOV $SYSEXIT, %eax
	MOV $EXIT_SUCCESS, %ebx
	INT $0x80
