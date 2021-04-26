; .bss
num resb 64
temp resb 4


; .text:
push 0x0a203a74 
push 0x75706e49
mov eax,4
mov ebx,1
mov ecx, esp
mov edx, 8
int 0x80

mov eax,3
mov ebx,0
mov ecx,num
mov edx,5
int 0x80

push 0x203a746c 
push 0x75736552
mov eax,4
mov ebx,1
mov ecx, esp
mov edx, 8
int 0x80

mov edx,num
xor eax, eax

.atoi:
movzx ecx, byte[edx]
inc edx
cmp ecx, '0'
jb .next
cmp ecx, '9'
ja .next
sub ecx,'0'
imul eax,10
add eax, ecx
jmp .atoi

.next:
xor ecx, ecx
mov ecx, eax
xor eax,eax

.cal:
add eax,ecx
loop .cal

xor ecx,ecx
xor ebx,ebx
mov ebx,10

.cal2:
xor edx,edx
cmp eax,0
je .next2
div ebx
add edx,'0'
push edx
add ecx,4
jmp .cal2

.next2:
mov [temp],ecx

.output:
mov eax,4
mov ebx,1
mov ecx,esp
mov edx, [temp]
int 0x80

mov eax,1
int 0x80
