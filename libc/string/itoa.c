#include <stdbool.h>
#include <stdio.h>

#define INT_DIGITS 32// max size for a 32 bit variable (in base 2)

char *itoa(int i,int base)
{
    int j;
    bool neg = false;
    if (i < 0 && base == 10)
    {
        neg = true;
        i = -i;
    }

    /* Room for INT_DIGITS digits, - and '\0' */
    static char buf[INT_DIGITS + 2]; // /!\ WARNING !! SHOULD BE REMPLACED BY A MALLOC ASAP !!!!!
    
    char* p = buf + INT_DIGITS + 1;

    *p = '\0';
    p--;

    do
    {
        j = i % base;

        if(j<10)
            *p = '0' + (char)j;
        else
            *p = 'a' + (char) (j-10);

        p--;

        i /= base;
    }while (i!=0);

    if(neg)
    {
        *p = '-';
        p--;
    }

    return p;
} 
