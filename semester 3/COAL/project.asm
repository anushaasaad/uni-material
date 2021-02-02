TITLE My First Program (main.asm)
INCLUDE Irvine32.inc
INCLUDE MatLib32.inc

.data 
choice DWORD ? 
var DWORD 4
tempM SDWORD 10 dup(?)
mat1 SDWORD 10 dup(?)
mat2 SDWORD 10 dup(?)
det SDWORD ?
rowS1 DWORD ?
colS1 DWORD ?
rowS2 DWORD ?
colS2 DWORD ?
rowS3 DWORD ?
colS3 DWORD ?
str0 BYTE "---------------------------------MATRIX CALCULATOR-------------------------------",0
msg BYTE "Enter your choice : ",0
str1 BYTE "1. Set Matrix A",0
str2 BYTE "2. Set Matrix B",0
str3 BYTE "3. Find Transpose of A",0
str4 BYTE "4. Find Transpose of B",0
str5 BYTE "5. Find Determinant of A",0
str6 BYTE "6. Find Determinant of B",0 
str7 BYTE "7. Find A+B",0 
str8 BYTE "8. Find A-B",0
str9 BYTE "9. Find AxB",0
str10 BYTE "10. Find CoFactors of A",0
str11 BYTE "11. Find CoFactors of B",0
str12 BYTE "12. Find Adjoint of A",0
str13 BYTE "13. Find Adjoint of B",0
str14 BYTE "14. Find Inverse of A",0
str15 BYTE "15. Find Inverse of B",0
str16 BYTE "16. Find Square of A",0
str17 BYTE "17. Find Square of B",0
str18 BYTE "18. Find Cube of A",0
str19 BYTE "19. Find Cube of B",0
str20 BYTE "20. Multiply Matrix A with an Integer",0
str21 BYTE "21. Multiply Matrix B with an Integer",0
str22 BYTE "22. Divide Matrix A with an Integer",0
str23 BYTE "23. Divide Matrix B with an Integer",0
str24 BYTE "24. Display Matrix A",0
str25 BYTE "25. Display Matrix B",0
str26 BYTE "Do you want to display the result? (1=yes) : ",0
str27 BYTE "Do you want to go back to the main menu? (1=yes) : ",0
str28 BYTE "26. Exit",0
error BYTE "Invalid choice! Enter your choice again : ",0
newM BYTE "Find determinant of 2x2 matrix (1) or 3x3 matrix (2) : ",0

msg1 BYTE "Enter row size : ",0
msg2 BYTE "Enter column size : ",0
msg4 BYTE "Enter the elements row ",0
msg8 BYTE " : ",0
msg9 BYTE "   ",0
msg14 BYTE "Enter the number that you want to multiply the matrix with : ",0
msg16 BYTE "Enter the number that you want to divide the matrix with: ",0
msg19 BYTE "Determinant of the matrix : ",0
error1 BYTE "Invalid Size! Enter again",0

;----------------------------------------
; Procedure Prototypes
;----------------------------------------
SetMatA PROTO
SetMatB PROTO

.code
;----------------------------------------
; main
;----------------------------------------
.code
main PROC
enter 0,0
top:
mov edx, OFFSET str0
call WriteString
call crlf
mov edx, OFFSET str1
call WriteString
call crlf
mov edx, OFFSET str2
call WriteString
call crlf
mov edx, OFFSET str3
call WriteString
call crlf
mov edx, OFFSET str4
call WriteString
call crlf
mov edx, OFFSET str5
call WriteString
call crlf
mov edx, OFFSET str6
call WriteString
call crlf
mov edx, OFFSET str7
call WriteString
call crlf
mov edx, OFFSET str8
call WriteString
call crlf
mov edx, OFFSET str9
call WriteString
call crlf
mov edx, OFFSET str10
call WriteString
call crlf
mov edx, OFFSET str11
call WriteString
call crlf
mov edx, OFFSET str12
call WriteString
call crlf
mov edx, OFFSET str13
call WriteString
call crlf
mov edx, OFFSET str14
call WriteString
call crlf
mov edx, OFFSET str15
call WriteString
call crlf
mov edx, OFFSET str16
call WriteString
call crlf
mov edx, OFFSET str17
call WriteString
call crlf
mov edx, OFFSET str18
call WriteString
call crlf
mov edx, OFFSET str19
call WriteString
call crlf
mov edx, OFFSET str20
call WriteString
call crlf
mov edx, OFFSET str21
call WriteString
call crlf
mov edx, OFFSET str22
call WriteString
call crlf
mov edx, OFFSET str23
call WriteString
call crlf
mov edx, OFFSET str24
call WriteString
call crlf
mov edx, OFFSET str25
call WriteString
call crlf
mov edx, OFFSET str28
call WriteString
call crlf
mov edx, OFFSET msg
call WriteString
call readdec
call clrscr
mov choice, eax
cmp eax, 1
je ch1
cmp eax, 2
je ch2
cmp eax, 3
je ch3
cmp eax, 4
je ch4
cmp eax, 5
je ch5
cmp eax, 6
je ch6
cmp eax, 7
je ch7
cmp eax, 8
je ch8
cmp eax, 9
je ch9
cmp eax, 10
je ch10
cmp eax, 11
je ch11
cmp eax, 12
je ch12
cmp eax, 13
je ch13
cmp eax, 14
je ch14
cmp eax, 15
je ch15
cmp eax, 16
je ch16
cmp eax, 17
je ch17
cmp eax, 18
je ch18
cmp eax, 19
je ch19
cmp eax, 20
je ch20
cmp eax, 21
je ch21
cmp eax, 22
je ch22
cmp eax, 23
je ch23
cmp eax, 24
je ch24
cmp eax, 25
je ch25
cmp eax, 26
je final
jmp last

ch25:
mov ecx, rowS2
mov eax, colS2
mov esi, offset mat2
INVOKE DisplayMat
jmp ask

ch24:
mov ecx, rowS1
mov eax, colS1
mov esi, offset mat1
INVOKE DisplayMat
jmp ask

ch23:
mov edx, offset msg16
call writestring
call readint
push eax
mov ecx, rowS2
mov eax, colS2
mov esi, offset mat2
INVOKE DivMat
mov ecx, rowS2
mov eax, colS2
mul ecx
mov ecx, eax
mov edi, offset tempM
cld
rep movsd 
mov ecx, rowS2
mov eax, colS2
mov esi, offset tempM
jmp disA

ch22:
mov edx, offset msg16
call writestring
call readint
push eax
mov ecx, rowS1
mov eax, colS1
mov esi, offset mat1
INVOKE DivMat
mov ecx, rowS1
mov eax, colS1
mul ecx
mov ecx, eax
mov edi, offset tempM
cld
rep movsd 
mov ecx, rowS1
mov eax, colS1
mov esi, offset tempM
jmp disA

ch21:
mov edx, offset msg14
call writestring
call writeint
push eax
mov ecx, rowS2
mov eax, colS2
mov esi, offset mat2
INVOKE ProMat
mov ecx, rowS2
mov eax, colS2
mul ecx
mov ecx, eax
mov edi, offset tempM
cld
rep movsd 
mov ecx, rowS2
mov eax, colS2
mov esi, offset tempM
jmp disA

ch20:
mov edx, offset msg14
call writestring
call readint
push eax
mov ecx, rowS1
mov eax, colS1
mov esi, offset mat1
INVOKE ProMat
mov ecx, rowS1
mov eax, colS1
mul ecx
mov ecx, eax
mov edi, offset tempM
cld
rep movsd 
mov ecx, rowS1
mov eax, colS1
mov esi, offset tempM
jmp disA

ch19:
mov ecx, rowS2
mov eax, colS2
mov esi, offset mat2
INVOKE CubMat
mov ecx, rowS2
mov eax, colS2
mul ecx
mov ecx, eax
mov edi, offset tempM
cld
rep movsd 
mov ecx, rowS2
mov eax, colS2
mov esi, offset tempM
jmp disA

ch18:
mov ecx, rowS1
mov eax, colS1
mov esi, offset mat1
INVOKE CubMat
mov ecx, rowS1
mov eax, colS1
mul ecx
mov ecx, eax
mov edi, offset tempM
cld
rep movsd 
mov ecx, rowS1
mov eax, colS1
mov esi, offset tempM
jmp disA

ch17:
mov ecx, rowS2
mov eax, colS2
mov esi, offset mat2
INVOKE SquMat
mov ecx, rowS2
mov eax, colS2
mul ecx
mov ecx, eax
mov edi, offset tempM
cld
rep movsd 
mov ecx, rowS2
mov eax, colS2
mov esi, offset tempM
jmp disA

ch16:
mov ecx, rowS1
mov eax, colS1
mov esi, offset mat1
INVOKE SquMat
mov ecx, rowS1
mov eax, colS1
mul ecx
mov ecx, eax
mov edi, offset tempM
cld
rep movsd 
mov ecx, rowS1
mov eax, colS1
mov esi, offset tempM
jmp disA

ch15:
mov ecx, rowS2
mov eax, colS2
mov esi, offset mat2
INVOKE InvMat
mov ecx, rowS2
mov eax, colS2
mul ecx
mov ecx, eax
mov edi, offset tempM
cld
rep movsd 
mov ecx, rowS2
mov eax, colS2
mov esi, offset tempM
jmp disA

ch14:
mov ecx, rowS1
mov eax, colS1
mov esi, offset mat1
INVOKE InvMat
mov ecx, rowS1
mov eax, colS1
mul ecx
mov ecx, eax
mov edi, offset tempM
cld
rep movsd 
mov ecx, rowS1
mov eax, colS1
mov esi, offset tempM
jmp disA

ch13:
mov ecx, rowS2
mov eax, colS2
mov esi, offset mat2
INVOKE AdjMat
mov ecx, rowS2
mov eax, colS2
mul ecx
mov ecx, eax
mov edi, offset tempM
cld
rep movsd 
mov ecx, rowS2
mov eax, colS2
mov esi, offset tempM
jmp disA

ch12:
mov ecx, rowS1
mov eax, colS1
mov esi, offset mat1
INVOKE AdjMat
mov ecx, rowS1
mov eax, colS1
mul ecx
mov ecx, eax
mov edi, offset tempM
cld
rep movsd 
mov ecx, rowS1
mov eax, colS1
mov esi, offset tempM
jmp disA

ch11:
mov ecx, rowS2
mov eax, colS2
mov esi, offset mat2
INVOKE CoFacMat
mov ecx, rowS2
mov eax, colS2
mul ecx
mov ecx, eax
mov edi, offset tempM
cld
rep movsd 
mov ecx, rowS2
mov eax, colS2
mov esi, offset tempM
jmp disA

ch10:
mov ecx, rowS1
mov eax, colS1
mov esi, offset mat1
INVOKE CoFacMat
mov ecx, rowS1
mov eax, colS1
mul ecx
mov ecx, eax
mov edi, offset tempM
cld
rep movsd 
mov ecx, rowS1
mov eax, colS1
mov esi, offset tempM
jmp disA

ch9:
mov esi, offset mat1
mov edi, offset mat2
push rowS1
push colS1
push rowS2
push colS2
INVOKE MulMat
mov rowS3, ecx
mov colS3, eax
mul ecx
mov ecx, eax
mov edi, offset tempM
cld
rep movsd 
mov ecx, rowS3
mov eax, colS3
mov esi, offset tempM
jmp disA

ch8:
mov esi, offset mat1
mov edi, offset mat2
push rowS1
push colS1
push rowS2
push colS2
INVOKE SubMat
mov ecx, rowS2
mov eax, colS2
mul ecx
mov ecx, eax
mov edi, offset tempM
cld
rep movsd 
mov ecx, rowS2
mov eax, colS2
mov esi, offset tempM
jmp disA

ch7:
mov esi, offset mat1
mov edi, offset mat2
push rowS1
push colS1
push rowS2
push colS2
INVOKE SumMat
mov ecx, rowS1
mov eax, colS1
mul ecx
mov ecx, eax
mov edi, offset tempM
cld
rep movsd 
mov ecx, rowS1
mov eax, colS1
mov esi, offset tempM
jmp disA

ch6:
mov edx, OFFSET newM
call WriteString
call readdec
mov choice, eax
cmp eax, 1
je S1
cmp eax, 2
je S2
jmp ch6
S1:
mov ecx, rowS2
mov esi, offset mat2
INVOKE Det2Mat
mov det, eax
mov edx, OFFSET msg19
call WriteString
call writeint
call crlf
jmp ask

S2:
mov ecx, rowS2
mov esi, offset mat2
INVOKE Det3Mat
mov det, eax
mov edx, OFFSET msg19
call WriteString
call writeint
call crlf
jmp ask


ch5:
mov edx, OFFSET newM
call WriteString
call readdec
mov choice, eax
cmp eax, 1
je SS1
cmp eax, 2
je SS2
jmp ch6
SS1:
mov ecx, rowS1
mov esi, offset mat1
INVOKE Det2Mat
mov det, eax
mov edx, OFFSET msg19
call WriteString
call writeint
call crlf
jmp ask

SS2:
mov ecx, rowS1
mov esi, offset mat1
INVOKE Det3Mat
mov det, eax
mov edx, OFFSET msg19
call WriteString
call writeint
call crlf
jmp ask


ch4:
mov ecx, rowS2
mov eax, colS2
mov esi, offset mat2
INVOKE TransMat
mov rowS3, ecx
mov colS3, eax
mul ecx
mov ecx, eax
mov edi, offset tempM
cld
rep movsd 
mov ecx, rowS3
mov eax, colS3
mov esi, offset tempM
jmp disA

ch3:
mov ecx, rowS1
mov eax, colS1
mov esi, offset mat1
INVOKE TransMat
mov rowS3, ecx
mov colS3, eax
mul ecx
mov ecx, eax
mov edi, offset tempM
cld
rep movsd 
mov ecx, rowS3
mov eax, colS3
mov esi, offset tempM
jmp disA

ch2:
INVOKE SetMatB
jmp ask

ch1:
INVOKE SetMatA
jmp ask

disA:
push eax
mov edx, offset str26
call WriteString
call readdec
mov choice, eax
cmp eax, 1
pop eax
jne new3
INVOKE DisplayMat
new3:
jmp ask

ask:
mov edx, OFFSET str27
call WriteString
call readdec
mov choice, eax
cmp eax, 1
jne final
call clrscr
jmp top

last:
mov edx, offset error
call writestring
call crlf
jmp top

final:
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
