TITLE coal final project
INCLUDE Irvine32.inc
INCLUDE MatLib32.inc

.data
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
msg9 BYTE "   ",0
error1 BYTE "Invalid Size! Enter again",0
error2 BYTE "Size of the matices donot match!",0
error3 BYTE "Adjoint of the matix is not possible!",0
error4 BYTE "Inverse of the matix does not exist!",0
error5 BYTE "Invalid Size!",0

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
END