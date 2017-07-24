global kcall
global kcall_asm_handler
extern kcall_handler

kcall:
    mov eax, [esp + 4] ; int code_call
    mov ebp, [esp + 8] ; void* args
    int 0x80
    ret ; return calue is in eax


kcall_asm_handler:
    ; Push every thing
    push 0 
    push 0 ; int_no & err_code

    pusha
    push ds 
    push es 
    push fs 
    push gs 
    mov ax, 0x10 ; Kernel data segment descriptor
    mov ds, ax 
    mov es, ax 
    mov fs, ax 
    mov gs, ax 
    mov eax, esp
    push eax ; push the stack

    call kcall_handler

    ; Pop everything
    add esp, 4 ; drop pushed stack
    pop gs
    pop fs
    pop es
    pop ds
    ; reverse popa without affecting eax
    pop edi
    pop esi
    pop ebp
    add esp, 4 ; drop pushed stack - bis
    pop ebx
    pop edx
    pop ecx
    add esp, 12     ; Cleans up the pushed error code and pushed ISR number + eax

    iret
