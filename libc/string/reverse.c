#include <stddef.h>

void reverse(char str[], size_t length)
{
    int start = 0;
    int end = length -1;
    while (start < end)
    {
        // Xor based swap
        *(str+start) ^= *(str+end);
        *(str+end)   ^= *(str+start);
        *(str+start) ^= *(str+end);

        start++;
        end--;
    }
}

