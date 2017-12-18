global _userland_jump

_userland_jump:

    cli
    mov eax, [esp + 0x4]
    mov cr3, eax ; load userland page_dir

    mov eax, [esp + 0x8]

    ; load userland data segment
    mov bx, 0x23 ; CPL = 3
    mov ds, bx
    mov es, bx
    mov fs, bx
    mov gs, bx

    ; hacking iret to get in ring3
    mov ebx, esp
    push 0x23 ; data segment again CPL = 3
    push ebx
    pushf
    
    pop ebx
    or ebx, 0x202
    push ebx

    push 0x1B ; code segment CPL=3
    push eax ; Where we go
    iret ; go and never never come back
