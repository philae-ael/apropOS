#include <stdio.h>
 
char* gets(char* str)
{
    char c;
    char* strPtr = str;
    while(1)
    {
        c = getchar();

        if(!c)
        {
            return NULL;
        }

        if(c == '\n')
        {
            *strPtr = '\0';
            break;
        }
        *strPtr = c;

        strPtr++;
    }

	return str;
}
