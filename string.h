#include <string.h>

char *strndup_(const char *src, int len) {
    char *dst = malloc(len + 1);
    _assert(dst != NULL);
    strncpy(dst, src, len);
    dst[len] = '\0';
    return dst;
}
