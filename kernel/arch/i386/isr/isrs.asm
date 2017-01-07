section .text
global isr0
global isr1
global isr2
global isr3
global isr4
global isr5
global isr6
global isr7
global isr8
global isr9
global isr10
global isr11
global isr12
global isr13
global isr14
global isr15
global isr16
global isr17
global isr18
global isr19
global isr20
global isr21
global isr22
global isr23
global isr24
global isr25
global isr26
global isr27
global isr28
global isr29
global isr30
global isr31

extern isr_handler

isr_common_handler:
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
    mov eax, isr_handler
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

; Divide by 0 exception
isr0:
    cli ; disable interuptions
    push byte 0 ; dummy error code
    push byte 0 ; isr number
    jmp isr_common_handler

; Debug exception
isr1:
    cli ; disable interuptions
    push byte 0 ; dummy error code
    push byte 1 ; isr number
    jmp isr_common_handler

; Non Maskable Interrupt Exception
isr2:
    cli ; disable interuptions
    push byte 0 ; dummy error code
    push byte 2 ; isr number
    jmp isr_common_handler

; Breakpoint Exception
isr3:
    cli ; disable interuptions
    push byte 0 ; dummy error code
    push byte 3 ; isr number
    jmp isr_common_handler

; Into Detected Overflow Exception
isr4:
    cli ; disable interuptions
    push byte 0 ; dummy error code
    push byte 4 ; isr number
    jmp isr_common_handler

; Out of Bounds Exception
isr5:
    cli ; disable interuptions
    push byte 0 ; dummy error code
    push byte 5 ; isr number
    jmp isr_common_handler

; Invalid Opcode Exception
isr6:
    cli ; disable interuptions
    push byte 0 ; dummy error code
    push byte 6 ; isr number
    jmp isr_common_handler

; No Coprocessor Exception 
isr7:
    cli ; disable interuptions
    push byte 0 ; dummy error code
    push byte 7 ; isr number
    jmp isr_common_handler

; Double Fault Exception
isr8:
    cli ; disable interuptions
    ; NO dummy error code
    push byte 8 ; isr number
    jmp isr_common_handler

; Coprocessor Segment Overrun Exception
isr9:
    cli ; disable interuptions
    push byte 0 ; dummy error code
    push byte 9 ; isr number
    jmp isr_common_handler

; Bad TSS Exception
isr10:
    cli ; disable interuptions
    ; NO dummy error code
    push byte 0 ; dummy error code
    push byte 10 ; isr number
    jmp isr_common_handler

; Segment Not Present Exception
isr11:
    cli ; disable interuptions
    ; NO dummy error code
    push byte 11 ; isr number
    jmp isr_common_handler

; Stack Fault Exception
isr12:
    cli ; disable interuptions
    ; NO dummy error code
    push byte 12 ; isr number
    jmp isr_common_handler

; General Protection Fault Exception
isr13:
    cli ; disable interuptions
    ; NO dummy error code
    push byte 13 ; isr number
    jmp isr_common_handler

; Page Fault Exception
isr14:
    cli ; disable interuptions
    ; NO dummy error code
    push byte 14 ; isr number
    jmp isr_common_handler

; Unknown Interrupt Exception
isr15:
    cli ; disable interuptions
    push byte 0 ; dummy error code
    push byte 15 ; isr number
    jmp isr_common_handler

; Coprocessor Fault Exception
isr16:
    cli ; disable interuptions
    push byte 0 ; dummy error code
    push byte 16 ; isr number
    jmp isr_common_handler

; Alignment Check Exception (486+)
isr17:
    cli ; disable interuptions
    push byte 0 ; dummy error code
    push byte 17 ; isr number
    jmp isr_common_handler

; Machine Check Exception (Pentium/586+)
isr18:
    cli ; disable interuptions
    push byte 0 ; dummy error code
    push byte 18 ; isr number
    jmp isr_common_handler

; Reserved Exceptions
isr19:
    cli ; disable interuptions
    push byte 0 ; dummy error code
    push byte 19 ; isr number
    jmp isr_common_handler

isr20:
    cli ; disable interuptions
    push byte 0 ; dummy error code
    push byte 20 ; isr number
    jmp isr_common_handler

isr21:
    cli ; disable interuptions
    push byte 0 ; dummy error code
    push byte 21 ; isr number
    jmp isr_common_handler

isr22:
    cli ; disable interuptions
    push byte 0 ; dummy error code
    push byte 22 ; isr number
    jmp isr_common_handler

isr23:
    cli ; disable interuptions
    push byte 0 ; dummy error code
    push byte 23 ; isr number
    jmp isr_common_handler

isr24:
    cli ; disable interuptions
    push byte 0 ; dummy error code
    push byte 24 ; isr number
    jmp isr_common_handler

isr25:
    cli ; disable interuptions
    push byte 0 ; dummy error code
    push byte 25 ; isr number
    jmp isr_common_handler

isr26:
    cli ; disable interuptions
    push byte 0 ; dummy error code
    push byte 26 ; isr number
    jmp isr_common_handler

isr27:
    cli ; disable interuptions
    push byte 0 ; dummy error code
    push byte 27 ; isr number
    jmp isr_common_handler

isr28:
    cli ; disable interuptions
    push byte 0 ; dummy error code
    push byte 28 ; isr number
    jmp isr_common_handler

isr29:
    cli ; disable interuptions
    push byte 0 ; dummy error code
    push byte 29 ; isr number
    jmp isr_common_handler

isr30:
    cli ; disable interuptions
    push byte 0 ; dummy error code
    push byte 30 ; isr number
    jmp isr_common_handler

isr31:
    cli ; disable interuptions
    push byte 0 ; dummy error code
    push byte 31 ; isr number
    jmp isr_common_handler
