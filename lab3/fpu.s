.code32

.data

l1: .float 14.12

l2: .float -13.5

SYSEXIT = 1
EXIT_SUCCESS = 0

.text
.global _start
_start:

pluszero:
fld l1 
fldz
fmulp #mnozy i pop, czyli inkrementacja wskaznika stosu

minuszero:
fld l2
fldz
fmulp

#najpierw przez co dzielimy czyli zero potem liczba ktora dzielimy czyli l1
plusinf:
fldz
fld l1
fdivp

minusinf:
fldz
fld l2
fdivp

#pierwiastek liczby ujmnej
NaN1:
fld l2
fsqrt

#zero podzielic przez zero
NaN2:
fldz
fldz
fdivp

exit:
mov $SYSEXIT, %eax
mov $EXIT_SUCCESS, %ebx
int $0x80
