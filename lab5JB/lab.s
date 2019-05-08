.data

invalid: .string "Niedozwolona operacja"
denormalized: .string "liczba zdenormalizowana"
zerodiv: .string "dzielenie przez zero"
overflow: .string "overflow"
underflow: .string "underflow"
precision: .string "utrata precyzji"

one: .float 0x00000001

.text
.globl throwInvalid
.type throwInvalid, @function
throwInvalid:

pushq %rbp
movq %rsp, %rbp

finit 

fld1
fchs
fsqrt

movq %rbp, %rsp
popq %rbp
ret

.globl throwDenormalized
.type throwDenormalized, @function
throwDenormalized:

pushq %rbp
movq %rsp, %rbp

finit 

#pushq $0x00000001

#fld (%rsp)
fld1
fldz
faddp

movq %rbp, %rsp
popq %rbp
ret

.globl readExceptions
.type readExceptions, @function
readExceptions:
pushq %rbp
movq %rsp, %rbp

movb $1, %dl
movq $0, %rax
fstsw %ax

readInvalid:
testb %al, %dl
jz readDenormal
movq $invalid, %rdi
call puts

readDenormal:
salb $1, %dl
testb %al, %dl
jz readZeroDiv
mov $denormalized, %rdi
call puts

readZeroDiv:
salb $1, %dl
testb %al, %dl
jz readOverflow
mov $zerodiv, %rdi
call puts

readOverflow:
salb $1, %dl
testb %al, %dl
jz readUnderflow
mov $overflow, %rdi
call puts

readUnderflow:
salb $1, %dl
testb %al, %dl
jz readPrecision
mov $underflow, %rdi
call puts

readPrecision:
salb $1, %dl
testb %al, %dl
jz readEnd
mov $precision, %rdi
call puts

readEnd:

movq %rbp, %rsp
popq %rbp
ret


