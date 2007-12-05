#ifndef MINIMAL_STRING_H
#define MINIMAL_STRING_H

#include <string.h>

_unused static char *strndup_(const char *src, int len) {
    char *dst = malloc(len + 1);
    _assert(dst != NULL);
    strncpy(dst, src, len);
    dst[len] = '\0';
    return dst;
}

#endif/*MINIMAL_STRING_H*/
