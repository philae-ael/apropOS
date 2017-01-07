global idt_load:function
idtr:
    dw 0 ; size
    dd 0 ; idt
idt_load: ; void idt_load(struct idt, size_t idt_size)
    mov eax, [esp + 4]  ; get Size
    mov [idtr + 2], eax ; fill idtr.size with it
    mov ax, [esp + 8]   ; get idt
    mov [idtr], ax     ; fill idtr.idt with it

    lidt [idtr]         ; Ask the CPU to use the idt

    ret
