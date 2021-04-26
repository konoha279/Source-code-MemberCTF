section .text
global _start
_start:
push 0xa
push 0x7d67616c 
push 0x665f656b 
push 0x2d616870 
push 0x7b465443 
push 0x7265626d 
push 0x654d203a 
push 0x73692067 
push 0x616c4620 
push 0x656b2d61 
push 0x6850

mov eax,4
mov ebx,1
mov ecx, esp
mov edx, 41
int 0x80

mov eax,1
int 0x80

