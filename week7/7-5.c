#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <errno.h>

enum
{

    MIN_YEAR = 1902,
    MAX_YEAR = 2037,

    CONST_YEAR = 1900,
    ISDST_FLAG = -1,

    MOON_YEAR = 2021,
    MOON_MONTH = 5,
    MOON_DAY = 26,
    MOON_HOUR = 11,
    MOON_MIN = 14,
    MOON_SEC = 0,

    PERIOD_DAY = 256,

    SYNODIC_DAY = 29,
    SYNODIC_HOUR = 12,
    SYNODIC_MIN = 44,

    SEC_IN_DAY = 86400,
    SEC_IN_HOUR = 3600,
    SEC_IN_MIN = 60,

    MONDAY = 1,
    TO_FOURTH_MONDAY = 21

};

int
main(int argc, char *argv[])
{

    int year;
    if ((scanf("%d", &year) != 1)) {
        fprintf(stderr, "Error reading a year\n");
        exit(1);
    }
    if (year > MAX_YEAR || year < MIN_YEAR) {
        fprintf(stderr, "Incorect input data: year must be in [%d, %d]\n", MIN_YEAR, MAX_YEAR);
    }

    struct tm moon_t = {};
    moon_t.tm_year = MOON_YEAR - CONST_YEAR;
    moon_t.tm_mon = MOON_MONTH - 1;
    moon_t.tm_mday = MOON_DAY;
    moon_t.tm_hour = MOON_HOUR;
    moon_t.tm_min = MOON_MIN;
    moon_t.tm_sec = MOON_SEC;
    moon_t.tm_isdst = ISDST_FLAG;

    errno = 0;
    time_t moon_time = mktime(&moon_t);
    if (moon_time == -1 && errno) {
        fprintf(stderr, "Mktime error\n");
        exit(1);
    }

    time_t synodic_period = SYNODIC_DAY * SEC_IN_DAY + SYNODIC_HOUR * SEC_IN_HOUR + SYNODIC_MIN * SEC_IN_MIN;

    if (year >= MOON_YEAR) {
        while (moon_t.tm_year != year - CONST_YEAR || moon_t.tm_yday < PERIOD_DAY) {
            moon_t.tm_sec += synodic_period;
            timegm(&moon_t);
        }
    } else {
        while (moon_t.tm_year != year - CONST_YEAR || moon_t.tm_yday >= PERIOD_DAY) {
            moon_t.tm_sec -= synodic_period;
            timegm(&moon_t);
        }
        moon_t.tm_sec += synodic_period;
        moon_t.tm_yday += 1;
        timegm(&moon_t);
    }

    moon_t.tm_mday++;
    timegm(&moon_t);

    while (moon_t.tm_wday != MONDAY) {
        moon_t.tm_mday++;
        timegm(&moon_t);
    }
    moon_t.tm_mday += TO_FOURTH_MONDAY;
    timegm(&moon_t);

    printf("%04d-%02d-%02d\n", moon_t.tm_year + CONST_YEAR, moon_t.tm_mon + 1, moon_t.tm_mday);

    return 0;
}
