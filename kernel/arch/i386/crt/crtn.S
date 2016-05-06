.intel_syntax noprefix

/*
    crtn.S give the epilog for the .init and the .fini section 
*/
.section .init
_init:
	pop ebp
    ret

.section .fini
_fini:
	pop ebp
    ret	
