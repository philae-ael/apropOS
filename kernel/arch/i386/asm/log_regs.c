#include <kernel/i386/asm/regs.h>
#include <logging.h>

void log_regs(struct regs* r){
    errf("Regs: ");
    errf("gs: %X\tfs: %X\tes: %Xds: %X", r->gs, r->fs, r->es, r->ds);
    errf("edi: %X\tesi: %X\tebp: %Xesp: %X", r->edi, r->esi, r->ebp, r->esp);
    errf("ebx: %X\tedx: %X\tecx: %X\teax: %X", r->ebx, r->edx, r->ecx, r->eax);
    errf("eip: %X\tcs: %X\teflags: %X\tuseresp: %Xss: %X", r->eip, r->cs, r->eflags, r->useresp, r->ss);
}
