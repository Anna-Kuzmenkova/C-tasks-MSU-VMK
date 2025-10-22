#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <limits.h>
#include <unistd.h>

enum
{
    KIBIBYTE = 1024
};

int
main(int argc, char *argv[])
{
    long long sum_size = 0;
    for (int i = 1; i < argc; ++i) {

        struct stat stb;
        if (lstat(argv[i], &stb) >= 0 && S_ISREG(stb.st_mode) && stb.st_nlink == 1 && stb.st_size % KIBIBYTE == 0) {
            sum_size += stb.st_size;
        }
    }
    printf("%lld\n", sum_size);
    return 0;
}
