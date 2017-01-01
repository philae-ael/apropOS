[BITS 32]
global gdt_flush


; The GDT descriptor sctructure
gdtr:
    dw 0 ; limit
    dd 0 ; base

gdt_flush:
   mov eax, [esp+4]  ; Get the pointer to the GDT, passed as a parameter.
   mov [gdtr + 2], eax
   mov ax, [esp+8]   ; And his size
   mov [gdtr], ax
   lgdt [gdtr]        ; Load the new GDT pointer

   ; Now set the selectors with the good segments
    
   mov ax, 0x10      ; 0x10 is the offset in the GDT to our data segment
   mov ds, ax        ; Load all data segment selectors
   mov es, ax
   mov fs, ax
   mov gs, ax
   mov ss, ax
   jmp 0x08:flush   ; 0x08 is the offset to our code segment: Far jump!
flush:
   ret
