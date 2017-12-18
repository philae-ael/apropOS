#include <kernel/i386/asm/regs.h>
#include <libk/logging.h>

void log_regs(struct regs* r){
    errf("Regs: ");
    errf("gs: %X\tfs: %X\tes: %X\tds: %X", r->gs, r->fs, r->es, r->ds);
    errf("edi: %X\tesi: %X\tebp: %X\tesp: %X", r->edi, r->esi, r->ebp, r->esp);
    errf("ebx: %X\tedx: %X\tecx: %X\teax: %X", r->ebx, r->edx, r->ecx, r->eax);
    errf("eip: %X\tcs: %X\teflags: %X\tuseresp: %X\tss: %X", r->eip, r->cs, r->eflags, r->useresp, r->ss);
    errf("err_code %X\tds %X\tes %X", r->err_code, r->ds, r->es, r->fs);
}
