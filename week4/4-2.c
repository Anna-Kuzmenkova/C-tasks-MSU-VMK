#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <errno.h>
#include <limits.h>

enum
{
    RADIX = 10
};

int
main(int argc, char *argv[])
{
    int fd = open(argv[1], O_RDWR);
    if (fd < 0) {
        fprintf(stderr, "Error opening file\n");
        exit(1);
    }
    char *eptr = NULL;
    errno = 0;
    long n = strtol(argv[2], &eptr, RADIX);
    if (errno || *eptr || eptr == argv[2] || (int) n != n) {
        fprintf(stderr, "Incorrect command line arguments: error converting a string to a number\n");
        exit(1);
    }
    if (n <= 1) {
        return 0;
    }
    double in_num, out_num;
    if (read(fd, &in_num, sizeof(in_num)) < 0) {
        fprintf(stderr, "Error reading from a file\n");
        exit(1);
    }
    int count = 1;
    while (read(fd, &out_num, sizeof(out_num)) == sizeof(out_num) && count < n) {
        if (lseek(fd, -sizeof(out_num), SEEK_CUR) < 0) {
            fprintf(stderr, "Lseek error\n");
            exit(1);
        }
        in_num = out_num - in_num;
        if (write(fd, &in_num, sizeof(in_num)) < 0) {
            fprintf(stderr, "Error writing in file\n");
            exit(1);
        }
        count++;
    }
    close(fd);
    return 0;
}
