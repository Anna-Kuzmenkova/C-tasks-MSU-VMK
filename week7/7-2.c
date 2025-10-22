#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <errno.h>

enum
{
    MIN_YEAR = 1910,
    MAX_YEAR = 2037,
    MONTHS = 12,
    DAYS = 31,
    CONST_YEAR = 1900,
    THURSDAY = 4,
    DIVIDER = 3,
    WEEK_DAYS = 7,
    FOURTH_THURSDAY_WEEK = 3
};

int
main(int argc, char *argv[])
{
    int year;
    if (scanf("%d", &year) != 1) {
        fprintf(stderr, "Error reading data from input stream\n");
        exit(1);
    }
    if (year > MAX_YEAR || year < MIN_YEAR) {
        fprintf(stderr, "Incorect input data: year must be in [1910, 2037]");
        exit(1);
    }

    for (int month = 0; month < MONTHS; ++month) {
        struct tm t = {};
        t.tm_year = year - CONST_YEAR;
        t.tm_isdst = -1;
        t.tm_mon = month;
        t.tm_mday = 1;

        errno = 0;
        if (mktime(&t) == -1 && errno) {
            fprintf(stderr, "mktime error\n");
            exit(1);
        }

        int first_thusday = 1 + ((THURSDAY - t.tm_wday + WEEK_DAYS) % WEEK_DAYS);
        int second_thursday = first_thusday + WEEK_DAYS;
        int fourth_thursday = first_thusday + WEEK_DAYS * FOURTH_THURSDAY_WEEK;

        struct tm fourth_th = t;
        fourth_th.tm_mday = fourth_thursday;
        errno = 0;
        if (mktime(&fourth_th) == -1 && errno) {
            fprintf(stderr, "mktime error\n");
            exit(1);
        }
        if (fourth_th.tm_mon != month) {
            fourth_thursday = 0;
        }

        if (second_thursday % DIVIDER != 0) {
            printf("%d %d\n", month + 1, second_thursday);
        }
        if (fourth_thursday && fourth_thursday % DIVIDER != 0) {
            printf("%d %d\n", month + 1, fourth_thursday);
        }
    }
    return 0;
}
