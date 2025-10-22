#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <limits.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
enum
{
    RADIX = 8
};

int
main(int argc, char *argv[])
{
    const char template[] = "rwxrwxrwx";
    const int result_str_len = sizeof(template);

    for (int i = 1; i < argc; ++i) {
        char *eptr = NULL;
        errno = 0;
        long file_perm = strtol(argv[i], &eptr, RADIX);
        if (errno || *eptr || eptr == argv[i] || (int) file_perm != file_perm) {
            fprintf(stderr, "Incorrect command line arguments: error converting a string to a number\n");
            exit(1);
        }

        char result[result_str_len];
        int len = result_str_len - 1;
        long mask = 1;
        for (int j = len - 1; j >= 0; --j) {
            if (file_perm & mask) {
                result[j] = template[j];
            } else {
                result[j] = '-';
            }
            mask <<= 1;
        }
        result[result_str_len - 1] = '\0';
        printf("%s\n", result);
    }
    return 0;
}
