global enable_paging
global set_page_dir

set_page_dir:
    push ebp
    mov ebp, esp

    mov eax, [ebp + 0x8]
    mov cr3, eax ; Arg is passed by eax

    pop ebp
    ret

enable_paging:
    mov eax, cr0
    or eax, 0x80000000
    mov cr0, eax
    
    ret

