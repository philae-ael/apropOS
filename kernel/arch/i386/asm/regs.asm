global write_cr0
global read_cr0
global write_cr3
global read_cr3

write_cr3:
    mov eax, [esp + 4]
    mov cr3, eax
    ret

write_cr0:
    mov eax, [esp + 4]
    mov cr0, eax
    ret

read_cr3:
    mov eax, cr3
    ret

read_cr0:
    mov eax, cr0
    ret
