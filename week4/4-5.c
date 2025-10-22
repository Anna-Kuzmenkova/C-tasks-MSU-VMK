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
    int fd1 = open(argv[1], O_RDONLY);
    if (fd1 < 0) {
        fprintf(stderr, "Error opening file1\n");
        exit(1);
    }
    int fd2 = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0666);
    if (fd2 < 0) {
        fprintf(stderr, "Error opening file2\n");
        exit(1);
    }
    char *eptr = NULL;
    errno = 0;
    long mod = strtol(argv[3], &eptr, RADIX);
    if (errno || *eptr || eptr == argv[3] || (int) mod != mod) {
        fprintf(stderr, "Incorrect command line arguments: error converting a string to a number\n");
        exit(1);
    }
    unsigned char pos;
    long long sum = 0, count = 0;
    while (read(fd1, &pos, sizeof(pos)) > 0) {
        for (int i = 1; i <= CHAR_BIT; ++i) {
            count++;
            sum += count * count;
            if (pos & 1) {
                int num = sum % mod;
                if (write(fd2, &num, sizeof(num)) < 0) {
                    fprintf(stderr, "Error writing in file\n");
                    exit(1);
                }
            }
            pos >>= 1;
        }
    }
    close(fd1);
    close(fd2);
    return 0;
}
