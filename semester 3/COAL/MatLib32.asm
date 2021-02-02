TITLE coal final project
INCLUDE Irvine32.inc
INCLUDE MatLib32.inc

.data 
count DWORD 0
tempM SDWORD 20 dup(?)
res1 SDWORD 20 dup(?)
res2 SDWORD 20 dup(?)
newR REAL8 20 dup(?)
dummy SDWORD 20 dup(?)
dummy2 SDWORD 20 dup(?)
dummy3 SDWORD 20 dup(?)
det SDWORD ?
num1 SDWORD ?
num2 SDWORD ?
var2 SDWORD ?
var DWORD 4
var3 SDWORD ?
temp SDWORD ?
temp2 SDWORD ?
temp3 SDWORD ?
temp4 SDWORD ?
rowS DWORD ?
colS DWORD ?
msg4 BYTE "Enter the elements row ",0
msg8 BYTE " : ",0
msg9 BYTE "   ",0
error1 BYTE "Invalid Size! Enter again",0
error2 BYTE "Size of the matices donot match!",0
error3 BYTE "Adjoint of the matix is not possible!",0
error4 BYTE "Inverse of the matix does not exist!",0
error5 BYTE "Invalid Size!",0
error6 BYTE "Invalid Number!",0

.code
;-------------------------------------------------------
; Display function
;-------------------------------------------------------
DisplayMat PROC 
push ebp
mov ebp, esp
mov ebx, esi
L1:
call crlf
push ecx
mov ecx, eax
push eax
mov esi, 0

L2:
mov eax, [ebx+esi]
cmp eax, 0
jge next
call writeint
jmp next2
next:
call writedec
next2:
mov edx, offset msg9
call writeString
add esi, 4 
loop L2

pop eax
push eax 
mul var
add ebx, eax
pop eax
pop ecx
loop L1

call crlf
pop ebp
ret
DisplayMat endp


;-------------------------------------------------------
; Matrix Addition
;-------------------------------------------------------
SumMat PROC
push ebp
mov ebp, esp
mov ecx, [ebp+20]
mov eax, [ebp+12]
cmp eax, ecx
jne print
mov ecx, [ebp+16]
mov eax, [ebp+8]
cmp eax, ecx
je next2
jmp print

next2:
mov ecx, [ebp+12]
mov ebx, esi
push 0
L1:
call crlf
mov temp, ecx
mov ecx, eax
mov temp2, eax
mov esi, 0

L2:
mov eax, [ebx+esi]
mov edx, [edi+esi]
add eax, edx
mov temp3, ebx 
pop ebx
mov res1[ebx+esi], eax
push ebx
mov ebx, temp3
add esi, 4 
loop L2

mov eax, temp2
mul var
mov temp3, ebx 
pop ebx
add ebx, eax
push ebx
add edi, eax
mov ebx, temp3
add ebx, eax
mov eax, temp2
mov ecx, temp
loop L1
pop eax
mov esi, offset res1
jmp final

print:
mov edx, offset error2
call writeString
call crlf

final:
pop ebp
ret
SumMat endp


;-------------------------------------------------------
; Matrix subtraction
;-------------------------------------------------------
SubMat PROC
push ebp
mov ebp, esp
mov ecx, [ebp+20]
mov eax, [ebp+12]
cmp eax, ecx
jne print
mov ecx, [ebp+16]
mov eax, [ebp+8]
cmp eax, ecx
je next2
jmp print

next2:
mov ecx, [ebp+12]
mov ebx, esi
push 0
L1:
call crlf
mov temp, ecx
mov ecx, eax
mov temp2, eax
mov esi, 0

L2:
mov eax, [ebx+esi]
mov edx, [edi+esi]
sub eax, edx
mov temp3, ebx 
pop ebx
mov res1[ebx+esi], eax
push ebx
mov ebx, temp3
add esi, 4 
loop L2

mov eax, temp2
mul var
mov temp3, ebx 
pop ebx
add ebx, eax
push ebx
add edi, eax
mov ebx, temp3
add ebx, eax
mov eax, temp2
mov ecx, temp
loop L1
pop eax
mov esi, offset res1
jmp final

print:
mov edx, offset error2
call writeString
call crlf

final:
pop ebp
ret
SubMat endp


;-------------------------------------------------------
; Matrix Square
;-------------------------------------------------------
SquMat PROC 
push ebp
mov ebp, esp
mov ebx, esi
mov edi, 0
L1:
call crlf
mov temp, ecx
mov ecx, eax
mov temp2, eax
mov esi, 0

L2:
mov eax, [ebx+esi]
imul eax
mov res1[edi+esi], eax
add esi, 4 
loop L2

mov eax, temp2
push eax
mul var
add ebx, eax
add edi, eax
pop eax
mov ecx, temp
loop L1
mov esi, offset res1
pop ebp
ret
SquMat endp


;-------------------------------------------------------
; Matrix Cube
;-------------------------------------------------------
CubMat PROC 
push ebp
mov ebp, esp
mov ebx, esi
mov edi, 0
L1:
call crlf
mov temp, ecx
mov ecx, eax
mov temp2, eax
mov esi, 0

L2:
mov eax, [ebx+esi]
imul eax
mov edx, [ebx+esi]
imul edx
mov res1[edi+esi], eax
add esi, 4 
loop L2

mov eax, temp2
push eax
mul var
add ebx, eax
add edi, eax
pop eax
mov ecx, temp
loop L1
mov esi, offset res1
pop ebp
ret
CubMat endp


;-------------------------------------------------------
; Multplies the Matrix with an integer
;-------------------------------------------------------
ProMat PROC 
push ebp
mov ebp, esp
mov ebx, esi
mov edx, [ebp+8]
mov num1, edx
mov edi, 0
L1:
call crlf
mov temp, ecx
mov ecx, eax
mov temp2, eax
mov esi, 0

L2:
mov edx, 0
mov eax, [ebx+esi]
imul num1
mov res1[edi+esi], eax
add esi, 4 
loop L2

mov eax, temp2
push eax
mul var
add ebx, eax
add edi, eax
pop eax
mov ecx, temp
loop L1
 
mov esi, offset res1
pop ebp
ret
ProMat endp


;-------------------------------------------------------
; Divides the Matrix with an integer
;-------------------------------------------------------
DivMat PROC 
push ebp
mov ebp, esp
mov ebx, esi
mov edx, [ebp+8]
mov num1, edx
cmp edx, 0
je print

mov edi, 0
L1:
call crlf
mov temp, ecx
mov ecx, eax
mov temp2, eax
mov esi, 0

L2:
mov edx, 0
mov eax, [ebx+esi]
cdq
idiv num1
mov res1[edi+esi], eax
add esi, 4 
loop L2

mov eax, temp2
push eax
mul var
add ebx, eax
add edi, eax
pop eax
mov ecx, temp
loop L1
mov esi, offset res1
jmp final

print:
mov edx, offset error6
call writestring
call crlf

final:
pop ebp
ret
DivMat endp


;-------------------------------------------------------
; Finds the transpose of the matrix 
;-------------------------------------------------------
TransMat PROC 
push ebp
mov ebp, esp
mov ebx, esi
mov edi, 0
push eax
mul var
mov var2, eax
mov eax, ecx
mul var
mov var3, eax
pop eax 
push eax
push ecx

L1:
mov temp, ecx
mov ecx, eax
mov temp2, eax
mov esi, 0
mov edx, 0

L2:
mov eax, [ebx+esi]
mov res2[edx+edi], eax
add esi, 4 
add edx, var3
loop L2

add edi, 4
mov eax, temp2
add ebx, var2
mov ecx, temp
loop L1

mov esi, offset res2
pop eax
pop ecx
pop ebp
ret
TransMat endp


;-------------------------------------------------------
; Finds the determinant of a 2x2 matrix 
;-------------------------------------------------------
Det2Mat PROC 
push ebp
mov ebp, esp
cmp ecx, 2
je next
jmp print

next:
mov ebx, esi
mov esi, 0

mov eax, [ebx+esi]
add ebx, 4*2
add esi, 4
mov ecx, [ebx+esi]
mul ecx
push eax
mov esi, 0
mov  eax, [ebx+esi]
sub ebx, 4
mov ecx, [ebx+esi]
mul ecx
pop edx
sub eax, edx
neg eax
jmp final

print:
mov edx, offset error5
call writestring
call crlf

final:
pop ebp
ret
Det2Mat endp


;-------------------------------------------------------
; Finds the determinant of a 3x3 matrix 
;-------------------------------------------------------
Det3Mat PROC 
push ebp
mov ebp, esp
cmp ecx, 3
je next
jmp print

next:
mov ebx, esi
mov edx, esi
mov esi, 0
mov eax, [ebx+esi]
mov temp, eax
add edx, 16
sub edx, esi
mov ecx, 2
push esi
mov esi, 0

L3:
push ecx
mov edi, 0
mov ecx, 2

L4:
mov eax, [edx+edi]
mov dummy[esi], eax 
add esi, 4 
add edi, 4
loop L4

add edx, 12
pop ecx
loop L3

push ebx
mov ecx, 2
mov esi, offset dummy
INVOKE Det2Mat
imul temp
mov dummy2[0], eax

pop ebx
mov edx, ebx
pop esi
add esi, 4
mov eax, [ebx+esi]
mov temp, eax
add edx, 16
sub edx, esi
mov ecx, 2
push esi
mov esi, 0

LL3:
push ecx
mov edi, 0
mov ecx, 2

LL4:
mov eax, [edx+edi]
mov dummy[esi], eax 
add esi, 4 
add edi, 8
loop LL4

add edx, 12
pop ecx
loop LL3

push ebx
mov esi, offset dummy
mov ecx, 2
INVOKE Det2Mat
imul temp
mov dummy2[4], eax

pop ebx
mov edx, ebx
pop esi
add esi, 4
mov eax, [ebx+esi]
mov temp, eax
add edx, 16
sub edx, esi
mov ecx, 2
push esi
mov esi, 0
mov edi, 8
sub edi, 4

LLL3:
push ecx
mov ecx, 2

LLL4:
mov eax, [edx+edi]
mov dummy[esi], eax 
add esi, 4 
add edi, 4
loop LLL4

add edi, 4
pop ecx
loop LLL3

mov esi, offset dummy
mov ecx, 2
INVOKE Det2Mat
imul temp
pop esi
add eax, dummy2[0]
sub eax, dummy2[4]
jmp final

print:
mov edx, offset error5
call writestring
call crlf

final:
pop ebp
ret
Det3Mat endp


;-------------------------------------------------------
; Finds the adjoint of a 2x2 matrix and 3x3 matrix
;-------------------------------------------------------
AdjMat PROC 
push ebp
mov ebp, esp
cmp eax, ecx
jne print
cmp eax, 3
jne next
push eax
push ecx
INVOKE CoFacMat
pop ecx
pop eax
INVOKE TransMat
jmp final

next:
cmp eax, 2
jne print
mov edi, 0

mov eax, [esi]
mov tempM[edi+12], eax
mov eax, [esi+12]
mov tempM[edi], eax
mov eax, [esi+4]
neg eax
mov tempM[edi+4], eax
mov eax, [esi+8]
neg eax
mov tempM[edi+8], eax
mov esi, offset tempM
jmp final

print:
mov edx, offset error3
call writestring
call crlf

final:
pop ebp
ret
AdjMat endp

;-------------------------------------------------------
; Finds the inverse of a 2x2 matrix and a 3x3 matrix
;-------------------------------------------------------
InvMat PROC
push ebp
mov ebp, esp
cmp eax, ecx
jne print
push esi
push ecx
cmp ecx, 3
je next
cmp ecx, 2
jne print
INVOKE Det2Mat
jmp find
next:
INVOKE Det3Mat
find:
mov temp2, eax
cmp eax, 0
pop ecx
pop esi
je print

push ecx
push eax
mov eax, ecx
INVOKE AdjMat
mov ebx, esi

pop num1 ;our det
pop ecx
mov eax, ecx
mul ecx
mov ecx, eax
mov edi, 0
mov esi,0

L1:
mov edx, 0
mov eax, [ebx+esi]
cdq
idiv num1
mov tempM[edi], eax
add esi, 4
add edi, 4
loop L1
mov esi, offset tempM
jmp final

print:
mov edx, offset error4
call writestring
call crlf

final:
pop ebp
ret
InvMat endp

;-------------------------------------------------------
; Finds the product of two matrices
;-------------------------------------------------------
MulMat PROC
push ebp
mov ebp, esp
mov ecx, [ebp+16]
mov eax, [ebp+12]
cmp eax, ecx
je next
jmp print

next:
mov ebx, esi
mov eax, [ebp+20]
mov ecx, [ebp+8]
mul ecx
mov ecx, eax 
mov esi, 0
NL1:
mov dummy[esi], 0
add esi, 4
LOOP NL1

mov eax, [ebp+16] 
mul var
mov num2 , eax
mov eax, [ebp+8]
mul var
mov num1, eax
mov ecx, [ebp+20]
mov edx, edi

L1:
mov temp3, ecx
mov temp4, edx
mov ecx, [ebp+8]

L2:
;call crlf
mov temp, ecx
mov ecx, [ebp+12]
mov esi, 0
mov edi, 0

L3:
push ecx
mov eax, [ebx+esi]
mov ecx, [edx+edi]
push edx
mov edx, 0
imul ecx
pop edx
mov var2, esi 
mov esi, count
add dummy[esi], eax
mov esi, var2
add esi, 4 
add edi, num1
pop ecx
loop L3
 
add edx, 4
add count, 4
mov ecx, temp
loop L2

add ebx, num2
mov edx, temp4
mov ecx, temp3
LOOP L1

mov esi, offset dummy
jmp final

print:
mov edx, offset error2
call writeString
call crlf

final:
mov count, 0
mov ecx, [ebp+20]
mov eax, [ebp+8]

pop ebp
ret
MulMat endp

;-------------------------------------------------------
; Finds the cofactor of a 3x3 matrix and 2x2 matrix 
;-------------------------------------------------------
CoFacMat PROC
push ebp
mov ebp, esp
cmp ecx, 3
je next
cmp ecx, 2
jne print
push eax
push ecx
INVOKE AdjMat
pop ecx
pop eax
INVOKE TransMat
jmp final

next:
mov ebx, esi
mov edx, esi
mov esi, 0
add edx, 16
mov ecx, 2
push ecx

L1:
push ecx
mov edi, 0
mov ecx, 2

L2:
mov eax, [edx+edi]
mov dummy[esi], eax 
add esi, 4 
add edi, 4
loop L2

add edx, 12
pop ecx
loop L1

pop ecx
push ebx
mov esi, offset dummy
INVOKE Det2Mat
mov dummy2[0], eax

pop ebx
mov edx, ebx
mov temp, eax
add edx, 12
mov ecx, 2
mov esi, 0
push ecx

L3:
push ecx
mov edi, 0
mov ecx, 2

L4:
mov eax, [edx+edi]
mov dummy[esi], eax 
add esi, 4 
add edi, 8
loop L4

add edx, 12
pop ecx
loop L3

pop ecx
push ebx
mov esi, offset dummy
INVOKE Det2Mat
neg eax
mov dummy2[4], eax

pop ebx
mov edx, ebx
mov temp, eax
add edx, 8
mov ecx, 2
push ecx
mov esi, 0
mov edi, 4

L5:
push ecx
mov ecx, 2

L6:
mov eax, [edx+edi]
mov dummy[esi], eax 
add esi, 4 
add edi, 4
loop L6

add edi, 4
pop ecx
loop L5

pop ecx
push ebx
mov esi, offset dummy
INVOKE Det2Mat
mov dummy2[8], eax

pop ebx
mov edx, ebx
mov temp, eax
add edx, 4
mov ecx, 2
push ecx
mov esi, 0

L7:
push ecx
mov ecx, 2
mov edi, 0

L8:
mov eax, [edx+edi]
mov dummy[esi], eax 
add esi, 4 
add edi, 4
loop L8

add edx, 24
pop ecx
loop L7

pop ecx
push ebx
mov esi, offset dummy
INVOKE Det2Mat
neg eax
mov dummy2[12], eax

pop ebx
mov edx, ebx
mov temp, eax
mov ecx, 2
push ecx
mov esi, 0
mov edi, 0

NL1:
push ecx
mov ecx, 2

NL2:
mov eax, [edx+edi]
mov dummy[esi], eax 
add esi, 4 
add edi, 8
loop NL2

add edx, 8
pop ecx
loop NL1

pop ecx
push ebx
mov esi, offset dummy
INVOKE Det2Mat
mov dummy2[16], eax

pop ebx
mov edx, ebx
mov temp, eax
mov ecx, 2
push ecx
mov esi, 0

NL3:
push ecx
mov edi, 0
mov ecx, 2

NL4:
mov eax, [edx+edi]
mov dummy[esi], eax 
add esi, 4 
add edi, 4
loop NL4

add edx, 24
pop ecx
loop NL3

pop ecx
push ebx
mov esi, offset dummy
INVOKE Det2Mat
neg eax
mov dummy2[20], eax

pop ebx
mov edx, ebx
mov temp, eax
add edx, 4
mov ecx, 2
push ecx
mov esi, 0

NL5:
push ecx
mov ecx, 2
mov edi, 0

NL6:
mov eax, [edx+edi]
mov dummy[esi], eax 
add esi, 4 
add edi, 4
loop NL6

add edx, 12
pop ecx
loop NL5

pop ecx
push ebx
mov esi, offset dummy
INVOKE Det2Mat
mov dummy2[24], eax

pop ebx
mov edx, ebx
mov temp, eax
mov ecx, 2
push ecx
mov esi, 0
mov edi, 0

NL7:
push ecx
mov ecx, 2

NL8:
mov eax, [edx+edi]
mov dummy[esi], eax 
add esi, 4 
add edi, 8
loop NL8

sub edi, 4
pop ecx
loop NL7

pop ecx
push ebx
mov esi, offset dummy
INVOKE Det2Mat
neg eax
mov dummy2[28], eax

pop ebx
mov edx, ebx
mov temp, eax
mov ecx, 2
push ecx
mov esi, 0

NLL1:
push ecx
mov ecx, 2
mov edi, 0

NLL2:
mov eax, [edx+edi]
mov dummy[esi], eax 
add esi, 4 
add edi, 4
loop NLL2

add edx, 12
pop ecx
loop NLL1

pop ecx
mov esi, offset dummy
INVOKE Det2Mat
mov dummy2[32], eax

mov esi, offset dummy2
jmp final

print:
mov edx, offset error2
call writeString
call crlf

final:
pop ebp
ret
CoFacMat endp
END