#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <errno.h>

enum
{
    MAX_RATE = 10000,
    MIN_RATE = 0,
    MAX_CHANGE = 100,
    MIN_CHANGE = -100,
    PERCENT_DIV = 100,
    ROUND_CONST = 10000
};

int
main(int argc, char *argv[])
{

    char *eptr = NULL;
    errno = 0;
    long double rate = strtold(argv[1], &eptr);
    if (errno || *eptr != '\0' || eptr == argv[1]) {
        fprintf(stderr, "Incorrect command line arguments: error converting a string to a number\n");
        exit(1);
    }
    if (rate <= MIN_RATE || rate > MAX_RATE) {
        fprintf(stderr, "Incorrect data: the exchange rate should be in range (0, 10000)\n");
        exit(1);
    }

    for (int i = 2; i < argc; ++i) {

        char *eptr = NULL;
        errno = 0;
        long double change = strtold(argv[i], &eptr);

        if (errno || *eptr != '\0' || eptr == argv[i]) {
            fprintf(stderr, "Incorrect command line arguments: error converting a string to a number\n");
            exit(1);
        }
        if (change <= MIN_CHANGE || change >= MAX_CHANGE) {
            fprintf(stderr, "Incorrect data: the course change should be in range (-100, 100)\n");
            exit(1);
        }
        rate *= (1 + change / (double) PERCENT_DIV);
        rate = round(rate * (double) ROUND_CONST) / (double) ROUND_CONST;
    }
    printf("%.4Lf\n", rate);
    return 0;
}
