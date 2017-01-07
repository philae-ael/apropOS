global irq_disable:function
irq_disable:
    mov al, 0xff
    out 0xa1, al
    out 0x21, al
    ret
