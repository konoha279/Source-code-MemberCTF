section .text
global _start
_start:
push 0x0a
mov eax,0x11111111
mov ebx, 0x6C73217B
xor ebx, eax
push ebx
inc eax
 
mov ebx, 0x3C752122
xor ebx, eax
push ebx
inc eax

mov ebx, 0x764E2274
xor ebx, eax
push ebx
inc eax

mov ebx, 0x7F227D78
xor ebx, eax
push ebx
inc eax

mov ebx, 0x25795238
xor ebx, eax
push ebx
inc eax

mov ebx, 0x6562517A
xor ebx, eax
push ebx
inc eax

mov ebx, 0x3C227943
xor ebx, eax
push ebx
inc eax

mov ebx, 0x6A57455B
xor ebx, eax
push ebx
inc eax

mov ebx, 0x63747374
xor ebx, eax
push ebx
inc eax

push 0x654d203a 
push 0x73692067 
push 0x00616c46

mov eax,4
mov ebx,1
mov ecx,esp
mov edx,50
int 0x80

mov eax,1
int 0x80