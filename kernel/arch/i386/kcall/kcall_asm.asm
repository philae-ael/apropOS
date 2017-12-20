global kcall
global kcall_asm_handler
extern _kcall_handler

kcall:
    push ebp
    mov ebp, esp

    ; CDECL need those not to be modified, so let's save them
    mov eax, [esp + 0x8] ; int code_call
    mov edx, [esp + 0xC] ; void* args
    int 0x80


    pop ebp
    ret ; return calue is in eax


kcall_asm_handler:
    ; Some fields are already pushed by CPU
    push byte 0   ; err_no
    push eax ; eax is int_no

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

    push edx ; push args
    push eax ; push the stack

    mov eax, _kcall_handler
    call eax

    ; Pop args
    pop eax
    pop edx

    ; restore state
    pop gs
    pop fs
    pop es
    pop ds
    popa

    pop eax
    pop eax

    ; And return
    iret
