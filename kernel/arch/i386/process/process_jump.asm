global process_jump

process_jump:
    cli
    mov ebp, esp
    mov eax, [ebp + 0x8]
    mov cr3, eax ; load userland page_dir

    mov eax, [ebp + 0x4]

    ; load userland data segment
    mov bx, 0x23 ; CPL = 3
    mov ds, bx
    mov es, bx
    mov fs, bx
    mov gs, bx

    push 0x23 ; data segment CPL = 3
    mov ebx, [ebp + 0xC]
    push ebx ; set stack
    pushf

    pop ebx
    or ebx, 0x202 ; enable interupts when far-jumping (setting eflags)
    push ebx

    push 0x1B ; code segment CPL=3
    push eax; Where we go
    iret ; go and never never come back
