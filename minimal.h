#define _assert(expr) \
    do if (!(expr)) { \
        fprintf(stderr, "_assert(%s)\n", #expr); \
        exit(1); \
    } while (false)

#define _syscall(expr) \
    do if ((long) (expr) != -1) \
        break; \
    else switch (errno) { \
        case EINTR: \
            continue; \
        default: \
            _assert(false); \
    } while (true)

#define _forever \
    for (;;)

#define _trace() \
    printf("_trace(%s:%u)\n", __FILE__, __LINE__)

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h>
