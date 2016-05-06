#include <i386/asm/asm.h>

#include <kdb/kdb.h>
#include <i386/kdb/kdb.h>
#include <i386/kdb/scansets.h>

char getChar(){
    static char c=0; // TODO re a clean thing for kdb
    do {
        if(inb(0x60)!=c)
        {
            c=inb(0x60);
            if(c>0)
                return c;
        }
    }while(1);
}
