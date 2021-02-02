TITLE My First Program (main.asm)
INCLUDE MatLib32.inc

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

.code
main PROC
enter 0,0
mov edx, OFFSET msg3
mov edx, OFFSET msg3
call WriteString
call crlf
call SetMatA

mov edx, OFFSET msg3
call WriteString
call crlf
call SetMatB

mov esi, offset mat1
mov ecx, rowS1
mov eax, colS1
INVOKE DisplayMat

mov esi, offset mat2
mov ecx, rowS2
mov eax, colS2
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
call readint
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
call readint
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
end main