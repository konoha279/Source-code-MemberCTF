; .data
msg db "Hello, Format flag is: MemberCTF{}",0xa,"Real flag is: "
length equ $-msg
flag db "M0d1fY_t3xt_!!__0x19923",0xa
lengthFlag equ $-flag
FakeFlag db "Pha_ke_flag_0x41520",0xa
lengthFakeFlag equ $-FakeFlag

; .text
mov eax, 4
mov ecx, msg
mov ebx, 1
mov edx, length
int 0x80

xor eax, eax
xor ebx, ebx
xor ecx, ecx
xor edx, edx

mov eax, flag
mov ebx, FakeFlag
add eax, 16
add ebx, 12

edit:
movzx edx, byte[ebx]

cmp edx, 'a'
jb .next
cmp edx, 'z'
ja .end
jmp .do

.next:
cmp edx, 'A'
jb .next2
cmp edx, 'Z'
ja .end
jmp .do

.next2:
cmp edx, '0'
jb .end
cmp edx, '9'
ja .end
jmp .do

.do:
mov [eax], dl
inc eax
inc ebx
jmp edit

xor eax, eax

.end:
mov eax,1
int 0x80



























































































must not compile