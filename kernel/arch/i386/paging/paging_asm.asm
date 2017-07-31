global enable_paging

extern page_directory

enable_paging:
    mov cr3, eax ; Arg is passed by eax

    mov eax, cr0
    or eax, 0x80000001
    mov cr0, eax
    
    ret

