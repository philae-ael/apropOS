global irq0
global irq1
global irq2
global irq3
global irq4
global irq5
global irq6
global irq7
global irq8
global irq9
global irq10
global irq11
global irq12
global irq13
global irq14
global irq15

extern irq_handler

irq_common_handler:
    ; Push every thing
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

    ; Call the handler 
    mov eax, irq_handler
    call eax

    ; Pop everything
    pop eax
    pop gs
    pop fs
    pop es
    pop ds
    popa
    add esp, 8     ; Cleans up the pushed error code and pushed ISR number

    ; And return 
    iret


irq0:
    cli ; disable interuptions
    push byte 0 ; dummy error code
    push byte 0 ; irq number
    jmp irq_common_handler


irq1:
    cli ; disable interuptions
    push byte 0 ; dummy error code
    push byte 1 ; irq number
    jmp irq_common_handler


irq2:
    cli ; disable interuptions
    push byte 0 ; dummy error code
    push byte 2 ; irq number
    jmp irq_common_handler


irq3:
    cli ; disable interuptions
    push byte 0 ; dummy error code
    push byte 3 ; irq number
    jmp irq_common_handler


irq4:
    cli ; disable interuptions
    push byte 0 ; dummy error code
    push byte 4 ; irq number
    jmp irq_common_handler


irq5:
    cli ; disable interuptions
    push byte 0 ; dummy error code
    push byte 5 ; irq number
    jmp irq_common_handler


irq6:
    cli ; disable interuptions
    push byte 0 ; dummy error code
    push byte 6 ; irq number
    jmp irq_common_handler


irq7:
    cli ; disable interuptions
    push byte 0 ; dummy error code
    push byte 7 ; irq number
    jmp irq_common_handler


irq8:
    cli ; disable interuptions
    push byte 0 ; dummy error code
    push byte 8 ; irq number
    jmp irq_common_handler


irq9:
    cli ; disable interuptions
    push byte 0 ; dummy error code
    push byte 9 ; irq number
    jmp irq_common_handler


irq10:
    cli ; disable interuptions
    push byte 0 ; dummy error code
    push byte 10 ; irq number
    jmp irq_common_handler


irq11:
    cli ; disable interuptions
    push byte 0 ; dummy error code
    push byte 11 ; irq number
    jmp irq_common_handler


irq12:
    cli ; disable interuptions
    push byte 0 ; dummy error code
    push byte 12 ; irq number
    jmp irq_common_handler


irq13:
    cli ; disable interuptions
    push byte 0; dummy error code
    push byte 13 ; irq number
    jmp irq_common_handler


irq14:
    cli ; disable interuptions
    push byte 0 ; dummy error code
    push byte 14 ; irq number
    jmp irq_common_handler


irq15:
    cli ; disable interuptions
    push byte 0 ; dummy error code
    push byte 15 ; irq number
    jmp irq_common_handler
