#include <sys/mman.h>

#include <errno.h>
#include <unistd.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

void *map(const char *path, size_t offset, size_t size, size_t *psize, bool ro) {
    int fd;
    _syscall(fd = open(path, ro ? O_RDONLY : O_RDWR));

    if (size == _not(size_t)) {
        struct stat stat;
        _syscall(fstat(fd, &stat));
        size = stat.st_size;
    }

    if (psize != NULL)
        *psize = size;

    void *base;
    _syscall(base = mmap(NULL, size, ro ? PROT_READ : PROT_READ | PROT_WRITE, MAP_SHARED, fd, offset));

    _syscall(close(fd));
    return base;
}
