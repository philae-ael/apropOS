#include <libk/string.h>

int memcmp(const void *ptr1, const void *ptr2, size_t num) {
  const char *char1 = ptr1;
  const char *char2 = ptr2;
  while (num > 0) {
    if (*char1 != *char2)
      return *char1 - *char2;

    num--;
    char1++;
    char2++;
  }
  return 0;
}
