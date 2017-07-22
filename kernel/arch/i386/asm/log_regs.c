#include <asm/regs.h>
#include <logging.h>

void log_regs(struct regs* r){
    errf("Regs: \n");
    errf("gs: %X\tfs: %X\tes: %X\tds: %X\n", r->gs, r->fs, r->es, r->ds);
    errf("edi: %X\tesi: %X\tebp: %X\tesp: %X\n", r->edi, r->esi, r->ebp, r->esp);
    errf("ebx: %X\tedx: %X\tecx: %X\teax: %X\n", r->ebx, r->edx, r->ecx, r->eax);
    errf("eip: %X\tcs: %X\teflags: %X\tuseresp: %X\tss: %X\n", r->eip, r->cs, r->eflags, r->useresp, r->ss);
}
