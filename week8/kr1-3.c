#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <limits.h>
#include <errno.h>
#include <time.h>

enum
{
    CONST_YEAR = 1900,
    SIX_MONTHS = 6,
    SATURDAY = 6,
    SUNDAY = 0
};

int
main(int argc, char *argv[])
{

    int year, mon, day, count;
    scanf("%d-%d-%d %d", &year, &mon, &day, &count);
    if (count < 1) {
        fprintf(stderr, "Incorect input data\n");
        exit(1);
    }

    struct tm t = {};
    t.tm_year = year - CONST_YEAR;
    t.tm_mon = mon - 1;
    t.tm_mday = day;
    t.tm_isdst = -1;

    for (int i = 1; i <= (count * 2); ++i) {

        struct tm new_t = t;
        new_t.tm_mon += SIX_MONTHS * i;

        errno = 0;
        time_t time = mktime(&new_t);
        if (time == -1 && errno) {
            fprintf(stderr, "Mktime error\n");
            exit(1);
        }

        if (new_t.tm_wday == SATURDAY) {
            new_t.tm_mday += 2;
            errno = 0;
            time_t time = mktime(&new_t);
            if (time == -1 && errno) {
                fprintf(stderr, "Mktime error\n");
                exit(1);
            }

        } else if (new_t.tm_wday == SUNDAY) {
            new_t.tm_mday += 1;
            errno = 0;
            time_t time = mktime(&new_t);
            if (time == -1 && errno) {
                fprintf(stderr, "Mktime error\n");
                exit(1);
            }
        }
        printf("%04d-%02d-%02d\n", new_t.tm_year + CONST_YEAR, new_t.tm_mon + 1, new_t.tm_mday);
    }
    return 0;
}
