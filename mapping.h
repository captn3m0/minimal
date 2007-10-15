#include <sys/mman.h>

#include <errno.h>
#include <unistd.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

void *Map(const char *path, size_t *size, bool ro) {
    int fd;
    _syscall(fd = open(path, ro ? O_RDONLY : O_RDWR));

    struct stat stat;
    _syscall(fstat(fd, &stat));

    if (size != NULL)
        *size = stat.st_size;

    void *base;
    _syscall(base = mmap(0, stat.st_size, ro ? PROT_READ : PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0));

    _syscall(close(fd));
    return base;
}
