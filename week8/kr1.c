#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

enum {
    MAX_N = 100000,
    MIN_N = 0
};

int
sort_func(const void *p1, const void *p2)
{
    int v1 = *(const int *) p1;
    int v2 = *(const int *) p2;
    if (v1 > v2) {
        return -1;
    }
    return v1 < v2;
}
int
main(int argc, char *argv[])
{

    int n;
    if (scanf("%d", &n) != 1) {
        fprintf(stderr, "Error reading a number\n");
        exit(1);
    }
    if (n < MIN_N || n > MAX_N) {
        fprintf(stderr, "Incorrect input data: N must be in [%d, %d]\n", MIN_N, MAX_N);
        exit(1);
    }
    if (n == 0) {
        return 0;
    }
    int32_t *arr = calloc(n, sizeof(*arr));
    if (!arr) {
        fprintf(stderr, "Calloc error\n");
        exit(1);
    }

    for (int i = 0; i < n; ++i) {
        if (scanf("%d", &arr[i]) != 1) {
            fprintf(stderr, "Error reading a number\n");
            free(arr);
            exit(1);
        }
    }
    qsort(arr, n, sizeof(*arr), sort_func);
    for (int i = 0; i < n; ++i) {
        printf("%d\n", arr[i]);
    }
    free(arr);
    return 0;
}
