TITLE My First Program (Test.asm)
INCLUDE Irvine32.inc

.data 
count DWORD ?
tempM SDWORD 10 dup(?)
mat1 SDWORD 10 dup(?)
mat2 SDWORD 10 dup(?)
res1 SDWORD 10 dup(?)
res2 SDWORD 10 dup(?)
dummy SDWORD 10 dup(?)
dummy2 SDWORD 10 dup(?)
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
rowS1 DWORD ?
colS1 DWORD ?
rowS2 DWORD ?
colS2 DWORD ?
rowS3 DWORD ?
colS3 DWORD ?
msg1 BYTE "Enter row size : ",0
msg2 BYTE "Enter column size : ",0
msg3 BYTE "Setting a matrix...",0
msg4 BYTE "Enter the elements row ",0
msg5 BYTE "Enter the elemnets in matrix A : ",0
msg6 BYTE "Enter the in matrix B : ",0
msg7 BYTE "SUM : ",0
msg8 BYTE " : ",0
msg9 BYTE "   ",0
msg10 BYTE "Sum of Two Matrices : ",0
msg11 BYTE "Sub of Two Matrices : ",0
msg12 BYTE "Square of the matrix : ",0
msg13 BYTE "Cube of the matrix : ",0
msg14 BYTE "Enter the number that you want to multiply the matrix with : ",0
msg15 BYTE "Matrix after multiplying with ",0
msg16 BYTE "Enter the number that you want to divide the matrix with: ",0
msg17 BYTE "Matrix after dividing with ",0
msg18 BYTE "Transpose of the matrix : ",0
msg19 BYTE "Determinant of the matrix : ",0
msg20 BYTE "Adjoint of the matrix : ",0
error1 BYTE "Invalid Size! Enter again",0
error2 BYTE "Size of the matices donot match!",0
error3 BYTE "Adjoint of the matix is not possible!",0
error4 BYTE "Inverse of the matix does not exist!",0

;----------------------------------------
; Procedure Prototypes
;----------------------------------------
DivMat PROTO
ProMat PROTO
CubMat PROTO
SquMat PROTO
SumMat PROTO
SubMat PROTO 
SetMatA PROTO
SetMatB PROTO
TransMat PROTO
Det2Mat PROTO
Det3Mat PROTO
MulMat PROTO
InvMat PROTO
CoFacMat PROTO
AdjMat PROTO
DisplayMat PROTO

;----------------------------------------
; main
;----------------------------------------
.code
main PROC
enter 0,0
mov edx, OFFSET msg3
mov edx, OFFSET msg3
call WriteString
call crlf
INVOKE SetMatA

mov edx, OFFSET msg3
call WriteString
call crlf
INVOKE SetMatB

mov esi, offset mat1
mov ecx, rowS1
mov eax, colS1
INVOKE DisplayMat

mov esi, offset mat2
mov ecx, rowS2
mov eax, colS2
INVOKE DisplayMat

mov esi, offset mat1
;;mov edi, offset mat2
;push rowS1
;push colS1
;push rowS2
;push colS2
;INVOKE MulMat

mov ecx, rowS1
mov eax, colS1
INVOKE CoFacMat

mov ecx, rowS1
mov eax, colS1
mul ecx
mov ecx, eax
mov edi, offset tempM
cld
rep movsd 

mov esi, offset tempM
mov ecx, rowS1
mov eax, colS1
INVOKE DisplayMat
call crlf
leave 
ret
exit
main ENDP

;-------------------------------------------------------
; sets Matrix A
;-------------------------------------------------------
SetMatA PROC
push ebp
mov ebp, esp

top1:
mov edx, OFFSET msg1
call WriteString
call readdec
cmp eax, 0
jle top1
mov rowS1, eax 

top2:
mov edx, OFFSET msg2
call WriteString
call readdec
cmp eax, 0
jle top2
mov colS1, eax 
mov ecx, rowS1
mov eax, 0
mov ebx, 0

L1:
inc eax
mov edx, offset msg4
call writeString
call writedec
push eax
mov edx, offset msg8
call writeString
push ecx
mov ecx, colS1
mov esi, 0

L2:
call readdec
mov mat1[ebx+esi],eax
add esi, 4
loop L2

call crlf
mov eax, colS1
mul var
add ebx, eax
pop ecx
pop eax
loop L1

pop ebp 
ret
SetMatA endp


;-------------------------------------------------------
; sets Matrix B
;-------------------------------------------------------
SetMatB PROC
push ebp
mov ebp, esp

top1:
mov edx, OFFSET msg1
call WriteString
call readdec
cmp eax, 0
jle top1
mov rowS2, eax 

top2:
mov edx, OFFSET msg2
call WriteString
call readdec
cmp eax, 0
jle top2
mov colS2, eax 

mov ecx, rowS2
mov eax, 0
mov ebx, 0

L1:
inc eax
mov edx, offset msg4
call writeString
call writedec
push eax
mov edx, offset msg8
call writeString
push ecx
mov ecx, colS2
mov esi, 0

L2:
call readdec
mov mat2[ebx+esi],eax
add esi, 4
loop L2

call crlf
mov eax, colS2
mul var
add ebx, eax
pop ecx
pop eax
loop L1

pop ebp 
ret
SetMatB endp


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
;mov num1, [ebp+8]
mov edi, 0
L1:
call crlf
mov temp, ecx
mov ecx, eax
mov temp2, eax
mov esi, 0

L2:
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
;mov num1, [ebp+8]
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
idiv num2
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
jne print
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
mov edx, offset error3
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
cmp eax, 2
jne print

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
INVOKE Det2Mat
imul temp
pop esi
add eax, dummy2[0]
sub eax, dummy2[4]
jmp final

print:
mov edx, offset error3
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
push ecx
INVOKE TransMat
pop ecx
mov eax, ecx
mul var
mov temp2, eax
push esi
mov ebx, esi

mov eax, [esi]
push eax
mov eax, [esi+12]
mov [esi], eax
pop eax
mov [esi+12], eax
mov esi, 0

L1:
mov eax, [ebx+esi]
neg eax
mov [ebx+esi], eax
add esi, temp2
add esi, 4
loop L1
pop esi
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
cmp eax, 0
je print

pop ecx
pop esi
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
mov edx, offset error3
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
mov eax ,ecx
je next
jmp print
next:
mov ecx, [ebp+20]
mul var
mov num2 , eax
mov eax, [ebp+8]
push ecx
push eax
mul var
mov num1, eax
pop eax
push eax
mov ebx, esi
mov edx, edi

L1:
mov temp3, ecx
mov temp4, edx
mov ecx, [ebp+8]

L2:
call crlf
mov temp, ecx
mov ecx, [ebp+12]
mov esi, 0
mov edi, 0

L3:
push ecx
mov eax, [ebx+esi]
mov ecx, [edx+edi]
push edx
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
pop eax
pop ecx 
pop ebp
ret
MulMat endp

;-------------------------------------------------------
; Finds the cofactor of a 3x3 matrix and 2x2 matrix 
;-------------------------------------------------------
CoFacMat PROC
push ebp
mov ebp, esp
cmp eax, ecx
jne print
cmp eax, 3
jmp next
cmp eax, 2
jne print
INVOKE AdjMat
jmp final

next:
mov ebx, esi
mov edx, esi
mov esi, 0
add edx, 16
mov ecx, 2

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

push ebx
mov esi, offset dummy
INVOKE Det2Mat
mov dummy2[8], eax

pop ebx
mov edx, ebx
mov temp, eax
add edx, 4
mov ecx, 2
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

push ebx
mov esi, offset dummy
INVOKE Det2Mat
neg eax
mov dummy2[12], eax

pop ebx
mov edx, ebx
mov temp, eax
mov ecx, 2
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

push ebx
mov esi, offset dummy
INVOKE Det2Mat
mov dummy2[16], eax

pop ebx
mov edx, ebx
mov temp, eax
mov ecx, 2
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

push ebx
mov esi, offset dummy
INVOKE Det2Mat
mov dummy2[24], eax

pop ebx
mov edx, ebx
mov temp, eax
mov ecx, 2
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

push ebx
mov esi, offset dummy
INVOKE Det2Mat
neg eax
mov dummy2[28], eax

pop ebx
mov edx, ebx
mov temp, eax
mov ecx, 2
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
end main