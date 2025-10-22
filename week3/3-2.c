#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <limits.h>

enum
{
    RADIX = 10
};

int
main(int argc, char *argv[])
{
    long int num;
    long long int sum1 = 0, sum2 = 0;
    for (int i = 1; i < argc; i++) {
        char *eptr = NULL;
        errno = 0;
        num = strtol(argv[i], &eptr, RADIX);
        if (errno || *eptr || eptr == argv[i] || (int) num != num) {
            fprintf(stderr, "Incorrect command line arguments: error converting a string to a number\n");
            exit(1);
        }
        if (num > 0) {
            sum1 += num;
        } else {
            sum2 += num;
        }
    }
    printf("%lld\n%lld\n", sum1, sum2);
    return 0;
}
